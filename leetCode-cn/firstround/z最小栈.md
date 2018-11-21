> 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。  
push(x) -- 将元素 x 推入栈中。  
pop() -- 删除栈顶的元素。  
top() -- 获取栈顶元素。  
getMin() -- 检索栈中的最小元素。  
示例:  
MinStack minStack = new MinStack();  
minStack.push(-2);  
minStack.push(0);  
minStack.push(-3);  
minStack.getMin();   --> 返回 -3.  
minStack.pop();  
minStack.top();      --> 返回 0.  
minStack.getMin();   --> 返回 -2.  

|push(-2)|push(0)|push(-3)|pop()|
|-|-|-|-|
|-2|0|-3|0|
||-2|0|-2|
|||-2||

~~> Solution: **链栈**，每个Node有两个指针域，分别按入栈顺序和元素大小进行链接。2018-11-02~~ 插入时需要按元素大小遍历链表决定插入位置，时间复杂度o(n)
> Solution: 