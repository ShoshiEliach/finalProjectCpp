#pragma once
#include "string.h"
#include <string.h>
#include <string>
<<<<<<< HEAD
=======
#include <chrono>
#include <vector>
#include <list>
#include "carsInSt.h"
>>>>>>> 291b4d0c445a10d666ce58a2a6915f0dfd4d609a
using namespace std;
class st
{
private:
<<<<<<< HEAD
	std::string id;
	int num_cars;
	bool red;
	int priority;
	st* next_st_1;
	st* next_st_2;
public:	
=======
    std::string id;
    std::list<std::chrono::system_clock::time_point> cars_list;

    bool red = true;
    std::chrono::system_clock::time_point startLight;
    int priority;
    int weight;

    string axisId;
    vector<string> rand_out;
    bool inAxis = false;
    int id_node;
    /*st* next_st_right;
    st* next_st_straight;
    st* next_st_left;*/
public:
    st() :id(""), red(false), priority(0), weight(0) {}
    st(std::string id) : id(id), red(false), priority(0), weight(0) {}
    //void intiliaizeNext(std::string s1, std::string s2);
>>>>>>> 291b4d0c445a10d666ce58a2a6915f0dfd4d609a
    //get
    std::string& getId();
    int getNumCars();
    bool isRed();
    int getPriority();
<<<<<<< HEAD
    st* getNextSt1();
    st* getNextSt2();
=======
    //st* getNextSt1();
    //st* getNextSt2();
    std::chrono::system_clock::time_point getStartLight();
    string getAaxisId();
    bool getInAxis();
    vector<string> getRand_out();
    int getId_node();
    string print_waiting_time();
>>>>>>> 291b4d0c445a10d666ce58a2a6915f0dfd4d609a

    // set
    void setId(std::string& newId) { id = newId; }
    void setNumCars(int newNumCars) { num_cars = newNumCars; }
    void setRed(bool isRed) { red = isRed; }
<<<<<<< HEAD
    void setPriority(int newPriority) { priority = newPriority; }
    void setNextSt1(st* newNextSt1) { next_st_1 = newNextSt1; }
    void setNextSt2(st* newNextSt2) { next_st_2 = newNextSt2; }
=======
    void setPriority(int newPriority) { priority += newPriority; }
    //void setNextSt1(st* newNextSt1) { next_st_right = newNextSt1; }
    //void setNextSt2(st* newNextSt2) { next_st_straight = newNextSt2; }
    //void setNextSt3(st* newNextSt2) { next_st_left = newNextSt2; }
    void setWeight(int w) { weight = w; }
    void setAxisId(string axisId);
    void setInAxis(bool in);
    void setRandOut(vector<string> rand_out);
    void setStartLight(std::chrono::system_clock::time_point start);
    void setId_node(int idn);
    //other
    void deleteCarsTravel();
    void addCar(std::chrono::system_clock::time_point new_car, int priority);
>>>>>>> 291b4d0c445a10d666ce58a2a6915f0dfd4d609a

};

