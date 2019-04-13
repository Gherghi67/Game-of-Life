#ifndef AGENT1_H 
#define AGENT1_H
#include "Agent.h"
#include "Map.h"
class Agent1 : public Agent {
public:
	Agent1(int i, int j);
	Agent1(const Agent1 &agent);
	void Move();
	char GetChar();
};
#endif