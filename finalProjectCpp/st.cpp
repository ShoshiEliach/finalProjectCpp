#include "st.h"
#include "functions2.h"





//void st::intiliaizeNext(std::string s1,std::string s2)
//{
//	std::string id1;
//	std::string id2;
//	id1 = this->f.changeDieNumber(s1);
//	id2 = this->f.changeDieNumber(s2);
//	this->getNextSt1()->setId(id1);
//	this->getNextSt2()->setId(id2);
//
//}

std::string& st::getId()
{
	return id;
}



bool st::isRed()
{
	return red;
}

int st::getPriority()
{
	return priority;
}

int st::getWeight()
{
	return weight;
}

//st* st::getNextSt1()
//{
//	return next_st_right;
//}
//
//st* st::getNextSt2()
//{
//	return next_st_left;
//}

std::chrono::system_clock::time_point st::getStartLight()
{
	return startLight;
}

bool st::getInAxis()
{
	return inAxis;
}

vector<string> st::getRand_out()
{
	return this->rand_out;
}

int st::getId_node()
{
	return this->id_node;
}

string st::print_waiting_time()
{
	std::string output = "not waiters";
	if (!this->getListCars().empty()) {
		std::chrono::system_clock::time_point firstTimePoint = this->getListCars().front();
		std::time_t time = std::chrono::system_clock::to_time_t(firstTimePoint);
		std::tm* timeDetails = std::localtime(&time);
		int minutes = timeDetails->tm_min;
		int seconds = timeDetails->tm_sec;

		output = "time of waiting: " + std::to_string(minutes) + ":" + std::to_string(seconds);

	}
	return output;

}

string st::getAaxisId()
{
	return axisId;
}

void st::setAxisId(string axisId)
{
	axisId = axisId;
}

void st::setInAxis(bool in)
{
	inAxis = in;
	setInAxis(true);
}

void st::setRandOut(vector<string> rand_out)
{
	this->rand_out = rand_out;
}

void st::setStartLight(std::chrono::system_clock::time_point start)
{
	this->startLight = start;

}

void st::setId_node(int idn)
{
	this->id_node = idn;
}

void st::deleteCarsTravel()
{
	std::time_t current_time = std::time(nullptr);
	if (!cars_list.empty())
	{
		for (size_t i = 0; i < cars_list.size(); i++)
		{

			std::chrono::system_clock::time_point timeValueFirst = cars_list.front();
			double timeDifference = std::difftime(current_time, std::chrono::system_clock::to_time_t(timeValueFirst));
			//לקרוא מקובץ חיצוני
			if (timeDifference >= 4)
			{
				cars_list.pop_front();

			}

		}
	}
}

void st::addCar(std::chrono::system_clock::time_point new_car, int priority1)
{
	carsInSt cIs;
	
	this->cars_list.push_back(new_car);
	///לקרןא מקובץ חיצוני
	if (this->getId_node() == 5)
	{
		std::string id_st_for_car = std::string(1, this->getId()[0]);
		cIs.add_new_car(id_st_for_car);

	}
	this->setPriority(priority1);
	

}

std::list<std::chrono::system_clock::time_point> st::getListCars()
{
	return this->cars_list;
}


