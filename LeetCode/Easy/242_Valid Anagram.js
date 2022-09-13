/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
 let isAnagram = function(s, t) {
  let numArr = [...new Set(s)];
  let countArr = [];
  let answer = true;
  
  if (s.length !== t.length) return false;
  
  for (let i = 0; i < numArr.length; i++) countArr.push(s.split(numArr[i]).length - 1);
  
  for (let i = 0; i < numArr.length; i++) {
      if (countArr[i] !== t.split(numArr[i]).length - 1) {
          answer = false;
          break;
      }
  }
  
  return answer;
};