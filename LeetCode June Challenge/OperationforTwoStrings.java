
class Solution {
    public int minDistance(String word1, String word2) {
        int word1Len = word1.length(), word2Len = word2.length();
        char[] charWord1 = word1.toCharArray(), charWord2 = word2.toCharArray();
        int[][] dp = new int[word1Len + 1][word2Len + 1];
        for(int i = 1; i < word1Len + 1; ++i){
            for(int j = 1; j < word2Len + 1; ++j){
                if(charWord1[i - 1] == charWord2[ j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }else dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        } 
        return (word1Len - dp[word1Len][word2Len]) + (word2Len - dp[word1Len][word2Len]); 
    }
}
public class OperationforTwoStrings {
    public static void main(String[] args) {
        String word1 = "sea", word2 = "eat";
        Solution s = new Solution();
        System.out.println(s.minDistance(word1, word2));
    }
}
