class Solution {
    public String reverseWords(String s) {
        String res = "";
        for(String ch : s.split(" ")) res += new StringBuilder(ch).reverse().toString() + " ";
        return res.trim(); 
    }
}
public class ReverseWordsinaString3{
    public static void main(String[] args) {
        String s = "Let's take LeetCode contest";
        Solution S = new Solution();
        System.out.println(S.reverseWords(s));
    }
}