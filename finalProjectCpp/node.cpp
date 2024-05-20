#include "node.h"
#include "priorityQueue.h"
#include "priorityQueue.cpp"
#include "functions.h"
#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <map>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <bitset>
#include "nodeInAxis.h"


#define INDEX_VALUE(difference)
//#define SET_VALUES(difference, out1, out2, out3, vec_rand) do { \
//                            out1 = (difference == 1 ? "A2" : \
//                                    (difference > 1 ? "A1" : \
//                                    (difference == -1 ? "C2" : \
//                                    "A3"))); \
//                            out2 = (difference == 1 ? "B1" : \
//                                    (difference > 1 ? "D2" : \
//                                    (difference == -1 ? "B3" : \
//                                    "B2"))); \
//                            out3 = (difference == 1 ? "D3" : \
//                                    (difference > 1 ? "C3" : \
//                                    (difference == -1 ? "D1" : \
//                                    "C1"))) ; \
//                             vec_rand = (difference == 1 ? {"A1", "A2", "A3"}: \		
//                                   (difference > 1 ?{"B1","B2","B3"}: \
//								   (difference == -1 ?{"C1","C2","C3"} : \
//								   {"D1", "D2", "D3"})));
using namespace std;


template <typename T>
node<T>::node(int id)
{
	this->id_node = id;
	//this->pq_node = new priorityQueue<T>();
	this->initialize_st();
}

template <typename T>
void node<T>::initialize_st()
{
	map<string, vector<string>> mapOut = { {"A1",{"D1","D2","D3"}},
										   {"A2",{"A1","A2","A3"}},
										   {"A3",{"B1","B2","B3"}},
										   {"B1",{"A1","A2","A3"}},
										   {"B2",{"B1","B2","B3"}},
										   {"B3",{"C1","C2","C3"}},
										   {"C1",{"B1","B2","B3"}},
										   {"C2",{"C1","C2","C3"}},
										   {"C3",{"D1","D2","D3"}},
										   {"D1",{"C1","C2","C3"}},
										   {"D2",{"D1","D2","D3"}},
										   {"D3",{"A1","A2","A3"}} };
	for (size_t i = 0; i < arrStIds->length(); i++)
	{
		st s(arrStIds[i]);
		this->getNodeSt()[arrStIds[i]] = s;
		this->getNodeSt()[arrStIds[i]].setRandOut(mapOut[arrStIds[i]]);
	}



}
template<typename T>
void node<T>::nextSt(int idNextNode, NodeMint n)
{
	vector<std::string> nextNodeDirection[4];
	//קטן ממנו ביותר מ-1
	nextNodeDirection[0].push_back("A3");
	nextNodeDirection[0].push_back("B2");
	nextNodeDirection[0].push_back("C1");
	//גדול ממנו ב1

	nextNodeDirection[1].push_back("A2");
	nextNodeDirection[1].push_back("B1");
	nextNodeDirection[1].push_back("D3");
	//קטן ממנו ב1

	nextNodeDirection[2].push_back("C2");
	nextNodeDirection[2].push_back("D1");
	nextNodeDirection[2].push_back("B3");
	//גדול ממנו ביותר מ1

	nextNodeDirection[3].push_back("A1");
	nextNodeDirection[3].push_back("D2");
	nextNodeDirection[3].push_back("C3");


	int index;
	int difference = idNextNode - this->getIdNode();
	double num_difference = static_cast<double>(idNextNode - this->getIdNode());
	std::bitset<sizeof(int) * 8> binary(difference);
	bool rightmost_bit = binary.test(0);
	bool leftmost_bit = binary.test(sizeof(int) * 8 - 1);
	index = rightmost_bit + leftmost_bit;
	if (std::signbit(num_difference) && difference != -1)
		index = 0;
	else
		if (difference != 1)
			index = 3;

	n.all_options_toOut = nextNodeDirection[index];



	/*srand(time(0));

	int number_rand;
	map<string, vector<string>> stOut;
	if (idNextNode - this->getIdNode() == 1)
	{
		stOut["A2"] = { "A1","A2","A3" };
		stOut["B1"] = { "A1","A2","A3"};
		stOut["D3"] = { "A1","A2","A3" };

	}
	else
	{
		if (idNextNode - this->getIdNode() > 1)
		{
			stOut["A1"] = { "D1","D2","D3" };
			stOut["D2"] = { "D1","D2","D3" };
			stOut["C3"] = { "D1","D2","D3" };


		}
		else
			if (idNextNode - this->getIdNode() < 1 == -1) {
				"B3"
				"C2"
				"D1"
			}
		 if(idNextNode - this->getIdNode()<1)
		{
			stOut["A3"]={}
			stOut["B2"]
			stOut3["C1"]


		}
	}

	return stOut;*/
}






template <typename T>
void node<T>::pushPq(std::string st1, std::string st2, int n1, int n2) {
	this->pq_node.push(st1, st2, n1, n2);
	this->pq_node.checkForDuplicates();
}

template<typename T>
std::vector<std::pair<int, std::chrono::system_clock::time_point>> node<T>::getTimePointsAndIdsForFirstCar()
{
	std::vector<std::pair<int, std::chrono::system_clock::time_point>> pointsAndIds;

	for (int i = 0; i < arrStIds->length(); i++)
	{
		if (!stNodes[arrStIds[i]].getNumCars().empty())
		{
			const auto& firstCar = stNodes[arrStIds[i]].getNumCars().front();
			pointsAndIds.push_back(std::make_pair(arrStIds[i], firstCar));
		}
	}

	return pointsAndIds;
}

