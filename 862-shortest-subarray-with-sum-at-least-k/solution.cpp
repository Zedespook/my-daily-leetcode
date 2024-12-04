class Solution {
public:
  int shortestSubarray(vector<int> &nums, int k) {
    int n = nums.size();
    vector<long long> prefix(n + 1);

    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
      prefix[i + 1] = prefix[i] + nums[i];
    }

    int minLen = INT_MAX;
    deque<int> monoq;

    for (int i = 0; i <= n; i++) {
      while (!monoq.empty() && prefix[i] - prefix[monoq.front()] >= k) {
        minLen = min(minLen, i - monoq.front());
        monoq.pop_front();
      }

      while (!monoq.empty() && prefix[i] <= prefix[monoq.back()]) {
        monoq.pop_back();
      }

      monoq.push_back(i);
    }

    return minLen == INT_MAX ? -1 : minLen;
  }
};