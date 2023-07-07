class Solution {
    public int maxConsecutiveAnswers(String answerKey, int k) {
        int T = 0, F = 0, curr = 0, res = 0;

        for(int i = 0; i < answerKey.length(); ++i){
            if(answerKey.charAt(i) == 'T') T++;
            else F++;
            if(Math.min(T, F) > k){
                if(answerKey.charAt(curr) == 'T')T--;
                else F--;
                ++curr;
            }
            res = Math.max(res, T + F);
        }
        return res;
    }
}
public class MaximizetheConfusionofanExam{
    public static void main(String[] args) {
        String answerKey = "TTFF"; int k = 2;
        System.out.println(new Solution().maxConsecutiveAnswers(answerKey, k));
    }
}