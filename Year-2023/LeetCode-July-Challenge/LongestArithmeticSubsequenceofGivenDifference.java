import java.util.*;

class Solution {
    public int longestSubsequence(int[] arr, int difference) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int res = 1;

        for (int x : arr) {
            if (mp.containsKey(x - difference))
                mp.put(x, mp.get(x - difference) + 1);
            else
                mp.put(x, 1);
            res = Math.max(res, mp.get(x));
        }
        return res;
    }
}

public class LongestArithmeticSubsequenceofGivenDifference {
    public static void main(String[] args) {
        int arr[] = { 1, 2, 3, 4 };
        int difference = 1;

        System.out.println(new Solution().longestSubsequence(arr, difference));
    }
}
