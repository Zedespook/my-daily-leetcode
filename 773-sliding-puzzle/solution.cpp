class Solution {
  string TARGET = "123450";
  vector<vector<int>> DIRS = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  vector<vector<int>> NEIGHBORS = {{1, 3}, {0, 2, 4}, {1, 5},
                                   {0, 4}, {1, 3, 5}, {2, 4}};

  string boardToString(vector<vector<int>> &board) {
    string s;
    for (const auto &row : board)
      for (int x : row)
        s += to_string(x);
    return s;
  }

  bool isSolvable(string &state) {
    int inversions = 0;
    for (int i = 0; i < state.length(); i++) {
      if (state[i] == '0')
        continue;
      for (int j = i + 1; j < state.length(); j++) {
        if (state[j] == '0')
          continue;
        if (state[i] > state[j])
          inversions++;
      }
    }
    return inversions % 2 == 0;
  }

public:
  int slidingPuzzle(vector<vector<int>> &board) {
    string start = boardToString(board);
    if (!isSolvable(start))
      return -1;
    if (start == TARGET)
      return 0;

    queue<string> q;
    unordered_set<string> visited;

    q.push(start);
    visited.insert(start);
    int moves = 0;

    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        string curr = q.front();
        q.pop();

        int zero = curr.find('0');

        for (int next : NEIGHBORS[zero]) {
          string next_state = curr;
          swap(next_state[zero], next_state[next]);

          if (visited.count(next_state))
            continue;

          if (next_state == TARGET)
            return moves + 1;

          visited.insert(next_state);
          q.push(next_state);
        }
      }
      moves++;
    }

    return -1;
  }
};