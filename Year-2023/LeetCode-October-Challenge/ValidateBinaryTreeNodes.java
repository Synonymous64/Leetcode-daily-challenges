import java.util.*;

class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        int count = n - 1;
        int[] parent = new int[n];
        int[] visited = new int[n];

        Arrays.fill(parent, -1);
        Arrays.fill(visited, 0);

        for(int i = 0; i < n; ++i){
            if(leftChild[i] == -1) continue;
            if(visited[leftChild[i]] == 1) return false;
            int temp = parent[i];
            while(temp != -1){
                if(temp == leftChild[i]) return false;
                temp = parent[temp];
            }

            parent[leftChild[i]] = i;
            visited[leftChild[i]] = 1;
            count--;
        }

        for(int i = 0; i < n; ++i){
            if(rightChild[i] == -1) continue;
            if(visited[rightChild[i]] == 1) return false;
            int temp = parent[i];
            while(temp != -1){
                if(temp == rightChild[i]) return false;
                temp = parent[temp];
            }

            parent[rightChild[i]] = i;
            visited[rightChild[i]] = 1;
            count--;
        }

        return count == 0;
    }
}

public class ValidateBinaryTreeNodes{
    public static void main(String[] args) {
        int n = 4;
        int[] leftChild = {1,-1,3,-1}, rightChild = {2,-1,-1,-1};
        System.out.println(new Solution().validateBinaryTreeNodes(n, leftChild, rightChild));
    }
}