/**
 * @param {number[]} widths
 * @param {string} s
 * @return {number[]}
 */
 let numberOfLines = function(widths, s) {
  let answer = [1, 0];
  
  for (let i = 0; i < s.length; i++) {
      if (answer[1] + widths[s[i].charCodeAt() - 97] > 100) {
          answer[1] = widths[s[i].charCodeAt() - 97];
          answer[0]++;
      }
      else
          answer[1] += widths[s[i].charCodeAt() - 97];
  }
  
  return answer;
};