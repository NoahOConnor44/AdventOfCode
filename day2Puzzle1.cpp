#include <fstream>
#include <iostream>
using namespace std;

/*
Elfs are playing tic tac toe. They gave you a cheat sheet of what the opponent will play
and what you should play in response. Some plays are purposefly lost or draws to avoid suspicion. 

Calculate the total score you would have if you followed their move set.

Opponent - Col 1: A(Rock), B(Paper), C(Scissors)
Correct  - Col 2: X(Rock), Y(Paper), Z(Scissors)

Round score:
  Choice: 1(Rock), 2(Paper), 3(Scissors)
  Outcome 0(Lose), 3(Draw), 6(Win)
*/

int calcRoundScore(char opp, char str);

int calcPlayResult(char opp, char str);

int main() {
  ifstream fin;

  char oppChoice;
  char corrChoice;

  fin.open("input2.txt");

  int scoreTotal = 0;

  while(fin >> oppChoice >> corrChoice)
  {
    scoreTotal += calcRoundScore(oppChoice, corrChoice);
  }

  cout << scoreTotal << endl;
  return 0;
}

int calcRoundScore(char opp, char str) {
  int roundScore = 0;

  // Rock
  if (str == 'X') {
    roundScore += 1;
  } else if (str == 'Y') {
    roundScore += 2;
  } else {
    roundScore += 3;
  }
  roundScore += calcPlayResult(opp, str);

  return roundScore;
}

int calcPlayResult(char opp, char str) {
  // use ascii values to make simpler comparisons
  int userSelection = int(str % 88);

  // convert X,Y,Z ==> A,B,C
  char strat = char(65 + userSelection);

  // assume we lose, update as necessary
  int score = 0;

  // Draw
  if (opp == strat)
    score = 3;

  // Check for a winning result
  else {
    if ((opp == 'A' && strat == 'B')) {
      score = 6;
    } else if ((opp == 'B' && strat == 'C')) {
      score = 6;
    } else if ((opp == 'C' && strat == 'A')) {
      score = 6;
    }
  }

  return score;
}
