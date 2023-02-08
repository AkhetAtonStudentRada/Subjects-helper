package task;

import java.util.Scanner;

public class individual {
    public static double var7(double x){
        final int n = 5;
        double y;
        if (x < 6){
            double sum = 0;
            for (int k = 1; k < n; k++) {
                sum += Math.pow((7 - x), 1.0 / k);
            }
            y = sum;
        }
        else {
            y = (Math.sin(0.5 * x - 3)) + 8;
        }
        return y;
    }


    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        System.out.print("Input X-start point, X-end point and step: \n");

        double xStart = s.nextDouble();
        double xEnd = s.nextDouble();
        double step = s.nextDouble();

        if (xStart > xEnd || step <= 0) {
            System.err.println("Incorrect data");
        }

        for (double x = xStart; x < xEnd; x += step){
            System.out.printf("x = %f \t y = %f \n", x, var7(x));
        }

    }


}