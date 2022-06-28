# ifndef Node_H
# define Node_H


# include <iostream>


template <typename Data>

class Node {

private:

    Data data;
    Node* next;

public:

    // PRE: d es un dato valido.
    // POST: Construye un Node con d como dato y next apuntado a null.
    Node(Data d);

    // PRE: Node es un Node valido.
    // POST: next apunta a n.
    void set_next(Node* Node);

    // PRE: -
    // POST: Devuelve el dato.
    Data get_data();

    // PRE: -
    // POST: Devuelve el Node next, si no lo hubiera devuelve null.
    Node* get_next();

    // PRE: -
    // POST: Se llama al destructor del dato y luego se destruye el Node.
    ~Node();

};


template <typename Data>

Node<Data>::Node(Data d) {

    data = d;
    next = NULL;
}


template <typename Data>

void Node<Data>::set_next(Node* n) {

    next = n;
}


template <typename Data>

Data Node<Data>::get_data() {

    return data;
}

template <typename Data>

Node<Data>* Node<Data>::get_next() {

    return next;
}


template <typename Data>

Node<Data>::~Node() {

    delete data;
}


# endif