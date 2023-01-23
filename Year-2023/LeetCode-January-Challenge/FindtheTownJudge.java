class Solution {
    public int findJudge(int n, int[][] trust) {
        int[] in = new int[n + 1], out = new int[n + 1];
        for(int[] x: trust){
            in[x[1]]++;
            out[x[0]]++;
        }
        int res = -1;
        for(int i = 1; i <= n; ++i)
            if(in[i] == n - 1 && out[i] == 0) return res = i;
        return res;
    }
}
public class FindtheTownJudge {
    public static void main(String[] args) {
        int n = 2;
        int[][] trust = {{1,2}};
        Solution s = new Solution();
        System.out.println(s.findJudge(n, trust));
    }
}
