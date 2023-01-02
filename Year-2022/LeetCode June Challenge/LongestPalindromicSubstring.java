class Solution {
    public String longestPalindrome(String s) {
        int start = 0, end = 0, maxLen = 0, n= s.length();
        char[] str= s.toCharArray();
        if(n <= 1) return s;
        for(int i = 0; i < n - 1; ++i){
            int left = i, right = i;
            while(left >= 0 && right < n){
                if(str[left] == str[right]){
                    --left;++right;
                }else break;
            }
            int len = right - left - 1;
            if(maxLen < len){
                maxLen = len;
                start = left + 1;
                end = right - 1;
            }
        }
        for(int i = 0; i < n - 1; ++i){
            int left = i, right = i + 1;
            while(left >= 0 && right < n){
                if(str[left] == str[right]){
                    --left;++right;
                }else break;
            }
            int len = right - left - 1;
            if(maxLen < len){
                maxLen = len;
                start = left + 1;
                end = right - 1;
            }
        }
        return s.substring(start, end + 1);
    }
}
public class LongestPalindromicSubstring {
    public static void main(String[] args) {
        Solution s = new Solution();
        String str = "bb";
        System.out.println(s.longestPalindrome(str));
    }
}
