/**
 * @param {string} moves
 * @return {boolean}
 */
 let judgeCircle = function(moves) {
  let answer = true;
  
  if (moves.split('').filter(item => item === 'U').length !== moves.split('').filter(item => item === 'D').length)
      return false;
  
  if (moves.split('').filter(item => item === 'R').length !== moves.split('').filter(item => item === 'L').length)
      return false;
  
  return answer;
};