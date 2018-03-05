/*
 *     cs106b Programming Abstractions - lecture 04 - Winter 2018
 *
 *     Abstract Data types (ADT): Vectors, LinkedLists, Stacks and Queues
 *     ref
 *      https://www.youtube.com/watch?v=_ImwLa34d9I&feature=youtu.be
 */


#include <iostream>
#include "console.h"
#include "queue.h"
#include "stack.h"
using namespace std;

//Stutter
//queue of integers and replaces by two copies of each element
// {1, 2, 3} --> {1, 1, 2, 2, 3, 3}
void stutter(Queue<int>& q);

//Mirror
//queue of strings and appends the queue content's to itself in reverse order
//{"a", "b", "c"} --> {"a", "b", "c", "c", "b", "a"}
void mirror(Queue<string>& queue);

int main() {
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q << endl;
    stutter(q);
    cout << q << endl;


    Queue<string> queue;
    queue.enqueue("a");
    queue.enqueue("b");
    queue.enqueue("c");

    cout << queue << endl;
    mirror(queue);
    cout << queue << endl;


    return 0;
}

void stutter(Queue<int>& q) {
    for (int i= q.size(); i > 0; i--)
        q.enqueue(q.peek()), q.enqueue(q.dequeue());
}


void mirror(Queue<string>& queue) {
    Stack<string> stack;
    for (int i= queue.size(); i > 0; i--)
        stack.push(queue.peek()), queue.enqueue(queue.dequeue());

    while(!stack.isEmpty())
        queue.enqueue(stack.pop());


}





