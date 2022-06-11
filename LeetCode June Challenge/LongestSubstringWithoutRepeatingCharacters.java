import java.util.Arrays;
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.length() == 0) return 0;
        int[] dict = new int[256];
        Arrays.fill(dict, -1);
        int start = -1, maxLen = 0;
        char[] p = s.toCharArray();
        for(int i = 0; i < s.length(); ++i){
            if(dict[p[i]] > start){
                start = dict[p[i]];
            }
            dict[p[i]] = i;
            maxLen = Math.max(maxLen, i-start);
        }
        return maxLen;
    }
}
public class LongestSubstringWithoutRepeatingCharacters {
    public static void main(String[] args) {
        String s = "abcabcbb";
        Solution p = new Solution();
        System.out.println(p.lengthOfLongestSubstring(s));
    }
}
