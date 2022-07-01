import java.util.Arrays;

class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        Arrays.sort(boxTypes, (a , b) -> b[1] - a[1]);
        int ans = 0, nBoxes = 0, takenBoxes = 0, i = 0;
        for(; i < boxTypes.length; ++i){
            nBoxes += boxTypes[i][0];
            if(nBoxes <= truckSize){
                takenBoxes += boxTypes[i][0];
                ans += boxTypes[i][0] * boxTypes[i][1];
            } else break;
        }
        if(takenBoxes < truckSize && i < boxTypes.length){
            ans += (truckSize - takenBoxes) * boxTypes[i][1];
        }    
        return ans;
    }
}
public class MaximumUnitsonaTruck {
    public static void main(String[] args) {
        int[][] boxTypes = {{1,3},{2,2},{3,1}};
        int truckSize = 4;
        Solution s = new Solution();
        System.out.println(s.maximumUnits(boxTypes, truckSize));
    }
}
