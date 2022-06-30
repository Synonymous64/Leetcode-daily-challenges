class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int sum = 0, maxSum = 0, n = cardPoints.length;
        for(int i = 0; i < k; ++i){
            sum += cardPoints[i];
        }        
        maxSum = sum;
        for(int i = k - 1; i >=0; --i){
            sum -= cardPoints[i];
            sum += cardPoints[n - k + i];
            maxSum = Math.max(maxSum, sum);
        }
        return maxSum;
    }
}
public class MaximumPointsYouCanObtainfromCards {
    public static void main(String[] args) {
        int[] cardPoints = {1,2,3,4,5,6,1};
        int k = 3;
        Solution s = new Solution();
        System.out.println(s.maxScore(cardPoints, k));
    }
}
