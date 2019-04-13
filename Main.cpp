#include <iostream>
#include <process.h>
#include "Game.h"
using namespace std;
int main() {
	Game::Start();
	int i = 1;
	char c = 'f';
	while (c == 'f') {
		cout << "Pasul " << i << "\n";
		Game::Update();
		i++;
		cin >> c;
	}
	system("pause");
	return 0;
}