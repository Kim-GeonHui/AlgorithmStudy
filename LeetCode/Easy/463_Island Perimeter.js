/**
 * @param {number[][]} grid
 * @return {number}
 */
 let islandPerimeter = function(grid) {
  let row = grid.length;
  let col = grid[0].length;
  let answer = 0;
  
  let arr = new Array(row + 2);
  for (let i = 0; i < row + 2; i++) {
      arr[i] = new Array(col + 2);
      arr[i].fill(0);
  }
  
  for (let i = 0; i < row; i++) {
      for (let j = 0; j < col; j++) {
          arr[i + 1][j + 1] = grid[i][j];
      }
  }
  
  for (let i = 1; i <= row; i++) {
      for (let j = 1; j <= col; j++) {
          if (arr[i][j]) {
              if (!arr[i + 1][j]) answer++;
              if (!arr[i - 1][j]) answer++;
              if (!arr[i][j + 1]) answer++;
              if (!arr[i][j - 1]) answer++;
          }
      }
  }
  
  return answer;
};