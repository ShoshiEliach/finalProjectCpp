#pragma once
#include "string.h"
#include <string.h>
#include <string>
using namespace std;
class st
{
private:
	std::string id;
	int num_cars;
	bool red;
	int priority;
	st* next_st_1;
	st* next_st_2;
public:	
    //get
    std::string& getId();
    int getNumCars();
    bool isRed();
    int getPriority();
    st* getNextSt1();
    st* getNextSt2();

    // set
    void setId(std::string& newId) { id = newId; }
    void setNumCars(int newNumCars) { num_cars = newNumCars; }
    void setRed(bool isRed) { red = isRed; }
    void setPriority(int newPriority) { priority = newPriority; }
    void setNextSt1(st* newNextSt1) { next_st_1 = newNextSt1; }
    void setNextSt2(st* newNextSt2) { next_st_2 = newNextSt2; }

};

