#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<bool> visited;
    void DFS(int idx, int size, vector<vector<int>> &stones){
        visited[idx] = true;
        for(int i = 0; i < size; ++i){
            if(visited[i]) continue;
            if(stones[idx][0] == stones[i][0] || stones[idx][1] == stones[i][1]) DFS(i, size, stones);
        }
        return;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int size = stones.size(), count = 0;
        visited.resize(size, false);
        for(int i = 0; i < size; ++i){
            if(visited[i]) continue;
            count++;
            DFS(i, size, stones);
        }
        return size - count;
    }
};
int main(){
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    Solution *s = new Solution();
    cout<<s->removeStones(stones)<<endl;
    return 0;
}