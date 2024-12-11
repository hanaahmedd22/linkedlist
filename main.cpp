#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList l;
    LinkedList *p = new LinkedList();

    l.addNode(5);
    l.addNode(10);
    cout << "number of nodes: " << l.getcount() << endl;

    l.addNode(15);
    int index = 0;
    cout << "index of node " << index << " has data  " << l.getDatabyIndex(index) << endl;
    l.display();
    cout << endl;
    l.getDatabyIndex(5);
    // l.Remove(15);
    //l.Remove(10);
    // l.display();
    //l.Remove(5);

    l.insertafter(101, 15);
    l.insertafter(102, 10);
    l.insertafter(103, 5); //5 103 10 102 15 101
    l.display();
    cout << endl;
    l.insertbefore(400,405);
    l.insertbefore(200, 5);
    l.insertbefore(201, 10);
    l.insertbefore(202, 101);
    cout << endl;
    l.display();


    return 0;
}
