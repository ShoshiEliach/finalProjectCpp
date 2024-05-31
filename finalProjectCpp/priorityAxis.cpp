#include "priorityAxis.h"

void priorityAxis::push(const std::string& id, const std::map<int, int>& members)
{
    int priority = 0;
    for (const auto& pair : members) {
        priority += pair.second;
    }
    this->pq.push({ id, members, priority });
}

void priorityAxis::pop()
{
    if (!pq.empty()) {
        pq.pop();
    }

}

priorityAxis::ElementAxis priorityAxis::top()
{
    return pq.top();
}

void priorityAxis::updateValue(const std::string& id, int member, int newValue)
{
    std::priority_queue<ElementAxis> tempQueue;
    while (!pq.empty()) {
        ElementAxis elem = pq.top();
        pq.pop();
        if (elem.id == id && elem.members.find(member) != elem.members.end()) {
            elem.members[member] = newValue;
            elem.priority = 0;
            for (const auto& pair : elem.members) {
                elem.priority += pair.second;
            }
        }
        tempQueue.push(elem);
    }
    pq = tempQueue;
}

bool priorityAxis::checkTopId(const std::string& id)
{

    if (!pq.empty()) {
        priorityAxis::ElementAxis topElement = pq.top();
        return topElement.id == id;

    }
    return false;
}

