#include <fstream>
#include <iostream>
using namespace std;

/*
Opponent - Col 1: A(Rock), B(Paper), C(Scissors)
Round End  Col 2: X(Lose), Y(Draw), Z(Win)

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
  char strat;

  // If str == X need to end the round with a loss
  if(str == 'X') {
    if (opp == 'A') {
      strat = 'C';
    } else if (opp == 'B') {
      strat = 'A';
    } else if (opp == 'C') {
      strat = 'B';
    }
  }
  // If str == Y need to end the round with a draw
  else if(str == 'Y') {
    strat = opp;
  }
  // If str == Z need to end the round with a win
  else {
    if (opp == 'A') {
      strat = 'B';
    } else if (opp == 'B') {
      strat = 'C';
    } else if (opp == 'C') {
      strat = 'A';
    }
  }

  if(strat == 'A') {
    roundScore += 1;
  }
  else if(strat == 'B') {
    roundScore += 2;
  }
  else {
    roundScore += 3;
  }

  roundScore += calcPlayResult(opp, strat);

  return roundScore;
}

int calcPlayResult(char opp, char str) {

  // assume we lose, update as necessary
  int score = 0;

  // Draw
  if (opp == str)
    score = 3;

  // Check for a winning result
  else {
    if ((opp == 'A' && str == 'B')) {
      score = 6;
    } else if ((opp == 'B' && str == 'C')) {
      score = 6;
    } else if ((opp == 'C' && str == 'A')) {
      score = 6;
    }
  }

  return score;
}