template<typename T>
bool node<T>::compareTimePoints(const std::pair<int, std::chrono::system_clock::time_point>& pair1, const std::pair<int, std::chrono::system_clock::time_point>& pair2) {
	return pair1.second > pair2.second;
}

template<typename T>
void node<T>::sortTimeListByElapsedTime(std::vector<std::pair<int, std::chrono::system_clock::time_point>>& timePairList) {
	if (timePairList.size() <= 1) {
		return;
	}

	std::sort(timePairList.begin(), timePairList.end(), [](const auto& pair1, const auto& pair2) {
		return pair1.second > pair2.second;
		});
}

template<typename T>
void node<T>::transferToNext(string id_st_green)
{
	nodeInAxis nA;
	vector <string> rand_out;
	string stNext;
	node* next_node;
	int seconds;
	int length;
	int randomInt;
	int numSt;
	int priority1 = 0;
	std::chrono::system_clock::time_point car_now;

	for (const NodeMint& nodeMint : nextNodes)
	{
		if (nodeMint.all_options_toOut[id_st_green])
		{

			next_node = nodeMint.next;
			seconds = nodeMint.edge;
			rand_out = this->getNodeSt()[id_st_green].getRand_out();
			length = rand_out.size();
			numSt = id_st_green.back() - '0';


			break;

		}


	}

	///גל ירוק
	if (this->getNodeSt()[id_st_green].getInAxis())
	{
		if (nA.getPqAxis().checkTopId(this->getNodeSt()[id_st_green].getAaxisId()))
			priority1 = this->getNodeSt()[id_st_green].getListCars().size() * 10;
	}
	while (this->getNodeSt()[id_st_green].getListCars())
	{
		car_now = this->getNodeSt()[id_st_green].getListCars().pop_front();

		randomInt = 0 + rand() % (length - 0 + 1);
		stNext = this->getNodeSt()[id_st_green].getRand_out()[randomInt];
		if (numSt != 3)
			std::this_thread::sleep_for(std::chrono::seconds(seconds));
		next_node->getNodeSt()[stNext].addCar(std::chrono::system_clock::now(), priority1);
		//לשנות עדיפות לנתיב שנכנס עכשיו
		next_node->getPqNode()->replace(stNext, next_node->getNodeSt()[stNext].getPriority());
	}

}


template<typename T>
void node<T>::onTrrafic(string idSt)
{
	this->getNodeSt()[idSt].setRed(false);
	this->getNodeSt()[idSt].setStartLight(std::chrono::system_clock::now());

	this->getPqNode()->replace(idSt, this->getNodeSt()[idSt].getListCars().size());
	this->transferToNext(idSt);
}

template<typename T>
void node<T>::offTrrafic(string idSt) {

	this->getNodeSt()[idSt].setRed(true);

}



//פונקציה שמנהלת את הרמזור בצומת
template<typename T>
void node<T>::trraficLogicInNode()
{
	while (true)
	{
		//לעשות את הפונקציה הזאת
		this->offTrrafic(lightNow1, lightNow2);

		std::this_thread::sleep_for(std::chrono::seconds(2));

		//לקחת את האיבר מראש התור
		auto top = pq_node.getTopStringIds();
		string stTop1 = top.first;
		string stTop2 = top.second;
		onTrrafic(stTop1);
		onTrrafic(stTop2);


		std::this_thread::sleep_for(std::chrono::seconds(30));
	}
}





//בודקת האם אין נתיב שממתין מעבר לזמן ההמתנה המקסימלי
template<typename T>
 void node<T>::overWaiting()
{
	std::vector<std::pair<int, std::chrono::system_clock::time_point>> timeList;
	string firstWaiterOver;
	while (true)
	{
		timeList = getTimePointsAndIdsForFirstCar();
		//לקבל את הid של מי שחכה הכי הרבה זמן

		sortTimeListByElapsedTime(timeList);
		std::time_t firstMemberTime = std::chrono::system_clock::to_time_t(timeList.front().second);
		firstWaiterOver = this->getNodeSt()[timeList.front().first];
		auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		double lesstimeLight = std::difftime(currentTime, this->stNodes[lightNow1].getStartLight()) / 60.0;

		double diffMinutesOver = std::difftime(currentTime, firstMemberTime) / 60.0;

		if (diffMinutesOver > 3.0 && lesstimeLight > 0.1)
		{
			//לעשות את הפונקציה הזאת
			offTrrafic(this->lightNow1);
			offTrrafic(this->lightNow2);
			std::this_thread::sleep_for(std::chrono::seconds(2));
			//לעשות את הפונקציה הזאת
			onTrrafic(firstWaiterOver);

		}
	}
}

template<typename T>
void node<T>::updatePriority()
{
	int prioritySt, numOfWaiters, timeWait, seconds, numCulculate;
	while (true)
	{
		for (int i = 0; i < arrStIds->length(); i++)
		{
			if (!stNodes[arrStIds[i]].getListCars().empty())
			{
				stNodes[arrStIds[i]].deleteCarsTravel();
				numOfWaiters = stNodes[arrStIds[i]].getListCars().size();
				std::time_t waitingTime = std::chrono::system_clock::to_time_t(stNodes[arrStIds[i]].getListCars().front());
				seconds = static_cast<int>(waitingTime);
				numCulculate = seconds / 60;

				prioritySt = numOfWaiters * (1 + numCulculate) * 5;
				prioritySt = (numOfWaiters < 60) ? prioritySt : numOfWaiters;
				prioritySt += this->getNodeSt()[arrStIds[i]].getPriority();
				this->getPqNode().replace(arrStIds[i], prioritySt);

			}
		}
		std::this_thread::sleep_for(std::chrono::seconds(25));
	}

}



