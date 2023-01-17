#include "node.hpp"
#include <iostream>

using namespace std;

Node::Node()
{
    filename = "";
    size = -1;
}

// if a directory is made: size == 0
Node::Node(string filename, int size)
{
    this->filename = filename;
    this->size = size;
}