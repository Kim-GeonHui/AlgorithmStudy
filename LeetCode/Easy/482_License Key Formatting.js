/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
 let licenseKeyFormatting = function(s, k) {
  s = s.split('-').join('');
  let answer = s.slice(0, s.length % k).toUpperCase();
  
  let index = s.length % k;
  
  while(index < s.length) {
      answer += "-";
      answer += s.slice(index, index + k).toUpperCase();
      index += k;
  }
  
  if (answer[0] === '-') return answer.slice(1);
  else return answer;
};