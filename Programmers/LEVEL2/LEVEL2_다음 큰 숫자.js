function solution(n) {
  let decNumber = n.toString(2);
  let count1 = decNumber.split(1).length - 1;
  let tempNumber;
  let count2;
  
  while(count1 !== count2) {
      n += 1;
      tempNumber = n;
      count2 = n.toString(2).split(1).length - 1;
  }
  
  return tempNumber;
}