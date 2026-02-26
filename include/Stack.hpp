#ifndef STACK_HPP
#define STACK_HPP



class Stack {

    public: 
        Stack();
        ~Stack();

        Stack(const Stack& other);
        Stack& operator=(const Stack& other);

        void push(int value);
        int pop();

        int getTop() const;
        int getSize() const;

        bool isEmpty() const;

        void clear();   

        // Implement print method
        void print() const;

    private:
        int numElem;
        struct Element {
            int value;
            Element* next;
        } *top;

};

#endif // STACK_HPP