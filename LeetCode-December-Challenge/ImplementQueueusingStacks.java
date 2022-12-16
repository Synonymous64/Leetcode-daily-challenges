import java.util.*;

class MyQueue {
    private Stack<Integer> s1, s2;

    public MyQueue() {
        s1 = new Stack<>();
        s2 = new Stack<>();
    }

    public void push(int x) {
        s1.push(x);
    }

    public int pop() {
        peek();
        int top =  s2.peek();
        s2.pop();
        return top;
    }

    public int peek() {
        if (s2.empty())
            while (!s1.empty()) {
                s2.add(s1.peek());
                s1.pop();
            }
        return s2.peek();
    }

    public boolean empty() {
        return s1.empty() && s2.empty();
    }
}

public class ImplementQueueusingStacks {
    public static void main(String[] args) {

    }
}
