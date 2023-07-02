#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool isBuildingsBalanced(vector<int> &buildings){
        for(auto x: buildings)
            if(x != 0) return false;
        return true;
    }
    void calculatePossibleRequest(int n, int &possibleRequest, int requestCount, vector<int> &buildings, vector<vector<int>> &requests){
        if(isBuildingsBalanced(buildings))
            possibleRequest = max(possibleRequest, requestCount);

        if(n == requests.size()) return;

        int buildingLeaving = requests[n][0], buildingEntering = requests[n][1];
        buildings[buildingLeaving]--;
        buildings[buildingEntering]++;

        calculatePossibleRequest(n + 1, possibleRequest, requestCount + 1, buildings, requests);

        buildings[buildingLeaving]++;
        buildings[buildingEntering]--;
        calculatePossibleRequest(n + 1, possibleRequest, requestCount, buildings, requests);
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> buildings(n, 0);
        int possibleRequest = 0;
        calculatePossibleRequest(0, possibleRequest, 0, buildings, requests);
        return possibleRequest;
    }
};

int main(){
    int n = 5; vector<vector<int>> requests = {{0,1},{1,0},{0,1},{1,2},{2,0},{3,4}};
    Solution *s = new Solution();
    cout<<s->maximumRequests(n, requests)<<endl;
    return 0;
}
