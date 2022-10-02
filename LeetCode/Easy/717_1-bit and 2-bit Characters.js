/**
 * @param {number[]} bits
 * @return {boolean}
 */
 let isOneBitCharacter = function(bits) {
  let index = 0;
  if (bits[bits.length - 1] === 1) return false;
  
  while (index < bits.length) {
      if (index === bits.length - 2 && bits[index] === 1) return false;
      
      if (bits[index] === 1) {
          index += 2;
          continue;
      }
      
      if (bits[index] === 0) {
          index++;
          continue;
      }
  }
  
  return true;
};