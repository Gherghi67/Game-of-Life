#ifndef AGENT4_H
#define AGENT4_H
#include "Agent.h"
#include "Map.h"
class Agent4 : public Agent {
private:
	int zigZag;
	bool ok = false;
public:
	Agent4(int i, int j);
	Agent4(const Agent4 &agent);
	void Move();
	char GetChar();
};
#endif