
#include "node.h"
#include "priorityQueue.h"

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
#include <algorithm>
#include "nodeInAxis.h"
#include <future> 
#include <cstring>
#include <stdio.h>



using namespace std;




node::node(int id)
{
	this->id_node = id;
	nodeMutexPtr = std::make_shared<std::mutex>();
	this->initialize_st();
	this->initislize_pq();
}

node& node::operator=(const node& other)
{
	cout << "1" << endl;
	if (this != &other) {
		this->id_node = other.id_node;
		this->pq_node = other.pq_node;
		this->stNodes = other.stNodes; 
		this->lightNow1 = other.lightNow1;
		this->lightNow2 = other.lightNow2;
		this->nextNodes = other.nextNodes;
	}
	return *this;

}

void node::initialize_st()
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
	map<std::string, st> new_node_st;
	int arrSize = sizeof(arrStIds) / sizeof(arrStIds[0]);

	for (size_t i = 0; i < arrSize; i++)
	{
		
		st s(arrStIds[i]);
		s.setId_node(this->getIdNode());
		s.setRandOut(mapOut[arrStIds[i]]);
		new_node_st[arrStIds[i]] = s;
		
	}
	this->setNodeSt(new_node_st);



}
void node::initislize_pq()
{
	Element e("A1", "A2", 0, 0);
	Element e1("B1", "B2", 0, 0);
	Element e2("C1", "C2", 0, 0);
	Element e3("D1", "D2", 0, 0);
	Element e4("A2", "C2", 0, 0);
	Element e5("B2", "D2", 0, 0);
	this->pq_node.push(e);
	this->pq_node.push(e1);
	this->pq_node.push(e2);
	this->pq_node.push(e3);
	this->pq_node.push(e4);
	this->pq_node.push(e5);
	
}

void node::nextSt(int idNextNode, NodeMint n)
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






void node::pushPq(std::string st1, std::string st2, int n1, int n2) {
	Element newE(st1,st2, n1, n2);
	this->pq_node.push(newE);
	this->pq_node.checkForDuplicates();
}

std::vector<std::pair<std::string, std::chrono::system_clock::time_point>> node::getTimePointsAndIdsForFirstCar()
{
	std::vector<std::pair<std::string, std::chrono::system_clock::time_point>> pointsAndIds;

	for (int i = 0; i < arrStIds->length(); i++)
	{
		if (!stNodes[arrStIds[i]].getListCars().empty())
		{
			const auto& firstCar =this->getNodeSt()[arrStIds[i]].getListCars().front();
			pointsAndIds.push_back(std::make_pair(arrStIds[i], firstCar));
		}
	}

	return pointsAndIds;
}

bool node::compareTimePoints(const std::pair<int, std::chrono::system_clock::time_point>& pair1, const std::pair<int, std::chrono::system_clock::time_point>& pair2) {
	return pair1.second > pair2.second;
}

void node::sortTimeListByElapsedTime(std::vector<std::pair<std::string, std::chrono::system_clock::time_point>>& timePairList) {
	if (timePairList.size() <= 1) {
		return;
	}

	std::sort(timePairList.begin(), timePairList.end(), [](const auto& pair1, const auto& pair2) {
		return pair1.second > pair2.second;
		});
}

void node::transferToNext(string id_st_green)
{
	nodeInAxis nA;
	vector <string> rand_out;
	string stNext;
	node* next_node = nullptr;
	int seconds=0, length=0,randomInt=0,numSt=0,priority1=0;
		std::chrono::system_clock::time_point car_now;

	for (const NodeMint& nodeMint : nextNodes)
	{
		if (*(find(nodeMint.all_options_toOut.begin(), nodeMint.all_options_toOut.end(),id_st_green))!="")
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
			priority1 = this->getNodeSt()[id_st_green].getListCars().size()*10;
	}
	while (!this->getNodeSt()[id_st_green].getListCars().empty())	
	{
		car_now = this->getNodeSt()[id_st_green].getListCars().front();
		this->getNodeSt()[id_st_green].getListCars().pop_front();

		randomInt = 0 + rand() % (length - 0 + 1);
		stNext = this->getNodeSt()[id_st_green].getRand_out()[randomInt];
		if (numSt != 3) {
			auto future_sleep = std::async(std::launch::async, [](int seconds) {
				std::this_thread::sleep_for(std::chrono::seconds(seconds));
				}, seconds);
		}
		if (next_node != nullptr) {

			next_node->getNodeSt()[stNext].addCar(std::chrono::system_clock::now(), priority1);
			//לשנות עדיפות לנתיב שנכנס עכשיו
			next_node->getPqNode().replace(stNext, next_node->getNodeSt()[stNext].getPriority());

		}
	}

}


