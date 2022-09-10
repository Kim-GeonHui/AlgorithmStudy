/**
 * @param {number} rowIndex
 * @return {number[]}
 */
 let getRow = function(rowIndex) {
  let arr = new Array(rowIndex + 1);
  arr[0] = [1];
  if (rowIndex >= 1) arr[1] = [1, 1];
  for (let i = 2; i <= rowIndex; i++) {
      arr[i] = new Array(i + 1);
      arr[i][0] = 1;
      for (let j = 1; j < i; j++) arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
      arr[i][i] = 1;
  }
  
  return arr[rowIndex];
};