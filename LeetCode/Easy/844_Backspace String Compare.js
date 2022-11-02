/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
 let backspaceCompare = function(s, t) {
  let stackS = [];
  let stackT = [];
  
  for (let i = 0; i < s.length; i++) {
      if (s[i] === '#') stackS.pop();
      else stackS.push(s[i]);
  }
  
  for (let i = 0; i < t.length; i++) {
      if (t[i] === '#') stackT.pop();
      else stackT.push(t[i]);
  }
  
  return (JSON.stringify(stackS) === JSON.stringify(stackT))
};