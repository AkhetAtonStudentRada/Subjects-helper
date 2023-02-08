package task1;

import java.util.Random;
import java.util.Scanner;

/**
 * ���� LoopsImplementation<br>
 * � ���� ��������� ������ ��� ��������� �������� ����� ����������� ����� � �������.
 */
class LoopsImplementation {
    /**
     * ����� LoopsImplementation.test<br>
     * ��������������� ��� ������������ ������ ��������� ����� ����������� ����� ����� ����� �� ������ � ��������
     * ����������.<br>
     * � ����� ����������� ���������� ����� ����� �����, ���� ������������ ����������� ��������� ���������� ��������
     * �� ������� �� ���������� �� �����. ���� ����������� ����� �����, ���� ������������ ����������� ������� �������
     * �������, �������� � ������� �� ����������, ���� ���� ��������� �� ��������, �������� � ������� �� ���� ����������.
     */
    public static void test() {
        int[][] intMatrix = Utils.createIntMatrix();
        fillRandomNumbers(intMatrix);
        System.out.println("Integer matrix:");
        printIntMatrix(intMatrix);
        String[] stringArray = createStringArray(intMatrix);
        System.out.println("String array before sorting:");
        printStringArray(stringArray);
        sortStringArrayByLengthAscending(stringArray);
        System.out.println("String array after sorting:");
        printStringArray(stringArray);
    }

    /**
     * ����� fillRandomNumbers<br>
     * �������� ���������� ����� ����� ����� ����������� ��������� ���������� �������� �� �������� (������� �������
     * �� 8 ������� �� 26 ���������).
     *
     * @param intMatrix ���������� ����� ����� �����
     */
    public static void fillRandomNumbers(int[][] intMatrix) {
        for (int i = 0; i < intMatrix.length; i++) {
            for (int j = 0; j < intMatrix[i].length; j++) {
                intMatrix[i][j] = (new Random().nextInt(26 / 2 - 8 / 2) + 8 / 2) * 2;
            }
        }
    }

    /**
     * ����� createStringArray<br>
     * ������� ����� ����� �������� �� ������� �������� ����������� ������ ����� �����. ������ ������������
     * ����������� ������� �������, ���� ���� ����������, ������� �������� � ������� (��������� ������� �������).
     *
     * @param intMatrix ���������� ����� ����� �����
     * @return ����� �����
     */
    public static String[] createStringArray(int[][] intMatrix) {
        String[] stringArray = new String[intMatrix[0].length];
        Scanner in = new Scanner(System.in);
        System.out.print("Character: ");
        char ch = in.next().charAt(0);
        for (int i = 0; i < stringArray.length; i++) {
            stringArray[i] = "";
            for (int j = 0; j < Utils.minItemInColumn(intMatrix, i); j++) {
                stringArray[i] += ch;
            }
        }
        return stringArray;
    }

    /**
     * ����� printIntMatrix<br>
     * �������� � ������� ���������� ����� ����� �����.
     *
     * @param intMatrix ���������� ����� ����� �����
     */
    public static void printIntMatrix(int[][] intMatrix) {
        for (int i = 0; i < intMatrix.length; i++) {
            for (int j = 0; j < intMatrix[i].length; j++) {
                System.out.print(intMatrix[i][j] + "\t");
            }
            System.out.println();
        }
    }

    /**
     * ����� printStringArray<br>
     * �������� � ������� ����� �����.
     *
     * @param stringArray ����� �����
     */
    public static void printStringArray(String[] stringArray) {
        for (int i = 0; i < stringArray.length; i++) {
            System.out.println(stringArray[i]);
        }
    }

    /**
     * ����� sortStringArrayByLengthAscending<br>
     * ����� ����� ����� �� ���������� �������.
     *
     * @param stringArray ����� �����
     */
    public static void sortStringArrayByLengthAscending(String[] stringArray) {
        for (int i = 0; i < stringArray.length - 1; i++) {
            for (int j = i + 1; j < stringArray.length; j++) {
                if (stringArray[i].length() > stringArray[j].length()) {
                    String tempString = stringArray[i];
                    stringArray[i] = stringArray[j];
                    stringArray[j] = tempString;
                }
            }
        }
    }
}