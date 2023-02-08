package task;

import java.util.Scanner;

public class task1_2_second_var {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Input final degree: \n");

        int n = scan.nextInt();
        if (n < 0 || n > 10) {
            System.err.println("Incorrect data");
        }

        for (int i = 0; i <= n; i++) {
            System.out.printf("4 pow %d = %d\n", i, 1 << 4*i);
        }
    }
}
