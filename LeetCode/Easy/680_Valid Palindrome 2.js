/**
 * @param {string} s
 * @return {boolean}
 */
 var validPalindrome = function(s) {
  let index = [];
  
  for (let i = 0; i < s.length; i++) {
      if (i >= s.length - 1 - i) break;
      
      if (s[i] !== s[s.length - 1 - i]) {
          index.push(i);
          index.push(s.length - 1 - i);
          break;
      }
  }
  
  let arr = [];
  if (index.length === 0) return true;
  else {
      arr = s.slice(0, index[0]) + s.slice(index[0] + 1);
      if (arr === arr.split('').reverse().join('')) return true;
      arr = s.slice(0, index[1]) + s.slice(index[1] + 1);
      if (arr === arr.split('').reverse().join('')) return true;
      return false;
  }
  
};