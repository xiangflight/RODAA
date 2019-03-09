package coding_interviews;

/**
 * @author 赵翔 xiangflightATfoxmaildotcom
 * @version coding_interviews
 * @date 2019-03-09 11:42
 *
 * 跳台阶
 *
 */

public class Solution10 {

    /**
     * 题目：一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙
     *      跳上一个n级的台阶总共有多少种跳法。
     *
     * @param target target级台阶
     * @return 跳法总数
     */
    public int JumpFloor(int target) {
        if (target <= 2) {
            return target;
        }
        int first = 1;
        int second = 2;
        int ret = 0;
        for (int i = 3; i <= target; i++) {
            ret = first + second;
            first = second;
            second = ret;
        }
        return ret;
    }

}
