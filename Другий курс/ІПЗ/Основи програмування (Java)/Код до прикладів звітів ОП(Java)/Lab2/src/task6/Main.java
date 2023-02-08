//          6. ��������� ���������� Comparator
//
//  �������� ���� Triangle. ��������� ��������� ��������� �����. ����� ���������� � ����� ������� ���� ���� ���������
//  �� �������� ������:
//      S(triangle) = 1 / 4 * sqrt((a + b + c) * (b + c - a) * (a + c - b) * (a + b - c)),
//  �� a, b � c � ������� ����� ����������. �� ��������� ������� Arrays.sort() �������� ���������� ������ ����������
//  �� ���������� �����. ��� ���������� ������ ���������� ��������������� ��'���, ���� ������ ��������� Comparator.

package task6;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Triangle[] triangles = new Triangle[]{
                new Triangle(1, 1, 1),
                new Triangle(3, 3, 3),
                new Triangle(2, 2, 2),
        };

        System.out.println("Triangles:");
        for (Triangle triangleToPrint : triangles) {
            System.out.println(triangleToPrint);
        }

        Arrays.sort(triangles, new CompareByAreaDescending());

        System.out.println("\nSorted by area descending:");
        for (Triangle triangleToPrint : triangles) {
            System.out.println(triangleToPrint);
        }
    }
}