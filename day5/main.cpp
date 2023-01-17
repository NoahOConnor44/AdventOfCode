#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

int readNumStacks(ifstream &fin);
void readStackData(ifstream &fin, queue<char>* crates, int dataEnds);
void rearrangeStacks(ifstream& fin, queue<char>* crates);

int main()
{
    ifstream fin;
    int numStacks = -1;
    fin.open("input.txt");
    string line;

    numStacks = readNumStacks(fin);

    // array of queues (a queue for each stack of crates)
    queue<char> crates[numStacks];

    // store read position where moves will start
    int readPosition = fin.tellg();

    // reset read pointer
    fin.seekg(0, ios::beg);

    // convert stack data into list of linked lists.
    readStackData(fin, crates, readPosition);

    std::cout << "---------------------------\n";

    rearrangeStacks(fin, crates);

    return 0;
}

int readNumStacks(ifstream &fin)
{
    string line;
    int numStacks;

    // read line by line
    while (getline(fin, line))
    {
        // stop when it list the stack #'s
        if (line[0] != '[')
        {
            string temp;
            temp += line[line.length() - 2];
            numStacks = stoi(temp);
            break;
        }
    }
    return numStacks;
}

void readStackData(ifstream &fin, queue<char>* stackArr, int dataEnds)
{
    string line;
    int row = 0;
    bool head = true;

    // read only the stack data at the top of the file
    while (getline(fin, line) && fin.tellg() != dataEnds)
    {
        // replace areas with no crates with placeholders so easier to work with
        // remove brackets so easier to fill into correct crate locations.
        string newLine = regex_replace(line, regex("    "), "[1]");
        newLine = regex_replace(newLine, regex(" "), "");
        newLine = regex_replace(newLine, regex("\\["), "");
        newLine = regex_replace(newLine, regex("\\]"), "");
        newLine += '\n';

        int column = 0;
        while (newLine[column] != '\n')
        {
            if (isalnum(newLine[column]))
            {
                if (isalpha(newLine[column]))
                {
                    stackArr[column].push(newLine[column]);
                }
            }
            column++;
        }
        row++;
    }

    // print populated stacks that were created
    for(int i = 0; i < 9; i++) 
    {
        queue<char> copy = stackArr[i];
        
        while(!copy.empty())
        {
            cout << copy.front() << " ";
            copy.pop();
        }
        cout << endl;
    }
    cout << endl;
}

void rearrangeStacks(ifstream& fin, queue<char>* stack)
{
    string line;
    int howMany, source, dest;
    
    // first line after stack setup is a new line, throw it away.
    getline(fin, line);

    // read instructions until the end of the file
    while(getline(fin, line))
    {
        // create string stream and add line to it
        stringstream in;
        in << line;

        string temp;

        // break line by spaces (6 words per line)
        // format: "move <numBlocks> from <stack1> to <stack2>"
        for(int lcv = 0; lcv < 6; lcv++)
        {
            in >> temp;
            if (lcv == 0 || lcv == 2 || lcv == 4) continue;
            if (lcv == 1)
            { 
                howMany = stoi(temp);
            }
            if (lcv == 3)
            {
                source = stoi(temp);
            }
            if (lcv == 5)
            {
                dest = stoi(temp);
            }
        }

        // remove 'n' items from a stack to another
        for(int i = 0; i < howMany; i++)
        {
            // store data to be moved
            char data = stack[source-1].front();

            // remove that data from the source container stack
            stack[source-1].pop();

            // create a new queue to maintain proper order
            queue<char> newStack;

            // add new box first
            newStack.push(data);
            
            // add "old" containers to the new one
            while(!stack[dest-1].empty())
            {
                newStack.push(stack[dest-1].front());
                stack[dest-1].pop();
            }

            // set the queue to the new one
            stack[dest-1] = newStack;
        }
    }

    // print stacks after crates are moved
    for(int i = 0; i < 9; i++) 
    {
        queue<char> copy = stack[i];
        
        while(!copy.empty())
        {
            cout << copy.front() << " ";
            copy.pop();
        }
        cout << endl;
    }
}