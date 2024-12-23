#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumOperations(TreeNode *root) {
    int operations = 0;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int levelSize = q.size();
      vector<int> levelValues;

      for (int i = 0; i < levelSize; ++i) {
        TreeNode *node = q.front();
        q.pop();
        levelValues.push_back(node->val);

        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }

      operations += minSwapsToSort(levelValues);
    }

    return operations;
  }

private:
  int minSwapsToSort(vector<int> &arr) {
    int n = arr.size();
    vector<pair<int, int>> arrPos(n);
    for (int i = 0; i < n; ++i) {
      arrPos[i].first = arr[i];
      arrPos[i].second = i;
    }

    sort(arrPos.begin(), arrPos.end());

    vector<bool> visited(n, false);
    int swaps = 0;

    for (int i = 0; i < n; ++i) {
      if (visited[i] || arrPos[i].second == i) {
        continue;
      }

      int cycleSize = 0;
      int j = i;
      while (!visited[j]) {
        visited[j] = true;
        j = arrPos[j].second;
        cycleSize++;
      }

      if (cycleSize > 0) {
        swaps += (cycleSize - 1);
      }
    }

    return swaps;
  }
};