class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int low = 1, high = piles[0];
        for (int x : piles)
            high = Math.max(high, x);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long count = 0;
            for (int i = 0; i < piles.length; ++i) {
                if (piles[i] < mid)
                    count++;
                else
                    count += ((piles[i] / mid) + ((piles[i] % mid) != 0 ? 1 : 0));
            }
            if (count > h)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
}

public class KokoEatingBananas {
    public static void main(String[] args) {
        int[] piles = { 3, 6, 7, 11 };
        int h = 8;
        Solution s = new Solution();
        System.out.println(s.minEatingSpeed(piles, h));
    }
}