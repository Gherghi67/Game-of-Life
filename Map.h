#ifndef MAP_H
#define MAP_H
#include <iostream>
#include "GeneratorY.h"
#include "GeneratorI.h"
#include "GeneratorU.h"
using namespace std;
class Map {
private:
	static const int WIDTH = 80;
	static const int HEIGHT = 80;
	static char _2DMap[HEIGHT][WIDTH];
public:
	static const int GetWidth();
	static const int GetHeight();
	static void MapOutput();
	static void InitialiseMap();
	static void InitialiseGenerators(int x, int y, char c);
	static void UpdateAgentPositions(int x, int y, char c);
	static void DeleteAgents(int x, int y);
	static bool isOccupied(int x, int y);
};
#endif