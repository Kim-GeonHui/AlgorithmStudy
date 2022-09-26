/**
 * @param {string[]} list1
 * @param {string[]} list2
 * @return {string[]}
 */
 let findRestaurant = function(list1, list2) {
  let arr = [];
  let index = 2000;
  let tempIndex = 0;
  
  for (let i = 0; i < list1.length; i++) {
      tempIndex = list2.indexOf(list1[i]);
      if (tempIndex !== -1) {
          if (i + tempIndex > index) continue;
          else {
              if (i + tempIndex < index) arr = [];
              arr.push(list1[i]);
              index = i + tempIndex;
          }
      }
  }
  
  return arr;
};