#include "Stack.hpp"
#include <exception>
#include <iostream>

Stack::Stack() : top(nullptr), numElem(0) {}

Stack::~Stack() {
    clear();
}

Stack::Stack(const Stack& other) : numElem(0), top(nullptr) {
    *this = other;
}

Stack& Stack::operator=(const Stack& other) {
    if(this != &other) {
        clear();
        Element* current = other.top;
        while(current != nullptr) {
            push(current->value);
            current = current->next;
        }
    }
    return *this;
}

void Stack::push(int value){ 
    try {
        Element* newElement = new Element{value, top};
        newElement->value = value;
        newElement->next = top;
        top = newElement;
        ++numElem;
    } catch (const std::bad_alloc& e) {
        throw "Failed to allocate memory for new element"; // Rethrow the exception to be handled by the caller
    }
}
        
int Stack::pop() {
    if(isEmpty()) {
        //Lanzar una excepcion propia de la pila (pendiente)
        throw "Stack is empty";
    }
    Element* temp = top;
    top = top->next;
    delete temp;
    --numElem;
}

int Stack::getTop() const {
    if(isEmpty()) {
        throw "Stack is empty";
    }
    return top->value;
}
        
int Stack::getSize() const {
    return numElem;
}

bool Stack::isEmpty() const {
    return numElem == 0;
}

void Stack::clear() {
    while(!isEmpty()) {
        pop();
    }
}

void Stack::print() const {
    Element* current = top;
    std::cout << "Top-> ";
    while(current != nullptr) {
        std::cout << current->value << ", ";
        current = current->next;
    }
    if(!isEmpty()) {
        std::cout << "\b\b ";
    }
}