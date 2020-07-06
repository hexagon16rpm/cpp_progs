#include <stdlib.h>
#include <stdio.h>
// for typo
#define temp template<typename type>

temp
class StackMimic{
public:
    
    StackMimic(int size);
    StackMimic();
    bool isEmpty();
    bool isFull();
    void push(type element);
    type pop();
    type show();

private:

    int size;
    type *stackElements;
    int topIndex = -1;
    
    bool checkCapacity();

};

// rest of the thing

temp
// constructor
StackMimic<type>::StackMimic(int size){
    this->size = size;
    this->stackElements = (type*)malloc(sizeof(type)*size);
}
temp
StackMimic<type>::StackMimic() : StackMimic(0){

}

temp
// returns true if the stack is full
bool StackMimic<type>::isFull(){
    return this->topIndex == (size - 1);
}

temp
// returns true if the stack is empty
bool StackMimic<type>::isEmpty(){
    return this->topIndex == -1;
}

temp
// returns true is the stack is niether empty nor full
bool StackMimic<type>::checkCapacity(){
    return !isEmpty() && !isFull();
}

temp
// insert a new element to the stack
void StackMimic<type>::push(type e){
    if(!isFull()){
        this->topIndex++;
        this->stackElements[this->topIndex] = e; 
    }
}

temp
// delete and return the top element of the stack
type StackMimic<type>::pop(){
    if(!isEmpty()){
        this->topIndex--;
        return stackElements[topIndex+1];
    }
}

temp
// pop w/o deletion
type StackMimic<type>::show(){
    if(!isEmpty()){
        return stackElements[topIndex];
    }
}

//driver
int main(){
    StackMimic<int> *stk = new StackMimic<int>(5);

    stk->push(2);
    stk->push(4);
    stk->push(69);
    stk->push(244);
    stk->push(420);

    for (int lol = 0; lol < 5; lol++ ){
        printf("element %d: %d\n", lol+1, stk->pop());        
    }
    
    return 0;
}
