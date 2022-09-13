/**
 * @param {number} n
 * @return {boolean}
 */
 let isPowerOfTwo = function(n) {
  let arr = [];
  
  for (let i  = 0; i < 32; i++) arr.push(Math.pow(2, i));
  
  if (arr.indexOf(n) === -1) return false;
  else return true;
};