#include "Map.h"
const int Map::GetHeight() {
	return HEIGHT;
}
const int Map::GetWidth() {
	return WIDTH;
}
void Map::MapOutput() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			cout << _2DMap[i][j] << " ";
		}
		cout << "\n";
	}
}
void Map::InitialiseMap() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			_2DMap[i][j] = '0';
		}
	}
}
void Map::InitialiseGenerators(int x, int y, char c) {
	for (int i = y - Generator::GetWidth() / 2; i <= y + Generator::GetWidth() / 2; i++) {
		_2DMap[x - Generator::GetHeight() / 2][i] = c;
	}
	for (int i = x - Generator::GetHeight() / 2 + 1; i <= x + Generator::GetHeight() / 2; i++) {
		_2DMap[i][y + Generator::GetWidth() / 2] = c;
	}
	for (int i = y + Generator::GetWidth() / 2 - 1; i >= y - Generator::GetWidth() / 2; i--) {
		_2DMap[x + Generator::GetHeight() / 2][i] = c;
	}
	for (int i = x + Generator::GetHeight() / 2 - 1; i >= x - Generator::GetHeight() / 2 + 1; i--) {
		_2DMap[i][y - Generator::GetWidth() / 2] = c;
	}
}
void Map::UpdateAgentPositions(int x, int y, char c) {
	_2DMap[x][y] = c;
}
void Map::DeleteAgents(int x, int y) {
	if (_2DMap[x][y] != 'I' && _2DMap[x][y] != 'U' && _2DMap[x][y] != 'Y') {
		_2DMap[x][y] = '0';
	}
}
bool Map::isOccupied(int x, int y) {
	if (x < 0 || x > HEIGHT || y < 0 || y > WIDTH) {
		return false;
	}
	if (_2DMap[x][y] == '1' || _2DMap[x][y] == '2' || _2DMap[x][y] == '3' || _2DMap[x][y] == '4') {
		return true;
	}
	return false;
}