class Solution {
public:
  int maxTwoEvents(vector<vector<int>> &events) {
    sort(events.begin(), events.end());
    int n = events.size();

    vector<int> maxVal(n);
    maxVal[n - 1] = events[n - 1][2];

    for (int i = n - 2; i >= 0; i--) {
      maxVal[i] = max(maxVal[i + 1], events[i][2]);
    }

    int result = 0;

    for (int i = 0; i < n; i++) {
      int curr = events[i][2];
      result = max(result, curr);

      int left = i + 1, right = n - 1;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (events[mid][0] > events[i][1]) {
          result = max(result, curr + maxVal[mid]);
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }
    }

    return result;
  }
};