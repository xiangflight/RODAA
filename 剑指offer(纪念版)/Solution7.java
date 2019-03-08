package coding_interviews;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

/**
 * @author 赵翔 xiangflightATfoxmaildotcom
 * @version coding_interviews
 * @date 2019-03-06 22:31
 *
 * 用两个栈实现队列
 *
 */

public class Solution7 {

    /**
     * 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数push和pop，
     *      分别完成在队列尾部插入结点和在队列头部删除结点的功能。
     */

    Stack<Integer> stack1 = new Stack<Integer>();
    Stack<Integer> stack2 = new Stack<Integer>();

    public void push(int node) {
        stack1.push(node);
    }

    public int pop() {
        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }
        if (stack2.isEmpty()) {
            throw new RuntimeException("queue is empty");
        }
        return stack2.pop();
    }

    /**
     * 扩展：用两个队列实现一个栈。
     */
    Queue<Integer> queue1 = new LinkedList<>();
    Queue<Integer> queue2 = new LinkedList<>();

    public void pushToStack(int node) {
        if (queue1.isEmpty()) {
            queue2.offer(node);
        } else {
            queue1.offer(node);
        }
    }

    public int top() {
        int ele = 0;
        if (queue1.isEmpty() && queue2.isEmpty()) {
            throw new RuntimeException("stack is empty");
        }
        if (queue1.isEmpty()) {
            while (!queue2.isEmpty()) {
                ele = queue2.poll();
                if (!queue2.isEmpty()) {
                    queue1.offer(ele);
                }
            }
        } else {
            while (!queue1.isEmpty()) {
                ele = queue1.poll();
                if (!queue1.isEmpty()) {
                    queue2.add(ele);
                }
            }
        }
        return ele;
    }

    public static void main(String[] args) {
        Solution7 solution7 = new Solution7();
        solution7.pushToStack(1);
        System.out.println(solution7.top());
    }

}
