import java.util.*;
class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int low = 0, high = people.length - 1;
        int boatCount = 0;
        while(low <= high){
            if(people[low] + people[high] <= limit) low++;
            high--;
            boatCount++;
        }
        return boatCount;
    }
}
public class BoatstoSavePeople{
    public static void main(String[] args) {
        int[] people = {1,2}; int limit = 3;
        Solution s = new Solution();
        System.out.println(s.numRescueBoats(people, limit));
    }
}