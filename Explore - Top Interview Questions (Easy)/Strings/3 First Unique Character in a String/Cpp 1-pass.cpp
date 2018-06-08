#include <array>

using namespace std;

class Solution
{
  public:
    int firstUniqChar(string s)
    {
        array<int, 26> c_stat{};
        /*
            stat = 0: not tested
            stat > 0: stat - 1 is the index
            stat < 0: duplicated
        */

        for (int i = 0; i < s.length(); ++i)
        {
            int c = s[i] - 'a';

            if (c_stat[c] == 0)
            {
                c_stat[c] = i + 1;
            }
            else
            {
                c_stat[c] = -1;
            }
        }

        int result = -1;
        for (int c = 0; c < 26; ++c)
        {
            int stat = c_stat[c];

            if (stat > 0)
            {
                if (result == -1)
                {
                    result = stat - 1;
                }
                else
                {
                    result = min(result, stat - 1);
                }
            }
        }

        return result;
    }
};