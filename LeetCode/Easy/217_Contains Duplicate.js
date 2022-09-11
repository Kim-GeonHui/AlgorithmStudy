/**
 * @param {number} n
 * @return {boolean}
 */
 let isHappy = function(n) {
  let tempNum = 0;
  let numArr = [];
  let count = 0;
  
  while(true) {
      if (n === 1) return true;
      if (numArr.indexOf(n) !== -1) return false;
      numArr.push(n);
      tempNum = 0;
      
      while (n !== 0) {
          tempNum += Math.pow(n % 10, 2);
          n = Math.floor(n / 10);
          count++;
      }
      n = tempNum;
  }
};