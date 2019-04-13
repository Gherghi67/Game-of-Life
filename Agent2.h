#ifndef AGENT2_H
#define AGENT2_H
#include "Agent.h"
#include "Map.h"
class Agent2 : public Agent {
public:
	Agent2(int i, int j);
	Agent2(const Agent2 &agent);
	void Move();
	char GetChar();
};
#endif