import java.util.*;
class Solution {
    public String makeGood(String s) {
        Stack<Character> st = new Stack<>();
        for(int i = 0; i < s.length(); ++i){
            if(!st.isEmpty() && Math.abs(st.peek() - s.charAt(i)) == 32){
                st.pop();
            } else st.push(s.charAt(i));
        }
        char[] res = new char[st.size()];
        int idx = st.size() - 1;
        while(!st.isEmpty()){
            res[idx--] = st.peek();
            st.pop();
        } 
        return new String(res);
    }
}
class Solution1 {
    public String makeGood(String s) {
        for(int i = 0; i < s.length() - 1; ++i){
            if(Math.abs(s.charAt(i) - s.charAt(i + 1)) == 32)
                return makeGood(s.substring(0, i) + s.substring(i + 2));
        }
        return s;
    }
}
public class MakeTheStringGreat {
    public static void main(String[] args) {
        String s = "leEeetcode";
        Solution1 S = new Solution1();
        System.out.println(S.makeGood(s));
    }
}
