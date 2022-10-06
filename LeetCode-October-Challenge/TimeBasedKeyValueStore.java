import java.util.*;

class TimeMap {
    private HashMap<String, TreeMap<Integer, String>> mp = new HashMap<>();

    public TimeMap() {
    }

    public void set(String key, String value, int timestamp) {
        if (!mp.containsKey(key)) {
            mp.put(key, new TreeMap<>());
        }
        mp.get(key).put(timestamp, value);
    }

    public String get(String key, int timestamp) {
        TreeMap<Integer, String> treeMap = mp.get(key);
        if (treeMap == null)
            return "";
        Integer floor = treeMap.floorKey(timestamp);
        if (floor == null)
            return "";
        return treeMap.get(floor);
    }
}

public class TimeBasedKeyValueStore {
    public static void main(String[] args) {
        TimeMap t = new TimeMap();
        t.set("foo", "bar", 1);
        System.out.println(t.get("foo", 1));
        System.out.println(t.get("foo", 3));
        t.set("foo", "bar2", 4);
        System.out.println(t.get("foo", 4));
        System.out.println(t.get("foo", 5));
    }
}
