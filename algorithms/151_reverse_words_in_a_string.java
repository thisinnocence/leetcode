public class Solution {
    public String reverseWords(String s) {
        String[] strs = s.trim().split(" ");
        StringBuilder result= new StringBuilder();
        for (int i = 0; i < strs.length; i++) {
            if (strs[strs.length - i - 1].trim().length() > 0) {
                result.append(strs[strs.length - i - 1].trim());
                result.append(" ");
            }
        }
        return result.toString().trim();
    }
}
