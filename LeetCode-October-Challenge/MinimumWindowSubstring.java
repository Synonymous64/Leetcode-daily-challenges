import java.util.*;
class Solution {
    public String minWindow(String s, String t) {
        int n = s.length();
        if(n < t.length()) return ""; 
        Map<Character, Integer> mp = new TreeMap<>();
        for(char ch: t.toCharArray()) mp.put(ch, mp.getOrDefault(ch, 0) + 1);
        int requiredCount = t.length(), minWindowSize = Integer.MAX_VALUE;
        int start = 0, i = 0, j = 0;
        while(j < n){
            char ch = s.charAt(j);
            if(mp.getOrDefault(ch, 0) > 0) requiredCount--;
            mp.put(ch, mp.getOrDefault(ch, 0) - 1);
            while(requiredCount == 0){
                int currWindowSize = j - i + 1;
                if(currWindowSize < minWindowSize){
                    minWindowSize = currWindowSize;
                    start = i;
                }
                mp.put(s.charAt(i), mp.getOrDefault(s.charAt(i), 0) + 1);
                if(mp.get(s.charAt(i)) > 0) requiredCount++;
                i++;
            }
            j++;
        }
        return minWindowSize == Integer.MAX_VALUE ? "" : s.substring(start, start + minWindowSize);
    }
}
public class MinimumWindowSubstring {
    public static void main(String[] args) {
        String s = "ADOBECODEBANC", t = "ABC";
        Solution S = new Solution();
        System.out.println(S.minWindow(s, t));
    }
}
