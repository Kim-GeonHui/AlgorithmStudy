/**
 * @param {string} s
 * @return {number[][]}
 */
 let largeGroupPositions = function(s) {
  let index = 1;
  let size = 1;
  let answer = [];
  
  while (index < s.length) {
      if (s[index] === s[index - 1])
          size++;
      else {
          if (size >= 3) 
              answer.push([index - size, index - 1]);
          size = 1;
      }
      index++;
  }
  
  if (size >= 3) {
              answer.push([index - size, index - 1]);
              size = 1;
  }
  
  return answer;
};