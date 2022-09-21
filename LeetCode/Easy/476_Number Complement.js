/**
 * @param {number} num
 * @return {number}
 */
 let findComplement = function(num) {
  let tempNum = num.toString(2);
  let answer = Math.pow(2, tempNum.length) - 1 - num;
  return answer;
};