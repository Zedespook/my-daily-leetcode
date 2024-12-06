class Solution {
public:
  int maxCount(vector<int> &banned, int n, int maxSum) {
    unordered_set<int> bannedSet(banned.begin(), banned.end());

    int count = 0;
    long long sum = 0;

    for (int i = 1; i <= n; i++) {
      if (bannedSet.count(i))
        continue;

      if (sum + i > maxSum)
        break;

      sum += i;
      count++;
    }

    return count;
  }
};