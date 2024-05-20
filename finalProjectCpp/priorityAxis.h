#pragma once
#include <iostream>
#include <queue>
#include <map>
class priorityAxis
{
private:
    struct ElementAxis {
        std::string id;
        std::map<int, int> members;
        int priority;

        bool operator<(const ElementAxis& other) const {
            return priority < other.priority;
        }
    };

    std::priority_queue<ElementAxis> pq;


public:
    void push(const std::string& id, const std::map<int, int>& members);
    void pop();
    ElementAxis top();
    void updateValue(const std::string& id, int& member, int newValue);


    bool checkTopId(const std::string& id);

};








//דוגמא לזימון

//int main() {
//    CustomPriorityQueue pq;
//
//    // Push elements into the priority queue
//    std::map<std::string, int> members1 = { {"A", 3}, {"B", 5} };
//    pq.push("ID1", members1);
//
//    std::map<std::string, int> members2 = { {"C", 2}, {"D", 4} };
//    pq.push("ID2", members2);
//
//    // Update value within the priority queue