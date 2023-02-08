package task2;

import java.util.Arrays;

class EratosthenesSieve {
    public static void printPrimeNumbersOf300From(int from) {
        boolean[] boolPrimeNumbers = getBoolPrimeNumbers(from);

        int[] numbers = new int[from + 301];
        setNumbers(numbers);

        setCompositeNumbersToNegative(numbers, boolPrimeNumbers);

        printPositiveNumbersFrom(numbers, from);
    }

    public static boolean[] getBoolPrimeNumbers(int n) {
        boolean[] boolPrimeNumbers = new boolean[n + 301];
        Arrays.fill(boolPrimeNumbers, true);
        boolPrimeNumbers[0] = false;
        boolPrimeNumbers[1] = false;
        for (int i = 2; i * i < n + 301; i++) {
            if (boolPrimeNumbers[i] == true) {
                for (int j = i * i; j < n + 301; j += i) {
                    boolPrimeNumbers[j] = false;
                }
            }
        }
        return boolPrimeNumbers;
    }

    public static void setNumbers(int[] numbers) {
        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = i;
        }
    }

    public static void setCompositeNumbersToNegative(int[] numbers, boolean[] boolPrimeNumbers) {
        for (int i = 0; i < numbers.length; i++) {
            if (boolPrimeNumbers[i] == false) {
                numbers[i] *= -1;
            }
        }
    }

    public static void printPositiveNumbersFrom(int[] numbers, int from) {
        for (int i = from; i < numbers.length; i++) {
            if (numbers[i] > 0) {
                System.out.print(numbers[i] + " ");
            }
        }
    }
}
