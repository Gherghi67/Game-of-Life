#include "Agent.h"
Agent::Agent(int i, int j) {
	this->i = i;
	this->j = j;
}
Agent::Agent(const Agent &agent) {
	i = agent.i;
	j = agent.j;
}
int Agent::GetNumberOfRoundsStayingStill() const {
	return number_of_rounds_staying_still;
}
void Agent::IncrementNumberOfRoundsStayingStill() {
	number_of_rounds_staying_still++;
}
void Agent::SetCoordinates(int i, int j) {
	this->i = i;
	this->j = j;
}
int Agent::GetI() const {
	return i;
}
int Agent::GetJ() const {
	return j;
}