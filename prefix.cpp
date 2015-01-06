/* vim:set sw=4:ts=4: */
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using std::string;
using std::vector;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix = "";
        char x;

        for (int i = 0; i < strs[0].length(); i++)
        {
            x = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j].length() < i || x != strs[j][i]) return prefix;
            }

            prefix += x;
        }

        return prefix;
    }
};

int main()
{
    Solution s;
    vector<string> arr;
    arr.push_back("daa");
    arr.push_back("abb");
    arr.push_back("aaaa");
    arr.push_back("aacaaa");

    std::cout << s.longestCommonPrefix(arr) << std::endl;

    return 0;
}
