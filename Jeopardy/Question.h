#pragma once
#include <iostream>
#include <string>
using namespace std;

class Question {
public:
	//creates a question
	class Question(int point, string question, string answer) {
		mPointValue = point; 
		mQuestion = question;
		mAnswer = answer;
	};
	//returns a question
	string getQuestion(){ return mQuestion; }
	//returns a quesion's answer
	string getAnswer() { return mAnswer; }
	//returns a point value of a question
	int getPoints() { return mPointValue; }

private:
	int mPointValue;
	string mQuestion;
	string mAnswer;
};
