/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
 let reverseStr = function(s, k) {
  let index = 0;
  let answer = "";
  
  while (index < s.length) {
      answer += s.slice(index, index + k).split('').reverse().join('');
      answer += s.slice(index + k, index + 2 * k);
      index += 2 * k;
  }
  
  return answer;
};