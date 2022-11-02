/**
 * @param {number} n
 * @return {number}
 */
 let binaryGap = function(n) {
  n = n.toString(2).split('');
  
  let tempArr = [];
  
  tempArr.push(n.indexOf('1', 0));
  
  while(n.indexOf('1', tempArr[tempArr.length - 1] + 1) !== -1) {
      tempArr.push(n.indexOf('1', tempArr[tempArr.length - 1] + 1));
  }
  
  let answer = 0;
  
  if (tempArr.length === 1) return 0;
  else {
      for (let i = 0; i < tempArr.length - 1; i++) {
          answer = Math.max(answer, tempArr[i + 1] - tempArr[i])
      }
  }
  
  return answer;
};