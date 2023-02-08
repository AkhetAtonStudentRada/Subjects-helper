//          5. ��������� ���������� Comparable
//
//  �������� ���� Circle, ���� ������ ��������� Comparable. ������� ��������� ���� � ������ �������.
//  �������� ���������� ������ ��'���� ���� Circle �� ��������� ������� Arrays.sort().

package task5;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Circle[] circles = new Circle[] {
                new Circle(5),
                new Circle(2),
                new Circle(7)
        };

        System.out.println("Circles:");
        for (Circle circleToPrint : circles) {
            System.out.println(circleToPrint);
        }

        Arrays.sort(circles);

        System.out.println("\nCircles sorted by radius: ");
        for (Circle circleToPrint : circles) {
            System.out.println(circleToPrint);
        }
    }
}