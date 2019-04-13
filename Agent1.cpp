#include "Agent1.h"
Agent1::Agent1(int i, int j) : Agent(i, j) {

}
Agent1::Agent1(const Agent1 &agent) : Agent(agent) {

}
void Agent1::Move() {
	if (Map::isOccupied(i - 1, j)) {
		j++;
		return;
	}
	i--;
	number_of_rounds_staying_still = 0;
}
char Agent1::GetChar() {
	return '1';
}