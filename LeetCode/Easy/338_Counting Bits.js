/**
 * @param {number} n
 * @return {number[]}
 */
 let countBits = function(n) {
  let answer = [];
  for (let i = 0; i <= n; i++) {
      answer.push(i.toString(2).split('1').length - 1);
  }
  return answer;
};