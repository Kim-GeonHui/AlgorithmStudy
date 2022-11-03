/**
 * @param {string} s1
 * @param {string} s2
 * @return {string[]}
 */
 let uncommonFromSentences = function(s1, s2) {
  s1 = s1.split(' ');
  s2 = s2.split(' ');
  
  let arr = s1.concat(s2);

  let answer = [];
  let tempIndex = 0;
  
  for (let i = 0; i < s1.length; i++) {
      tempIndex = arr.indexOf(s1[i]);
      if (tempIndex === -1) continue;
      
      if (arr.indexOf(s1[i], tempIndex + 1) !== - 1)
          arr = arr.filter(item => item !== s1[i]);
  }
  
  let index = 0;
  
  while(index < arr.length) {
      if (arr.indexOf(arr[index], index + 1) !== -1)
          arr = arr.filter(item => item !== arr[index]);
      else index++;
  }
  
  return arr;
};