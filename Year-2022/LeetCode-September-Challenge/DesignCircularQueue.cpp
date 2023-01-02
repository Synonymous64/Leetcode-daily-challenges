#include<bits/stdc++.h>
using namespace std;
class MyCircularQueue {
private:
    int rear = 0;
    int front = 0;
    int size = 0;
    int capacity = 0;
    vector<int> arr;
public:
    MyCircularQueue(int k) {
        capacity = k;
        arr.resize(k);
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            front = rear = 0;
            arr[rear] = value;
            size++;
            return true;
        }
        rear++;
        size++;
        rear %= capacity;
        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        arr[front] = -1;
        size--;
        front++;
        front %= capacity;
        return true;
    }
    int Front() {
        return isEmpty() ? -1 : arr[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : arr[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};
int main()
{
    MyCircularQueue q(3);
    cout << q.enQueue(1) << endl;
    cout << q.enQueue(2) << endl;
    cout << q.enQueue(3) << endl;
    cout << q.enQueue(4) << endl;
    cout << q.Rear() << endl;
    cout << q.isFull() << endl;
    cout << q.deQueue() << endl;
    cout << q.enQueue(4) << endl;
    cout << q.Rear() << endl;
    return 0;
}