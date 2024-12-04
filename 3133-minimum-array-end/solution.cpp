class Solution {
public:
  long long minEnd(int n, int x) {
    long long res = x;
    long long i_x = 1;
    long long i_n = 1;

    while (i_n <= n - 1) {
      if ((i_x & x) == 0) {
        if (i_n & (n - 1)) {
          res = res | i_x;
        }
        i_n = i_n << 1;
      }
      i_x = i_x << 1;
    }
    return res;
  }
};