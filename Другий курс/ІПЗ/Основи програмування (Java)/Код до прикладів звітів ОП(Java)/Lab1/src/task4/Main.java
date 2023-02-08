package task4;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.println("\"" + args[0] + "\" length: " + args[0].length());
        System.out.print("Enter needed length: ");
        Scanner in = new Scanner(System.in);
        int length = in.nextInt();
        in.close();
        String alignedString = AlignmentOfString.alignString(args[0], length);
        System.out.println("\"" + alignedString + "\" length: " + alignedString.length());
    }
}