/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
 let findTheDifference = function(s, t) {
  s = s.split('').sort();
  t = t.split('').sort();
  
  return t.filter((item, index) => item !== s[index])[0];
};