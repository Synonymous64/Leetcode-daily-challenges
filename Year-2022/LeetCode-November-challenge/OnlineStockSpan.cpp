#include<bits/stdc++.h>
using namespace std;
class StockSpanner {
private:
    stack<pair<int,int>> myStack;
public:
    int next(int price) {
        int res = 1;
        while(!myStack.empty() && price >= myStack.top().first){
            res += myStack.top().second;
            myStack.pop();
        }
        myStack.push({price, res});
        return res;
    }
};
int main(){
    StockSpanner *re = new StockSpanner();
    cout<<re->next(100)<<endl;
    cout<<re->next(80)<<endl;
    cout<<re->next(60)<<endl;
    cout<<re->next(70)<<endl;
    cout<<re->next(60)<<endl;
    cout<<re->next(75)<<endl;
    cout<<re->next(85)<<endl;
    return 0;
}