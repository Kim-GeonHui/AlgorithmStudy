/**
 * @param {string[]} operations
 * @return {number}
 */
let calPoints = function (operations) {
  let arr = [];
  for (let i = 0; i < operations.length; i++) {
    if (operations[i] === '+') arr.push(arr[arr.length - 1] + arr[arr.length - 2]);
    else if (operations[i] === 'D') arr.push(arr[arr.length - 1] * 2);
    else if (operations[i] === 'C') arr.pop();
    else arr.push(Number(operations[i]));
  }

  if (arr.length === 0) return 0;
  else return arr.reduce((a, b) => (a + b));
};