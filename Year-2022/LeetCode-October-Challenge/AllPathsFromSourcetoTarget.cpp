#include<bits/stdc++.h>
using namespace std;
//! BFS
// class Solution {
// public:
//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//         vector<vector<int>> res;
//         queue<vector<int>> q;
//         q.push({0});
//         while(!q.empty()){
//             vector<int> path = q.front();
//             q.pop();
//             if(path.back() == graph.size() - 1) res.push_back(path);
//             for(auto child: graph[path.back()]){
//                 path.push_back(child);
//                 q.push(path);
//                 path.pop_back();
//             }
//         }
//         return res;
//     }
//     void printCode(vector<int> &nums){
//         for(int i = 0; i < nums.size(); ++i) cout<<nums[i]<<" ";
//     }
// };
//! DFS
class Solution {
public:
    int size;
    vector<int> temp;
    vector<vector<int>> res;
    void helper(vector<vector<int>> &graph, int currNode = 0){
        temp.push_back(currNode);
        if(currNode == size) res.push_back(temp);
        for(auto child: graph[currNode]){
            helper(graph, child);
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        size = graph.size() - 1;
        helper(graph);
        return res;
    }
    void printCode(vector<int> &nums){
        for(int i = 0; i < nums.size(); ++i) cout<<nums[i]<<" ";
    }
};
int main(){
    vector<vector<int>> graph = {{1,2},{3},{3},{}};
    Solution *s = new Solution();
    vector<vector<int>> res = s->allPathsSourceTarget(graph);
    for(int i = 0; i < res.size(); ++i) s->printCode(res[i]);
    return 0;
}
