#ifndef GENERATORI_H
#define GENERATORI_H
#include "Generator.h"
#include "Agent1.h"
#include "Agent2.h"
#include "Agent3.h"
#include "Agent4.h"
#include "Map.h"
#include "Game.h"
class GeneratorI : public Generator {
public:
	GeneratorI(int x, int y);
	void GenerateAgent();
};
#endif