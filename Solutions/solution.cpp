#include <vector>
#include <string>
#include <cctype>

class Solution {
public:
    std::vector<std::string> letterCasePermutation(const std::string& s);

private:
    void helper(std::string& s, int index, std::vector<std::string>& res);
};

void Solution::helper(std::string& s, int index, std::vector<std::string>& res) {
    if (index == s.size()) {
        res.push_back(s);
        return;
    }

    if (std::isalpha(s[index])) {
        s[index] = std::tolower(s[index]);
        helper(s, index + 1, res);

        s[index] = std::toupper(s[index]);
        helper(s, index + 1, res);
    } else {
        helper(s, index + 1, res);
    }
}

std::vector<std::string> Solution::letterCasePermutation(const std::string& s) {
    std::vector<std::string> res;
    std::string copy = s;
    helper(copy, 0, res);
    return res;
}
