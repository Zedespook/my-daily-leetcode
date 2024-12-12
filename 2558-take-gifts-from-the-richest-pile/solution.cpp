class Solution {
public:
  long long pickGifts(vector<int> &gifts, int k) {
    priority_queue<int> pq(gifts.begin(), gifts.end());

    while (k--) {
      int max_gifts = pq.top();
      pq.pop();

      int remaining = floor(sqrt(max_gifts));
      pq.push(remaining);
    }

    long long total = 0;
    while (!pq.empty()) {
      total += pq.top();
      pq.pop();
    }

    return total;
  }
};