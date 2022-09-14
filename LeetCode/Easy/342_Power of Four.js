/**
 * @param {number} n
 * @return {boolean}
 */
 let isPowerOfFour = function(n) {
  if (n < 0) return false;
  
  while (n >= 4) {
      if (n % 4 !== 0) return false;
      n /= 4;
  }
  
  if (n === 1) return true;
  else return false;
};