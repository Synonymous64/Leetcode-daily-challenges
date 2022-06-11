public class RunningSumof1dArray{
    public int[] runningSum(int[] nums) {
        if(nums.length == 0) return null;
        for(int i = 1; i < nums.length; ++i)
            nums[i] += nums[i - 1];
        return nums;
    }
    public void displayCode(int[] nums){
        for(int i = 0; i < nums.length; ++i)
            System.out.println(nums[i]);
    }
    public static void main(String[] args) {
        int[] nums = {1,2,3,4};
        RunningSumof1dArray p = new RunningSumof1dArray();
        int[] ans = p.runningSum(nums);
        p.displayCode(ans);
        
    }
}