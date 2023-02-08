package task3;

class FibonacciNumbers {
    private static final long[] fibonacciNumbers = new long[92];
    private static int greatestCounted = 1;

    static {
        fibonacciNumbers[0] = 1;
        fibonacciNumbers[1] = 1;
    }

    public static long getFibonacciNumber(int n) {
        if (n - 1 > greatestCounted) {
            for (int i = greatestCounted + 1; i <= n - 1; i++) {
                fibonacciNumbers[i] = fibonacciNumbers[i - 1] + fibonacciNumbers[i - 2];
            }
            greatestCounted = n - 1;
        }

        return fibonacciNumbers[n - 1];
    }
}
