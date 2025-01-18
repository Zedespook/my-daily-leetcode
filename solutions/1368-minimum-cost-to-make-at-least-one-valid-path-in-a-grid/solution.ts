function minCost(grid: number[][]): number {
  const m = grid.length;
  const n = grid[0].length;

  // Directions array corresponding to the grid values (1-based)
  // [right, left, down, up]
  const dirs = [
    [0, 1],
    [0, -1],
    [1, 0],
    [-1, 0],
  ];

  // Initialize distance matrix with Infinity
  const dist = Array(m)
    .fill(0)
    .map(() => Array(n).fill(Infinity));
  dist[0][0] = 0;

  // Use a deque for 0-1 BFS
  // Format: [row, col, current_cost]
  const deque: [number, number, number][] = [[0, 0, 0]];

  while (deque.length > 0) {
    const [row, col, cost] = deque.shift()!;

    // If this path is no longer the minimum, skip it
    if (cost > dist[row][col]) continue;

    // Try all four directions
    for (let i = 0; i < 4; i++) {
      const newRow = row + dirs[i][0];
      const newCol = col + dirs[i][1];

      // Skip if out of bounds
      if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n) continue;

      // Calculate new cost
      // If the current cell's arrow points to this direction, cost is 0
      // Otherwise, we need to change the arrow, so cost is 1
      const newCost = cost + (grid[row][col] === i + 1 ? 0 : 1);

      // If we found a better path, update it
      if (newCost < dist[newRow][newCol]) {
        dist[newRow][newCol] = newCost;

        // If we didn't change direction (cost = 0), add to front of deque
        // If we changed direction (cost = 1), add to back of deque
        if (grid[row][col] === i + 1) {
          deque.unshift([newRow, newCol, newCost]);
        } else {
          deque.push([newRow, newCol, newCost]);
        }
      }
    }
  }

  // Return the minimum cost to reach bottom-right cell
  return dist[m - 1][n - 1];
}
