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
    
    e1 = stoi(firstRng.substr(dashLoc+1,firstRng.length()));
    e2 = stoi(secRng.substr(dashLoc2+1,secRng.length()));
    
    cout << s1 << " " << e1 << " " << s2 << " " << e2 << endl;

    if(s1 >= s2 && e1 <= e2) {
      containedPairs++;
    }
    else if(s2 >= s1 && e2 <= e1) {
      containedPairs++;
    }
  }

  cout << containedPairs << endl;
  
  return 0;
}