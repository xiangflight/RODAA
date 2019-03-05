package coding_interviews;

/**
 * @author 赵翔 xiangflightATfoxmaildotcom
 * @version coding_interviews
 * @date 2019-03-05 11:37
 *
 * 替换空格
 *
 */

public class Solution4 {

    /**
     * 题目：请实现一个函数，把字符串中的的每个空格替换成"%20"。例如输入"We are happy"，则输出"We%20are%20happy"。
     * @param str 输入的字符串
     * @return 转换后的字符串
     */
    private static String replaceBlank(StringBuffer str) {
        int originLen = str.length() - 1;
        for (int i = 0; i <= originLen; i++) {
            if (str.charAt(i) == ' ') {
                str.append("  ");
            }
        }
        int p1 = originLen, p2 = str.length() - 1;
        for (; p1 >= 0; p1--) {
            char c = str.charAt(p1);
            if (c != ' ') {
                str.setCharAt(p2, c);
                p2--;
            } else {
                str.setCharAt(p2--, '0');
                str.setCharAt(p2--, '2');
                str.setCharAt(p2--, '%');
            }
        }
        return str.toString();
    }

    public static void main(String[] args) {
        String string = "We are happy";
        System.out.println(replaceBlank(new StringBuffer(string)));
    }

}
