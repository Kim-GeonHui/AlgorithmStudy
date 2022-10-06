/**
 * @param {string} jewels
 * @param {string} stones
 * @return {number}
 */
 let numJewelsInStones = function(jewels, stones) {
  let arr = jewels.split('');
  let answer = 0;
  
  for (let i = 0; i < arr.length; i++) {
      answer += stones.split(arr[i]).length - 1;
  }
  
  return answer;
};