function solution(n, words) {
  let tempArr = [];
  let index = 0;
  tempArr.push(words[0]);
  
  for (let i = 1; i < words.length; i++) {
      if (tempArr.indexOf(words[i]) !== -1) {
          index = i;
          break;
      }
      else if (tempArr[tempArr.length - 1][tempArr[tempArr.length - 1].length - 1] !== words[i][0]) {
          index = i;
          break;
      }
      else tempArr.push(words[i]);
  }
  
  if (index === 0) return [0,0];
  else return [index%n + 1, Math.floor(index/n) + 1];
}