class Solution {
public:
  vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
    const int n = items.size();
    const int q = queries.size();

    sort(items.begin(), items.end());

    vector<pair<int, int>> compressed;
    compressed.reserve(n);

    int maxBeauty = 0;
    for (const auto &item : items) {
      maxBeauty = max(maxBeauty, item[1]);
      compressed.emplace_back(item[0], maxBeauty);
    }

    vector<int> result(q);
    for (int i = 0; i < q; ++i) {
      auto pos = upper_bound(compressed.begin(), compressed.end(),
                             make_pair(queries[i], INT_MAX));

      if (pos == compressed.begin()) {
        result[i] = 0;
      } else {
        result[i] = prev(pos)->second;
      }
    }

    return result;
  }
};