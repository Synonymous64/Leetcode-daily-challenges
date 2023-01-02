import java.util.Arrays;

class Solution {
    public int earliestFullBloom(int[] plantTime, int[] growTime) {
        int n = plantTime.length;
        int[][] days = new int[n][2];
        for(int i = 0; i < n; ++i) {
            days[i][0] = plantTime[i];
            days[i][1] = growTime[i];
        }
        Arrays.sort(days, (a, b)-> b[1] - a[1]);
        int start = 0, res = 0;
        for(int i = 0; i < days.length; ++i){
            start += days[i][0];
            res = Math.max(res, start + days[i][1]);
        }
        return res;
    }
}
public class EarliestPossibleDayofFullBloom {
    public static void main(String[] args) {
        int[] plantTime = {1,4,3}, growTime = {2,3,1};
        Solution s = new Solution();
        System.out.println(s.earliestFullBloom(plantTime, growTime));
    }
}
