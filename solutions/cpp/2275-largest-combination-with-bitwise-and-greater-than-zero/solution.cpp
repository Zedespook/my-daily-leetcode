class Solution {
public:
  int largestCombination(vector<int> &candidates) {
    vector<int> bitCounts(32);
    for (int num : candidates) {
      for (int bit = 0; bit < 32; bit++) {
        if (num & (1 << bit)) {
          bitCounts[bit]++;
        }
      }
    }
    return *max_element(bitCounts.begin(), bitCounts.end());
  }
};