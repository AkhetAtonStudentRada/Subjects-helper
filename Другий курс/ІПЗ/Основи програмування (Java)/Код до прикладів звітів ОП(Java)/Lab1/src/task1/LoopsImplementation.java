package task1;

import java.util.Random;
import java.util.Scanner;

/**
 * Клас LoopsImplementation<br>
 * У класі реалізовані методи для виконання завдання через традиційний підхід з циклами.
 */
class LoopsImplementation {
    /**
     * Метод LoopsImplementation.test<br>
     * Використовується для демонстрації роботи реалізації через традиційний підхід через цикли та роботу з окремими
     * елементами.<br>
     * У методі створюється двовимірний масив цілих чисел, який заповнюється випадковими додатними значеннями відповідно
     * до варіанту та виводиться на екран. Потім створюється масив рядків, який заповнюється повторенням певного символу
     * кількістю, вказаною у таблиці та виводиться, після чого сортується за правилом, вказаним в таблиці та знов виводиться.
     */
    public static void test() {
        int[][] intMatrix = Utils.createIntMatrix();
        fillRandomNumbers(intMatrix);
        System.out.println("Integer matrix:");
        printIntMatrix(intMatrix);
        String[] stringArray = createStringArray(intMatrix);
        System.out.println("String array before sorting:");
        printStringArray(stringArray);
        sortStringArrayByLengthAscending(stringArray);
        System.out.println("String array after sorting:");
        printStringArray(stringArray);
    }

    /**
     * Метод fillRandomNumbers<br>
     * Заповнює двовимірний масив цілих чисел випадковими додатними значеннями відповідно до завдання (парними числами
     * від 8 включно до 26 невключно).
     *
     * @param intMatrix двовимірний масив цілих чисел
     */
    public static void fillRandomNumbers(int[][] intMatrix) {
        for (int i = 0; i < intMatrix.length; i++) {
            for (int j = 0; j < intMatrix[i].length; j++) {
                intMatrix[i][j] = (new Random().nextInt(26 / 2 - 8 / 2) + 8 / 2) * 2;
            }
        }
    }

    /**
     * Метод createStringArray<br>
     * Створює масив строк довжиною як кількість стовпців двовимірного масиву цілих чисел. Строки заповнюються
     * повторенням певного символу, який задає користувач, кількістю вказаною у таблиці (мінімальний елемент стовпця).
     *
     * @param intMatrix двовимірний масив цілих чисел
     * @return масив строк
     */
    public static String[] createStringArray(int[][] intMatrix) {
        String[] stringArray = new String[intMatrix[0].length];
        Scanner in = new Scanner(System.in);
        System.out.print("Character: ");
        char ch = in.next().charAt(0);
        for (int i = 0; i < stringArray.length; i++) {
            stringArray[i] = "";
            for (int j = 0; j < Utils.minItemInColumn(intMatrix, i); j++) {
                stringArray[i] += ch;
            }
        }
        return stringArray;
    }

    /**
     * Метод printIntMatrix<br>
     * Виводить в консоль двовимірний масив цілих чисел.
     *
     * @param intMatrix двовимірний масив цілих чисел
     */
    public static void printIntMatrix(int[][] intMatrix) {
        for (int i = 0; i < intMatrix.length; i++) {
            for (int j = 0; j < intMatrix[i].length; j++) {
                System.out.print(intMatrix[i][j] + "\t");
            }
            System.out.println();
        }
    }

    /**
     * Метод printStringArray<br>
     * Виводить в консоль масив строк.
     *
     * @param stringArray масив строк
     */
    public static void printStringArray(String[] stringArray) {
        for (int i = 0; i < stringArray.length; i++) {
            System.out.println(stringArray[i]);
        }
    }

    /**
     * Метод sortStringArrayByLengthAscending<br>
     * Сортує масив строк за збільшенням довжини.
     *
     * @param stringArray масив строк
     */
    public static void sortStringArrayByLengthAscending(String[] stringArray) {
        for (int i = 0; i < stringArray.length - 1; i++) {
            for (int j = i + 1; j < stringArray.length; j++) {
                if (stringArray[i].length() > stringArray[j].length()) {
                    String tempString = stringArray[i];
                    stringArray[i] = stringArray[j];
                    stringArray[j] = tempString;
                }
            }
        }
    }
}