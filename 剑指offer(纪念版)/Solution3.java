package coding_interviews;

/**
 * @author 赵翔 xiangflightATfoxmaildotcom
 * @version coding_interviews
 * @date 2019-03-05 11:04
 *
 * 二维数组中的查找
 *
 */

public class Solution3 {

    /**
     * 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列按照从上到下递增的顺序排序。
     *      请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
     *
     * @param arr 待查询的二维数组
     * @param target 查找的数
     * @return 查找结果
     */
    private static boolean find(int[][] arr, int target) {
        if (arr == null || arr.length == 0 || arr[0].length == 0) {
            return false;
        }
        int rows = arr.length, cols = arr[0].length;
        // 左下角 或 右上角
        int i = rows - 1, j = 0;
        while (i >= 0 && j <= cols - 1) {
            if (arr[i][j] == target) {
                return true;
            } else if (arr[i][j] < target) {
                j++;
            } else {
                i--;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int[][] matrix = {
                {1, 2, 8, 9},
                {2, 4, 9, 12},
                {4, 7, 10, 13},
                {6, 8, 11, 15}};
        System.out.println(find(matrix, 2));
        System.out.println(find(matrix, 16));
    }
}
