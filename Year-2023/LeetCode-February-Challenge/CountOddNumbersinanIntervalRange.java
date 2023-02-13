class Solution {
    public int countOdds(int low, int high) {
        return (high + 1)/2 - low / 2;
    }
}
public class CountOddNumbersinanIntervalRange{
    public static void main(String[] args) {
        Solution s = new Solution();
        int low = 5, high = 7;
        System.out.println(s.countOdds(low, high));
    }
}