# ifndef LIST_H
# define LIST_H


# include "Node.h"


template <typename Data>

class List {

private:

    int size;
    Node<Data>* first;
    Node<Data>* current;

public:

    // PRE: -
    // POST: Crea una List empty.
    List();

    // PRE: -
    // POST: Mueve el current al inicio de la List.
    void inicialize();

    // PRE:
    // POST: Devuelve true si hay un nodo next, false si se esta en el final.
    bool not_end();

    // PRE:
    // POST: Devuelve el dato de current y mueve el current hacia la next posicion.
    Data next();

    // PRE: -
    // POST: Devuelve true si esta empty, false en caso contrario.
    bool empty();

    // PRE: e es un dato valido. 0 <= Pos <= obtener.size() + 1
    // POST: Agrega el elem en la posicion pos. (empieza en 0)
    void push(Data e, int pos); 
    
    // PRE: 0 <= Pos <= obtener.size().
    // POST: Da de pop al elemento en pos.
    void pop(int pos);

    // PRE: 0 <= Pos <= obtener.size().
    // POST: Devuelve el elemento en pos.
    Data get_data(int pos);

    // PRE: -
    // POST: Devuelve el tamaño de la List.
    int get_size();

    //PRE: -
    //POST: Destruye la List.
    ~List();

private:

    Node<Data>* get_node(int pos);

};


template <typename Data>

List<Data>::List() {
    size = 0;
    first = NULL;
    current = NULL;
}


template <typename Data>

void List<Data>::inicialize() {

    current = first;
}

template <typename Data>

bool List<Data>::not_end() {

    return current -> get_next() != NULL;
}


template <typename Data>

Data List<Data>::next() {

    Data return_ = current -> get_data();
    current = current -> get_next();

    return return_;
}


template <typename Data>

bool List<Data>::empty() {

    return (first == NULL);
}


template <typename Data>

int List<Data>::get_size() {

    return size;
}


template <typename Data>

Node<Data>* List<Data>::get_node(int pos) {

    Node<Data>* aux = first;
    int counter = 0;

    while(counter < pos) {
        aux = aux -> get_next();
        counter++;
    }

    return aux;
}


template <typename Data>

Data List<Data>::get_data(int pos) {

    Node<Data>* aux = get_node(pos);
    return aux -> get_data();
}


template <typename Data>

void List<Data>::push(Data e, int pos) {

    Node<Data>* new_node = new Node<Data>(e);

    if( pos == 0) {
        new_node -> cambiar_next(first);
        first = new_node;

    }
    else {

        Node<Data>* previous = get_node(pos - 1);
        new_node -> cambiar_next(previous -> get_next());

        previous -> cambiar_next(new_node);

    }
    size++;
}


template <typename Data>

void List<Data>::pop(int pos) {

    Node<Data>* delete_node = first;

    if(pos == 0)
        first = first -> get_next();
    else {
        Node<Data>* previous = get_node(pos - 1);
        borrar = previous -> get_next();
        previous -> cambiar_next(delete_node -> get_next());
    }
    size--;

    delete delete_node; 
}

template <typename Data>

List<Data>::~List() {
    while(!empty())
        pop(0);
}


# endif