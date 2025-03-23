#pragma once
#include "priorityAxis.h"
class nodeInAxis
{
private:
	priorityAxis pqAxis;


public:
	priorityAxis getPqAxis() {
		return pqAxis;

	}

	void setPqAxis(priorityAxis pq) {
		this->pqAxis = pq;
	}
};

