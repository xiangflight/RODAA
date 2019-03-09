package coding_interviews;

import java.util.Arrays;

/**
 * @author 赵翔 xiangflightATfoxmaildotcom
 * @version coding_interviews
 * @date 2019-03-09 11:49
 *
 * 变态跳台阶
 *
 */

public class Solution11 {

    /**
     * 题目：一只青蛙一次可以跳上1级台阶，也可以跳上2级...也可以跳上
     *      n级，此时青蛙跳上一个n级的台阶有多少种跳法。
     *      动态规划
     *
     * @param target target级台阶
     * @return 跳法总数
     */
    public int JumpFloorII1(int target) {
        int[] dp = new int[target];
        Arrays.fill(dp, 1);
        for (int i = 1; i < target; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j];
            }
        }
        return dp[target - 1];
    }

    /**
     * 题目：一只青蛙一次可以跳上1级台阶，也可以跳上2级...也可以跳上
     *      n级，此时青蛙跳上一个n级的台阶有多少种跳法。
     *      数学归纳
     *      f(n-1) = f(n-2)+f(n-3)+f(n-4)+...f(0)
     *      f(n) = f(n-1)+f(n-2)+f(n-3)+...f(0)
     *      相减得：
     *      f(n) - f(n-1) = f(n-1) => f(n) = 2 * f(n-1)
     *      等比数列
     *
     * @param target target级台阶
     * @return 跳法总数
     */
    public int JumpFloorII2(int target) {
        return (int) Math.pow(2, target - 1);
    }

}
