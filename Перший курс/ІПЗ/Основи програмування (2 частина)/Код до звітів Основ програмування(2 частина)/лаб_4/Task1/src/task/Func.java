package task;

import java.util.Scanner;

public class Func {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Input x and n: \n");

        double x = scan.nextDouble();
        int n = scan.nextInt();
        if (n <= 1) {
            System.err.println("Incorrect data");
        } else {
            boolean a = true;
            double sum = 0;
            double mult = 1;
            double y = 0;
            label1:
            for (int i = 1; i <= (n - 1); i++) {
                    label:
                    for (int j = 0; j <= n; j++) {
                        if (i == j + x) {
                            System.out.println("y = " + y);
                            a = false;
                            break label1;
                        }
                        if (j + x == 0) {
                            System.err.println("Error. Division by zero");
                            a = false;
                            break label1;
                        }
                        sum += i / (j + x);
                    }
                    mult *= sum;


                System.out.println("y = " + mult);

            }
        }
    }
}