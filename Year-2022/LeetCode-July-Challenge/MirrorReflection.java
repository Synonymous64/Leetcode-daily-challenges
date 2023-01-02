class Solution {
    public int mirrorReflection(int p, int q) {
        int extension = q, reflection = p;
        while(extension % 2 == 0 && reflection % 2 == 0){
            extension /= 2;
            reflection /= 2;
        }
        if(extension % 2 == 0 && reflection % 2 != 0) return 0;
        if(extension % 2 != 0 && reflection % 2 == 0) return 2;
        if(extension % 2 != 0 && reflection % 2 != 0) return 1;
        return -1;
    }
}
public class MirrorReflection{
    public static void main(String[] args){
        Solution s = new Solution();
        int p = 2, q = 1;
        System.out.println(s.mirrorReflection(p, q));

    }
}