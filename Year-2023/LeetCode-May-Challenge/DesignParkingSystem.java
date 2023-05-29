class ParkingSystem {
    private int bigPark;
    private int mediumPark;
    private int smallPark;

    public ParkingSystem(int big, int medium, int small) {
        this.bigPark = big;
        this.mediumPark = medium;
        this.smallPark = small;
    }

    public boolean addCar(int carType) {
        if (carType == 1 && bigPark > 0) {
            bigPark--;
            return true;
        } else if (carType == 2 && mediumPark > 0) {
            mediumPark--;
            return true;
        } else if (carType == 3 && smallPark > 0) {
            smallPark--;
            return true;
        }
        return false;
    }
}

public class DesignParkingSystem {
    public static void main(String[] args) {
        ParkingSystem p = new ParkingSystem(1, 1, 0);
        System.out.println(p.addCar(1));
        System.out.println(p.addCar(2));
        System.out.println(p.addCar(3));
        System.out.println(p.addCar(1));
    }
}