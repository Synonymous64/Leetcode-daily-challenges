import java.util.*;

class Solution {
    private HashSet<List<Integer>> mySet = new HashSet<>();

    private void helper(int[] nums, ArrayList<Integer> temp, int idx) {
        if (idx == nums.length) {
            if (temp.size() > 1) {
                mySet.add(new ArrayList<Integer>(temp));
            }
            return;
        }
        int curr = nums[idx], prev = temp.size() == 0 ? -101 : temp.get(temp.size() - 1);
        if (curr >= prev) {
            temp.add(curr);
            helper(nums, temp, idx + 1);
            temp.remove(temp.size() - 1);
            helper(nums, temp, idx + 1);
        } else
            helper(nums, temp, idx + 1);
        return;
    }

    public List<List<Integer>> findSubsequences(int[] nums) {
        helper(nums, new ArrayList<>(), 0);
        return new ArrayList<List<Integer>>(mySet);
    }
}

public class NondecreasingSubsequences {
    public static void main(String[] args) {

    }
}
