#include "precomp.h"
#include "node.h"


//node::node()
//{
//    node *left, *right;
//};
//
//node* node::newNode(Tank* tank)
//{
//    node* temp = new node();
//
//    temp->tank = tank;
//
//    temp->left = temp->right = NULL;
//    return temp;
//}
//
//node* node::insertNode(Tank* tank, unsigned int depth)
//{
//    if (this == NULL)
//    {
//        return newNode(tank);
//    }
//
//    unsigned cd = depth % k;
//
//    if (tank->get_position()[cd] < (this->tank->get_position()[cd]))
//    {
//        if (!this->left)
//            return this->left = newNode(tank);
//        this->left->insertNode(tank, depth + 1);
//    }
//    else
//    {
//        if (!this->right)
//            return this->right = newNode(tank);
//        this->right->insertNode(tank, depth + 1);
//    }
//    return this;
//}