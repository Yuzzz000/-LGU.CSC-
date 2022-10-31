
/* Q2:
 * File: ReverseQueue.cpp
 * ----------------------
 * This file tests the ReverseQueue function.
 */

#include <iostream>
#include "csc300222fall/assignment2/reversequeue.h"
#include <stack>
using namespace std;

/* TODO PART:
 * Function: reverseQueue
 * Usage: reverseQueue(queue);
 * ---------------------------
 * Reverses the order of the elements in a queue.  This
 * implementation does so by using a stack to hold the
 * values as they are being reversed.
 */

void reverseQueue(queue<string> & queue) {
   // TODO
    string str;
    stack<string> s;
    while (queue.size() != 0){
        str = queue.front();
        queue.pop();
        s.push(str);
    }
    while (s.size() != 0){
        str = s.top();
        s.pop();
        queue.push(str);
    }

}

/* TODO PART:
 * Function: listQueue
 * Usage: listQueue(queue);
 * ------------------------
 * Lists the contents of the queue on the standard output stream.
 */

void listQueue(queue<string> & queue) {
   // TODO
   std :: queue<string> q;
   q = queue;
   cout << "The queue contains:";
   while (q.size() != 0)
   {
    cout << " " << q.front();
    q.pop();
   }
   cout << endl;
}

/* DO NOT modify this main() part*/

int main() {
    string str;
    queue<string> line;

    while(cin>>str){
        line.push(str);
    }
    listQueue(line);
    reverseQueue(line);
    listQueue(line);
    return 0;
}
