class Solution {
    public String mergeAlternately(String word1, String word2) {
        int word1Len = word1.length(), word2Len = word2.length();
        int i = 0, j = 0;
        String res = "";
        while(i < word1Len && j < word2Len){
            res += word1.charAt(i++);
            res += word2.charAt(j++);
        }
        while(i < word1Len) res += word1.charAt(i++);
        while(j < word2Len) res += word2.charAt(j++);
        return res;
    }
}
public class MergeStringsAlternately{
    public static void main(String[] args) {
        String word1 = "ab", word2 = "pqrs";
        System.out.println(new Solution().mergeAlternately(word1, word2));
    }
}