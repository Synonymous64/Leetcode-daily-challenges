import java.util.*;
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int[] res = new int[temperatures.length];
        Stack<Integer> myStack = new Stack<>();
        Arrays.fill(res, 0);
        for(int i = 0; i < temperatures.length; ++i){
            while(!myStack.empty() && temperatures[myStack.peek()] < temperatures[i])
                res[myStack.peek()] = i - myStack.pop();
            myStack.add(i);
        }
        return res;
    }
}
public class DailyTemperatures {
    public static void main(String[] args) {
        int[] temperatures = {73,74,75,71,69,72,76,73};
        Solution s = new Solution();
        int[] res = s.dailyTemperatures(temperatures);
        for(int x : res) System.out.print(x + " ");
    }
}
