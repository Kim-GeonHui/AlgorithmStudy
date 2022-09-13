/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */
 let wordPattern = function(pattern, s) {
  let arr = s.split(' ');    
  
  if ([...new Set(pattern)].length !== [...new Set(arr)].length) return false;
  if (arr.length !== pattern.length) return false;
  
  for (let i = 1; i < pattern.length; i++) {
      if (arr[i] !== arr[pattern.indexOf(pattern[i])]) return false;
  }
  
  return true;
};