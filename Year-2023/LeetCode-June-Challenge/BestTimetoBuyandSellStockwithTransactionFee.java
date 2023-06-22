class Solution {
    public int maxProfit(int[] prices, int fee) {
        int profit = 0, effectiveBuyPrice = prices[0];

        for(int i = 0; i < prices.length; ++i){
            profit = Math.max(profit, prices[i] - effectiveBuyPrice - fee);
            effectiveBuyPrice = Math.min(effectiveBuyPrice, prices[i] - profit);
        }
        return profit;
    }
}
public class BestTimetoBuyandSellStockwithTransactionFee{
    public static void main(String[] args) {
        int[] prices = {1,3,2,8,4,9}; int fee = 2;
        System.out.println(new Solution().maxProfit(prices, fee));
    }
}