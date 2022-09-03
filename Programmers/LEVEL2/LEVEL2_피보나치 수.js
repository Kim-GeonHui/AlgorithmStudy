function solution(n) {
  let fibo = [];
  fibo.push(0);
  fibo.push(1);
  
  let count = 1;
  
  while(count !== n) {
      fibo.push((fibo[count] + fibo[count - 1]) % 1234567);
      
      count++;
  }
  
  let answer = fibo[count] % 1234567;
  return answer;
}