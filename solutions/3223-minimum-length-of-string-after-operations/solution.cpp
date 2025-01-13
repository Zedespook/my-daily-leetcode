#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumLength(string s) {
    vector<bool> removed(s.length(), false);
    bool changed;

    do {
      changed = false;
      // Try each index as a potential pivot
      for (size_t i = 0; i < s.length(); i++) {
        if (removed[i])
          continue;

        // Find closest left match
        int left = -1;
        for (int j = static_cast<int>(i) - 1; j >= 0; j--) {
          if (!removed[j] && s[j] == s[i]) {
            left = j;
            break;
          }
        }

        // Find closest right match
        int right = -1;
        for (size_t j = i + 1; j < s.length(); j++) {
          if (!removed[j] && s[j] == s[i]) {
            right = static_cast<int>(j);
            break;
          }
        }

        // If we found both matches, remove them
        if (left != -1 && right != -1) {
          removed[left] = true;
          removed[right] = true;
          changed = true;
        }
      }
    } while (changed);

    // Count remaining characters
    int remaining = 0;
    for (bool r : removed) {
      if (!r)
        remaining++;
    }
    return remaining;
  }
};