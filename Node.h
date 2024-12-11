//
// Created by 11 on 12/11/2024.
//

#ifndef NODE_H
#define NODE_H
class Node
{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int _data) {
        data=_data;
        next=NULL;
        prev=NULL;

    }
    ~Node() {}

protected:

private:
};

#endif //NODE_H
