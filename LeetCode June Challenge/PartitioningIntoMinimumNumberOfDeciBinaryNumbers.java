class Solution {
    public int minPartitions(String n) {
        char temp = '0';
        for(int i =0; i < n.length(); ++i){
            if(temp < n.charAt(i)){
                temp = n.charAt(i);
            }
        }
        return temp -'0';
    }
}
public class PartitioningIntoMinimumNumberOfDeciBinaryNumbers {
    public static void main(String[] args) {
        String n = "27346209830709182346";
        Solution s = new Solution();
        System.out.println(s.minPartitions(n));
    }
}