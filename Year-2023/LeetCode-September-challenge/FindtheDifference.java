class Solution {
    public char findTheDifference(String s, String t) {
        char a = ' ' , b = ' ';
        for(char ch: s.toCharArray()) a += ch;
        for(char ch: t.toCharArray()) b += ch;
        return (char)(b - a);
    }
}

public class FindtheDifference{
    public static void main(String[] args) {
        String s = "abcd", t = "abcde";
        System.out.println(new Solution().findTheDifference(s, t));
    }
}