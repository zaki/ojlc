/* vim:set sw=4:ts=4: */
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using std::string;

class Solution {
public:
    int reverse(int x) {
        int r = 0, a = 0;
        int overflow = 2147483647;
        int sign = (x < 0 ? -1 : 1);
        if (x < 0) x = -1*x;

        while (x != 0)
        {
            a = x % 10;
            if (r > overflow / 10) return 0;
            r *= 10;

            if (r >=  overflow - a) return 0;
            r += a;

            x = x / 10;
        }

        return sign*r;
    }
};

int main()
{
  Solution s;
  std::cout << s.reverse(123)  << std::endl;
  std::cout << s.reverse(-123) << std::endl;

  return 0;
}
