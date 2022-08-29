let result = 0;

function DFS(numberArr, sum, count, target) {
  if (count === numberArr.length) {
    if (sum === target) result += 1;
    return;
  }

  DFS(numberArr, sum + numberArr[count], count + 1, target);
  DFS(numberArr, sum - numberArr[count], count + 1, target);
}

function solution(numbers, target) {
  let numberArr = numbers.sort((a, b) => a - b);

  DFS(numberArr, 0, 0, target);

  return result;
}