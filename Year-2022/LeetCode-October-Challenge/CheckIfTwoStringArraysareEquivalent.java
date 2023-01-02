class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        int wordIdx1 = 0, wordIdx2 = 0;
        int idx1 = 0, idx2 = 0;
        while(wordIdx1 < word1.length && wordIdx2 < word2.length){
            if(word1[wordIdx1].charAt(idx1) != word2[wordIdx2].charAt(idx2)) return false;
            idx1++; idx2++;
            if(idx1 == word1[wordIdx1].length()){
                idx1 = 0;
                wordIdx1++;
            }
            if(idx2 == word2[wordIdx2].length()){
                idx2 = 0;
                wordIdx2++;
            }
        }
        return wordIdx1 == word1.length && wordIdx2 == word2.length;
    }
}
public class CheckIfTwoStringArraysareEquivalent{
    public static void main(String[] args) {
        String[] word1 = {"ab", "c"}, word2 = {"a", "bc"};
        Solution s = new Solution();
        System.out.println(s.arrayStringsAreEqual(word1, word2));
    }
}