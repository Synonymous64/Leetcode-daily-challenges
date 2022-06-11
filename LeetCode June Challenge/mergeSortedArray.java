public class mergeSortedArray {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = m - 1, j = n, k = m + n - 1;
        while(j >= 0){
            if(i >= 0 && nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
        int l = m + n;
        for(int indx = 0; indx < l; ++indx){
            System.out.print(nums1[indx] + " ");
        }
    }
    public static void main(String[] args) {
        int[] nums1 = {1,2,3};
        int[] nums2 = {4,5,6};
        mergeSortedArray p = new mergeSortedArray();
        int i = nums1.length, j = nums2.length;
        p.merge(nums1, i, nums2, j);
    }
}
