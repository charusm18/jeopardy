#pragma once
#include <iostream>
#include <map>
#include "Question.h"
using namespace std;

class GameBoard {
public: 
	//creates a gameboard
	class GameBoard();
	//prints the point value of the gameboard
	void printBoard();
	//an int of the number of questions in the board
	int questionSize();
	//returns a question from the board of point value [point]
	shared_ptr<Question> getQuestion(int point);
	//removes a question from the board
	void removeQuestion(int point);
private: 
	map <int, shared_ptr<Question>> mQuestions;
};
