import java.util.*;
class Solution {
    public boolean reorderedPowerOf2(int n) {
        char[] res1 = String.valueOf(n).toCharArray();
        Arrays.sort(res1);
        for(int i = 0; i < 30; ++i){
            char[] res2 = String.valueOf(1 << i).toCharArray();
            Arrays.sort(res2);
            if(Arrays.equals(res1, res2)) return true;
        }
        return false;
    }
}
public class ReorderedPowerof2{
    public static void main(String[] args) {
        int n = 32;
        Solution s = new Solution();
        System.out.println(s.reorderedPowerOf2(n));
    }
}