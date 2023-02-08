package task1;

import java.util.Scanner;

/**
 * ���� Utils<br>
 * ̳����� ����� ��� ���� ����� ������ (��� �� ������������ ���).
 */
class Utils {
    /**
     * ����� createIntMatrix<br>
     * ������� ���������� ����� ����� �����, ������� ����� �� �������� ����� ���������� ����������.
     *
     * @return ���������� ����� �����
     */
    public static int[][] createIntMatrix() {
        Scanner in = new Scanner(System.in);
        System.out.print("Rows: ");
        int rows = in.nextInt();
        System.out.print("Columns: ");
        int columns = in.nextInt();
        return new int[rows][columns];
    }

    /**
     * ����� minItemInColumn<bp>
     * ��������� ��������� ������� ��������� ������� � ����������� ����� ����� �����.
     *
     * @param intMatrix ���������� ����� ����� �����
     * @param column ����� �������
     * @return ��������� ������� ��������� �������
     */
    public static int minItemInColumn(int[][]intMatrix, int column) {
        int min = intMatrix[0][column];
        for (int i = 0; i < intMatrix.length; i++) {
            if (intMatrix[i][column] < min) {
                min = intMatrix[i][column];
            }
        }
        return min;
    }
}