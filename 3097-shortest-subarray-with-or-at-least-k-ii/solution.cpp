class Solution {
public:
  int minimumSubarrayLength(vector<int> &nums, int k) {
    int res = numeric_limits<int>::max();
    vector<int> bits(32);

    int l = 0;
    for (int r = 0; r < nums.size(); r++) {
      bitsUpdate(bits, nums[r], 1);
      int curOr = bitsToInt(bits);

      while (curOr >= k && l <= r) {
        res = min(res, r - l + 1);
        bitsUpdate(bits, nums[l], -1);
        l++;
        curOr = bitsToInt(bits);
      }
    }

    return res == numeric_limits<int>::max() ? -1 : res;
  }

private:
  void bitsUpdate(vector<int> &bits, int n, int diff) {
    for (int i = 0; i < 32; i++) {
      if (n & (1 << i)) {
        bits[i] += diff;
      }
    }
  }

  int bitsToInt(const vector<int> &bits) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
      if (bits[i]) {
        res |= (1 << i);
      }
    }
    return res;
  }
};