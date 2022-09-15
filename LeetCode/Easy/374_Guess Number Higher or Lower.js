/** 
 * Forward declaration of guess API.
 * @param {number} num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * var guess = function(num) {}
 */

/**
 * @param {number} n
 * @return {number}
 */
 let guessNumber = function(n) {
  let front = 1;
  let end = n;
  let mid = Math.floor((front + end)/2);
  
  while(front < end) {
      if (guess(mid) === 0) return mid;
      else if (guess(mid) === -1) {
          end = mid - 1;
          mid = Math.floor((front + end)/2);
      }
      else {
          front = mid + 1;
          mid = Math.floor((front + end)/2);
      }
  }
  
  return mid;
};