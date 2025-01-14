class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B) {
    int n = A.size();
    vector<int> result(n);
    vector<bool> seenA(n + 1, false);
    vector<bool> seenB(n + 1, false);
    int commonCount = 0;

    // For each index i, check numbers up to that index
    for (int i = 0; i < n; i++) {
      // Mark current numbers as seen
      seenA[A[i]] = true;
      seenB[B[i]] = true;

      // If both arrays have seen the current numbers, increment count
      if (seenA[A[i]] && seenB[A[i]])
        commonCount++;
      if (A[i] != B[i] && seenA[B[i]] && seenB[B[i]])
        commonCount++;

      result[i] = commonCount;
    }

    return result;
  }
};