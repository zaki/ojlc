/* vim:set sw=4:ts=4: */
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using std::string;

class Solution
{
  static const int overflowP =  2147483647;
  static const int overflowM = -2147483648;

  int digit(int x, int c) { return x % (int)pow(10, c+1) / (int)pow(10, c); }

public:
    bool isPalindrome(int x)
    {
        if (x < 0) return false;
        int a = (int)floor(log10(x))+1;
        for (int i = 0; i < a / 2; i++)
        {
            if (digit(x, i) != digit(x, a - i - 1)) return false;
        }

        return true;
    }
};

int main()
{
    Solution s;

    std::cout << s.isPalindrome(192291);

    return 0;
}
