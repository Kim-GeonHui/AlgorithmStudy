function solution(arr1, arr2) {
  let answer = new Array(arr1.length);
  let tempNumber;
  
  for (let i = 0; i < arr1.length; i++)
      answer[i] = new Array(arr2[0].length);
  
  for (let i = 0; i < arr1.length; i++) {
      for (let j = 0; j < arr2[0].length; j++) {
          tempNumber = 0;
          for (let k = 0; k < arr1[0].length; k++) {
              tempNumber += arr1[i][k] * arr2[k][j];
          }
          answer[i][j] = tempNumber;
      }
  }
  
  return answer;
}