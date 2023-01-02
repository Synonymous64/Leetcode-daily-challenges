import java.util.Arrays;

class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length, totalCandies = 0;
        int[] candies = new int[n];
        if(n <= 1) return 1;
        Arrays.fill(candies, 1);
        for(int i = 1; i < n; ++i){
            if(ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]){
                candies[i] = candies[i - 1] + 1;
            }
        }
        for(int i = n - 2; i >= 0; --i){
            if(ratings[i] > ratings[i + 1] && candies[i] <= candies[i +  1]){
                candies[i] = candies[i + 1] + 1;
            }
        }
        for(int i = 0; i < candies.length; ++i){
            totalCandies += candies[i];
        }
        return totalCandies;
    }
}
public class Candy {
    public static void main(String[] args) {
        int[] ratings = {1,0,2};
        Solution s = new Solution();
        System.err.println(s.candy(ratings));
    }  
}