void node::onTrrafic(string idSt)
{
	
	int numSt = idSt.back() - '0';

	this->getNodeSt()[idSt].setRed(false);
	this->getNodeSt()[idSt].setStartLight(std::chrono::system_clock::now());

	this->getPqNode().replace(idSt, this->getNodeSt()[idSt].getListCars().size());
	this->transferToNext(idSt);
	//לכתוב לקובץ איזה רמזורים להדליק עכשיו
	if (this->getIdNode() == 5)
	{
		std::ofstream outFile("C:\\Users\\User\\Desktop\\trrafic_now.txt");
		if (outFile.is_open()) {
			outFile << idSt << endl;
			outFile.close();
			std::cout << "Values written to file successfully." << std::endl;
		}
		else {
			std::cerr << "Unable to open file for writing." << std::endl;
		}
	}
	
	
	
}

void node::offTrrafic(string idSt) {

	this->getNodeSt()[idSt].setRed(true);

}


void change_color_traffic(int id, bool status) {
	FILE* pipe =popen("C:/Users/User/Documents/finalProjectmain.py", "w");
	if (!pipe) {
		std::cerr << "Error opening pipe to Python script." << std::endl;
		return;
	}

	// Send the traffic light ID and status to the Python script
	fprintf(pipe, "%d %d\n", id, status ? 1 : 0);
	fflush(pipe); // Flush the output buffer

	// Close the write end of the pipe to signal end of input
	pclose(pipe);

	// Open a pipe to read the response from the Python script
	FILE* response_pipe = popen("C:/Users/User/Documents/finalProjectmain.py", "r");
	if (!response_pipe) {
		std::cerr << "Error opening response pipe from Python script." << std::endl;
		return;
	}

	// Read the response from the Python script
	char response[100];
	fgets(response, sizeof(response), response_pipe);

	// Close the read end of the response pipe
	pclose(response_pipe);

	
}
פונקציה שמנהלת את הרמזור בצומת
if (nodeMutexPtr)
nodeMutexPtr->lock();
void node::trraficLogicInNode()
{
	//node temp_node;
	while (true)
	{
		node* temp_node = new node; // Allocate memory for the new node object

		nodeMutexPtr->lock();
		*temp_node = *this;


		//node temp_node=node(this->getIdNode());
		//Car copiedCar = originalCar;
		//node* temp_node = this;
		////temp_node->setIdNode(this->getIdNode());
		//temp_node.setNextNodes(this->getNextNodes());
		//temp_node.setNodeSt(this->getNodeSt());
		//temp_node.setPqNode(this->getPqNode());
		//temp_node.setLightNow1(this->getLightNow1());
		//temp_node.setLightNow2(this->getLightNow2());


		nodeMutexPtr->unlock();
		//std::shared_lock<std::shared_mutex> lock(*nodeMutexPtr);
		//std::unique_lock<std::shared_mutex> lock(nodeMutex);
		//if (!nodeLock.exchange(true))
		//while (nodeLock.test_and_set(std::memory_order_acquire)) {}
		//nodeMutexPtr->lock();
		if (temp_node->getLightNow1()!= "" && temp_node->getLightNow2() != "")
		{

			nodeMutexPtr->lock();

			this->offTrrafic(lightNow1);
			this->offTrrafic(lightNow2);
			nodeMutexPtr->unlock();


		}


		std::this_thread::sleep_for(std::chrono::seconds(2));

		//לקחת את האיבר מראש התור
		
		if (!temp_node->getPqNode().isEmpty())
		{
			//std::string st1 = this->pq.top().getName1();
			//להחליפ את pq בpq_node
			/*Element tope = this->pq.top();
			cout << tope.getName1() << endl;*/

			/*auto top = temp_node.getPqNode().getTopStringIds();
			string stTop1 = top.first;
			string stTop2 = top.second;*/

			std::string stTop1 = temp_node->getPqNode().top().getName1();
			std::string stTop2 = temp_node->getPqNode().top().getName2();
			std::ofstream outputFile("C:/Users/User/Desktop/lightNow.txt");

			if (outputFile.is_open()) {
				// Write text to the file
				outputFile << "Hello, this is the lightNow in the node:\n" << this->getIdNode() << "\n";
				outputFile << stTop1<<"----"<<stTop2<<"\n";

				// Close the file
				outputFile.close();
				std::cout << "Text written to file successfully." << std::endl;
			}
			else {
				std::cerr << "Error opening the file." << std::endl;
			}
			nodeMutexPtr->lock();
			onTrrafic(stTop1);
			onTrrafic(stTop2);
			nodeMutexPtr->unlock();
		}


		//nodeLock.store(false);
		//nodeLock.clear(std::memory_order_release);


		std::this_thread::sleep_for(std::chrono::seconds(30));
	}
	
}




