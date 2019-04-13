#ifndef GAME_H
#define GAME_H
#include <vector>
#include "Agent.h"
#include "Agent1.h"
#include "Agent2.h"
#include "Agent3.h"
#include "Agent4.h"
#include "Map.h"
#include "Generator.h"
#include "GeneratorI.h"
#include "GeneratorU.h"
#include "GeneratorY.h"
#include "Generator.h"
#include <cstdlib>
#include <ctime>
#include <utility>
using namespace std;
class Game {
private:
	static vector<Agent*> Agents;
	static int step;
	static pair<int, int> DecideWhereToSpawnGenerators();
	static Generator* generatorY;
	static Generator* generatorU;
	static Generator* generatorI;
	static bool isOverlapping(pair<int, int> bottomLeft1, pair<int, int> topRight1, pair<int, int> bottomLeft2, pair<int, int> topRight2);
	static bool isPrime(int x);
	static bool isMemberOfProgression(int x);
public:
	static void Start();
	static void Update();
	static void AddAgent(Agent* agent);
};
#endif