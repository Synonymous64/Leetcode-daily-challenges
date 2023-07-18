import java.util.*;

public class LRUCache {
    private int capacity;
    private Queue<Integer> history = new LinkedList<>();
    private HashMap<Integer, Integer> counter = new HashMap<>();
    private HashMap<Integer, Integer> dict = new HashMap<>();

    public LRUCache(int capacity) {
        this.capacity = capacity;
    }

    public int get(int key) {
        if(dict.containsKey(key)){
            history.add(key);
            counter.put(key, counter.getOrDefault(key, 0) + 1);
            return dict.get(key);
        }
        return -1;
    }

    private void removeHistory(){
        while(!history.isEmpty()){
            int curr = history.poll();
            counter.put(curr, counter.get(curr) - 1);
            if(counter.get(curr) == 0){
                dict.remove(curr);
                break;
            }
        }
    }

    public void put(int key, int value) {
        history.add(key);
        counter.put(key, counter.getOrDefault(key, 0) + 1);
        dict.put(key, value);
        if(dict.size() > this.capacity) removeHistory();
        return;
    }
    public static void main(String[] args) {
        LRUCache l = new LRUCache(2);
        l.put(1,1);
        l.put(2,2);
        System.out.println(l.get(1));
    }
}
