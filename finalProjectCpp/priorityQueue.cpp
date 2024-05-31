#include "priorityQueue.h"
#include <stdexcept>
#include "Element.h"
#include <string>
#include "string.h"
//push
using namespace std;

void priorityQueue::push(Element& e)
{
    Element newElement(e);
    this->elementsPq.push(newElement);
}

//pop
 Element* priorityQueue::pop()
{
    if (!elementsPq.empty())
    {
        Element topElement = elementsPq.top();

        elementsPq.pop();
        return &topElement;
    }
    else
    {
        return nullptr;
    }
}


pair<std::string, std::string> priorityQueue::getTopStringIds()
{
    std::pair<std::string, std::string> returnPair;
    if (!elementsPq.empty()) {
        Element topElement = elementsPq.top(); 
        std::string name1 = topElement.getName1();
        std::string name2 = topElement.getName2();// ���� ����� ���� ����
         returnPair= std::make_pair(name1, name2);
    }
    return returnPair;
}

//replace
void priorityQueue::replace(string id, int p)
{

    priority_queue<Element> tempQueue;
    while (!elementsPq.empty())
    {
        Element current = elementsPq.top();
        elementsPq.pop();
        if (current.getName1() == id)
                current.setCount1(p);
        if (current.getName2() == id)
             current.setCount2(p);
            
        current.setCount_element(current.getCount1() + current.getCount2());
        tempQueue.push(current);
    }
    elementsPq= tempQueue;

}




//top
 Element priorityQueue::top()
{
     Element topElement;

    if (!elementsPq.empty())
    {
         topElement = elementsPq.top();

       
    }
    return topElement;
  /*  else {
        return nullptr;
    }*/

    //template<typename T>
    //bool priorityQueue<T>::checkForDuplicates()
    //{
    //   
    //}
}

void priorityQueue::checkForDuplicates()
{
    std::vector<Element> elementsCopy; // ����� ���� �� �� �������
    while (!elementsPq.empty())
    {
        Element currentElement = elementsPq.top(); // ������ �� ����� ���� ����
        elementsPq.pop();
    }
}

priority_queue<Element> priorityQueue::getPq()
{
    return elementsPq;
}

void priorityQueue::setPq(priority_queue<Element> new_pq)
{
    elementsPq = new_pq;
}


