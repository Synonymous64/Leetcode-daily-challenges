import java.util.*;
class Solution {
    public int scheduleCourse(int[][] courses) {
        Arrays.sort(courses, (a, b) -> a[1] - b[1]);
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        int time = 0;
        for(int[] course : courses){
            if(course[0] + time <= course[1]){
                time += course[0];
                maxHeap.add(course[0]);
            }
            else if(maxHeap.size() != 0 && maxHeap.peek() > course[0]){
                time += course[0] - maxHeap.poll();
                maxHeap.add(course[0]);
            }
        }
        return maxHeap.size();
    }
}
public class CourseSchedule3 {
    public static void main(String[] args) {
        int[][] courses = {{100,200},{200,1300},{1000,1250},{2000,3200}};
        Solution s = new Solution();
        System.err.println(s.scheduleCourse(courses));
    }
}
