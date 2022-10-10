class Solution {
    public String breakPalindrome(String palindrome) {
        int n = palindrome.length();
        char[] res = palindrome.toCharArray();
        if(n <= 1) return "";
        for(int i = 0; i < n / 2; ++i){
            if(res[i] != 'a'){
                res[i] = 'a';
                return String.valueOf(res);
            }
        }
        res[n - 1] = 'a';
        return String.valueOf(res);
    }
}
public class BreakaPalindrome {
    public static void main(String[] args) {
        String palindrome = "abccba";
        Solution s = new Solution();
        System.out.println(s.breakPalindrome(palindrome));
    }
}
