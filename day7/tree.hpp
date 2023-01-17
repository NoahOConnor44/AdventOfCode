#ifndef TREE_HPP
#define TREE_HPP

#include "node.hpp"
#include <iostream>

using namespace std;

class Tree
{
    public:
        Tree();
        Node* root;
        void traverseTree();
};

#endif