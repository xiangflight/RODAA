package coding_interviews;

import oneline_test.Solution1;

/**
 * @author 赵翔 xiangflightATfoxmaildotcom
 * @version coding_interviews
 * @date 2019-03-09 16:45
 *
 * 数值的整数次方
 *
 */

public class Solution14 {

    /**
     * 题目：实现函数，求base的exponent次方。不得使用
     *      函数库，同时不需要考虑大数问题。
     *
     * @param base 底数
     * @param exponent 指数
     * @return 求幂之后的值
     */
    public double power(double base, int exponent) {
        if (equal(base, 0.0) && exponent <= 0) {
            throw new RuntimeException("invalid input, base is zero and exponent is less or equal to zero.");
        }
        boolean flag = false;
        if (exponent < 0) {
            flag = true;
            exponent = -exponent;
        }
        double result = powerWithUnsignedExponent(base, exponent);
        if (flag) {
            result = 1 / result;
        }
        return result;
    }

    private static double powerWithUnsignedExponent(double base, int exponent) {
        if (exponent == 0) {
            return 1;
        }
        if (exponent == 1) {
            return base;
        }
        double result = powerWithUnsignedExponent(base, exponent >> 1);
        result *= result;
        if ((exponent & 0x1) != 0) {
            result *= base;
        }
        return result;
    }

    /**
     * 判断两个double数值是否相等
     *
     * @param num1 第一个double值
     * @param num2 第二个double值
     * @return 是否相等
     */
    private static boolean equal(double num1, double num2) {
        return (num1 - num2 < 0.0000001) && (num1 - num2 > -0.0000001);
    }

}
