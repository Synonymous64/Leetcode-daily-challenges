class Solution {
    private boolean validate(long time, int[] batteries, int n) {
        long total = 0;
        for (int x : batteries)
            total += Math.min(time,  x);
        return total >= time * n;
    }

    public long maxRunTime(int n, int[] batteries) {
        long low = 1, high = 0;
        for (int x : batteries)
            high += x;

        long res = 0;
        while (low <= high) {
            long mid = low + (high - low) / 2;
            if (validate(mid, batteries, n)) {
                res = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return res;
    }
}

public class MaximumRunningTimeofNComputers {
    public static void main(String[] args) {
        int n = 2;
        int[] batteries = { 3, 3, 3 };
        System.out.println(new Solution().maxRunTime(n, batteries));
    }
}