function solution(s) {
  let tempArr = [];
  tempArr = s.split(' ');
  
  let min = tempArr[0];
  let max = tempArr[0];
  
  for (let i = 1; i < tempArr.length; i++) {
      min = (Number(min) > Number(tempArr[i])) ? tempArr[i] : min;
      max = (Number(max) < Number(tempArr[i])) ? tempArr[i] : max;
  }
  
  return min + " " + max;
}