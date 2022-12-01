class Solution {
    private boolean isVowel(char s){
        return s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'A' || s == 'E' || s == 'O' || s == 'U' || s == 'I';
    }
    public boolean halvesAreAlike(String s) {
        int half = 0;
        for(int i = 0; i < s.length() / 2; ++i) if(isVowel(s.charAt(i))) half++;
        for(int i = s.length() / 2; i < s.length(); ++i) if(isVowel(s.charAt(i))) half--;
        return half == 0;
    }
}
public class DetermineifStringHalvesAreAlike {
    public static void main(String[] args) {
        String s = "book";
        Solution S = new Solution();
        System.out.println(S.halvesAreAlike(s));
    }
}
