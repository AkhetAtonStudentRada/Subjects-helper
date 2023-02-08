package task_1_4;

import java.util.Scanner;

import jdk.jshell.SourceCodeAnalysis;
import task.typeConversion;
import static task.typeConversion.fromBool;
import static task.typeConversion.inBool;

public class program4 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Input int data: \n");
        int x = s.nextInt();
        System.out.println(x + "=" + inBool(x));
        System.out.print("Input bool data: \n");
        boolean y = s.nextBoolean();
        System.out.println(y + "=" + fromBool(y));
    }
}
