#include <iostream>
#include <fstream>
#include "tree.hpp"

using namespace std;

int main()
{
    ifstream fin;
    string line;
    Tree tree;

    string directory;
    Node* currNode = nullptr;

    fin.open("input7.txt");

    while(getline(fin,line))
    {
        // command being performed
        if(line[0] == '$')
        {
            // switch to this parent node
            // in the tree
            if(line.substr(2,2) == "cd")
            {
                directory = line.substr(5,line.length());
                cout << directory << endl;

                // set pointer to that node so on following lines we can update
                // its size
                if(directory != "/")
                {
                    for(int i = 0; i < tree.root->children.size(); i++)
                    {
                        if(directory == tree.root->children.at(i)->filename)
                        {
                            currNode = tree.root->children.at(i);
                        }
                    }
                    tree.root->children.push_back(new Node(directory, 0));
                }
            }
            else if(line.substr(2,2) == "ls")
            {

            }
        }
        else
        {

        }
        cout << line << endl;
    }

    return 0;
}