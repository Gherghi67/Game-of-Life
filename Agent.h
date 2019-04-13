#ifndef AGENT_H
#define AGENT_H
class Agent {
protected:
	int i;
	int j;
	int number_of_rounds_staying_still = 0;
public:
	Agent(int i, int j);
	Agent(const Agent &agent);
	virtual void Move() = 0;
	virtual char GetChar() = 0;
	int GetNumberOfRoundsStayingStill() const;
	void IncrementNumberOfRoundsStayingStill();
	void SetCoordinates(int i, int j);
	int GetI() const;
	int GetJ() const;
};
#endif