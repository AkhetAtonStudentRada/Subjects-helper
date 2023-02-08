//          3. ̳���� �������
//
//  ���������� ��������, �� �������� ������ ����� ����� ������� �� ����������� ��������.
// �������� ����������� ������ ������ � ����������� ������� � ������ ������ ����� ���������
// � �������� ������� ������� � ������� ����� � ����� ��������� �������.
//
//  ���������:
// 3. ������������ ���������� ��������� ���������� � ��������� �����
//
//  ��������� ������ �������� �� ���� ����� ��������.

package task3.v3;

public class Main {
    public static void main(String[] args) {
        double xStart = -2, xEnd = 2, xStep = 1;

        System.out.println (String.format("Minimum of function on [%.2f; %.2f] with step %.2f = ", xStart, xEnd, xStep)
                + FunctionToFindMin.getMin(xStart, xEnd, xStep, new FunctionToFindMin() {
            @Override
            public double f(double x) {
                return x * x;
            }
        }));

        System.out.println (String.format("Minimum of function on [%.2f; %.2f] with step %.2f = ", xStart, xEnd, xStep)
                + FunctionToFindMin.getMin(xStart, xEnd, xStep, new FunctionToFindMin() {
            @Override
            public double f(double x) {
                return x * x * x;
            }
        }));
    }
}