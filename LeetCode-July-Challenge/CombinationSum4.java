import java.util.Arrays;

class Solution {
    private int combination(int[] nums, int target, int[] res){
        if(target < 0) return 0;
        if(target == 0) return 1;
        int ans = 0;
        if(res[target] != -1) return res[target];
        for(int i = 0; i < nums.length; ++i){
            ans += combination(nums, target - nums[i], res);
        }
        return res[target] = ans;
    }
    public int combinationSum4(int[] nums, int target) {
        int[] res = new int[target + 1];
        Arrays.fill(res, -1);
        return combination(nums, target, res); 
    }
}
public class CombinationSum4 {
    public static void main(String[] args) {
        int[] nums = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111};
        int target = 999;
        Solution s = new Solution();
        System.out.println(s.combinationSum4(nums, target));
    }
}
