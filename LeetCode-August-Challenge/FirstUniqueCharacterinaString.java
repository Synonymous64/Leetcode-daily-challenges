import java.util.*;
class Solution {
    public int firstUniqChar(String s) {
        int[] counts = new int[26];
        Arrays.fill(counts, 0);
        for (char ch : s.toCharArray())
            counts[ch - 'a']++;
        for(int i = 0; i < s.length(); ++i)
            if(counts[s.charAt(i) - 'a'] == 1) return i;
        return -1;
    }
}
public class FirstUniqueCharacterinaString {
    public static void main(String[] args) {
        String s = "leetcode";
        Solution S = new Solution();
        System.out.println(S.firstUniqChar(s));
    }
}
