#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<int, int> count;

        for (int i = 0; i < s.length(); ++i) {
            ++count[s[i]];
            --count[t[i]];
        }

        for (auto it : count) {
            if (it.second != 0) {
                return false;
            }
        }

        return true;
    }
};