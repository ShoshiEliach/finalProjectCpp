#pragma once
#ifndef PRIORITYQ_H
#define PRIORITYQ_H

#include "string.h"
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include "Element.h"
using namespace std;
//template <class T>
class priorityQueue
{
private:
    priority_queue<Element> elementsPq;

public:
    priorityQueue(){}
    //Car(const Car& other) : brand(other.brand), model(other.model), year(other.year) {}
    priorityQueue(const priorityQueue& other):elementsPq(other.elementsPq){}
    void push(Element& e);
    Element* pop();
    Element top();
    void checkForDuplicates();
    priority_queue<Element> getPq();
    void setPq(priority_queue<Element> new_pq);

    void replace(string id, int p);
    pair<std::string, std::string> getTopStringIds();
    bool isEmpty() {
        return elementsPq.empty();
    }
};
#endif //PRIORITYQUEUE_H

