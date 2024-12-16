class Solution {
public:
  int minimizedMaximum(int n, vector<int> &quantities) {
    int64_t left = 1,
            right = *max_element(quantities.begin(), quantities.end());

    while (left < right) {
      int64_t mid = (left + right) / 2;
      int64_t stores_needed = 0;

      for (int q : quantities) {
        stores_needed += (q + mid - 1) / mid;
      }

      if (stores_needed <= n) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }
};