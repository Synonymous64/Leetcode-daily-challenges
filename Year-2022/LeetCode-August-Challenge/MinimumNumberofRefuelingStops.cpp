#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int maxReach = startFuel, count = 0 , index = 0;
        priority_queue<int> pq;
        while(maxReach < target){
            while(index != stations.size() && stations[index][0] <= maxReach){
                pq.push(stations[index][1]);
                index++;
            }
            if(pq.empty()) return -1;
            maxReach += pq.top();
            pq.pop();
            count++;
        }
        return count;
    }
};
int main(){
    int target = 100, startFuel = 1;
    vector<vector<int>> stations = {{10,100}};
    Solution s;
    cout<<s.minRefuelStops(target, startFuel, stations)<<endl;
    return 0;
}