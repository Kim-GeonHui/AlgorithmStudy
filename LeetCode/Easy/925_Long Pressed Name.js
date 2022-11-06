/**
 * @param {string} name
 * @param {string} typed
 * @return {boolean}
 */
 let isLongPressedName = function(name, typed) {
  let index = 0;
  let strLen = 1;
  
  for (let i = 0; i < name.length; i++) {
      if (i !== name.length - 1 && name[i] === name[i + 1]) {
          strLen++;
          continue;
      }
      
      for (let j = index; j < index + strLen; j++) {
          if (typed[j] !== name[i]) return false;
      }
      index += strLen;
      
      for (let j = index; j < index + strLen; j++) {
          if (typed[j] !== name[i]) break;
          index++;
      }
      
      if (name[i] === typed[index]) return false;
      
      strLen = 1;
  }
  
  if (index <= typed.length - 1) return false;
  
  return true;
};