#include<bits/stdc++.h>
using namespace std;
class ParkingSystem {
private:
    int bigPark;
    int mediumPark;
    int smallPark;
public:
    ParkingSystem(int big, int medium, int small) {
        this->bigPark = big;
        this->mediumPark = medium;
        this->smallPark = small;
    }

    bool addCar(int carType) {
        if(carType == 1 && bigPark){
            bigPark--;
            return true;
        } else if(carType == 2 && mediumPark){
            mediumPark--;
            return true;
        } else if(carType == 3 && smallPark){
            smallPark--;
            return true;
        }
        return false;
    }
};

int main(){
    ParkingSystem *p = new ParkingSystem(1, 1, 0);
    cout<<std::boolalpha<<p->addCar(1)<<endl;
    cout<<std::boolalpha<<p->addCar(2)<<endl;
    cout<<std::boolalpha<<p->addCar(3)<<endl;
    cout<<std::boolalpha<<p->addCar(1)<<endl;
    return 0;
}
