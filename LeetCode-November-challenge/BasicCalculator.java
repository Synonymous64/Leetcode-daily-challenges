import java.util.*;
class Solution {
    public int calculate(String s) {
        int res = 0, sum = 0, sign = 1;
        Stack<Integer> myStack = new Stack<>();
        myStack.push(1);
        for(char ch: s.toCharArray()){
            if(Character.isDigit(ch)) sum = sum * 10 + (ch - '0');
            else{
                res += sum * sign * myStack.peek();
                sum = 0;
                if(ch == '-') sign = -1;
                else if(ch == '+') sign = 1;
                else if(ch == '('){
                    myStack.push(myStack.peek() * sign);
                    sign = 1;
                } else if(ch == ')') myStack.pop();
            }
        }
        return res += sign * sum;
    }
}
public class BasicCalculator{
    public static void main(String[] args) {
        String s = "(1+(4+5+2)-3)+(6+8)";
        Solution S = new Solution();
        System.out.println(S.calculate(s));
    }
}