class Solution {
    private boolean isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'; 
    }
    public String reverseVowels(String s) {
        int low = 0, high = s.length() - 1;
        char[] res = s.toCharArray();
        while(low < high){
            if(isVowel(s.charAt(low)) && isVowel(s.charAt(high))){
                char ch = res[low];
                res[low] = res[high];
                res[high] = ch;
                low++; high--;
            } else if(!isVowel(s.charAt(low))) low++;
            else high--;
        }
        return new String(res);
    }
}
public class ReverseVowelsofaString {
    public static void main(String[] args) {
        String s = "hello";
        Solution S = new Solution();
        System.out.println(S.reverseVowels(s));
    }
}
