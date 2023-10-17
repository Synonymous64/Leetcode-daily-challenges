#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int count = n - 1;
        vector<int> parent(n, -1);
        vector<int> visited(n, 0);

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
};

int main(){
    int n = 4;
    vector<int> leftChild = {1,2,0,-1}, rightChild = {-1,-1,-1,-1};
    Solution *s = new Solution();
    cout<<boolalpha<<s->validateBinaryTreeNodes(n, leftChild, rightChild)<<endl;
    return 0;
}