/* vim:set sw=4:ts=4: */
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using std::string;

class Solution
{
  static const int overflowP =  2147483647;
  static const int overflowM = -2147483648;
  enum State { START, SIGN, DIGITS };

  public:
    int atoi(const char *str)
    {
      int r = 0;
      int sign = 1;
      int start = 0;
      int a = 0;
      State state = START;

      for (int i = 0; i < strlen(str); i++)
      {
        if (str[i] == ' ' && state == START) continue;
        else if (str[i] == '+' && state == START) { state = SIGN; }
        else if (str[i] == '-' && state == START) { state = SIGN; sign = -1; }

        else if (str[i] >= '0' && str[i] <= '9')
        {
          state = DIGITS;
          a = str[i] - '0';

          if (sign ==  1 && r > Solution::overflowP / 10) return 0;
          if (sign == -1 && r < Solution::overflowM / 10) return 0;
          r *= 10;

          if (sign ==  1 && r > Solution::overflowP - a) return 0;
          if (sign == -1 && r < Solution::overflowM + a) return 0;
          r += sign * a;
        }
        else
          return r;

      }

      return r;
    }
};

int main()
{
  Solution s;
  int i = s.atoi("-2147483648");
  int j = s.atoi("2147483648");

  std::cout << i << std::endl;
  std::cout << j << std::endl;

  return 0;
}
