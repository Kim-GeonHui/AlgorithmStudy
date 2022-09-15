/**
 * @param {string} s
 * @return {number}
 */
 let firstUniqChar = function(s) {
  let list = [];
  
  for (let i = 0; i < s.length; i++) {
      if (list.indexOf(s[i]) !== -1) continue;
      else if (s.split(s[i]).length - 1 !== 1) list.push(s[i]);
      else return i;
  }
  
  return -1;
};