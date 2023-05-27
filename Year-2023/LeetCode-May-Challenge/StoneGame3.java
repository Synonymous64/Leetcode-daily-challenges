import java.util.*;

class Solution {
    public String stoneGameIII(int[] stoneValue) {
        int[] score = new int[stoneValue.length];
        Arrays.fill(score, 0);

        for (int i = score.length - 1; i >= 0; --i) {
            int take = 0;
            int best = Integer.MIN_VALUE;
            for (int j = 0; j < 3 && i + j < stoneValue.length; ++j) {
                take += stoneValue[i + j];
                int opponent = (i + j + 1 < stoneValue.length) ? score[i + j + 1] : 0;
                best = Math.max(best, take - opponent);
            }
            score[i] = best;
        }
        return score[0] > 0 ? "Alice" : score[0] == 0 ? "Tie" : "Bob";
    }
}

public class StoneGame3 {
    public static void main(String[] args) {
        int[] values = { 1, 2, 3, 7 };
        System.out.println(new Solution().stoneGameIII(values));
    }
}