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
//#include "libxl.h"
#include "Element.h"
#include <queue>
#include <shared_mutex>
#include <memory>
#include <fstream>
#include "priorityAxis.h"

using namespace std;
using namespace std::chrono;

 std::shared_ptr<std::mutex> nodeMutexPtr;


class node
{
private:

    int id_node;
    priorityQueue pq_node; 
    std::priority_queue<Element, std::vector<Element>, std::less<Element>> pq;

    //priority_queue<Element> pq;
    std::map<std::string, st> stNodes;
    //st** node_st=new st*[8];
    string lightNow1;
    string lightNow2;
    string arrStIds[12] = { "A1","A2","A3","B1","B2","B3","C1","C2","C3","D1","D2","D3" };
    struct NodeMint {
        node* next=nullptr;
        int edge;
        vector<string> all_options_toOut;
        NodeMint(node* n1, int e) {
            next = new node(n1->id_node);
            edge = e;


        }
    };
    list<NodeMint> nextNodes;
    std::shared_ptr<std::mutex> nodeMutexPtr;
    std::shared_mutex nodeMutex;
    std::atomic<bool> nodeLock{ false };
    std::atomic_flag nodeLock = ATOMIC_FLAG_INIT;

public:

    node() : id_node(0),nodeMutexPtr(std::make_shared<std::mutex>()){}
    
   node(const node & other) :id_node(other.id_node), pq_node(other.pq_node), stNodes(other.stNodes), lightNow1(other.lightNow1), lightNow2(other.lightNow2), nextNodes(other.nextNodes){}
    node(int id);
    node& operator=(const node& other);


    void initialize_st();
    void initislize_pq();

    void pushPq(std::string st1, std::string st2, int n1, int n2);
    int getIdNode()
    {
        return this->id_node;
    }
    
    void setIdNode( int id) {
        id_node = id;
    } 

    std::string getLightNow1() {
        return this->lightNow1;
    }
    std::string getLightNow2() {
        return this->lightNow2;
    }

    void setLightNow1(std::string ln1)
    {
        this->lightNow1 = ln1;
    } 
    void setLightNow2(std::string ln2)
    {
        this->lightNow2 = ln2;
    }
    // Getter and Setter for pq_node
    priorityQueue getPqNode() {
        return this->pq_node;
    }

    void setPqNode(priorityQueue pq)
    {
        this->pq_node = pq;
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


    void AddNextNode(node* next, int e)
    {
        NodeMint n(next, e);
        nextSt(next->getIdNode(), n);


        nextNodes.push_back(n);
    }
    std::vector<std::pair<std::string, std::chrono::system_clock::time_point>> getTimePointsAndIdsForFirstCar();
    bool compareTimePoints(const std::pair<int, std::chrono::system_clock::time_point>& pair1, const std::pair<int, std::chrono::system_clock::time_point>& pair2);
    void sortTimeListByElapsedTime(std::vector<std::pair<std::string, std::chrono::system_clock::time_point>>& timePairList);

   
    void updatePriority();
    void transferToNext(string id_st_green);










    void onTrrafic(string idSt);



    void offTrrafic(string idSt);




    void manageNode();
    void trraficLogicInNode();
    std::string overWaiting();
    void nextSt(int idNextNode, NodeMint n);

};
#endif 
