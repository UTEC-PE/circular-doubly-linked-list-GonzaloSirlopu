#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class Iterator {
    private:
        Node<T>* current;
    
    public:
        Iterator();
        Iterator(Node<T>* node);
         
        Iterator<T> operator=(Iterator<T> node){return current = node;}; // Esto está mal
        bool operator!=(Iterator<T> cmp){return current != cmp.current;};
        Iterator<T> operator++(){current = current -> next;}; // Falta return 
        Iterator<T> operator--(){current = current -> prev;}; // Falta return
        T operator*(){return current -> data;};
};

#endif