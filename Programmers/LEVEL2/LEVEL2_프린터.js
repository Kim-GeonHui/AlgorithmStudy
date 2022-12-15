class Node {
  constructor(data, loc) {
      this.data = data;
      this.rear = null;
      this.location = loc;
  }
}

class Queue {
  constructor() {
      this.start = null;
      this.end = null;
      this.size = 0;
  }
  
  isEmpty() {
      if (this.size != 0) return false;
      else return true;
  }
  
  push(data, loc) {
      const newNode = new Node(data, loc);
      if (this.isEmpty()) {
          this.start = newNode;
          this.end = newNode;
      }
      else {
          this.end.rear = newNode;
          this.end = newNode;
      }
      this.size++;
  }
  
  pop() {
      if (this.isEmpty()) return;
      if (this.size == 1) {
          this.end = null;
          this.start = null;
      }
      else this.start = this.start.rear;
      this.size--;
  }
  
  getFront() {
      if (this.isEmpty()) return;
      return this.start;
  } 
  
  getSize() {
      return this.size;
  }
}

function solution(priorities, location) {
  let priorityArr = [...priorities];
  let target = priorityArr[location];
  priorities.sort()
  
  const que = new Queue();
  
  for (let i = 0; i < priorityArr.length; i++) {
      que.push(priorityArr[i], i);
      
  }
      
  
  let answer = 0;
  while(true) {
      if (que.getFront().data == priorities[priorities.length - 1]) {
          if ((que.getFront().data == priorityArr[location]) && (que.getFront().location == location)) 
              return answer + 1;
          que.pop();
          priorities.pop();
          answer++;
      }
      else {
          que.push(que.getFront().data, que.getFront().location);
          que.pop();
      }
  }
  
  console.log(priorities, priorityArr, location);
}