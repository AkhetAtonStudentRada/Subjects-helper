//          3. Мінімум функції
//
//  Реалізувати програму, що дозволяє знайти мінімум деякої функції на визначеному інтервалі.
// Алгоритм знаходження мінімуму полягає в послідовному переборі з певним кроком точок інтервалу
// і порівнянні значень функції в поточній точці з раніше знайденим мінімумом.
//
//  Реалізація:
// 5. Використання посилань на методи
//
//  Перевірити роботу програми на двох різних функціях.

package task3.v5;

public class Main {
    public static void main(String[] args) {
        double xStart = -2, xEnd = 2, xStep = 1;

        System.out.println(String.format("Minimum of function on [%.2f; %.2f] with step %.2f = ", xStart, xEnd, xStep) + FunctionToFindMin.getMin(xStart, xEnd, xStep, Functions::f1));

        System.out.println(String.format("Minimum of function on [%.2f; %.2f] with step %.2f = ", xStart, xEnd, xStep) + FunctionToFindMin.getMin(xStart, xEnd, xStep, Functions::f2));
    }
}