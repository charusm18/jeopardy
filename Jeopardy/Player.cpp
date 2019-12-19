#include "Player.h"
using namespace std;

//constructs a player from a name and score
Player::Player(string name, int score) {
	mName = name;
	mScore = score;
}
//returns a players score
int Player::getScore() {
	return mScore;
}
//returns a player's name
string Player::getName() {
	return mName;
}
//updates a players score after they answer a question
void Player::updateScore(int points, bool correct) {
	if (correct) {
		mScore = mScore + points;
		cout << "You're answer was correct!! Your score is "<< mScore << endl;
	}
	else {
		mScore = mScore - points;
		cout << "You're answer was incorrect :(( Your score is " << mScore << endl;
	}
}
