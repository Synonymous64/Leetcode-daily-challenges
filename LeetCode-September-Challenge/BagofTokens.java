import java.util.*;
class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        Arrays.sort(tokens); int i = 0, j = tokens.length - 1, score = 0, res = 0;
        while(i <= j){
            if(tokens[i] <= power){
                score++;
                power -= tokens[i++];
                if(res < score) res = score;
            } else if(score > 0){
                score--;
                power += tokens[j--];
            } else break;
        }
        return res;
    }
}
public class BagofTokens {
    public static void main(String[] args) {
        int[] tokens = {100, 200}; int power = 150;
        Solution s = new Solution();
        System.out.println(s.bagOfTokensScore(tokens, power));
    }
}
