//          4. ��������� ������ ����� ����� ������ ������ �����
//
//  ���������� ��������������� ������������ ����� AbstractArrayOfPoints, ���������� � ������� 3.2, � ��� �������:
//   1. ����� ������������ ����������� ������ ������ �����: ����� ����� ������ �� ��������� �����;
//   2. ����� ������������ ������������ ������ ������ �����: ����� ���� ����� � ����� �� ��������� �����.
//  �������� ���������� ��������� �����.
//  �������: �� ��� ������� ���� � ��� ����� AbstractArrayOfPoints (�� �������� ���� ������ � ��������� ������ sortByY()).

package task4;

public class Main {
    public static void main(String[] args) {
        System.out.println("2-dimensional array of points:\n");
        new TwoDimensionalArrayOfPoints().test();
        System.out.println("1-dimensional array of points:\n");
        new OneDimensionalArrayOfPoints().test();
    }
}