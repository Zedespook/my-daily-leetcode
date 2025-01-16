#include <vector>
using namespace std;

class Solution {
public:
  int xorAllNums(vector<int> &nums1, vector<int> &nums2) {
    int result = 0;

    // If nums2.size() is odd, each number in nums1 will appear odd times in the
    // final result
    if (nums2.size() % 2 == 1) {
      for (int num : nums1) {
        result ^= num;
      }
    }

    // If nums1.size() is odd, each number in nums2 will appear odd times in the
    // final result
    if (nums1.size() % 2 == 1) {
      for (int num : nums2) {
        result ^= num;
      }
    }

    return result;
  }
};