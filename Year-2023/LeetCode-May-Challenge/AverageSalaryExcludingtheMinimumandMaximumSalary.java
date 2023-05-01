class Solution {
    public double average(int[] salary) {
        double sum = 0;
        int minVal = Integer.MAX_VALUE, maxVal = Integer.MIN_VALUE;
        for (int x : salary) {
            sum += x;
            minVal = Math.min(minVal, x);
            maxVal = Math.max(maxVal, x);
        }
        sum -= (minVal + maxVal);
        return sum / (salary.length - 2);
    }
}

public class AverageSalaryExcludingtheMinimumandMaximumSalary {
    public static void main(String[] args) {
        int[] salary = { 4000, 3000, 1000, 2000 };
        System.out.println(new Solution().average(salary));
    }
}