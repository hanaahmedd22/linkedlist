//
// Created by 11 on 12/11/2024.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
int counter=0;
using namespace std;
class LinkedList
{

    Node * head;
    Node * tail;
public:
    LinkedList() {
        head=tail=NULL;
    }
    void addNode(int _data){
        //Create Node
        Node *newNode=new Node(_data); // Nodedata=data , next,prev=null;
        if(head == NULL){
            head=tail=newNode;
            return ;
        }
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;

    }
    void display(){
        Node *current=head;
        if(current == NULL){
            cout<<"Linked List Empty \n";
            return;
        }
        while(current != NULL ){
            cout<<current->data<<"\t";
            current=current->next;
        }



    }
    int getcount() {
        Node *current=head;
        if(current == NULL){
            cout<<"Linked List Empty \n";
            return 0;
        }
        while(current != NULL ){
            counter++;
            current=current->next;
        }
        return counter;
    }

    void Remove(int _data){
        Node * node=GetNode(_data);
        if(node==NULL){
            cout<<"Not Found "<<endl;
            return ;
        }
        if(head == node){
            if(head == tail){
                head=tail=NULL;
            }
            else{
                head=head->next;
                head->prev=NULL;
            }
        }
        else if(tail == node){
            tail=tail->prev;
            tail->next=NULL;
        }
        else{
            Node * A= node->prev;
            Node * B= node->next;
            A->next=B;
            B->prev=A;

        }
        delete node;
    }
    void insertbefore(int _data,int beforenodedata) {
        Node * newNode=new Node(_data);
        Node* bNode=GetNode(beforenodedata);
        if (bNode != NULL) {
            if (head == bNode) {
                head->prev = newNode;//head kan prev b null b2a byshawr 3la new node
                newNode->next = head;
                head = newNode;
            } else {
                Node *A = bNode->prev;
                bNode->prev = newNode;
                newNode->next = bNode;
                newNode->prev = A;
                A->next = newNode;
            }
            cout<< "successful insertion "<<endl;
            return ;
        } else {
            cout << "Node Not Found " << endl;
            return;
        }
    }
    void insertafter(int _data,int afternodedata) {
        Node * newNode=new Node(_data);
        Node* aNode=GetNode(afternodedata);
        if (aNode==NULL) {
            cout<<"Node Not Found "<<endl;
            return ;
        }
        else if(aNode==tail) {
                aNode->next=newNode;
                newNode->prev=aNode;
                tail=newNode;
            }
        else {
            Node * B=aNode->next;
            aNode->next=newNode;
            newNode->prev=aNode;
            newNode->next=B;
            B->prev=newNode;

        }
        cout<< "successful insertion "<<endl;
        return ;
    }
    int getDatabyIndex(int index) {
        int i=0;
        Node *current=head;
        if(current == NULL){
            cout<<"Linked List Empty \n";
            return 0;
        }
        while(current != NULL ){
           if(i==index) {
               return current->data;
           }
            i++;
            current=current->next;
        }
        cout<<"index Not Found "<<endl;
        return 0;



    }
    ~LinkedList() {}

protected:

private:
    //Helper Function
    Node * GetNode(int _data){
        Node *current=head;
        while(current != NULL ){
            if(current->data == _data){
                return current;
            }
            current=current->next;
        }
        return NULL;
    }
};

#endif // LINKEDLIST_H

