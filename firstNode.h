#ifndef FIRSTNODE_H
#define FIRSTNODE_H
#include "secondNode.h"
#include "Vector.h"

typedef unsigned short int usi;

struct firstNode
{
    usi value;
    Vector<secondNode> child_node;
};

#endif // FIRSTNODE_H
