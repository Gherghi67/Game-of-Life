#include "Agent3.h"
Agent3::Agent3(int i, int j) : Agent(i, j) {
	zigZag = i;
}
Agent3::Agent3(const Agent3 &agent) : Agent(agent) {
	zigZag = i;
}
void Agent3::Move() {
	if (ok == false) {
		if (Map::isOccupied(zigZag + 1, j)) {
			number_of_rounds_staying_still++;
			return;
		}
		i = zigZag + 1;
		ok = true;
	}
	else {
		if (Map::isOccupied(zigZag - 1, j)) {
			number_of_rounds_staying_still++;
			return;
		}
		i = zigZag - 1;
		ok = false;
	}
	j++;
	number_of_rounds_staying_still = 0;
}
char Agent3::GetChar() {
	return '3';
}