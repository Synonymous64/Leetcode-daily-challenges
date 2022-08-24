class Solution {
    public boolean isPowerOfThree(int n) {
        // while(n >= 3){
        //     if(n % 3 != 0) return false;
        //     n = n / 3;
        // }
        // return n == 1;
        if( n < 1) return false;
        if(n == 1) return true;
        if(n % 3 != 0) return false;
        return isPowerOfThree(n / 3);
    }
}
public class PowerofThree {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.isPowerOfThree(27));
    }
}
