import java.util.*;
class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        char[] ch = searchWord.toCharArray();
        Arrays.sort(products);
        List<List<String>> ans = new ArrayList<>();
        int n = products.length, start = 0, end = n - 1;
        for(int i = 0; i < searchWord.length(); ++i){
            while(start <= end && (i >= products[start].length() || products[start].codePointAt(i) < ch[i])) ++start;
            while(start <= end && (i >= products[end].length() || products[end].codePointAt(i) > ch[i])) ++start;
            for(int j = start; j < Math.min(start + 3, end + 1); ++j){}
        }
    }
}
public class SearchSuggestionsSystem {
    public static void main(String[] args) {
        
    }
}
