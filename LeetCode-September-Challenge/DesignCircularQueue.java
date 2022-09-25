import java.util.Arrays;

class MyCircularQueue {
    private int rear = 0, front = 0, size = 0;
    private int[] arr;
    public MyCircularQueue(int k) {
        arr = new int[k];
        Arrays.fill(arr, -1);
    }
    
    public boolean enQueue(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            rear = front = 0;
            arr[rear] = value;
            size++;
            return true;
        }
        rear++;
        size++;
        rear %= arr.length;
        arr[rear] = value;
        return true;
    }
    
    public boolean deQueue() {
        if(isEmpty()) return false;
        arr[front] = -1;
        front++;
        size--;
        front %= arr.length;
        return true;
    }
    
    public int Front() {
        return arr[front];
    }
    
    public int Rear() {
        return arr[rear];
    }
    
    public boolean isEmpty() {
        return size == 0;
    }
    
    public boolean isFull() {
        return size == arr.length;
    }
}
public class DesignCircularQueue {
    public static void main(String[] args) {
        MyCircularQueue q = new MyCircularQueue(3);
        System.out.println(q.enQueue(1));
        System.out.println(q.enQueue(2));
        System.out.println(q.enQueue(3));
        System.out.println(q.enQueue(4));
        System.out.println(q.Rear());
        System.out.println(q.isFull());
        System.out.println(q.deQueue());
        System.out.println(q.enQueue(4));
        System.out.println(q.Rear());
    }
}
