class Solution {
    public int bulbSwitch(int n) {
        return (int)Math.sqrt(n);
    }
}
public class BulbSwitcher{
    public static void main(String[] args) {
        int n = 1;
        System.out.println(new Solution().bulbSwitch(n));
    }
}