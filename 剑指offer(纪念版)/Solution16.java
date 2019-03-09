package coding_interviews;

import java.util.Arrays;

/**
 * @author 赵翔 xiangflightATfoxmaildotcom
 * @version coding_interviews
 * @date 2019-03-09 18:23
 *
 * 打印1到最大的n位数
 *
 */

public class Solution16 {

    /**
     * 题目：输入数字n，按顺序打印出从1到最大的n位十进制数。
     *      比如输入3，则打印出1，2，3...999
     *
     * @param n 输入的数字n
     */
    public void printOneToMaxOfNDigits(int n) {
        if (n <= 0) {
            return;
        }
        char[] numbers = new char[n];
        Arrays.fill(numbers, '0');
        while (plusOne(numbers)) {
            printNumber(numbers);
        }
    }

    private boolean plusOne(char[] numbers) {
        int bit = numbers.length - 1;
        while (bit >= 0) {
            if (numbers[bit] < 9 + '0') {
                numbers[bit]++;
                return true;
            } else {
                numbers[bit] = '0';
                bit--;
            }
        }
        return false;
    }

    private void printNumber(char[] numbers) {
        int start = 0;
        while (start < numbers.length && numbers[start] == '0') {
            start++;
        }
        while (start < numbers.length) {
            System.out.print(numbers[start++]);
        }
        System.out.println();
    }

    /**
     * 回溯法
     *
     * @param n 输入的n
     */
    public void print1ToMaxOfNDigits(int n) {
        if (n <= 0) {
            return;
        }
        char[] number = new char[n];
        print1ToMaxOfNDigits(number, 0);
    }

    private void print1ToMaxOfNDigits(char[] number, int digit) {
        // 所有的数据排列都结束了
        if (digit == number.length) {
            printNumber(number);
            return;
        }
        for (int i = 0; i < 10; i++) {
            number[digit] = (char) (i + '0');
            print1ToMaxOfNDigits(number, digit + 1);
        }
    }

    public static void main(String[] args) {
        Solution16 solution16 = new Solution16();
        solution16.print1ToMaxOfNDigits(3);
    }

}
