#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> visited;
        queue<string> q; int count = 0;
        visited.insert(start);
        q.push(start);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string node = q.front();
                q.pop();
                if(node == end) return count;
                for(auto ch: "ACGT"){
                    for(int i = 0; i < node.size(); ++i){
                        string adjNode = node;
                        adjNode[i] = ch;
                        if(!visited.count(adjNode) && find(bank.begin(), bank.end(), adjNode) != bank.end()){
                            visited.insert(adjNode);
                            q.push(adjNode);
                        }
                    }
                }
            }
            count++;
        }
        return -1;
    }
};
int main(){
    string start = "AACCGGTT", end = "AACCGGTA"; vector<string> bank = {"AACCGGTA"};
    Solution s;
    cout<<s.minMutation(start, end, bank)<<endl;
    return 0;
}