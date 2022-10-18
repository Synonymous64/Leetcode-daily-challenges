class Solution {
    public String countAndSay(int n) {
        if(n == 1) return "1";
    
        StringBuilder res = new StringBuilder();
    
        String s = countAndSay(n-1) + "0"; 
        for(int i=0, c=1; i < s.length()-1; i++, c++){
            if(s.charAt(i+1) != s.charAt(i)){
                res.append(c).append(s.charAt(i));
                c = 0;  
            }
        }
    
        return res.toString();
    }
}
public class CountandSay {
    public static void main(String[] args) {
        int n = 4;
        Solution s = new Solution();
        System.out.println(s.countAndSay(n));
    }
}
