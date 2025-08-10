import java.util.*;

public class Solution {

    static String isValid(String s) {
        int[] freq = new int[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        Map<Integer, Integer> countMap = new HashMap<>();
        for (int f : freq) {
            if (f > 0) {
                countMap.put(f, countMap.getOrDefault(f, 0) + 1);
            }
        }

        // If all same frequency
        if (countMap.size() == 1) {
            return "YES";
        }

        // If more than 2 different frequencies, not possible
        if (countMap.size() > 2) {
            return "NO";
        }

        // Exactly two frequencies, check if one can be adjusted
        List<Integer> keys = new ArrayList<>(countMap.keySet());
        int f1 = keys.get(0), f2 = keys.get(1);
        int c1 = countMap.get(f1), c2 = countMap.get(f2);

        // Case 1: One char with frequency 1
        if ((f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1)) {
            return "YES";
        }

        // Case 2: Difference between freqs is 1 and the higher freq occurs once
        if ((Math.abs(f1 - f2) == 1) && ((f1 > f2 && c1 == 1) || (f2 > f1 && c2 == 1))) {
            return "YES";
        }

        return "NO";
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        System.out.println(isValid(s));
    }
}
