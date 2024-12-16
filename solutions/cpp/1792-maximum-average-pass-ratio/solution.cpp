class Solution {
private:
  double getImprovement(double pass, double total) {
    return (pass + 1) / (total + 1) - pass / total;
  }

public:
  double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
    priority_queue<pair<double, pair<double, double>>> pq;

    for (const auto &c : classes) {
      double pass = c[0], total = c[1];
      double improvement = getImprovement(pass, total);
      pq.push({improvement, {pass, total}});
    }

    while (extraStudents--) {
      auto [imp, pr] = pq.top();
      pq.pop();

      double pass = pr.first + 1;
      double total = pr.second + 1;

      double newImprovement = getImprovement(pass, total);
      pq.push({newImprovement, {pass, total}});
    }

    double sumRatio = 0;
    int n = classes.size();

    while (!pq.empty()) {
      auto [imp, pr] = pq.top();
      pq.pop();
      sumRatio += pr.first / pr.second;
    }

    return sumRatio / n;
  }
};