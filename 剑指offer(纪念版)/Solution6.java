package coding_interviews;

import java.util.HashMap;
import java.util.Map;

/**
 * @author 赵翔 xiangflightATfoxmaildotcom
 * @version coding_interviews
 * @date 2019-03-05 15:47
 *
 * 重建二叉树
 *
 */

public class Solution6 {

    /**
     * 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
     *      假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
     *
     * @param pre 前序遍历的数组
     * @param in 中序遍历的数组
     * @return 还原后的二叉树
     */
    public TreeNode reConstructBinaryTree(int [] pre,int [] in) {
        if (pre == null || in == null || pre.length == 0 || pre.length != in.length) {
            return null;
        }
        // 缓存中序遍历中每个数对应的索引
        for (int i = 0; i < in.length; i++) {
            indexForInOrders.put(in[i], i);
        }
        return reConstructBinaryTree(pre, 0, pre.length - 1, 0);
    }

    /**
     *
     * @param pre 每轮前序遍历的数组
     * @param preL 每轮前序遍历的开始位置
     * @param preR 每轮前序遍历的结束位置
     * @param inL 每轮中序遍历的开始位置
     * @return 每轮树的根结点
     */
    private TreeNode reConstructBinaryTree(int[] pre, int preL, int preR, int inL) {
        // 终止条件
        if (preL > preR) {
            return null;
        }
        int first = pre[preL];
        // 创建一个结点
        TreeNode root = new TreeNode(first);
        // 找到该值在中序遍历数组中的位置
        int inIndex = indexForInOrders.get(first);
        // 得到左子树中元素个数
        int leftTreeSize = inIndex - inL;
        // 构建左子树
        root.left = reConstructBinaryTree(pre, preL + 1, preL + leftTreeSize, inL);
        // 构建右子树
        root.right = reConstructBinaryTree(pre, preL + leftTreeSize + 1, preR, inL + leftTreeSize + 1);
        return root;
    }

    private Map<Integer, Integer> indexForInOrders = new HashMap<>();

}
