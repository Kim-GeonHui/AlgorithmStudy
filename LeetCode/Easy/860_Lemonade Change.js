/**
 * @param {number[]} bills
 * @return {boolean}
 */
 let lemonadeChange = function(bills) {
  let arr = [0, 0, 0];
  
  for (let i = 0; i < bills.length; i++) {
      if (bills[i] === 5) arr[0]++;
      else if (bills[i] === 10) {
          if (arr[0] > 0) {
              arr[1]++;
              arr[0]--;
          }
          else return false;
      }
      else {
          if (arr[0] > 0 && arr[1] > 0) {
              arr[2]++;
              arr[1]--;
              arr[0]--;
          }
          else if (arr[0] >= 3) {
              arr[2]++;
              arr[0] -= 3;
          }
          else return false;
      }
  }
  
  return true;
};