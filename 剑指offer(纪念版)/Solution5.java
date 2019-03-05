package coding_interviews;

import java.util.ArrayList;
import java.util.Stack;

/**
 * @author 赵翔 xiangflightATfoxmaildotcom
 * @version coding_interviews
 * @date 2019-03-05 11:58
 *
 * 从尾到头打印链表
 *
 */

public class Solution5 {

    /**
     * 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值
     * @param listNode 链表的头节点
     * @return 输出的ArrayList
     */
    private static ArrayList<Integer> printListFromTailToHead(ListNode listNode) {
        if (listNode == null) {
            return null;
        }
        ArrayList<Integer> ret = new ArrayList<>();
        ListNode p = listNode;
        while (p != null) {
            ret.add(0, p.val);
            p = p.next;
        }
        return ret;
    }

    // 使用栈
    private static ArrayList<Integer> printListFromTailToHead2(ListNode listNode) {
        Stack<Integer> stack = new Stack<>();
        while (listNode != null) {
            stack.push(listNode.val);
            listNode = listNode.next;
        }
        ArrayList<Integer> ret = new ArrayList<>();
        while (!stack.isEmpty()) {
            ret.add(stack.pop());
        }
        return ret;
    }

    // 使用递归
    private static ArrayList<Integer> printListFromTailToHead3(ListNode listNode) {
        ArrayList<Integer> ret = new ArrayList<>();
        if (listNode != null) {
            ret.addAll(printListFromTailToHead3(listNode.next));
            ret.add(listNode.val);
        }
        return ret;
    }

    // 使用头插法构件逆序链表
    private static ArrayList<Integer> printListFromTailToHead4(ListNode listNode) {
       ListNode dummyNode = new ListNode(0);
       while (listNode != null) {
           ListNode next = listNode.next;
           listNode.next = dummyNode.next;
           dummyNode.next = listNode;
           listNode = next;
       }
       ArrayList<Integer> ret = new ArrayList<>();
       ListNode p = dummyNode.next;
       while (p != null) {
           ret.add(p.val);
           p = p.next;
       }
       return ret;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        for (int ele: printListFromTailToHead4(head)) {
            System.out.print(ele + " ");
        }
        System.out.println();
    }

}
