package task2;

import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class SortingIntsFromFile {
    public static void readAndWriteToFile(String inFileName, String firstOutFileName, String secondOutFileName) throws IOException {
        Integer[] arr = new Integer[] { };

        try (BufferedReader reader = new BufferedReader(new FileReader(inFileName));
             Scanner scanner = new Scanner(reader)) {
            while (scanner.hasNext()) {
                int n = scanner.nextInt();
                if (n > 0) {
                    Integer[] temp = new Integer[arr.length + 1];
                    System.arraycopy(arr, 0, temp, 0, arr.length);
                    temp[temp.length - 1] = n;
                    arr = temp;
                }
            }
        }

        PrintWriter writer1 = new PrintWriter(new FileWriter(firstOutFileName));
        PrintWriter writer2 = new PrintWriter(new FileWriter(secondOutFileName));

        try {
            Arrays.sort(arr, new CompareAsc());
            for (Integer n : arr) {
                writer1.print(n + " ");
            }

            Arrays.sort(arr, new CompareDesc());
            for (Integer n : arr) {
                writer2.print(n + " ");
            }
        }
        finally {
            writer1.close();
            writer2.close();
        }
    }

    private static int sumOfDigits(int n) {
        int sum = 0;
        while (n > 9) {
            sum += n % 10;
            n /= 10;
        }
        sum += n;
        return sum;
    }

    private static class CompareAsc implements Comparator<Integer> {
        @Override
        public int compare(Integer o1, Integer o2) {
            return Integer.compare(SortingIntsFromFile.sumOfDigits(o1), SortingIntsFromFile.sumOfDigits(o2));
        }
    }

    private static class CompareDesc implements Comparator<Integer> {
        @Override
        public int compare(Integer o1, Integer o2) {
            return -1 * Integer.compare(SortingIntsFromFile.sumOfDigits(o1), SortingIntsFromFile.sumOfDigits(o2));
        }
    }
}