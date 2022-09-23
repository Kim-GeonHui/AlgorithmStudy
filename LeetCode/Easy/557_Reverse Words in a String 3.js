/**
 * @param {string} s
 * @return {string}
 */
 let reverseWords = function(s) {
  s = s.split(' ');
  for (let i = 0; i < s.length; i++) s[i] = s[i].split('').reverse().join('');
  s = s.join(' ');
  
  return s;
};