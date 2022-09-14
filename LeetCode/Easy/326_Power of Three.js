/**
 * @param {number} n
 * @return {boolean}
 */
 let isPowerOfThree = function(n) {
  let arr = [];
  for (let i = 0; i <= 20; i++) arr.push(Math.pow(3, i));
  
  if (arr.indexOf(n) !== -1) return true;
  else return false;
};