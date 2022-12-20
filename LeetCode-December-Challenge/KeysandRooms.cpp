#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        vector<int> visited(rooms.size(), false);
        q.push(0), visited[0] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto x: rooms[curr]){
                if(!visited[x]){
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        for(auto x: visited) if(!x) return false;
        return true;
    }
};
int main(){
    vector<vector<int>> rooms = {{1,3},{3,0,1},{2},{0}};
    Solution *s = new Solution();
    cout<<std::boolalpha<<s->canVisitAllRooms(rooms)<<endl;
    return 0;
}