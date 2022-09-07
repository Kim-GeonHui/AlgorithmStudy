function solution(s) {
  let answer = false;
  let arr = [];

  arr.push(s[0]);
  if (s[0] === ')' || s[s.length - 1] === '(') return answer;
  if (s.length % 2 !== 0) return answer;
  
  for (let i = 1; i < s.length; i++) {
      if (arr[arr.length - 1] === '(' && s[i] === ')') {
          arr.pop();
          continue;
      }
      arr.push(s[i]);
  }

  if (arr.length === 0) answer = true;
      
  return answer;
}