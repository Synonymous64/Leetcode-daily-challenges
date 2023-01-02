import java.util.*;
class Solution {
    private int helper(int index, String temp, List<String> arr){
        Set<Character> mySet = new TreeSet<>();
        for(char ch: temp.toCharArray()) mySet.add(ch);
        if(temp.length() != mySet.size()) return 0;
        int res = temp.length();
        for(int i = index; i < arr.size(); ++i) res = Math.max(res, helper(i + 1, temp + arr.get(i), arr));
        return res;
    }
    public int maxLength(List<String> arr) {
        return helper(0, "", arr);
    }
}
public class MaximumLengthofaConcatenatedStringwithUniqueCharacters {
    public static void main(String[] args) {
        List<String> arr = Arrays.asList("un","iq","ue");
        Solution s = new Solution();
        System.out.println(s.maxLength(arr));
    }
}
