package coding_interviews;

/**
 * @author 赵翔 xiangflightATfoxmaildotcom
 * @version coding_interviews
 * @date 2019-03-09 16:23
 *
 * 二进制中1的个数
 *
 */

public class Solution13 {

    /**
     *
     * 题目：请实现一个函数，输入一个整数，输出该数二进制表示中
     *      1的个数。例如把9表示成二进制1001，有2位是1。因此
     *      输入9，该函数输出2。
     *
     *      n & (n-1) 可以去除二进制中最低位的1
     *      时间复杂度O(M)，M为n中1的个数
     *
     * @param n 输入的整数
     * @return 二进制中1的个数
     */
    public int numberOf1(int n) {
        int cnt = 0;
        while (n != 0) {
            cnt++;
            n &= n - 1;
        }
        return cnt;
    }

    /**
     * 利用1左移
     *
     * @param n 输入的整数
     * @return 二进制中1的个数
     */
    public int numberOfOne(int n) {
        int cnt = 0;
        int flag = 1;
        while (flag != 0) {
            if ((n & flag) != 0) {
                cnt++;
            }
            flag <<= 1;
        }
        return cnt;
    }

}
