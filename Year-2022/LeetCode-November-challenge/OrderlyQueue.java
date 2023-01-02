import java.util.*;
class Solution {
    public String orderlyQueue(String s, int k) {
        if(k == 1){
            String res = s;
            int size = s.length();
            String doubleString = s + s;
            for(int i = 1; i < size; ++i){
                String str = doubleString.substring(i, i + size);
                if(res.compareTo(str) > 0){
                    res = str;
                }
            }
            return res;
        }
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        return new String(chars);
    }
}
public class OrderlyQueue {
    public static void main(String[] args) {
        String s = "cba";
        int k = 1;
        Solution S = new Solution();
        System.out.println(S.orderlyQueue(s, k));
    }
}
