/*
given a string of characters, divide them up into two words.

for each word find the common character they both have. (done using frequency counter)

then based off the common letter, assign a priority 1-52 and sum it up.
*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int findIndex(char letter);
int findCommonType(int index);

int main() {
  ifstream fin;
  string line;
  fin.open("input3.txt");
  int totalPriority = 0;;

  while (getline(fin, line)) {
    int compartmentOne = (line.length() / 2) - 1;
    int compartmentTwo = line.length() - 1;

    string items1 = line.substr(0, compartmentOne + 1);
    string items2 = line.substr(compartmentOne + 1, compartmentTwo);

    cout << items1 << "\n" << items2 << endl;

    // stores frequency count for a-z, A-Z. Init all to zero frequency.
    int alphabet1[52] = {};
    int alphabet2[52] = {};

    cout << "\n";
    int index = 0;

    for (int i = 0; i < items1.length(); i++) {
      // check first compartment
      index = findIndex(items1[i]);
      alphabet1[index] += 1;

      // if found common type move on...
      if ((alphabet1[index] >= 1) && (alphabet2[index] >= 1)) {
        totalPriority += findCommonType(index);
        break;
      }

      // check second compartment
      index = findIndex(items2[i]);
      alphabet2[index] += 1;

      // if found common type move on...
      if ((alphabet2[index] >= 1) && (alphabet1[index] >= 1)) {
        totalPriority += findCommonType(index);
        break;
      }
    }
  }

  cout << "Total priority is: " << totalPriority << endl;

  return 0;
}

int findIndex(char letter) {
  int index = -1;

  if (islower(int(letter))) {
    index = 122 - int(letter);
    // make it a zero based index.
    index = 25 - index;
  } else {
    index = 90 - int(letter);
    // make it a zero based index.
    index = 25 - index;
    // store in capital part of array (26-51)
    index = 26 + index;
  }

  return index;
}

// returns priority value (1-52)
int findCommonType(int index) {
  int uppercase = 65;
  int lowercase = 97;

  cout << "Common type was: ";

  if (index <= 25) {
    cout << char(lowercase + index);
  } else {
    cout << char(uppercase + (index - 26));
  }
  cout << endl << endl;

  return index+1;
}