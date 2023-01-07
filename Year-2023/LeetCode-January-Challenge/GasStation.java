class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int res = 0, total = 0, index = 0;
        for(int i = 0; i < gas.length; ++i){
            int consume = gas[i] - cost[i];
            total += consume;
            if(total < 0){
                index = i + 1;
                total = 0;
            }
            res += consume;
        }
        return res < 0 ? -1: index;
    }
}
public class GasStation {
    public static void main(String[] args) {
        int[] gas = {1,2,3,4,5}, cost = {3,4,5,1,2};
        Solution s = new Solution();
        System.out.println(s.canCompleteCircuit(gas, cost));
    }
}
