class Solution {
    public String removeDuplicates(String s) {
        StringBuilder res = new StringBuilder();
        for(char ch: s.toCharArray()){
            if(res.length() != 0  && res.charAt(res.length() - 1) == ch){
                res.deleteCharAt(res.length() - 1);
            } else res.append(ch);
        }
        return res.toString();
    }
}
public class RemoveAllAdjacentDuplicatesInString {
    public static void main(String[] args) {
        String s = "abbaca";
        Solution S = new Solution();
        System.out.println(S.removeDuplicates(s));
    }
}
