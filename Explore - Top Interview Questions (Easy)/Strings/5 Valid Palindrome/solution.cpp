#include <string>
#include <iostream>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.size();
        int p = 0;
        int q = size - 1;
        while (p < q) {
            if (!isdigit(s[p]) && !isalpha(s[p])) {
                ++p;
                continue;
            }
            if (!isdigit(s[q]) && !isalpha(s[q])) {
                --q;
                continue;
            }
            if (tolower(s[p]) != tolower(s[q])) {
                return false;
            }
            ++p;
            --q;
        }
        return true;
    }
};

int main() {
    Solution s;
    if (s.isPalindrome("")) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}