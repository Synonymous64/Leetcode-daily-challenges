class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        for(int i = 0; i < flowerbed.length; ++i)
            if((flowerbed[i] == 0) && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.length - 1 || flowerbed[i + 1] == 0)){
                flowerbed[i] = 1;
                n--;
            }
        return n <= 0;
    }
}
public class CanPlaceFlowers{
    public static void main(String[] args) {
        int[] flowerbed = {1,0,0,0,0,1}; int n = 2;
        System.out.println(new Solution().canPlaceFlowers(flowerbed, n));
    }
}