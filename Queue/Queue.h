# ifndef QUEUE_H
# define QUEUE_H


# include "Node.h"


template <typename Data>

class Queue {

private:

    int size;
    Node<Data>* first;
    Node<Data>* last;

public:

    // PRE: -
    // POST: Creates empty queue
    Queue();

    // PRE: -
    // POST: True if Queue is empty
    bool empty();

    // PRE: d is valid Data
    // POST: Adds d at the end of the queue
    void push(Data d);

    // PRE: Queue is not empty
    // POST: Deletes first element of the queue
    Data pop();

    // PRE: Queue is not empty
    // POST: Returns first element of the Queue (without deleting it)
    Data get_first();

    // PRE: -
    // POST: Devuelve la cantidad de elementos de la Queue.
    int get_size();

    // PRE: -
    // POST: Destruye la Queue.
    ~Queue();

};

template <typename Data>

Queue<Data>::Queue() {

    size = 0;
    first = NULL;
    last = NULL;
}

template <typename Data>
int Queue<Data>::get_size(){
    return size;
}


template <typename Data>

bool Queue<Data>::empty() {

    return last == NULL;
}


template <typename Data>

Data Queue<Data>::get_first() {

    return first -> get_data();
}


template <typename Data>

void Queue<Data>::push(Data d) {

    Node<Data>* add = new Node<Data>(d);

    if(first)
        last -> cambiar_siguiente(add);
    else
        first = add;
    
    last = add;
    size++;
}


template <typename Data>

Data Queue<Data>::pop() {

    Node<Data>* delete_ = first;

    Data data = delete_ -> get_data();

    first = first -> get_next();

    if(!first)
        last = NULL;

    delete delete_;
    size--;
 
    return data;
}


template <typename Data>

Queue<Data>::~Queue() {
    while(!empty())
        pop();
}


# endif