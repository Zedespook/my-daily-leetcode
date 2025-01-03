class Solution {
public:
  bool checkIfExist(vector<int> &arr) {
    unordered_set<int> seen;
    int zeros = 0;

    for (int num : arr) {
      if (num == 0) {
        zeros++;
        if (zeros > 1)
          return true;
        continue;
      }
      if (seen.count(2 * num) || (num % 2 == 0 && seen.count(num / 2))) {
        return true;
      }
      seen.insert(num);
    }

    return false;
  }
};