//nodeMutexPtr->lock();
//shared_lock<shared_mutex> lock(nodeMutex);

//בודקת האם אין נתיב שממתין מעבר לזמן ההמתנה המקסימלי

 std::string node::overWaiting()
{
	std::vector<std::pair<std::string, std::chrono::system_clock::time_point>> timeList;
	string firstWaiterOver="";
	while (true)
	{
		//std::unique_lock<std::shared_mutex> lock(nodeMutex);
		/*if (!nodeLock.exchange(true))
		{*/

		//while (nodeLock.test_and_set(std::memory_order_acquire)) {}
		nodeMutexPtr->lock();
		nodeMutexPtr->try_lock();

   timeList = getTimePointsAndIdsForFirstCar();
			//לקבל את הid של מי שחכה הכי הרבה זמן

    sortTimeListByElapsedTime(timeList);
	if (!timeList.empty())
	{
		std::time_t firstMemberTime = std::chrono::system_clock::to_time_t(timeList.front().second);
		//firstWaiterOver = this->getNodeSt()[timeList.front().first];
		auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		double lesstimeLight = std::difftime(currentTime, std::chrono::system_clock::to_time_t(this->getNodeSt()[lightNow1].getStartLight())) / 60.0;

		double diffMinutesOver = std::difftime(currentTime, firstMemberTime) / 60.0;
		//לקורא מקובץ

		if (diffMinutesOver > 3.0 && lesstimeLight > 0.1)
		{
			firstWaiterOver = timeList.front().first;
			/*offTrrafic(this->lightNow1);
			offTrrafic(this->lightNow2);
			std::this_thread::sleep_for(std::chrono::seconds(2));
			onTrrafic(firstWaiterOver);*/

		}

	}
    
	return firstWaiterOver;
    //nodeMutexPtr->unlock();
    //nodeLock.store(false);
			//nodeLock.clear(std::memory_order_release);


	}
//}
// //shared_lock<shared_mutex> lock(nodeMutex);
// //nodeMutexPtr->lock();
//
//void node::updatePriority()
//{
//	int prioritySt, numOfWaiters, timeWait, seconds, numCulculate;
//	while (true)
//	{
//		//shared_lock<shared_mutex> lock(nodeMutex);
//
//		//std::unique_lock<std::shared_mutex> lock(nodeMutex);
//		/*if (!nodeLock.exchange(true)) {*/
//		//while (nodeLock.test_and_set(std::memory_order_acquire)) {}
//		nodeMutexPtr->lock();
//
//			for (int i = 0; i < arrStIds->length(); i++)
//			{
//				if (!stNodes[arrStIds[i]].getListCars().empty())
//				{
//					stNodes[arrStIds[i]].deleteCarsTravel();
//					numOfWaiters = stNodes[arrStIds[i]].getListCars().size();
//					std::time_t waitingTime = std::chrono::system_clock::to_time_t(stNodes[arrStIds[i]].getListCars().front());
//					seconds = static_cast<int>(waitingTime);
//					numCulculate = seconds / 60;
//
//					prioritySt = numOfWaiters * (1 + numCulculate) * 5;
//					prioritySt = (numOfWaiters < 60) ? prioritySt : numOfWaiters;
//					prioritySt += this->getNodeSt()[arrStIds[i]].getPriority();
//					this->getPqNode().replace(arrStIds[i], prioritySt);
//
//				}
//			}
//			nodeMutexPtr->unlock();
//			//nodeLock.store(false);
//			//nodeLock.clear(std::memory_order_release);
//
//		}
//		std::this_thread::sleep_for(std::chrono::seconds(25));
//	}

 void node::manageNode()
 {
	 steady_clock::time_point start = steady_clock::now();
	 steady_clock::time_point end;
	 int prioritySt, numOfWaiters, timeWait, seconds, numCulculate;

	 while (true)
	 {
		 end = steady_clock::now();
		 duration<double> elapsed_seconds = end - start;
		 string overWait = overWaiting();

		 //שינוי העדיפות
		 priorityAxis pA;
		
		 int member;
		 int arrSize = sizeof(arrStIds) / sizeof(arrStIds[0]);

		 for (int i = 0; i<arrSize; i++)
		 {
			 if (!stNodes[arrStIds[i]].getListCars().empty())
			 {
				 stNodes[arrStIds[i]].deleteCarsTravel();
				 numOfWaiters = stNodes[arrStIds[i]].getListCars().size();
				 std::time_t waitingTime = std::chrono::system_clock::to_time_t(stNodes[arrStIds[i]].getListCars().front());
				 seconds = static_cast<int>(waitingTime);
				 numCulculate = seconds / 60;
				 //לקרוא מקובץ
				 prioritySt = numOfWaiters * (1 + numCulculate) * 5;
				 prioritySt = (numOfWaiters < 60) ? prioritySt : numOfWaiters;
				 prioritySt += this->getNodeSt()[arrStIds[i]].getPriority();
				 this->getNodeSt()[arrStIds[i]].setPriority(prioritySt);
				 this->getPqNode().replace(arrStIds[i], prioritySt);
				 if (stNodes[arrStIds[i]].getInAxis())
				 {
					 member = this->getIdNode();
					 pA.updateValue(arrStIds[i], member, prioritySt);
				 }



			 }

		 }


		 //בודק האם יש מישהו שמחכה מעבר לזמן
		 if (overWait != "")
		 {
			 int high_priority = this->getPqNode().top().getCount1() + 10;
			 this->pq_node.replace(overWait, high_priority);
			 std::chrono::seconds additional_seconds{ 30 }; // Add 5 seconds

			 end += additional_seconds;
			 cout << "over" << overWait << endl;
		 }
		 //רק פעם ב30 שניות להדליק את הרמזור
		 //לקרוא מקובץ
		 if (elapsed_seconds.count() >= 30)
		 {
			 if (this->getLightNow1() != "" && this->getLightNow2() != "") {
				 this->offTrrafic(this->getLightNow1());
				 this->offTrrafic(this->getLightNow2());
			 }
			 //עוצר 2 שניות לפני הדלקת הרמזורים
			 std::this_thread::sleep_for(std::chrono::seconds(2));

			 //הדלקת הרמזורים
			 if (!this->getPqNode().isEmpty())
			 {

				 std::string stTop1 = this->getPqNode().top().getName1();
				 std::string stTop2 = this->getPqNode().top().getName2();
				 std::ofstream outputFile("C:/Users/User/Desktop/lightNow.txt");
				 onTrrafic(stTop1);
				 onTrrafic(stTop2);
				 setLightNow1(stTop1);
				 setLightNow1(stTop2);
				 
			 }

			 //הדפסה לקובץ את נתוני הצומת הנוכחיים:
			 string idFile = to_string(this->getIdNode());
			 std::ofstream outputFile(idFile+"node.txt"); 
			 if (outputFile.is_open()) {
				 outputFile << "Hello, this is node"+ idFile+":" << std::endl;
				 int arrSize = sizeof(arrStIds) / sizeof(arrStIds[0]);

				 for (size_t i = 0; i <arrSize; i++)
				 {
					 outputFile << "st:" << this->getNodeSt()[this->arrStIds[i]].getId().c_str()<< endl;
					 outputFile << "num of cars:"<<this->getNodeSt()[this->arrStIds[i]].getListCars().size() <<endl;

					 outputFile << this->getNodeSt()[this->arrStIds[i]].print_waiting_time() << endl;
					 outputFile << "priority:" << this->getNodeSt()[this->arrStIds[i]].getPriority()<< endl;

				 }
				 outputFile << "the green is:" << this->getLightNow1() << "," << this->getLightNow2() << endl;
				 outputFile.flush();
				 outputFile.close();
				 std::cout << "Data of node"<<this->getIdNode()<< "written to the file." << std::endl;
			 }
			 else {
				 std::cout << "Error opening the file." << std::endl;
			 }


		 }


	 }
 
 }
 




