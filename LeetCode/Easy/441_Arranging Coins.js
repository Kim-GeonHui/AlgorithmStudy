/**
 * @param {number} n
 * @return {number}
 */
 let arrangeCoins = function(n) {
  let number = 1;
  while (true) {
      if (number*(number+1)/2 === n) return number;
      else if (number*(number+1)/2 > n) return number - 1;
      else number++;
  }
};