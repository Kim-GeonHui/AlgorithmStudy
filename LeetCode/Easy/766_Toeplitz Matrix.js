/**
 * @param {number[][]} matrix
 * @return {boolean}
 */
 let isToeplitzMatrix = function(matrix) {
  let row = matrix.length;
  let col = matrix[0].length;
  
  let tempRow = 0;
  let tempCol = 0;
  
  for (let i = row - 2; i > 0; i--) {
      tempRow = i + 1;
      tempCol = 1;
      while (tempRow < row && tempCol < col) {
          if (matrix[tempRow][tempCol] !== matrix[tempRow - 1][tempCol - 1]) return false;
          
          tempRow++;
          tempCol++;
      }
  }
  
  for (let i = 0; i < col - 1; i++) {
      tempRow = 1;
      tempCol = i + 1;
      
      while (tempRow < row && tempCol < col) {
          if (matrix[tempRow][tempCol] !== matrix[tempRow - 1][tempCol - 1]) return false;
          
          tempRow++;
          tempCol++;
      }
  }
  
  return true;
};