class Solution {
    public double myPow(double x, long n) {
        double res = 1;
        if(n == 0 || x == 1) return 1;
        else if(n < 0){
            x = 1 / x;
            n = -n;
        }

        res *= x;
        n--;
        int t = 0;

        while(n != 0){
            t++;
            if(t < n){
                res *= res;
                n -= t;
                t += t;
            } if(n > 0){
                res *= x;
                n--;
            }
        }
        return res;
    }
}
public class Pow{
    public static void main(String[] args) {
        double x = 2.00000; long n = 10;
        System.out.println(new Solution().myPow(x, n));
    }
}