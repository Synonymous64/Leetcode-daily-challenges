class Solution {
    public int concatenatedBinary(int n) {
        long val = 0;
        int i = 1;
        while(i <= n){
            val = ((val << (1 + (int)(Math.log(i)/Math.log(2)))) % 1000000007 + i) % 1000000007;
            ++i;
        }
        return (int)val;
    }
}
public class ConcatenationofConsecutiveBinaryNumbers {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.concatenatedBinary(3));
    }
}
