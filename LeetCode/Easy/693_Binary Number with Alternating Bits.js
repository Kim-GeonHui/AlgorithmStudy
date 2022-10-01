/**
 * @param {number} n
 * @return {boolean}
 */
 let hasAlternatingBits = function(n) {
  let num = n.toString(2);
  
  for (let i = 1; i < num.length; i++) {
      if (num[i] === num[i - 1]) return false;
  }
  
  return true;
}; 