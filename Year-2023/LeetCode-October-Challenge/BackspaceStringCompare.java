class Solution {
    public boolean backspaceCompare(String s, String t) {
        int sLen = s.length() - 1;
        int tLen = t.length() - 1;
        int sCount = 0, tCount = 0;

        while(sLen >= 0 && tLen >= 0){
            if(s.charAt(sLen) == '#'){
                sCount++;
                sLen--;
            } else if(t.charAt(tLen) == '#'){
                tCount++;
                tLen--;
            } else if(s.charAt(sLen) != '#' && sCount > 0){
                sCount--;
                sLen--;
            } else if(t.charAt(tLen) != '#' && tCount > 0){
                tCount--;
                tLen--;
            } else if(s.charAt(sLen) != t.charAt(tLen)) return false;
            else{
                sCount = 0;
                tCount = 0;
                sLen--;
                tLen--;
            }
        }

        while(sLen >= 0){
            if(s.charAt(sLen) == '#'){
                sCount++;
                sLen--;
            } else if(s.charAt(sLen) != '#' && sCount > 0){
                sLen--;
                sCount--;
            } else return false;
        }

        while(tLen >= 0){
            if(t.charAt(tLen) == '#'){
                tCount++;
                tLen--;
            } else if(t.charAt(tLen) != '#' && tCount > 0){
                tLen--;
                tCount--;
            } else return false;
        }

        return true;
    }
}
public class BackspaceStringCompare{
    public static void main(String[] args) {
        String s = "ab#c", t = "ad#c";
        System.out.println(new Solution().backspaceCompare(s, t));
    }
}