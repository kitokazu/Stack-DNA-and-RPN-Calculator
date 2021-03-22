#ifndef GENSTACK_H
#define GENSTACK_H

#include "LinkedList.h"

template <typename T>
class NTStack{
public:
  NTStack();
  NTStack(int iSize);
  ~NTStack();
  void push(T c); //add to top
  void printStack(bool link);
  T pop(); //remove from top
  T peek(); //return top without removing
  bool isFull();
  bool isEmpty();
  int size();


private:
  T* stackArr;
  int count; //number of items currently in stack
  int maxSize; //max number of things in the stack
  int top; //index of the current top of stack
  DoublyLinkedList<T>* linkedlist;

};

//LinkedList Stack
//Uses functions in the linkedlist class
template <typename T>
NTStack<T>::NTStack(){
    linkedlist = new DoublyLinkedList<T>;
}

template <typename T>
NTStack<T>::NTStack(int iSize){
    linkedlist = new DoublyLinkedList<T>;
}

template <typename T>
NTStack<T>::~NTStack(){
    delete linkedlist;
}

template <typename T>
bool NTStack<T>::isFull(){
}

template <typename T>
bool NTStack<T>::isEmpty(){
  return linkedlist->isEmpty();
}

template <typename T>
int NTStack<T>::size(){
    return linkedlist->listSize;
}

template <typename T>
void NTStack<T>::push(T c){
    linkedlist->insertFront(c);
}

template <typename T>
T NTStack<T>::pop(){
  return linkedlist->removeFront();
}

template <typename T>
T NTStack<T>::peek(){
  return linkedlist->front->data;
}

template <typename T>
void NTStack<T>::printStack(bool link){
  linkedlist->printList(link);
}




#endif
