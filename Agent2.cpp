#include "Agent2.h"
Agent2::Agent2(int i, int j) : Agent(i, j) {

}
Agent2::Agent2(const Agent2 &agent) : Agent(agent) {

}
void Agent2::Move() {
	if (Map::isOccupied(i + 2, j)) {
		number_of_rounds_staying_still++;
		return;
	}
	i += 2;
	number_of_rounds_staying_still = 0;
}
char Agent2::GetChar() {
	return '2';
}