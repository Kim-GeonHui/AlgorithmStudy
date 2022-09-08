function solution(s) {
  let zeroCount = 0;
  let reCount = 0;
  
  while(s.length !== 1) {
      zeroCount += s.split('0').length - 1;
      while (s.indexOf('0') !== -1) s = s.replace('0', '');
      s = s.length.toString(2);
      reCount++;
  }
  
  return [reCount, zeroCount];
}