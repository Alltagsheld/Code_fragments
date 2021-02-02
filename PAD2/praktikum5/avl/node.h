#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;

class Node
{
public:
    Node(int k, string v = "", Node* l = nullptr, Node* r = nullptr);
    int getHeight();
    int key;
    string value;
    Node* left;
    Node* right;
    int height=0;
};

#endif // NODE_H
