class Solution {
    public int removePalindromeSub(String s) {
        if(s.isEmpty()) return 0;
        int n = s.length(), i = 0, j = n - 1;
        while(i <= j){
            if(s.charAt(i) != s.charAt(j)) return 2;
            else {i++; j--;}
        }
        return 1;
    }
}
public class RemovePaldindromicSubsequence {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.removePalindromeSub("aaba"));
    }
}
