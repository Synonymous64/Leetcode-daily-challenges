import java.util.*;

class Solution {
    private boolean isValidParanthesis(char a, char b){
        if(a == '(' && b == ')') return true;
        else if(a == '[' && b == ']') return true;
        else if(a == '{' && b == '}') return true;
        return false;
    }
    public boolean isValid(String s) {
        Stack<Character> myStack = new Stack<>();
        char checker;
        for(char ch: s.toCharArray()){
            if(ch == '(' || ch == '[' || ch == '{') myStack.add(ch);
            else if(ch == ')' || ch == ']' || ch == '}'){
                if(myStack.empty()) return false;
                checker = myStack.peek();
                if(!isValidParanthesis(checker, ch)) return false;
                else myStack.pop();
            }
        }
        return myStack.empty() ? true: false;
    }
}

public class ValidParentheses {
    public static void main(String[] args) {
        String s = "()[]{}";
        System.out.println(new Solution().isValid(s));
    }
}