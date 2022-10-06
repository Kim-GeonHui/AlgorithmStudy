/**
 * @param {string} s
 * @param {character} c
 * @return {number[]}
 */
 let shortestToChar = function(s, c) {
  s = s.split(c);
  
  let answer = [];
  for (let i = 0; i < s[0].length; i++) {
      answer.push(s[0].length - i);
  }
  
  for (let i = 1; i < s.length - 1; i++) {
      answer.push(0);
      for (let j = 0; j < s[i].length; j++) {
          answer.push(Math.min(j + 1, s[i].length - j));
      }
      
  }
  
  answer.push(0);
  for (let i = 0; i < s[s.length - 1].length; i++) {
      answer.push(i + 1);
  }
  
  return answer;
};