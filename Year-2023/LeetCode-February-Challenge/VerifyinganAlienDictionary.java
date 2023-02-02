import java.util.*;

class Solution {
    private HashMap<Character, Integer> mp = new HashMap<>();

    private boolean helper(String s1, String s2) {
        int s1Size = s1.length(), s2Size = s2.length();
        int minSize = Math.min(s1Size, s2Size);
        for (int i = 0; i < minSize; ++i) {
            if (mp.get(s1.charAt(i)) < mp.get(s2.charAt(i)))
                return true;
            else if (mp.get(s1.charAt(i)) > mp.get(s2.charAt(i)))
                return false;
        }
        return s2Size >= s1Size;
    }

    public boolean isAlienSorted(String[] words, String order) {
        for (int i = 0; i < order.length(); ++i)
            mp.put(order.charAt(i), mp.getOrDefault(order.charAt(i), 0) + i);
        int n = words.length;
        for (int i = 0; i < n - 1; ++i) {
            if (!helper(words[i], words[i + 1]))
                return false;
        }
        return true;
    }
}

public class VerifyinganAlienDictionary {
    public static void main(String[] args) {
        String[] words = {"hello","leetcode"};
        String order = "hlabcdefgijkmnopqrstuvwxyz";
        Solution s = new Solution();
        System.out.println(s.isAlienSorted(words, order));
    }
}
