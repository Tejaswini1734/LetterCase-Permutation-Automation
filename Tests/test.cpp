#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "../Solutions/solution.cpp"  // Make sure the path is correct and solution.cpp has no main()

int main() {
    Solution sol;

    std::string testInputs[] = {
        "a1b", "3z4", "12345", "0", "A", "ab", "a1B2", "C", "c7D8e", "Zz"
    };

    std::vector<std::vector<std::string>> expectedOutputs = {
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

    bool allPassed = true;

    for (int i = 0; i < 10; ++i) {
        std::vector<std::string> actual = sol.letterCasePermutation(testInputs[i]);
        std::vector<std::string> expected = expectedOutputs[i];

        std::sort(actual.begin(), actual.end());
        std::sort(expected.begin(), expected.end());

        std::cout << "Test Case " << (i + 1) << ": \"" << testInputs[i] << "\"\n";
        std::cout << "Expected: ";
        for (auto& e : expected) std::cout << e << " ";
        std::cout << "\nActual: ";
        for (auto& a : actual) std::cout << a << " ";
        std::cout << "\n";

        if (actual == expected) {
            std::cout << "✅ Test Case " << (i + 1) << " Passed\n";
        } else {
            std::cout << "❌ Test Case " << (i + 1) << " Failed\n";
            allPassed = false;
        }
        std::cout << "--------------------------\n";
    }

    if (!allPassed) {
        std::cerr << "❌ Some test cases failed.\n";
        return 1;
    } else {
        std::cout << "🎉 All test cases passed!\n";
        return 0;
    }
}
