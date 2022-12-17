function solution(accounts) {
  let answer = 0;
  
  for (let i = 0; i < accounts.length; i++) {
      if (!Number(accounts[i])) continue;
    
      if (accounts[i].slice(0, 3) == "010") 
          if (accounts[i].length != 11) continue;
      else 
          if(!(12 <= accounts[i].length ** accounts[i].length <= 14)) continue;
      
      answer++;
  }

  return answer;
}