#include <vector>
#include <string>
#include <map>
#include <iostream>

void backtracking(std::vector<std::string>& res, std::string& current, const std::string& digits, int index);
std::vector<std::string> letter_combinations(std::string digits);
void compareAndPrint(int idx, const std::vector<std::string>& a, const std::vector<std::string>& b);

const std::map<char, std::vector<char>> phone_keyboard = {
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y','z'}},
};

int main(void) {
    std::string digits;
    std::vector<std::string> expected;

    digits = "23";
    expected = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    compareAndPrint(1, expected, letter_combinations(digits));

    digits = "";
    expected = {};
    compareAndPrint(2, expected, letter_combinations(digits));

    digits = "2";
    expected = {"a", "b", "c"};
    compareAndPrint(3, expected, letter_combinations(digits));

    digits = "7";
    expected = {"p", "q", "r", "s"};
    compareAndPrint(4, expected, letter_combinations(digits));

    digits = "22";
    expected = {"aa", "ab", "ac", "ba", "bb", "bc", "ca", "cb", "cc"};
    compareAndPrint(5, expected, letter_combinations(digits));

    return 0;
}

void compareAndPrint(int idx, const std::vector<std::string>& a, const std::vector<std::string>& b) {
    std::cout << idx << ": " << (a == b ? "Correto" : "Incorreto") << std::endl;
}

std::vector<std::string> letter_combinations(std::string digits) {
    if (digits.length() == 0) {
        return {};
    }

    std::vector<std::string> response = {};

    std::string current;
    current.reserve(digits.length());
    backtracking(response, current, digits, 0);

    return response;
}

void backtracking(std::vector<std::string>& res, std::string& current, const std::string& digits, int index) {
    if (index == digits.length()) {
        res.push_back(current);
        return;
    }
    const std::vector<char>& letters = phone_keyboard.at(digits[index]);
    
    for (char letter : letters) {
        current.push_back(letter);
        backtracking(res, current, digits, index + 1);
        current.pop_back();
    }
}
