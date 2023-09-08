import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<>();

        for(int i = 0; i < numRows; ++i){
            int[] temp = new int[i + 1];
            Arrays.fill(temp, 1);
            for(int j = 1; j < i; ++j){
                temp[j] = res.get(i - 1).get(j - 1) + res.get(i - 1).get(j);
            }
            List<Integer> list = Arrays.stream(temp).mapToObj(Integer::valueOf).collect(Collectors.toList());
            res.add(list);
        }
        return res;
    }
    public void printCode(List<Integer> p){
        for(int i = 0; i < p.size(); ++i) System.out.print(p.get(i) + " ");
    }
}
public class PascalsTriangle {
    public static void main(String[] args) {
        int numRows = 5;
        List<List<Integer>> res = new Solution().generate(numRows);

        for(int i = 0; i < res.size(); ++i){
            new Solution().printCode(res.get(i));
        }
    }
}
