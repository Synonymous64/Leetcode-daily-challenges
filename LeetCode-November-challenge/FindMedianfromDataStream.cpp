#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:    
    void addNum(int num) {
        if(maxHeap.empty() && minHeap.empty()) maxHeap.push(num);
        else{
            if(maxHeap.top() < num) minHeap.push(num);
            else maxHeap.push(num);
        }
        int minSize = minHeap.size(), maxSize = maxHeap.size();
        if(minSize - maxSize == 2 || minSize - maxSize == -2){
            if(minSize > maxSize){
                int ele = minHeap.top();
                minHeap.pop();
                maxHeap.push(ele);
            }else{
                int ele = maxHeap.top();
                maxHeap.pop();
                minHeap.push(ele);
            }
        }
    }
    double findMedian() {
        int minSize = minHeap.size(), maxSize = maxHeap.size();
        if((minSize + maxSize) % 2 == 0)
            return (((double) minHeap.top()) + ((double) maxHeap.top())) / 2.0;
        if(minSize > maxSize) return minHeap.top();
        return maxHeap.top();
    }
};
int main(){
    MedianFinder *m = new MedianFinder();
    m->addNum(1);
    m->addNum(2);
    cout<<m->findMedian()<<endl;
    m->addNum(3);
    cout<<m->findMedian()<<endl;
}