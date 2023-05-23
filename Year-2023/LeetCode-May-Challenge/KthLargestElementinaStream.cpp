#include<bits/stdc++.h>
using namespace std;
class KthLargest {
private:
    int kth;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(auto x: nums) add(x);
    }

    int add(int val) {
        if(pq.size() < kth) pq.push(val);
        else if(pq.top() < val) pq.pop(), pq.push(val);
        return pq.top();g
    }
};

int main(){
    vector<int> nums = {4,5,8,2};
    int k = 3;
    KthLargest *s = new KthLargest(k, nums);
    cout<<s->add(3)<<endl;
    cout<<s->add(5)<<endl;
    cout<<s->add(10)<<endl;
    cout<<s->add(9)<<endl;
    cout<<s->add(4)<<endl;
    return 0;
}
