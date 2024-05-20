#pragma once
#include "string.h"
#include <string.h>
#include <string>
#include "functions.h"
#include <chrono>
#include <vector>
#include <list>
using namespace std;
class st
{
private:
    functions f;
    std::string id;
    std::list<std::chrono::system_clock::time_point> cars_list;

    bool red = true;
    std::chrono::system_clock::time_point startLight;
    int priority;
    int weight;

    string axisId;
    vector<string> rand_out;
    bool inAxis = false;
    /*st* next_st_right;
    st* next_st_straight;
    st* next_st_left;*/
public:
    st() :id(""), red(false), priority(0), weight(0) {}
    st(std::string id) : id(id), red(false), priority(0), weight(0) {}
    //void intiliaizeNext(std::string s1, std::string s2);
    //get
    std::string& getId();
    int getWeight();
    list<std::chrono::system_clock::time_point> getListCars();
    bool isRed();
    int getPriority();
    //st* getNextSt1();
    //st* getNextSt2();
    std::chrono::system_clock::time_point getStartLight();
    string getAaxisId();
    bool getInAxis();
    vector<string> getRand_out();



    // set
    void setId(std::string& newId) { id = newId; }
    void setCarsList(std::list<std::chrono::system_clock::time_point> newNumCars) { cars_list = newNumCars; }
    void setRed(bool isRed) { red = isRed; }
    void setPriority(int newPriority) { priority = newPriority; }
    //void setNextSt1(st* newNextSt1) { next_st_right = newNextSt1; }
    //void setNextSt2(st* newNextSt2) { next_st_straight = newNextSt2; }
    //void setNextSt3(st* newNextSt2) { next_st_left = newNextSt2; }
    void setWeight(int w) { weight = w; }
    void setAxisId(string axisId);
    void setInAxis(bool in);
    void setRandOut(vector<string> rand_out);
    void setStartLight(std::chrono::system_clock::time_point start);
    //other
    void deleteCarsTravel();
    void addCar(std::chrono::system_clock::time_point new_car, int priority);

};

