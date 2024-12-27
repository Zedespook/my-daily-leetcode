class Solution {
public:
  int maxScoreSightseeingPair(vector<int> &values) {
    int maxScore = 0;
    int maxValuePlusI = values[0] + 0; // Initialize with first element

    // For each j, find the best score using the best (values[i] + i) seen so
    // far
    for (int j = 1; j < values.size(); j++) {
      // Calculate current score using the best previous (values[i] + i)
      maxScore = max(maxScore, maxValuePlusI + values[j] - j);
      // Update the best (values[i] + i) seen so far
      maxValuePlusI = max(maxValuePlusI, values[j] + j);
    }

    return maxScore;
  }
};