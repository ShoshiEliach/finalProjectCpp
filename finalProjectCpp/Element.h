#pragma once
#include <string>
#include "string.h"
#include <iostream>
using namespace std;
class Element
{
private:
        int count1=0;
        int count2=0;
        int count_element=0;
        std::string name1="";
        std::string name2="";
        std::string name_element="";
public:
        Element();
        Element( std::string n1,  std::string n2, int c1, int c2) : count1(c1), count2(c2), count_element(c1 + c2), name1(n1), name2(n2), name_element(n1 + n2) {}

        //friend bool operator<(Event const& lhs, Event const& rhs)

        bool operator<(const Element& other) const {
            return count_element < other.count_element;
        } 


        //get
        int getCount1();
        int getCount2();
        int getCount_element();
        std::string getName1()const;
        std::string getName2();
        std::string getname_element();

        //set

        void setCount1(int c);
        void setCount2(int c);
        void setCount_element(int c);
        void setName1(std::string n);
        void setName2(std::string n);
        void setName_element(std::string n);
      
        
        
      
    
};

