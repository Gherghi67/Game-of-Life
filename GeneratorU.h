#ifndef GENERATORU_H
#define GENERATORU_H
#include "Generator.h"
#include "Agent1.h"
#include "Agent2.h"
#include "Agent3.h"
#include "Agent4.h"
#include "Map.h"
#include "Game.h"
class GeneratorU : public Generator {
public:
	GeneratorU(int x, int y);
	void GenerateAgent();
};
#endif