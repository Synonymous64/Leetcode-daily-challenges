#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        string res = ""; int count = 1;
        res = chars[0];

        for(int i = 1; i < chars.size(); ++i){
            if(chars[i] == chars[i - 1]) count++;
            else{
                if(count > 1) res = res + to_string(count);
                count = 1;
                res.push_back(chars[i]);
            }
        }
        if(count > 1) res = res + to_string(count);
        for(int i = 0; i < res.length(); ++i) chars[i] = res[i];
        return res.size();
    }
};

int main(){
    vector<char> chars = {'a','a','b','b','c','c','c'};
    Solution *s = new Solution();
    cout<<s->compress(chars)<<endl;
    return 0;
}