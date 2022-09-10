/**
 * @param {number} numRows
 * @return {number[][]}
 */
 let generate = function(numRows) {
  let arr = new Array(numRows);
  arr[0] = [1];
  if (numRows >= 2) arr[1] = [1, 1];
  for (let i = 2; i < numRows; i++) {
      arr[i] = new Array(i + 1);
      arr[i][0] = 1;
      for (let j = 1; j < i; j++) arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
      arr[i][i] = 1;
  }

  return arr;
};