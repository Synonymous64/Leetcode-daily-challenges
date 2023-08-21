class Solution {
    public boolean repeatedSubstringPattern(String str) {
        String s = str + str;
        return s.substring(1, s.length() - 1).contains(str);
    }
}

public class RepeatedSubstringPattern {
    public static void main(String[] args) {
        String s = "abab";
        System.out.println(new Solution().repeatedSubstringPattern(s));
    }
}