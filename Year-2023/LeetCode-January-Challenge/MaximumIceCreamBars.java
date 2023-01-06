import java.util.*;
class Solution {
    public int maxIceCream(int[] costs, int coins) {
        Arrays.sort(costs);
        if(costs[0] > coins) return 0;
        int count = 0;
        for(int i = 0; i < costs.length; ++i){
            if(costs[i] <= coins){
                count++;
                coins -= costs[i];
            } else return count;
        }
        return count;
    }
}
public class MaximumIceCreamBars {
    public static void main(String[] args) {
        int[] costs = {1,6,3,1,2,5}; int coins = 20;
        Solution s = new Solution();
        System.out.println(s.maxIceCream(costs, coins));
    }
}
