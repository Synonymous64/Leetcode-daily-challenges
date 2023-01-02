import java.util.*;
class Solution {
    private void reverse(int[] matchsticks){
        int i = 0, j = matchsticks.length - 1;
        while(i < j){
            int temp = matchsticks[i];
            matchsticks[i] = matchsticks[j];
            matchsticks[j] = temp;
            i++;j--; 
        }
    }
    private boolean helper(int[] matchsticks, int target, int[] sides, int index){
        if(index == matchsticks.length){
            if(sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3]) {
                return true;
            }
            return false;
        }
        for(int i = 0; i < 4; ++i){
            if(sides[i] + matchsticks[index] > target) continue;
            int j = i - 1;
            while(j >= 0){
                if(sides[j] == sides[i]) break;
                j--;
            }
            if(j != -1) continue;
            sides[i] += matchsticks[index];
            if(helper(matchsticks, target,sides, index + 1)) return true;
            sides[i] -= matchsticks[index];
        }
        return false;
    }
    public boolean makesquare(int[] matchsticks) {
        if(matchsticks.length == 0) return false;
        int[] sides = new int[4];
        Arrays.fill(sides, 0);
        int sum = 0;
        for(int i = 0; i < matchsticks.length; ++i) sum += matchsticks[i];
        int target = sum/4;
        Arrays.sort(matchsticks);
        reverse(matchsticks);
        if(matchsticks[0] > target) return false;
        return helper(matchsticks, target, sides, 0);
    }
}
public class MatchstickstoSquare {
    public static void main(String[] args) {
        int[] matchsticks = {1,1,2,2,2};
        Solution s = new Solution();
        System.out.println(s.makesquare(matchsticks));

    }
}
