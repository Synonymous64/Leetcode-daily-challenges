class Solution {
    public int minCost(String colors, int[] neededTime) {
        int i = 0, j = 0, n = neededTime.length, totalTime = 0;
        while(i < n && j < n){
            int currTime = 0, maxTime = 0;
            while(j < n && colors.charAt(i) == colors.charAt(j)){
                maxTime = Math.max(maxTime, neededTime[j]);
                currTime += neededTime[j];
                ++j;
            }
            i = j;
            totalTime += (currTime - maxTime);
        }
        return totalTime;
    }
}
public class MinimumTimetoMakeRopeColorful {
    public static void main(String[] args) {
        String colors = "aaabbbabbbb";
        int[] neededTime = {3,5,10,7,5,3,5,5,4,8,1};
        Solution s = new Solution();
        System.out.println(s.minCost(colors, neededTime));
    }
}

