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
	vector<node<int>> all_nodes = {};
	map < string, vector<tuple<int, int, int>>> axisInRoad;
	priorityAxis pqAxis;

public:
	std::vector<node<int>> getAllNodes() {
		return all_nodes;
	}
	void setAllNodes(std::vector<node<int>> newNodesVector) {
		all_nodes = newNodesVector;

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
				this->all_nodes[std::get<0>(tuple)].getNodeSt()[stId].setAxisId(item.first);
				this->all_nodes[std::get<1>(tuple)].getNodeSt()[stId].setAxisId(item.first);
				this->all_nodes[std::get<2>(tuple)].getNodeSt()[stId].setAxisId(item.first);

				members[std::get<0>(tuple)] = 0;
				members[std::get<1>(tuple)] = 0;
				members[std::get<2>(tuple)] = 0;


			}
			pqAxis.push(item.first, members);
			nA.setPqAxis(pqAxis);
		}

	}

	node<int> getNodeById(int nodeId)
	{
		for (auto& n : all_nodes)
		{
			if (n.getIdNode() == nodeId)
				return n;
		}
	}
};

