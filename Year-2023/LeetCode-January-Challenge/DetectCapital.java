// package Year-2023.LeetCode-January-Challenge;
class Solution {
    public boolean detectCapitalUse(String word) {
        boolean isUpper = true, isLower = true;
        if(word.length() <= 1) return true;
        for(int i = 1; i < word.length(); ++i){
            if(Character.isLowerCase(word.charAt(i))) isUpper = false;
            else if(Character.isUpperCase(word.charAt(i))) isLower = false;
        }
        return isLower || (isUpper && Character.isUpperCase(word.charAt(0)));
    }
}
public class DetectCapital {
    public static void main(String[] args){
        String word = "USA";
        Solution s = new Solution();
        System.out.println(s.detectCapitalUse(word));
    }
}
