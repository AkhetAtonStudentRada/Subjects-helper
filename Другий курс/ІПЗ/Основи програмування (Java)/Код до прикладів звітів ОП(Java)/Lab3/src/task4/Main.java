package task4;

import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Integer> integerList = Arrays.asList(0, -1, 2, -3, 4, -5, 6, -7, 8, -9);
        System.out.println("List: " + Arrays.toString(integerList.toArray()));

        System.out.println("First index of item equals 0: " + NumberListUtils.firstIndexOfZero(integerList));
        System.out.println("Amount of negative numbers in list: " + NumberListUtils.amountOfNegatives(integerList));
        System.out.println("Last negative number in list: " + NumberListUtils.lastNegative(integerList));

        System.out.println();

        List<Double> doubleList = Arrays.asList(0.0, -1.1, 2.2, -3.3, 4.4, -5.5, 6.6, -7.7, 8.8, -9.9);
        System.out.println("List: " + Arrays.toString(doubleList.toArray()));

        System.out.println("First index of item equals 0: " + NumberListUtils.firstIndexOfZero(doubleList));
        System.out.println("Amount of negative numbers in list: " + NumberListUtils.amountOfNegatives(doubleList));
        System.out.println("Last negative number in list: " + NumberListUtils.lastNegative(doubleList));
    }
}