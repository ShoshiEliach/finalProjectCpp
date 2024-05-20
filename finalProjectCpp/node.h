#pragma once
#ifndef NEWCLASS_H
#define NEWCLASS_H
#include <string>
#include "string.h"
#include "priorityQueue.h"
#include "st.h"
#include <list>
#include <map>
#include <unordered_map>
#include <utility>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include "nodeInAxis.h"
#include "priorityQueue.h"
#include "libxl."


using namespace std;


class node
{
private:

    int id_node;
    priorityQueue<Element> pqObject;    
    std::map<std::string, st> stNodes;
    //st** node_st=new st*[8];
    string lightNow1;
    string lightNow2;
    string arrStIds[12] = { "A1","A2","A3","B1","B2","B3","C1","C2","C3","D1","D2","D3" };
    struct NodeMint {
        node* next;
        int edge;
        vector<string> all_options_toOut;
        NodeMint(node* n1, int e) {
            next = new node(n1->id_node);
            edge = e;


        }
    };
    list<NodeMint> nextNodes;
    functions f;

public:

    node() : id_node(0) {}
    node(int id);
    void initialize_st();


    void pushPq(std::string st1, std::string st2, int n1, int n2);
    int getIdNode()
    {
        return id_node;
    }

    void setIdNode(const std::string& id) {
        id_node = id;
    }

    // Getter and Setter for pq_node
    priorityQueue<T>* getPqNode() {
        return pq_node;
    }

    void setPqNode(priorityQueue<typename priorityQueue<T>::Element>* pq) {
        pq_node = *pq;
    }

    // Getter and Setter for node_st
    std::map<std::string, st> getNodeSt() {
        return stNodes;
    }

    void setNodeSt(std::map<std::string, st> stMap) {
        stNodes = stMap;
    }

    // Getter and Setter for next_nodes
    list<NodeMint> getNextNodes() {
        return nextNodes;
    }

    void setNextNodes(const std::list<NodeMint> nodes) {

        this->nextNodes = nodes;
    }


    string& getStOut(NodeMint& nodeMint) {
        return nodeMint.stOut;
    }

    string& getNoxtNodeNextSt(NodeMint& nodeMint) {
        return nodeMint.stNextIn;
    }
    // Setter function to modify stOut member
    void setStOut(NodeMint& nodeMint, const std::string& newValue) {
        nodeMint.stOut = newValue;
    }



    //other
    void AddNextNode(node* next, int e)
    {
        NodeMint n(next, e);
        nextSt(next->getIdNode(), n);


        nextNodes.push_back(n);
    }
    std::vector<std::pair<int, std::chrono::system_clock::time_point>> getTimePointsAndIdsForFirstCar();
    bool compareTimePoints(const std::pair<int, std::chrono::system_clock::time_point>& pair1, const std::pair<int, std::chrono::system_clock::time_point>& pair2);
    void sortTimeListByElapsedTime(std::vector<std::pair<int, std::chrono::system_clock::time_point>>& timePairList);

    //VVV
    void updatePriority();
    void transferToNext(string id_st_green);






   // void addPrioritySt(string stId);




    //כאן להפעיל את גל ירוק וטרנספר וגם לעדכן עדיפות
    void onTrrafic(string idSt);



    void offTrrafic(string idSt);





    void trraficLogicInNode();
    static void overWaiting();
    void nextSt(int idNextNode, NodeMint n);

};
#endif 
