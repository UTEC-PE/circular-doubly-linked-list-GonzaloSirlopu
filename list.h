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

    public:
        List(){
            start=nullptr;
            nodes=0;
        };

        T front(){return start -> data;};
        T back(){return start -> prev -> data;};
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
        void pop_front(){
            Node<T>*temporal=start;
            start -> next = start-> next -> next;
        };
        void pop_back();
        T get(int position);
        void concat(List<T> &other);
        bool empty(){return nodes==0;};
        int size(){return nodes;};
        void clear(){};
        Iterator<T> begin(){return Iterator<T>(start);};
        Iterator<T> end(){return Iterator<T>(start->prev);};

        ~List(){};
};

#endif