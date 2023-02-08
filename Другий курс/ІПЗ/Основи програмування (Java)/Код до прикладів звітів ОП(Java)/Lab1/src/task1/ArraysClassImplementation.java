package task1;

import java.util.*;

/**
 * Клас ArraysClassImplementation<br>
 * У класі реалізовані методи для виконання завдання через методи класу Arrays.
 */
class ArraysClassImplementation {
    /**
     * Метод ArraysClassImplementation.test<br>
     * Використовується для демонстрації роботи реалізації через функції Arrays (без циклів).<br>
     * У методі створюється двовимірний масив цілих чисел, який заповнюється випадковими додатними значеннями відповідно
     * до варіанту та виводиться на екран. Потім створюється масив рядків, який заповнюється повторенням певного символу
     * кількістю, вказаною у таблиці та виводиться, після чого сортується за правилом, вказаним в таблиці та знов виводиться.
     */
    public static void test() {
        int[][] intMatrix = Utils.createIntMatrix();
        Arrays.setAll(intMatrix, i -> getRandomIntArray(intMatrix[0].length));
        System.out.println("Integer matrix:");
        System.out.println(Arrays.deepToString(intMatrix));
        Scanner in = new Scanner(System.in);
        System.out.print("Character: ");
        char ch = in.next().charAt(0);
        String[] stringArray = new String[intMatrix[0].length];
        Arrays.setAll(stringArray, i -> String.valueOf(ch).repeat(Utils.minItemInColumn(intMatrix, i)));
        System.out.println("String array before sorting:");
        System.out.println(Arrays.toString(stringArray));
        Arrays.sort(stringArray, Comparator.comparingInt(String::length));
        System.out.println("String array after sorting:");
        System.out.println(Arrays.toString(stringArray));
    }

    /**
     * Метод getRandomIntArray<br>
     * Повертає одновимірний масив цілих чисел, що заповнений випадковими додатними значеннями відповідно до завдання
     * (парними числами від 8 включно до 26 невключно).
     *
     * @param length довжина одновимірного масиву цілих чисел
     * @return одновимірний масив цілих чисел, заповнений відповідними випадковими значеннями
     */
    public static int[] getRandomIntArray(int length) {
        int[] randomIntArray = new int[length];
        Arrays.setAll(randomIntArray, i -> (new Random().nextInt(26 / 2 - 8 / 2) + 8 / 2) * 2);
        return randomIntArray;
    }
}