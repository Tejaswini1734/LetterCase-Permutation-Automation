package Tests;

import java.util.List;
import java.util.Arrays;
import java.util.Collections;
import Solutions.Solution;

public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();

        String[] inputs = {
            "a1b2",          // mixed letters and digits
            "3z4",           // one letter
            "123",           // digits only
            "ABC",           // uppercase only
            "abc",           // lowercase only
            "a",             // single lowercase letter
            "Z",             // single uppercase letter
            "0",             // single digit
            "",              // empty string
            "a1B2c3"         // mixed with uppercase and lowercase letters & digits
        };

        String[][] expectedOutputs = {
            {"a1b2", "a1B2", "A1b2", "A1B2"},
            {"3z4", "3Z4"},
            {"123"},
            {"ABC", "aBC", "AbC", "ABc", "abC", "aBc", "Abc", "abc"},
            {"abc", "Abc", "aBc", "abC", "ABc", "aBC", "AbC", "ABC"},
            {"a", "A"},
            {"Z", "z"},
            {"0"},
            {""},
            {"a1b2c3", "a1b2C3", "a1B2c3", "a1B2C3", "A1b2c3", "A1b2C3", "A1B2c3", "A1B2C3"}
        };

        boolean allPassed = true;

        for (int i = 0; i < inputs.length; i++) {
            String input = inputs[i];
            List<String> actual = sol.letterCasePermutation(input);
            List<String> expected = Arrays.asList(expectedOutputs[i]);

            Collections.sort(actual);
            Collections.sort(expected);

            if (actual.equals(expected)) {
                System.out.println("Test #" + (i + 1) + " passed.");
            } else {
                System.out.println("Test #" + (i + 1) + " failed.");
                System.out.println("Expected: " + expected);
                System.out.println("Got:      " + actual);
                allPassed = false;
            }
        }

        if (allPassed) {
            System.out.println("\n🎉 All tests passed!");
        } else {
            System.out.println("\nSome tests failed.");
        }
    }
}
