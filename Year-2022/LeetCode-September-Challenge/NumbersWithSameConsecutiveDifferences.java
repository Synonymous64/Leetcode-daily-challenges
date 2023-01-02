import java.util.*;
class Solution {
    private void DFS(int n, int k, int curr, int i, int prev, ArrayList<Integer> res){
        if(i == n - 1){
            res.add(curr);
            return;
        }
        int next = prev + k;
        if(next < 10) DFS(n, k, (curr * 10) + next, i + 1, next, res);
        next = prev - k;
        if(k != 0 && next >= 0) DFS(n, k, (curr * 10) + next, i + 1, next, res);
    }
    public int[] numsSameConsecDiff(int n, int k) {
        if(n == 1) return new int[] {0, 1, 2, 3, 4, 5, 6, 7, 9};
        ArrayList<Integer> res = new ArrayList<>();
        for(int i = 1; i <= 9; ++i) DFS(n, k, i, 0, i, res);
        int[] ans = new int[res.size()];
        for(int i = 0; i <  res.size(); ++i){
            ans[i] = res.get(i);
        }
        return ans;
    }
}
public class NumbersWithSameConsecutiveDifferences {
    public static void main(String[] args) {
        int n = 3, k= 7;
        Solution s = new Solution();
        int[] res = s.numsSameConsecDiff(n, k);
        for(int i = 0; i < res.length; ++i) System.out.print(res[i] + " ");
    }
}