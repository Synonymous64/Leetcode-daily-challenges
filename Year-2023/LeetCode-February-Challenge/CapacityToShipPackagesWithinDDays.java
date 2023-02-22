class Solution {
    private boolean isValid(int[] weights, int days, int capacity) {
        int requiredDays = 1;
        int currWeight = 0;
        for (int x : weights) {
            if (currWeight + x > capacity) {
                currWeight = 0;
                requiredDays++;
            }
            currWeight += x;
        }
        if (requiredDays > days)
            return false;
        else
            return true;
    }

    public int shipWithinDays(int[] weights, int days) {
        int low = 0, high = 0;
        for (int x : weights) {
            low = Math.max(low, x);
            high += x;
        }
        int res = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(weights, days, mid)) {
                res = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return res;
    }
}

public class CapacityToShipPackagesWithinDDays {
    public static void main(String[] args) {
        int[] weights = { 3, 2, 2, 4, 1, 4 };
        int days = 3;
        Solution s = new Solution();
        System.out.println(s.shipWithinDays(weights, days));
    }
}