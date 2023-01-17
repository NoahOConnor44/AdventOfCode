#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <vector>
using namespace std;

class Node
{
    public:
        Node();
        Node(string filename, int size);
        string filename;
        int size;
        vector<Node*> children;
};

#endif