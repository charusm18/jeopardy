/*Charu Murugesan
Finished 12.19.2019
Jeopardy game reads a txt file of questions and mimics a jeopardy game. 
Precondition: Number of questions should be a multiple of the number of players.
(i.e. if there are 3 players there can be 3 questions, 6 questions, 9, 12, ...)
No two questions can have the same point value.

*/
#include "GameBoard.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <functional>
#include <fstream>
#include <iterator>
#include <map>

using namespace std;

int main() {
	cout << "HOW TO PLAY :" << endl <<
		"1. Enter number of players and their names when prompted." << endl <<
		"2. Choose a question.The question number is the point value" << endl <<
		"3. Enter the answer.If it is correct, the number of points will" << endl <<
		"be added to your score.If it is incorrect it will be subtracted" << endl <<
		"4. After all the questions are done, the scores will be listed and" << endl <<
		"a winner will be determined." << endl;

	int numberOfPlayers;

	//map storing all the players
	map<string, shared_ptr<Player>> players;
	cout << "How many players are there (max 4 players)? " << endl;
	cin >> numberOfPlayers; 

	for (int i = 1; i <= numberOfPlayers; i++) {
		string name;
		cout << "Player " << i << ", what is your name?" << endl;
		cin >> name;
		shared_ptr<Player> pl(new Player(name, 0));
		players.insert({name, pl}) ;
	}
	//new gameboard
	shared_ptr<GameBoard> gb(new GameBoard());

	//while there are questions in the gameboard (i.e. the txt file)
	while (gb->questionSize() > 0) {

		//iterator keeps track of which players turn it is
		map<string, shared_ptr<Player>>::iterator currentPlayer;
		for(currentPlayer = players.begin(); currentPlayer != players.end(); currentPlayer ++) {
			int chosenQ;
			string playerAnswer;
			int temp = 0;
			shared_ptr<Question> q;

			//catches errors if an chosen question is out of bounds
			while (temp == 0) {
				try {
					gb->printBoard();
					cout << (*currentPlayer).first << ", which question would you like to choose?" << endl;
					cin >> chosenQ;
					q = gb->getQuestion(chosenQ);
					temp = 1;
				}
				catch (char)
				{
					cout << "This is not a valid input." << endl;
				}
			}

			//checks if player answer is correct
			cout << q->getQuestion();
			cin >> playerAnswer;
			if (playerAnswer == (q->getAnswer())) {
				(*currentPlayer).second->updateScore(chosenQ, true);
			}
			else {
				(*currentPlayer).second->updateScore(chosenQ, false);
				cout << "The correct answer is " << q->getAnswer() << endl;
			}

			//removes the question from the board
			gb->removeQuestion(chosenQ);
		}
	}

	//determines winner and prints the final score
	cout << "Here are the final scores! " << endl;
	map<string, shared_ptr<Player>>::iterator currentPlayer;
	shared_ptr<Player> winner((*players.begin()).second);
	for (currentPlayer = players.begin(); currentPlayer != players.end(); currentPlayer++) {
		if (winner->getScore() < (*currentPlayer).second->getScore()) {
			winner = (*currentPlayer).second;
		}
		cout << (*currentPlayer).first << ": " << (*currentPlayer).second ->getScore() << " points" << endl;
	} 
	cout << "The winner is " << winner ->getName() << endl;
	

}