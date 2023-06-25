//Implement a first in first out (FIFO) queue using only two stacks. The 
//implemented queue should support all the functions of a normal queue (push, peek, pop, 
//and empty). 
//
// Implement the MyQueue class: 
//
// 
// void push(int x) Pushes element x to the back of the queue. 
// int pop() Removes the element from the front of the queue and returns it. 
// int peek() Returns the element at the front of the queue. 
// boolean empty() Returns true if the queue is empty, false otherwise. 
// 
//
// Notes: 
//
// 
// You must use only standard operations of a stack, which means only push to 
//top, peek/pop from top, size, and is empty operations are valid. 
// Depending on your language, the stack may not be supported natively. You may 
//simulate a stack using a list or deque (double-ended queue) as long as you use 
//only a stack's standard operations. 
// 
//
// 
// Example 1: 
//
// 
//Input
//["MyQueue", "push", "push", "peek", "pop", "empty"]
//[[], [1], [2], [], [], []]
//Output
//[null, null, null, 1, 1, false]
//
//Explanation
//MyQueue myQueue = new MyQueue();
//myQueue.push(1); // queue is: [1]
//myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
//myQueue.peek(); // return 1
//myQueue.pop(); // return 1, queue is [2]
//myQueue.empty(); // return false
// 
//
// 
// Constraints: 
//
// 
// 1 <= x <= 9 
// At most 100 calls will be made to push, pop, peek, and empty. 
// All the calls to pop and peek are valid. 
// 
//
// 
// Follow-up: Can you implement the queue such that each operation is amortized 
//O(1) time complexity? In other words, performing n operations will take overall 
//O(n) time even if one of those operations may take longer. 
//
// Related Topics 栈 设计 队列 👍 931 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class MyQueue {
public:
    MyQueue() {
    }
    
    void push(int x) {
        sk_in.push(x);
    }
    
    int pop() {
        if(sk_out.empty()) {
            while(!sk_in.empty()) {
                sk_out.push(sk_in.top());
                sk_in.pop();
            }
        }
        int tmp = sk_out.top();
        sk_out.pop();
        return tmp;
    }
    
    int peek() {
        if(sk_out.empty()) {
            while(!sk_in.empty()) {
                sk_out.push(sk_in.top());
                sk_in.pop();
            }
        }
        return sk_out.top();
    }

    bool empty() {
        return sk_in.empty() && sk_out.empty();
    }
private:
    stack<int> sk_in;
    stack<int> sk_out;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    //[[maybe_unused]] Solution s;
    
    return 0;
}