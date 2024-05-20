#include "st.h"
#include "functions.h"




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

void st::deleteCarsTravel()
{
	std::time_t current_time = std::time(nullptr);
	if (!cars_list.empty())
	{
		for (size_t i = 0; i < cars_list.size(); i++)
		{

			std::chrono::system_clock::time_point timeValueFirst = cars_list.front();
			double timeDifference = std::difftime(current_time, std::chrono::system_clock::to_time_t(timeValueFirst));
			if (timeDifference >= 4)
			{
				cars_list.pop_front();

			}

		}
	}
}

void st::addCar(std::chrono::system_clock::time_point new_car, int priority1)
{
	this->cars_list.push_back(new_car);
	this->setPriority(priority1);

}

std::list<std::chrono::system_clock::time_point> st::getListCars()
{
	return this->cars_list;
}


