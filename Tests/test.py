import sys
import os
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '../Solutions')))

from solution import Solution

def test():
    sol = Solution()
    test_inputs = [
        "a1b", "3z4", "12345", "0", "A", "ab", "a1B2", "C", "c7D8e", "Zz"
    ]

    expected_outputs = [
        ["a1b", "a1B", "A1b", "A1B"],
        ["3z4", "3Z4"],
        ["12345"],
        ["0"],
        ["a", "A"],
        ["ab", "aB", "Ab", "AB"],
        ["a1b2", "a1B2", "A1b2", "A1B2"],
        ["c", "C"],
        ["c7d8e", "c7d8E", "c7D8e", "c7D8E", "C7d8e", "C7d8E", "C7D8e", "C7D8E"],
        ["zz", "zZ", "Zz", "ZZ"]
    ]

    all_passed = True

    for i, s in enumerate(test_inputs):
        actual = sol.letterCasePermutation(s)
        expected = expected_outputs[i]

        actual.sort()
        expected.sort()

        print(f"Test Case {i + 1}: \"{s}\"")
        print("Expected:", expected)
        print("Actual:  ", actual)

        if actual == expected:
            print(f"✅ Test Case {i + 1} Passed")
        else:
            print(f"❌ Test Case {i + 1} Failed")
            all_passed = False
        print("--------------------------")

    if all_passed:
        print("🎉 All test cases passed!")
    else:
        raise AssertionError("❌ Some test cases failed.")

if __name__ == "__main__":
    test()
