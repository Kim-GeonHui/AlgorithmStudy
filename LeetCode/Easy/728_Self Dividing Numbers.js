/**
 * @param {number} left
 * @param {number} right
 * @return {number[]}
 */
 let selfDividingNumbers = function(left, right) {
  let arr = [];
  let num = 0;
  
  for (let i = left; i <= right; i++) {
      num = i;
      
      while (num !== 0) {
          if (i % (num % 10) !== 0) break;
          num = Math.floor(num / 10);
      }
      
      if (num === 0) arr.push(i);
  }
  
  return arr;
};