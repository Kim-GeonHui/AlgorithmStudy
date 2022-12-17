function solution(gates, airlines) {
  let answer = [];
  let sortAirlines = [...airlines].sort((a, b) => b - a);
  let tempSortedAir;
  let sortGate;
  let isFalse;

  for (let i = 0; i < gates.length; i++) {
      sortGate = [...gates[i]].sort((a, b) => b - a);
      tempSortedAir = [...sortAirlines];
      isFalse = false;
    
      for (let j = 0; j < sortGate.length; j++) {
          if (tempSortedAir[0] == 0) break;
          
          if (sortGate[j] == 0) {
              isFalse = true;
              break;
          }
          
          tempSortedAir[0] = (tempSortedAir[0] - sortGate[j] > 0) ? (tempSortedAir[0] - sortGate[j]) : 0;
          tempSortedAir.sort((a, b) => b - a);
      }
  
      if (tempSortedAir[0] != 0) isFalse = true;
      if (isFalse) continue;
      answer.push(i + 1);
  }

  if (answer.length == 0) return [-1];
  else return answer;
}