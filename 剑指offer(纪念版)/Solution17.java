package coding_interviews;

/**
 * @author 赵翔 xiangflightATfoxmaildotcom
 * @version coding_interviews
 * @date 2019-03-09 21:29
 *
 * 在O(1)时间删除链表结点
 *
 */

public class Solution17 {

    /**
     * 题目：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间
     *      删除该结点
     *
     * @param head 头结点
     * @param toBeDeleted 待删除的结点
     * @return 删除的结点
     */
    public ListNode deleteNode(ListNode head, ListNode toBeDeleted) {
        if (head == null || toBeDeleted == null) {
            return null;
        }
        ListNode temp;
        // 不是尾结点
        if (toBeDeleted.next != null) {
            temp = toBeDeleted.next;
            toBeDeleted.val = temp.val;
            toBeDeleted.next = temp.next;
        } else if (head == toBeDeleted) {
            head =  null;
        } else {
            temp = head;
            while (temp.next != toBeDeleted) {
                temp = temp.next;
            }
            temp.next = null;
        }
        return head;
    }

}
