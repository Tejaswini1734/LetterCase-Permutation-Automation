package tests;

import java.util.*;

import solutions.Solution;

public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();

        String[] testInputs = {
            "a1b", "3z4", "12345", "0", "A", "ab", "a1B2", "C", "c7D8e", "Zz"
        };

        String[][] expectedOutputs = {
            {"a1b", "a1B", "A1b", "A1B"},
            {"3z4", "3Z4"},
            {"12345"},
            {"0"},
            {"a", "A"},
            {"ab", "aB", "Ab", "AB"},
            {"a1b2", "a1B2", "A1b2", "A1B2"},
            {"c", "C"},
            {"c7d8e", "c7d8E", "c7D8e", "c7D8E", "C7d8e", "C7d8E", "C7D8e", "C7D8E"},
            {"zz", "zZ", "Zz", "ZZ"}
        };

        boolean allPassed = true;

        for (int i = 0; i < testInputs.length; i++) {
            String input = testInputs[i];
            List<String> actual = sol.letterCasePermutation(input);
            List<String> expected = Arrays.asList(expectedOutputs[i]);

            Collections.sort(actual);
            Collections.sort(expected);

            System.out.println("Test Case " + (i + 1) + ": \"" + input + "\"");
            System.out.println("Expected: " + expected);
            System.out.println("Actual:   " + actual);

            boolean passed = actual.equals(expected);

            if (passed) {
                System.out.println("✅ Test Case " + (i + 1) + " Passed");
            } else {
                System.out.println("❌ Test Case " + (i + 1) + " Failed");
                allPassed = false;
            }

            System.out.println("--------------------------");
        }

        if (!allPassed) {
            throw new AssertionError("❌ Some test cases failed.");
        } else {
            System.out.println("🎉 All test cases passed!");
        }
    }
}
