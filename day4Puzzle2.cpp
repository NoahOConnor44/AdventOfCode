#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream fin;
  string line;
  fin.open("input.txt");

  int containedPairs = 0;
  
  // start - end values for each pair.
  int s1, e1, s2, e2;

  while(getline(fin, line)) {
    int commaLoc = line.find(',');
    
    string firstRng = line.substr(0,commaLoc);
    string secRng = line.substr(commaLoc+1,line.length());

    s1 = stoi(firstRng);
    s2 = stoi(secRng);

    int dashLoc = firstRng.find('-');
    int dashLoc2 = secRng.find('-');

    int min = -1, max = -1;
    
    e1 = stoi(firstRng.substr(dashLoc+1,firstRng.length()));
    e2 = stoi(secRng.substr(dashLoc2+1,secRng.length()));

    // find max of starting boundaries (left side of intervals)
    if(s1 > s2) {
      max = s1;
    }
    else {
      max = s2;
    }

    // find min of end boundaries (right side of intervals)
    if(e1 < e2) {
      min = e1;
    }
    else {
      min = e2;
    }

    // set 1 fully contained in set 2
    if(s1 >= s2 && e1 <= e2) {
      containedPairs++;
    }
    // set 2 fully contained in set 1
    else if(s2 >= s1 && e2 <= e1) {
      containedPairs++;
    }
    // partial overlap of sets
    else if (max <= min) {
      containedPairs++;
    }
  }

  cout << containedPairs << endl;
  
  return 0;
}