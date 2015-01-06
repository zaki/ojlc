/* vim:set sw=4:ts=4: */
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

class Solution {
public:
    std::string convert(std::string s, int nRows) {
        if (nRows == 1) return s;

        std::vector<string> rows;
        for (int i = 0; i < nRows; i++) rows.push_back("");

        int counter = 0, dir = 1;

        for (int i = 0; i < s.length(); i++)
        {
            rows[counter] += s[i];

            if (dir == 1  && counter == nRows - 1) { dir = -1; }
            if (dir == -1 && counter == 0)         { dir =  1; }

            counter += dir;
        }

        std::string ret = "";
        for (int i = 0; i < nRows; i++) ret += rows[i];

        return ret;
    }
};

int main()
{
    Solution s;

    std::cout << s.convert("LOREMIPSUMDOLORSITAMET", 3) << std::endl;
    return 0;
}
