import java.util.*;
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int top = 0; Stack<Integer> myStack = new Stack<>();
        for(int x: pushed){
            myStack.add(x);
            while(!myStack.empty() && myStack.peek() == popped[top]){
                myStack.pop();
                top++;
            }
        }
        return myStack.empty();
    }
}
public class ValidateStackSequences {
    public static void main(String[] args) {
        int[] pushed = {1,2,3,4,5}, popped = {4,5,3,2,1};
        Solution s = new Solution();
        System.out.println(s.validateStackSequences(pushed, popped));
    }
}
