#ifndef AGENT3_H
#define AGENT3_H
#include "Agent.h"
#include "Map.h"
class Agent3 : public Agent {
private:
	int zigZag;
	bool ok = false;
public:
	Agent3(int i, int j);
	Agent3(const Agent3 &agent);
	void Move();
    char GetChar();
};
#endif