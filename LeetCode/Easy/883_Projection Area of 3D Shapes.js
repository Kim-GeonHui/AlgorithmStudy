/**
 * @param {number[][]} grid
 * @return {number}
 */
 let projectionArea = function(grid) {
  let answer = 0;
  
  for (let i = 0; i < grid.length; i++) {
      answer += grid[i].filter(item => item !== 0).length;
  }
  
  let tempArr1 = new Array(grid.length);
  let tempArr2 = new Array(grid.length);
  tempArr2.fill(0);
  
  for (let i = 0; i < grid.length; i++) {
      tempArr1[i] = Math.max(...grid[i]);
      for (let j = 0; j < grid[i].length; j++)
          tempArr2[j] = Math.max(grid[i][j], tempArr2[j]);
  }
  
  for (let i = 0; i < grid.length; i++) {
      answer += tempArr1[i] + tempArr2[i];
  }
  
  return answer;
};