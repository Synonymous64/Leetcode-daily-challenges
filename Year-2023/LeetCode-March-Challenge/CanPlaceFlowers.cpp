#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0; i < flowerbed.size(); ++i)
            if((flowerbed[i] == 0) && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)){
                flowerbed[i] = 1;
                n--;
            }
        return n <= 0;
    }
};
int main(){
    vector<int> flowerbed = {1,0,0,0,0,1}; int n = 2;
    Solution *s = new Solution();
    cout<<std::boolalpha<<s->canPlaceFlowers(flowerbed, n)<<endl;
    return 0;
}