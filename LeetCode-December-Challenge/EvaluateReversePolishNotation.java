import java.util.*;
class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> st = new Stack<>();
        for(String str: tokens){
            if(str.equals("+")){
                st.add(st.pop() + st.pop());
            } else if(str.equals("-")){
                int x2 = st.pop();
                int x1 = st.pop();
                st.add(x1 - x2);
            } else if(str.equals("*")){
                int x2 = st.pop();
                int x1 = st.pop();
                st.add(x1 * x2);
            } else if(str.equals("/")){
                int x2 = st.pop();
                int x1 = st.pop();
                st.add(x1 / x2);
            }
            else st.push(Integer.parseInt(str));
        }
        return st.peek();
    }
}
public class EvaluateReversePolishNotation {
    public static void main(String[] args) {
        String[] tokens = {"2","1","+","3","*"};
        Solution s = new Solution();
        System.out.println(s.evalRPN(tokens));
    }
}
