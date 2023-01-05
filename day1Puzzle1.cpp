/*
Advent of code - day 1

Read file, calculate calories for each elf, 

find elf with most calories (part 1)
find top-3 elfs carrying most calories, total them (part 2)
*/

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("input1.txt");

    string line;
    int i = 0;

    vector<int> elfCals;

    // init first elfs index with zero calories
    elfCals.push_back(0);

    while (getline(fin, line))
    {
        if (line.length() != 0)
        {
            elfCals.at(i) += stoi(line);
        }
        else
        {
            // move index to next elf
            i++;
            // add index in the vector for the next elf to store its total calories
            elfCals.push_back(0);
        }
    }
    
    int top[3] = {-1,-1,-1};

    for(int i = 0; i < 3; i++)
    {
        int max = -99;
        int ind = -1;

        for(int j = 0; j < elfCals.size(); j++)
        {
            if(elfCals.at(j) > max)
            {
                ind = j;
                max = elfCals.at(j);
            }
        }

        top[i] = elfCals.at(ind);
        cout << top[i] << endl;
        elfCals.erase(elfCals.begin() + ind);
    }

    int totalTopCals = 0;

    cout << "Elfs with most calories are: \n" ;
    for(int i = 0; i < 3; i++)
    {
        totalTopCals += top[i];
        cout << top[i] << endl;
    }

    cout << totalTopCals << endl;
    

    return 0;
}