package coding_interviews;

/**
 * @author 赵翔 xiangflightATfoxmaildotcom
 * @version coding_interviews
 * @date 2019-03-09 11:59
 *
 * 矩形覆盖
 *
 */

public class Solution12 {

    /**
     * 题目：用2*1的小矩形横着或竖着去覆盖更大的矩形，请问用n个
     *      小矩形无重叠覆盖一个2*n的大矩形，总共有多少种方法。
     *      横放
     *      竖放
     *
     * @param target 小矩形个数
     * @return 覆盖的方法数
     */
    public int RectCover(int target) {
        if (target <= 2) {
            return target;
        }
        int[] fib = new int[target];
        fib[0] = 1;
        fib[1] = 2;
        for (int i = 2; i < target; i++) {
            fib[i] = fib[i-1] + fib[i-2];
        }
        return fib[target-1];
    }

}
