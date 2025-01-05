class Solution {
public:
  string shiftingLetters(string s, vector<vector<int>> &shifts) {
    int n = s.length();
    // Create difference array to track cumulative shifts
    vector<int> diff(n + 1, 0);

    // Process all shifts using line sweep technique
    for (const auto &shift : shifts) {
      int start = shift[0];
      int end = shift[1];
      int direction = shift[2] ? 1 : -1; // Convert 0/1 to -1/1

      // Add shift at start and remove at end+1
      diff[start] += direction;
      diff[end + 1] -= direction;
    }

    // Calculate cumulative shifts and apply to string
    int currentShift = 0;
    string result = s;

    for (int i = 0; i < n; i++) {
      // Update current shift
      currentShift += diff[i];

      // Calculate new character position
      int newPos = (s[i] - 'a' + currentShift % 26 + 26) % 26;
      result[i] = 'a' + newPos;
    }

    return result;
  }
};