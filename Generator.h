#ifndef GENERATOR_H
#define GENERATOR_H
#include <cstdlib>
#include <ctime>
#include <iostream>
class Generator {
protected:
	static const int WIDTH = 20;
	static const int HEIGHT = 20;
	int x;
	int y;
	int DecideWhatTypeOfAgentToGenerate();
public:
	Generator(int x, int y);
	static const int GetWidth();
	static const int GetHeight();
	virtual void GenerateAgent() = 0;
};
#endif