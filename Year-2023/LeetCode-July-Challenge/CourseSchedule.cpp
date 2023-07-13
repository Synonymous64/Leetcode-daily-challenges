#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool DFS(vector<int> adj[], vector<bool> &visited, int idx, vector<bool> &visitedF){
        if(visitedF[idx]) return false;
        if(visited[idx]) return true;

        visited[idx] = visitedF[idx] = true;

        for(auto node: adj[idx])
            if(!DFS(adj, visited, node, visitedF))
                return false;

        visitedF[idx] = false;

        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(int i = 0; i < prerequisites.size(); ++i)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);

        vector<bool> visited(numCourses, false), visitedF(numCourses, false);

        for(int i = 0; i < numCourses; ++i)
            if(!visited[i] && !DFS(adj, visited, i, visitedF))
                return false;

        return true;
    }
};

int main(){
    vector<vector<int>> prerequisites = {{1,0}};
    int numCourses = 2;
    Solution *s = new Solution();
    cout<<std::boolalpha<<s->canFinish(numCourses, prerequisites)<<endl;
    return 0;
}