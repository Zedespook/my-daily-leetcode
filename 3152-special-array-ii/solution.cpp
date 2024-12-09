class Solution {
public:
  vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
    vector<bool> answer;
    answer.reserve(queries.size());

    for (const auto &query : queries) {
      int start = query[0];
      int end = query[1];

      bool isSpecial = true;
      for (int i = start; i < end; i++) {
        if ((nums[i] % 2) == (nums[i + 1] % 2)) {
          isSpecial = false;
          break;
        }
      }

      answer.push_back(isSpecial);
    }

    return answer;
  }
};