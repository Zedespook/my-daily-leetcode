class Solution {
public:
  bool canBeValid(string s, string locked) {
    int n = s.length();

    // If length is odd, it can't be valid
    if (n % 2)
      return false;

    // Forward pass - check if we have too many ')'
    int balance = 0;
    int canModify = 0;

    for (int i = 0; i < n; i++) {
      if (locked[i] == '0') {
        canModify++;
      } else if (s[i] == '(') {
        balance++;
      } else {
        balance--;
      }

      // At any point, if we have more ')' than we can handle
      if (balance + canModify < 0) {
        return false;
      }
    }

    // Backward pass - check if we have too many '('
    balance = 0;
    canModify = 0;

    for (int i = n - 1; i >= 0; i--) {
      if (locked[i] == '0') {
        canModify++;
      } else if (s[i] == ')') {
        balance++;
      } else {
        balance--;
      }

      // At any point, if we have more '(' than we can handle
      if (balance + canModify < 0) {
        return false;
      }
    }

    return true;
  }
};