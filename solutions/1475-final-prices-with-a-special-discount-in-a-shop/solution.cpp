class Solution {
public:
  vector<int> finalPrices(vector<int> &prices) {
    int n = prices.size();
    vector<int> answer = prices;
    stack<int> st;

    for (int i = 0; i < n; i++) {
      while (!st.empty() && prices[i] <= prices[st.top()]) {
        answer[st.top()] -= prices[i];
        st.pop();
      }
      st.push(i);
    }

    return answer;
  }
};