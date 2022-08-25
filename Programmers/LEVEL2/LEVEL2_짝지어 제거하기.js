function solution(s)
{
    let stack = [];
    let tempIndex = -1;

    for (let i = 0; i < s.length; i++) {
        if (stack.length === 0) {
            stack.push(s[i]);
            tempIndex++;
        }
        else if (stack[tempIndex] !== s[i]) {
            stack.push(s[i]);
            tempIndex++;
        }
        else if (stack[tempIndex] === s[i]) {
            stack.pop();
            tempIndex--;
        }
    }

    if (stack.length === 0)
        return 1;
    else
        return 0;
}