import java.util.Queue;
import java.util.*;
public class ImplementStackusingQueues {
    Queue<Integer> q = new LinkedList<>();
    public void push(int x) {
        int size = q.size();
        q.add(x);
        for(int i = 0; i < size; i++) { 
            q.add(q.peek());
            q.remove();
        }
    }
    
    public int pop() {
        int top = 0;
        if(!q.isEmpty()){
            top = q.peek();
            q.remove();
        }
        return top;
    }
    
    public int top() {
        int top = 0;
        if(!q.isEmpty()){   
            top = q.peek();
        }
        return top;
    }
    
    public boolean empty() {
        return q.isEmpty();
    }
    public static void main(String[] args) {
        
    }
}
