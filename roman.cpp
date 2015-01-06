/* vim:set sw=4:ts=4: */
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using std::string;

class Solution
{
public:
    int romanToInt(string s) {
        // I: 1
        // V: 5
        // X: 10
        // L: 50
        // C: 100
        // D: 500
        // M: 1000

        int ret  = 0;
        int prev = 0;
        int curr = 0;
        for (int i = 0; i < s.length(); i++)
        {
            switch (s[i])
            {
                case 'I': curr =    1; break;
                case 'V': curr =    5; break;
                case 'X': curr =   10; break;
                case 'L': curr =   50; break;
                case 'C': curr =  100; break;
                case 'D': curr =  500; break;
                case 'M': curr = 1000; break;
            }

            if (prev > 0 && prev < curr) ret -= 2*prev;

            ret += curr;
            prev = curr;
        }

        return ret;
    }
};

int main()
{
    Solution s;

    std::cout << s.romanToInt("MMMIX") << std::endl;

    return 0;
}
