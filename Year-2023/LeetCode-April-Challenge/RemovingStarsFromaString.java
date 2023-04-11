class Solution {
    public String removeStars(String s) {
        int i = 0, j = 0, n = s.length();
        char[] ch = s.toCharArray();
        while(j != n){
            if(ch[j] == '*') i--;
            else ch[i++] = ch[j];
            j++;
        }
        String res = new String(ch);
        return res.substring(0, i);
    }
}
public class RemovingStarsFromaString{
    public static void main(String[] args) {
        String  s = "leet**cod*e";
        System.out.println(new Solution().removeStars(s));
    }
}