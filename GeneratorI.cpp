#include "GeneratorI.h"
GeneratorI::GeneratorI(int x, int y) : Generator(x, y) {

}
void GeneratorI::GenerateAgent() {
	int number = DecideWhatTypeOfAgentToGenerate();
	if (number == 1) {
		Agent* agent = new Agent1(x - HEIGHT / 2 - 1, y);
		Map::UpdateAgentPositions(x - HEIGHT / 2 - 1, y, '1');
		Game::AddAgent(agent);
	}
	else if (number == 2) {
		Agent* agent = new Agent2(x + HEIGHT / 2 + 1, y);
		Map::UpdateAgentPositions(x + HEIGHT / 2 + 1, y, '2');
		Game::AddAgent(agent);
	}
	else if (number == 3) {
		Agent* agent = new Agent3(x, y + WIDTH / 2 + 1);
		Map::UpdateAgentPositions(x, y + WIDTH / 2 + 1, '3');
		Game::AddAgent(agent);
	}
	else if (number == 4) {
		Agent* agent = new Agent4(x, y - WIDTH / 2 - 1);
		Map::UpdateAgentPositions(x, y - WIDTH / 2 - 1, '4');
		Game::AddAgent(agent);
	}
}