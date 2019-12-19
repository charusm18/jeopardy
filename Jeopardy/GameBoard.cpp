#include "GameBoard.h"
#include <iostream>
#include <fstream>
#include <sstream> 
using namespace std;

//initializes gameboard by ready questions and answers from the txt file
GameBoard::GameBoard() {
	ifstream in("questions.txt");
	if (in.is_open()) {
		string line;
		int points;
		string question;
		string answer;
		int count = 1;

		while (getline(in, line)) {
			//reads point value
			if (count % 3 == 1) {
				stringstream temp(line);
				temp >> points;
			}
			//reads question 
			else if (count % 3 == 2) {
				question = line;
			}
			//reads answer
			else if (count % 3 == 0){
				answer = line;
				shared_ptr<Question> q(new Question(points, question, answer));
				std::map<int, shared_ptr<Question>>::value_type nextRecord(points, q);
				mQuestions.insert(nextRecord);
			}
			count++;
		}	
	}
	//if file could not be opened
	else {
		cout << "File could not be opened" << endl;
	}
}

//prints the gameboard as a list of point values
void GameBoard::printBoard() {
	cout << "Here are the different questions" << endl;
	for (auto it = mQuestions.cbegin(); it != mQuestions.cend(); ++it) {
		std::cout << (*it).first << endl;
	}
}

//number of questions in gameboard
int GameBoard::questionSize() {
	return mQuestions.size();
}

//returns a question for the point value. Throws a char if there is no point value that existss
shared_ptr<Question> GameBoard::getQuestion(int point) {
	map<int, shared_ptr<Question>>::iterator it;
	for(it = mQuestions.begin(); it != mQuestions.end(); it++){
		if (point == it->first) {
			return mQuestions[point];
		}
	}
	throw 'a';
}

//removes a question after it has been chosen
void GameBoard::removeQuestion(int point) {
	mQuestions.erase(point);
}