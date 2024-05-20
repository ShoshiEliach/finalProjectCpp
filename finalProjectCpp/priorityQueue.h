#pragma once
#ifndef PRIORITYQ_H
#define PRIORITYQ_H

#include "string.h"
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
template <typename T>

class priorityQueue
{


public:
    struct Element
    {
        int count1;
        int count2;
        int count_element;
        std::string name1;
        std::string name2;
        std::string name_element;

        Element(int c1, int c2, const string& n1, const string& n2) : count1(c1), count2(c2), count_element(c1 + c2), name1(n1), name2(n2), name_element(n1 + n2) {}

        bool operator<(const Element& other) const {
            return count_element < other.count_element;
        }
    };


    void push(int c1, int c2, std::string& n1, std::string& n2);
    Element* pop();
    Element* top();
    void checkForDuplicates();

    void replace(string id, int p);
    pair<string, string> getTopStringIds();

private:
    priority_queue<Element> elementsPq;
};
#endif //PRIORITYQUEUE_H

