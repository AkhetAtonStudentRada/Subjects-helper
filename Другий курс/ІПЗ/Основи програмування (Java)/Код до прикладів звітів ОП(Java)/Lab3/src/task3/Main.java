package task3;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Integer[] integerArray = new Integer[]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        System.out.println(Arrays.toString(integerArray));

        ArrayUtils.swapSubArrays(integerArray, 2, 6, 3);
        System.out.println(Arrays.toString(integerArray));

        ArrayUtils.swapNeighbourItems(integerArray);
        System.out.println(Arrays.toString(integerArray));

        ArrayUtils.setArrayByIndex(integerArray, new Integer[] {0, 0, 0}, 5);
        System.out.println(Arrays.toString(integerArray));

        System.out.println();

        Double[] doubleArray = new Double[]{ 0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9 };
        System.out.println(Arrays.toString(doubleArray));

        ArrayUtils.swapSubArrays(doubleArray, 2, 6, 3);
        System.out.println(Arrays.toString(doubleArray));

        ArrayUtils.swapNeighbourItems(doubleArray);
        System.out.println(Arrays.toString(doubleArray));

        ArrayUtils.setArrayByIndex(doubleArray, new Double[]{ 0.0, 0.0, 0.0 }, 5);
        System.out.println(Arrays.toString(doubleArray));

        System.out.println();

        String[] stringArray = new String[]{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
        System.out.println(Arrays.toString(stringArray));

        ArrayUtils.swapSubArrays(stringArray, 2, 6, 3);
        System.out.println(Arrays.toString(stringArray));

        ArrayUtils.swapNeighbourItems(stringArray);
        System.out.println(Arrays.toString(stringArray));

        ArrayUtils.setArrayByIndex(stringArray, new String[]{ "zero", "zero", "zero" }, 5);
        System.out.println(Arrays.toString(stringArray));
    }
}