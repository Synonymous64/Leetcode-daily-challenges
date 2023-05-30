class MyHashSet {
    public int size = (int) Math.pow(10, 6) + 1;
    public boolean[] myArr;

    public MyHashSet() {
        myArr = new boolean[size];
    }

    public void add(int key) {
        myArr[key] = true;
    }

    public void remove(int key) {
        myArr[key] = false;
    }

    public boolean contains(int key) {
        return myArr[key];
    }
}

public class DesignHashSet {
    public static void main(String[] args) {

    }
}