class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if(str1.length() < str2.length()) return gcdOfStrings(str2, str1);
        if(str2.isEmpty()) return str1;
        if(!str1.startsWith(str2)) return "";
        return gcdOfStrings(str1.substring(str2.length()), str2);
    }
}
public class GreatestCommonDivisorofStrings {
    public static void main(String[] args) {
        String str1 = "ABCABC", str2 = "ABC";
        Solution s = new Solution();
        System.out.println(s.gcdOfStrings(str1, str2));
    }
}
