#include "Game.h"
pair<int, int> Game::DecideWhereToSpawnGenerators() {
	srand(time(NULL));
	pair<int, int> coordinates;
	coordinates.first = rand() % (Map::GetHeight() - Generator::GetHeight() / 2) + Generator::GetHeight() / 2;
	coordinates.second = rand() % (Map::GetWidth() - Generator::GetWidth() / 2) + Generator::GetWidth() / 2;
	return coordinates;
}
bool Game::isOverlapping(pair<int, int> bottomLeft1, pair<int, int> topRight1, pair<int, int> bottomLeft2, pair<int, int> topRight2) {
	if (topRight1.second < bottomLeft2.second || bottomLeft1.second > topRight2.second) {
		return false;
	}
	if (topRight1.first < bottomLeft2.first || bottomLeft1.first > topRight2.first) {
		return false;
	}
	return true;
}
void Game::Start() {
	Map::InitialiseMap();
	step = 1;
	pair<int, int> coordinates = DecideWhereToSpawnGenerators();
	int x = coordinates.first;
	int y = coordinates.second;
	generatorY = new GeneratorY(x, y);
	Map::InitialiseGenerators(x, y, 'Y');
	pair<int, int> bottomLeft1;
	pair<int, int> topRight1;
	pair<int, int> bottomLeft2;
	pair<int, int> topRight2;
	bottomLeft1.first = x + Generator::GetHeight() / 2;
	bottomLeft1.second = y - Generator::GetWidth() / 2;
	topRight1.first = x - Generator::GetHeight() / 2;
	topRight1.second = y + Generator::GetWidth() / 2;
	bool ok = false;
	while (ok == false) {
		coordinates = DecideWhereToSpawnGenerators();
		bottomLeft2.first = coordinates.first + Generator::GetHeight() / 2;
		bottomLeft2.second = coordinates.second - Generator::GetWidth() / 2;
		topRight2.first = coordinates.first - Generator::GetHeight() / 2;
		topRight2.second = coordinates.second + Generator::GetWidth() / 2;
		if (!isOverlapping(bottomLeft1, topRight1, bottomLeft2, topRight2)) {
			ok = true;
		}
	}
	generatorU = new GeneratorU(coordinates.first, coordinates.second);
	Map::InitialiseGenerators(coordinates.first, coordinates.second, 'U');
	ok = false;
	pair<int, int> bottomLeft3;
	pair<int, int> topRight3;
	while (ok == false) {
		coordinates = DecideWhereToSpawnGenerators();
		bottomLeft3.first = coordinates.first + Generator::GetHeight() / 2;
		bottomLeft3.second = coordinates.second - Generator::GetWidth() / 2;
		topRight3.first = coordinates.first - Generator::GetHeight() / 2;
		topRight3.second = coordinates.second + Generator::GetWidth() / 2;
		if (!isOverlapping(bottomLeft1, topRight1, bottomLeft3, topRight3) && !isOverlapping(bottomLeft2, topRight2, bottomLeft3, topRight3)) {
			ok = true;
		}
	}
	generatorI = new GeneratorI(coordinates.first, coordinates.second);
	Map::InitialiseGenerators(coordinates.first, coordinates.second, 'I');
	Map::MapOutput();
}
void Game::AddAgent(Agent* agent) {
	Agents.push_back(agent);
}
bool Game::isPrime(int x) {
	for (int i = 2; i <= x / 2; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
bool Game::isMemberOfProgression(int x) {
	int i = 1;
	bool ok = false;
	while (ok == false) {
		if (2 + (i - 1) * 3 > x) {
			return ok;
		}
		if (2 + (i - 1) * 3 == x) {
			ok = true;
			return ok;
		}
		i++;
	}
}
void Game::Update() {
	if (step % 2 == 0) {
		generatorY->GenerateAgent();
	}
	if (isPrime(step)) {
		generatorU->GenerateAgent();
	}
	if (isMemberOfProgression(step)) {
		generatorI->GenerateAgent();
	}
	for (int i = 0; i < Agents.size(); i++) {
		if (Agents[i]->GetNumberOfRoundsStayingStill() == 4) {
			Map::DeleteAgents(Agents[i]->GetI(), Agents[i]->GetJ());
			Agents.erase(Agents.begin() + i);
			i--;
			continue;
		}
		Agents[i]->Move();
		if (Agents[i]->GetI() < 0 || Agents[i]->GetJ() < 0 || Agents[i]->GetI() > Map::GetHeight() || Agents[i]->GetJ() > Map::GetWidth()) {
			Agents.erase(Agents.begin() + i);
			i--;
			continue;
		}
		Map::UpdateAgentPositions(Agents[i]->GetI(), Agents[i]->GetJ(), Agents[i]->GetChar());
	}
	Map::MapOutput();
	step++;
}