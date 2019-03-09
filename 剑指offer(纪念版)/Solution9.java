package coding_interviews;

/**
 * @author 赵翔 xiangflightATfoxmaildotcom
 * @version coding_interviews
 * @date 2019-03-09 11:19
 *
 * 斐波那契数列
 *
 */

public class Solution9 {

    /**
     * 题目：写一个函数，输入n，求斐波那契数列的第n项
     *
     * @param n 第n项
     * @return 第n项的值
     */
    public int Fibonacci1(int n) {
        if (n <= 1) {
            return n;
        }
        int[] fib = new int[n+1];
        fib[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            fib[i] = fib[i-1] + fib[i-2];
        }
        return fib[n];
    }

    /**
     * 题目：写一个函数，输入n，求斐波那契数列的第n项
     *
     * @param n 第n项
     * @return 第n项的值
     */
    public int Fibonacci2(int n) {
        if (n <= 1) {
            return n;
        }
        int first = 0;
        int second = 1;
        int ret = 0;
        for (int i = 2; i <= n; i++) {
            ret = first + second;
            first = second;
            second = ret;
        }
        return ret;
    }
}
