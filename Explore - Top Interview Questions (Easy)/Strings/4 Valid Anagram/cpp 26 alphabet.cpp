#include <array>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length()) {
            return false;
        }

        array<int, 26> count{};

        for (int i = 0; i < s.length(); ++i) {
            ++count[s[i] - 'a'];
            --count[t[i] - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) {
                return false;
            }
        }
        return true;
    }
};