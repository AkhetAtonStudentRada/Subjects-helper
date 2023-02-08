package task1;

/**
 * Клас Main<br>
 * Використовується для тестування програми.
 */
public class Main {
    /**
     * Метод main<br>
     * У методі main викликаються методи для тестування роботи класів:
     * LoopsImplementation.test() традиційний підхід з циклами та роботі з окремими елементами;
     * ArraysClassImplementation.test - через функції класу Arrays (без циклів).
     *
     * @param args аргументи командної строки
     */
    public static void main(String[] args) {
        LoopsImplementation.test();
        System.out.print("\n+-------------------------+\n\n");
        ArraysClassImplementation.test();
    }
}