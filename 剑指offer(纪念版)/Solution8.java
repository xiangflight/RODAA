package coding_interviews;

import java.util.Random;

/**
 * @author 赵翔 xiangflightATfoxmaildotcom
 * @version coding_interviews
 * @date 2019-03-08 11:51
 *
 * 旋转数组的最小数字
 *
 */

public class Solution8 {

    public static void main(String[] args) {
        int[] arr = {3,4,5,1,2};
        final int min = new Solution8().minNumberInRotateArray(arr);
        System.out.println(min);
    }

    /**
     * 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
     *      输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
     *      例如：{3,4,5,1,2}为{1,2,3,4,5}的一个旋转。
     *
     * @param array 旋转后的数组
     * @return 数组中的最小数字
     */
    public int minNumberInRotateArray(int [] array) {
        if (array.length == 0) {
            return 0;
        }
        // l在排好序的前半部分，r在排好序的后半部分
        int l = 0, r = array.length - 1;
        int mid = l;
        while (array[l] >= array[r]) {
            if (r - l == 1) {
                mid = r;
                break;
            }
            mid = l + (r - l) / 2;
            // 如果左中右三值相等，则只能用顺序查找的方法找到最小值。
            if (array[l] == array[mid] && array[mid] == array[r]) {
                return minInOrder(array, l, r);
            }
            if (array[mid] >= array[l]) {
                l = mid;
            } else if (array[mid] <= array[r]) {
                r = mid;
            }
        }
        return array[mid];
    }

    public int minInOrder(int[] arr, int l, int r) {
        int min = arr[l];
        for (int i = l + 1; i <= r; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        return min;
    }

}
