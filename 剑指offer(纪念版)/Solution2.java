package coding_interviews;

/**
 * @author 赵翔 xiangflightATfoxmaildotcom
 * @version coding_interviews
 * @date 2019-03-05 10:26
 *
 * 实现Singleton模式
 *
 */

public class Solution2 {
    /**
     * 单例模式，饿汉式，线程安全
     */
    public static class Singleton {

        private final static Singleton INSTANCE = new Singleton();

        private Singleton(){}

        public static Singleton getInstance() {
            return INSTANCE;
        }
    }

    /**
     * 单例模式，懒汉式，线程不安全
     */
    public static class Singleton2 {

        private static Singleton2 INSTANCE = null;

        private Singleton2(){}

        public static Singleton2 getInstance() {
            if (INSTANCE == null) {
                INSTANCE = new Singleton2();
            }
            return INSTANCE;
        }
    }

    /**
     * 单例模式，懒汉式，线程安全，多线程环境下效率不高
     */
    public static class Singleton3 {

        private static Singleton3 INSTANCE;

        private Singleton3(){}

        public static synchronized Singleton3 getInstance() {
            if (INSTANCE == null) {
                INSTANCE = new Singleton3();
            }
            return INSTANCE;
        }
    }

    /**
     * 单例模式，懒汉式，线程安全，[推荐]
     * 优点：外部类加载时并不需要立即加载内部类，内部类不被加载则不去初始化INSTANCE，故而不占内存。
     *      只有当getInstance()方法第一次被调用时，才会去初始化INSTANCE，第一次调用getInstance()方法会导致虚拟机加载SingleTonHoler类
     *      因此，不仅能确保线程安全，也能保证单例的唯一性，同时也延迟了单例的实例化。
     *      虚拟机会保证一个类的<clinit>()方法在多线程环境中被正确地加锁、同步，
     *      如果多个线程同时去初始化一个类，那么只会有一个线程去执行这个类的<clinit>()方法，其他线程都需要阻塞等待，直到活动线程执行<clinit>()方法完毕。
     *      同一个加载器下，一个类型只会初始化一次。
     */
    public static class Singleton4 {

        private static final class SingletonHolder {
            private static final Singleton4 INSTANCE = new Singleton4();
        }

        private Singleton4(){}

        public static Singleton4 getInstance() {
            return SingletonHolder.INSTANCE;
        }
    }

    /**
     * 单例模式，DCL
     * 第一次判断null：为了避免非必要加锁
     * 有失效的时候-》原因：JVM有乱序执行的功能
     * JDK1.6 -》volatile确保INSTANCE每次均在主内存中读取
     */
    public static class Singleton5 {

        private volatile static Singleton5 INSTANCE;

        private Singleton5(){}

        public static Singleton5 getInstance() {
            if (INSTANCE == null) {
                synchronized (Singleton5.class) {
                    if (INSTANCE == null) {
                        INSTANCE = new Singleton5();
                    }
                }
            }
            return INSTANCE;
        }
    }

    public static void main(String[] args) {
        System.out.println(Singleton.getInstance() == Singleton.getInstance());
    }

}
