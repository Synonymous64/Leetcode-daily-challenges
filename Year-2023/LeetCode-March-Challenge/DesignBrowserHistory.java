import java.util.*;

class BrowserHistory {
    private ArrayList<String> history = new ArrayList<>();
    private int curr = -1;

    public BrowserHistory(String homepage) {
        history.add(homepage);
        curr++;
    }

    public void visit(String url) {
        history.subList(curr + 1, history.size()).clear();
        history.add(url);
        curr++;
    }

    public String back(int steps) {
        curr = Math.max(0, curr - steps);
        return history.get(curr);
    }

    public String forward(int steps) {
        curr = Math.min((int)history.size() - 1, steps + curr);
        return history.get(curr);
    }
}

public class DesignBrowserHistory {
    public static void main(String[] args) {

    }
}