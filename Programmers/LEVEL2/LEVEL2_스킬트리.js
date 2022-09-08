function solution(skill, skill_trees) {
  let answer = 0;
  let index = 0;
  let isTrue = true;
  
  for (let i = 0; i < skill_trees.length; i++) {
      index = 0;
      isTrue = true;
      
      for (let j = 0; j < skill_trees[i].length; j++) {
          if (skill.indexOf(skill_trees[i][j]) === -1) continue;
          
          if (skill.indexOf(skill_trees[i][j]) !== index) isTrue = false;

          if (skill.indexOf(skill_trees[i][j] === index)) index++;
      }
      
      if (isTrue) answer++;
  }
  
  return answer;
}