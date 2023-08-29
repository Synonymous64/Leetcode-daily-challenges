class Solution {
    public int bestClosingTime(String customers) {
        int n = customers.length();
        int penality = 0;

        for (char ch : customers.toCharArray())
            if (ch == 'N')
                penality++;

        int res = n;
        int mini = penality;

        for (int i = n - 1; i >= 0; --i) {
            if (customers.charAt(i) == 'Y')
                penality++;
            else
                penality--;
            if (penality <= mini) {
                mini = penality;
                res = i;
            }
        }
        return res;
    }
}

public class MinimumPenaltyforaShop {
    public static void main(String[] args) {
        String customers = "YYNY";
        System.out.println(new Solution().bestClosingTime(customers));
    }
}