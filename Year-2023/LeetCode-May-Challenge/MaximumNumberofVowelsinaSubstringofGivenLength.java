class Solution {
    public int maxVowels(String s, int k) {
        int countVowels = 0, tempCount = 0;
        for(int i = 0; i < s.length(); ++i){
            if(s.charAt(i) == 'a' || s.charAt(i) == 'e' || s.charAt(i) == 'i' || s.charAt(i) == 'o' || s.charAt(i) == 'u') tempCount++;
            if(i - k >= 0)
                if(s.charAt(i - k) == 'a' || s.charAt(i - k) == 'e' || s.charAt(i - k) == 'i' || s.charAt(i - k) == 'o' || s.charAt(i - k) == 'u') tempCount--;
            if(tempCount > countVowels){
                countVowels = tempCount;
            }
        }
        return countVowels;
    }
}
public class MaximumNumberofVowelsinaSubstringofGivenLength{
    public static void main(String[] args) {
        String s = "abciiidef"; int k = 3;
        System.out.println(new Solution().maxVowels(s, k));
    }
}