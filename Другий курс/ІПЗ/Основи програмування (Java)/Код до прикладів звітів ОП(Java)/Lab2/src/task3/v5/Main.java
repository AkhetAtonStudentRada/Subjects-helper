//          3. ̳���� �������
//
//  ���������� ��������, �� �������� ������ ����� ����� ������� �� ����������� ��������.
// �������� ����������� ������ ������ � ����������� ������� � ������ ������ ����� ���������
// � �������� ������� ������� � ������� ����� � ����� ��������� �������.
//
//  ���������:
// 5. ������������ �������� �� ������
//
//  ��������� ������ �������� �� ���� ����� ��������.

package task3.v5;

public class Main {
    public static void main(String[] args) {
        double xStart = -2, xEnd = 2, xStep = 1;

        System.out.println(String.format("Minimum of function on [%.2f; %.2f] with step %.2f = ", xStart, xEnd, xStep) + FunctionToFindMin.getMin(xStart, xEnd, xStep, Functions::f1));

        System.out.println(String.format("Minimum of function on [%.2f; %.2f] with step %.2f = ", xStart, xEnd, xStep) + FunctionToFindMin.getMin(xStart, xEnd, xStep, Functions::f2));
    }
}