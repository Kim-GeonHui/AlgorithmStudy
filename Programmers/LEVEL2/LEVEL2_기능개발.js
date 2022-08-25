function solution(progresses, speeds) {
  let answer = [];
  let tempIndex = 0;
  let lastTempIndex = 0;

  while(tempIndex <= progresses.length - 1) {               
      // 하루 진행속도 추가
      for (let i = tempIndex; i < progresses.length; i++) {
          progresses[i] += speeds[i];
      }

      lastTempIndex = tempIndex;

      // 당일 배포
      for (let i = tempIndex; i < progresses.length; i++) {
          if (progresses[i] >= 100) {
              tempIndex += 1;
              continue;
          }
          break;
      }

      if (tempIndex - lastTempIndex === 0)
          continue;

      answer.push(tempIndex - lastTempIndex);
  }

  return answer;
}