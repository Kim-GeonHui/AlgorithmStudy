/**
 * @param {number[][]} matrix
 * @return {number[][]}
 */
 let transpose = function(matrix) {
  let arr = new Array(matrix[0].length);
  for (let i = 0; i < matrix[0].length; i++) {
      arr[i] = new Array(matrix.length);
  }
  
  for (let i = 0; i < matrix.length; i++) {
      for (let j = 0; j < matrix[0].length; j++) {
          arr[j][i] = matrix[i][j];
      }
  }
  
  return arr;
};