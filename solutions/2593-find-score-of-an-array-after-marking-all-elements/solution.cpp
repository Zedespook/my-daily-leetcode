class Solution {
public:
  long long findScore(vector<int> &nums) {
    int n = nums.size();
    vector<bool> marked(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    for (int i = 0; i < n; i++) {
      pq.push({nums[i], i});
    }

    long long score = 0;

    while (!pq.empty()) {
      auto [val, idx] = pq.top();
      pq.pop();

      if (!marked[idx]) {
        score += val;
        marked[idx] = true;

        if (idx > 0) {
          marked[idx - 1] = true;
        }
        if (idx < n - 1) {
          marked[idx + 1] = true;
        }
      }
    }

    return score;
  }
};