#include "st.h"

std::string& st::getId()
{
	return id;
}

int st::getNumCars()
{
	return num_cars;
}

bool st::isRed()
{
	return red;
}

int st::getPriority()
{
	return priority;
}

st* st::getNextSt1()
{
	return next_st_1;
}

st* st::getNextSt2()
{
	return next_st_2;
}
