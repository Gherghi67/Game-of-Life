#include "Agent4.h"
Agent4::Agent4(int i, int j) : Agent(i, j) {
	zigZag = i;
}
Agent4::Agent4(const Agent4 &agent) : Agent(agent) {
	zigZag = i;
}
void Agent4::Move() {
	if (ok == false) {
		if (Map::isOccupied(zigZag - 1, j)) {
			i--;
			return;
		}
		i = zigZag - 1;
		ok = true;
	}
	else {
		if (Map::isOccupied(zigZag + 1, j)) {
			i--;
			return;
		}
		i = zigZag + 1;
		ok = false;
	}
	j--;
}
char Agent4::GetChar() {
	return '4';
}