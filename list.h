#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* start; 
        // No se definió nodes

    public:
        List(){
            start=nullptr;
            nodes=0;
        };

        T front(){return start -> data;}; // Falta controlar caso vacío
        T back(){return start -> prev -> data;}; // Falta controlar caso vacío
        void push_front(T value){
            Node<T>*temporal=new Node<T>;
            temporal -> data = value;
            if(start = nullptr){
                temporal -> next = temporal -> prev = temporal;
                start = temporal;
            }
            else{
                Node<T>* last = start -> prev;
                temporal -> next = start;
                temporal -> prev = last;
                last -> next = start -> prev;
                start = temporal;

            }
        };
        void push_back(T value){
            Node<T>*temporal=new Node<T>;
            temporal -> data = value;
            if(start = nullptr){
                temporal -> next = temporal -> prev = temporal;
                start = temporal;
            }
            else{
                Node<T>* last = start -> prev;
                temporal -> next = start;
                start -> prev = temporal;
                temporal -> prev = last;
                last -> next = temporal;
            }
        };
        void pop_front(){ // Falta
            Node<T>*temporal=start;
            start -> next = start-> next -> next;
        };
        void pop_back(); // No se implementó 
        T get(int position); // No se implementó 
        void concat(List<T> &other); // No se implementó 
        bool empty(){return nodes==0;};
        int size(){return nodes;};
        void clear(){}; // No se implementó 
        Iterator<T> begin(){return Iterator<T>(start);};
        Iterator<T> end(){return Iterator<T>(start->prev);};

        ~List(){}; // No se implementó
};

#endif