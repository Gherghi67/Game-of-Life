#include "Generator.h"
Generator::Generator(int x, int y) {
	this->x = x;
	this->y = y;
}
const int Generator::GetWidth() {
	return WIDTH;
}
const int Generator::GetHeight() {
	return HEIGHT;
}
int Generator::DecideWhatTypeOfAgentToGenerate() {
	srand(time(NULL));
	int number = rand() % 4 + 1;
	return number;
}