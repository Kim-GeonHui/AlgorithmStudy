function solution(s) {
   
  for (let i = 0; i < s.length; i++) {
      if (s[i] === ' ')
          continue;
      
      if (i === 0) {
          if (97 <= s.charCodeAt(0) && s.charCodeAt(0) <= 122) 
              s = s.replace(s[0], String.fromCharCode(s.charCodeAt(0) - 32));
          continue;
      }
      
      if (s[i - 1] === ' ') {
          if (97 <= s.charCodeAt(i) && s.charCodeAt(i) <= 122) {
              s = s.replace(s[i], String.fromCharCode(s.charCodeAt(i) - 32));
              continue;
          }
      }
      
      if (65 <= s.charCodeAt(i) && s.charCodeAt(i) <= 90) {
              s = s.replace(s[i], String.fromCharCode(s.charCodeAt(i) + 32));
              continue;
          }
  }    
  
  return s;
}