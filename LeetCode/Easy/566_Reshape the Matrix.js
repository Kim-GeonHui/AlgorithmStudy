/**
 * @param {number[][]} mat
 * @param {number} r
 * @param {number} c
 * @return {number[][]}
 */
 let matrixReshape = function(mat, r, c) {
  if (r * c !== mat.length * mat[0].length) return mat;
  
  let arr = new Array(r);
  for (let i = 0; i < r; i++) arr[i] = new Array(c);
  
  let index = 0;
  for (let i = 0; i < r; i++) {
      for (let j = 0; j < c; j++) {
          arr[i][j] = mat[Math.floor(index/mat[0].length)][index%mat[0].length];
          index++;
      }
  }
  
  return arr;
};