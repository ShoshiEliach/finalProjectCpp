#include "priorityQueue.h"
#include <stdexcept>

//push


template<typename T>
void priorityQueue<T>::push(int c1, int c2, std::string& n1, std::string& n2)
{
    Element newElement(c1, c2, n1, n2);
    this->elementsPq.push(newElement);
}

//pop
template<typename T>
typename priorityQueue<T>::Element* priorityQueue<T>::pop()
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


template <typename T>
pair<string, string> priorityQueue<T>::getTopStringIds()
{
    if (!elementsPq.empty()) {
        Element topElement = elementsPq.top(); // ���� ����� ���� ����
        return make_pair(topElement.name1, topElement.name2); // ����� �� ��� ����� �string id
    }
    return make_pair("", "");
}

//replace
template <typename T>
void priorityQueue<T>::replace(string id, int priority)
{

    priorityQueue<Element> tempQueue;
    while (!elementsPq.empty())
    {
        Element current = elementsPq.top();
        elementsPq.pop();

        if (current.name1 == id)
        {
            current.count1 = priority;
        }
        if (current.name2 == id)
        {
            current = priority;
        }
        tempQueue.push(current);


    }

    elementsPq = tempQueue;

}




//top
template <typename T>
typename priorityQueue<T>::Element* priorityQueue<T>::top()
{

    if (!elementsPq.empty())
    {
        Element topElement = elementsPq.top();

        return &topElement;
    }
    else {
        return nullptr;
    }

    //template<typename T>
    //bool priorityQueue<T>::checkForDuplicates()
    //{
    //   
    //}
}

template<typename T>
void priorityQueue<T>::checkForDuplicates()
{
    std::vector<Element> elementsCopy; // ����� ���� �� �� �������
    while (!elementsPq.empty())
    {
        Element* currentElement = elementsPq.top(); // ������ �� ����� ���� ����
        elementsPq.pop();
    }
}
