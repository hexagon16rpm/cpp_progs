#include <stdio.h>
#include <stdlib.h>
#define temp template<typename type>

temp
class QueueMimic{
public:
    QueueMimic(int);
    void enqueue(type);
    type dequeue();
    int topIndex;
    bool isFull();
    bool isEmpty();

private:
    type *queueElements;
    int queueSize;
    int tailIndex;
    int headIndex;
    int size;
};

temp
QueueMimic<type>::QueueMimic(int size){
    this->size = size;
    tailIndex = -1;
    headIndex = 0;
    //queueElements = new type[queueSize];
    queueElements = (type*)malloc(sizeof(type)*queueSize);
}

temp
void QueueMimic<type>::enqueue(type element){
    tailIndex++;
    queueElements[tailIndex] = element;
}

temp
type QueueMimic<type>::dequeue(){
    return queueElements[headIndex++];
}

temp
bool QueueMimic<type>::isEmpty(){
    return this->headIndex == 0 && this->tailIndex == -1;
}

temp
bool QueueMimic<type>::isFull(){
    return this->tailIndex == this->size - 1;
}
// driver
int main(){
    QueueMimic<char> *queue = new QueueMimic<char>(4);
    
    printf("isEmpty : %d\n", queue->isEmpty());
    printf("isFull : %d\n\n", queue->isFull());

    for(int k = 0; k < 4; k++){
        queue->enqueue(k + 65);
    }
    
    for(int k = 0; k < 4; k++){
        printf("element %d: %c\n",k ,queue->dequeue());
    }

    printf("\nisEmpty : %d\n", queue->isEmpty());
    printf("isFull : %d\n\n", queue->isFull());
    return 0;
}