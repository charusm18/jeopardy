#pragma once
#include <iostream>
using namespace std;

class Player {
public:
	//creates a player
	Player(string name, int score);
	//returns score as an int
	int getScore();
	//returns name as a string
	string getName();
	//updates the score
	void updateScore(int points, bool correct);
private:
	string mName;
	int mScore;


};
