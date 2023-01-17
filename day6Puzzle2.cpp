#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    string line;
    string subst;

    bool repeat = true;

    int left = 0;

    fin.open("input6.txt");

    getline(fin,line);

    while(repeat)
    {
        // assume letters are not repeats
        repeat = false;

        // get new substring to check
        subst = line.substr(left,14);
        cout << subst << endl;

        // for each message, check future letters for repeats
        for(int i = 0; i < 13; i++)
        {
            for(int j = i+1; j < 14; j++)
            {
                if(subst[i] == subst[j])
                {
                    repeat = true;
                }
            }  
        }

        // increment left index to check next substring
        left++;
    }

    cout << "Repeat: " << repeat << endl;
    // plus 13 because its incremented at the end of the last successful run
    cout << "Marker location: " << left+13 << endl;

    return 0;
}