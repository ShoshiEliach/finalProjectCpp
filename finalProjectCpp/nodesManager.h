#pragma once
#include "node.h"
#include <vector>
#include <map>
#include<tuple>
#include<iostream>
#include <string>
#include "priorityAxis.h"
#include "nodeInAxis.h"
#define SET_ST(difference) stId = (difference == 1 ? "A2" : \
                             (difference > 1 ? "B2" : \
                             (difference == -1 ? "C2" : \
                             "D2")))

using namespace std;
class nodesManager
{
private:
<<<<<<< HEAD
	vector<node> all_nodes = {};
=======
	std::vector<node> initialNodes;
	std::vector<node>* all_nodes = &initialNodes;
>>>>>>> 291b4d0c445a10d666ce58a2a6915f0dfd4d609a
	map < string, vector<tuple<int, int, int>>> axisInRoad;
	priorityAxis pqAxis;

public:
<<<<<<< HEAD
	std::vector<node> getAllNodes() {
		return all_nodes;
	}
	void setAllNodes(std::vector<node> newNodesVector) {
		all_nodes = newNodesVector;
=======
	std::vector<node>* getAllNodes() {
		return all_nodes;
	}
	void setAllNodes(std::vector<node> newNodesVector) {
		initialNodes.clear();
		for (auto& x : newNodesVector)
		{
			initialNodes.push_back(x);

		}
>>>>>>> 291b4d0c445a10d666ce58a2a6915f0dfd4d609a

	}

	map < string, vector<tuple<int, int, int>>> getAxisInRoad() {
		return axisInRoad;
	}

	void setAxisInRoad(string first, vector<tuple<int, int, int>> value)
	{
		this->axisInRoad[first] = value;
	}

	priorityAxis getAxisPriority() {
		return pqAxis;
	}

	void setAxisPriority(priorityAxis pq) {
		pqAxis = pq;
	}
	//להגדיר לכל צומת בגרף על כל נתיב שלה לאיזה ציר הוא שייך
	void definitionAxisForNode()
	{
		nodeInAxis nA;
		int difference;
		string stId;
		map<int, int> members;
		for (const auto& item : this->axisInRoad)
		{
			for (const auto& tuple : item.second)
			{
				difference = std::get<1>(tuple) - std::get<0>(tuple);
				SET_ST(difference);
				(*all_nodes)[std::get<0>(tuple)].getNodeSt()[stId].setAxisId(item.first);
				(*all_nodes)[std::get<1>(tuple)].getNodeSt()[stId].setAxisId(item.first);
				(*all_nodes)[std::get<2>(tuple)].getNodeSt()[stId].setAxisId(item.first);

				/*this->all_nodes[std::get<0>(tuple)].getNodeSt()[stId].setAxisId(item.first);
				this->all_nodes[std::get<1>(tuple)].getNodeSt()[stId].setAxisId(item.first);
				this->all_nodes[std::get<2>(tuple)].getNodeSt()[stId].setAxisId(item.first);*/

				members[std::get<0>(tuple)] = 0;
				members[std::get<1>(tuple)] = 0;
				members[std::get<2>(tuple)] = 0;


			}
			pqAxis.push(item.first, members);
			nA.setPqAxis(pqAxis);
		}

	}

	node* getNodeById(int nodeId)
	{
		for (auto& n : *all_nodes)
		{
			if (n.getIdNode() == nodeId)
				return &n;
			return nullptr;
		}
	}

	
};

