/*
    link: https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/

    methods:
    1. enqueue
    2. dequeue
    3. isFull
    4. isEmpty
    5. getFront
    6. getRear
*/


// ----------------------------------------------------------------------------------------------------------------------- //
class MyQueue {
    public:
    int front, rear, size;
    unsigned capacity;
    int arr[];

    MyQueue(unsigned cap) {
        capacity = cap;
        front = 0;
        rear = capacity - 1;
    }

    bool isFull() return size == capacity;

    bool isEmpty() return size == 0;

    void enqueue(int x) {
        if (isFull()) return;

        rear = (++rear) % capacity;
        arr[rear] = x;
        size++;
        cout << x << " is enqueued!" << endl;
    }

    void dequeued() {
        if (isEmpty()) return;

        int curr = arr[front];
        front = (++front) % capacity;
        size--;
        cout << curr << " is dequeued!" << endl;
    }

    int isFront() {
        if (isEmpty()) return INT_MIN;

        return arr[front];
    }

    int isRear() {
        if (isEmpty()) return INT_MIN;

        return arr[rear];
    }

}

int main() {
    MyQueue q = new MyQueue(10);
}