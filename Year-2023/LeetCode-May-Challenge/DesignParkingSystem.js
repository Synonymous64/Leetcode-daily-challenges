var ParkingSystem = function (big, medium, small) {
    this.bigPark = big;
    this.mediumPark = medium;
    this.smallPark = small;
};

ParkingSystem.prototype.addCar = function (carType) {
    if (carType === 1 && this.bigPark) {
        --this.bigPark;
        return true;
    } else if (carType === 2 && this.mediumPark) {
        --this.mediumPark;
        return true;
    } else if (carType === 3 && this.smallPark) {
        --this.smallPark;
        return true;
    }
    return false;
};

let p = new ParkingSystem(1, 1, 0);
console.log(p.addCar(1));
console.log(p.addCar(2));
console.log(p.addCar(3));
console.log(p.addCar(1));