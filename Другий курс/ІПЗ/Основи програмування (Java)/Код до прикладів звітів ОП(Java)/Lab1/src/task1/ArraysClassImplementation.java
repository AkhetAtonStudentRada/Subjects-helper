package task1;

import java.util.*;

/**
 * ���� ArraysClassImplementation<br>
 * � ���� ��������� ������ ��� ��������� �������� ����� ������ ����� Arrays.
 */
class ArraysClassImplementation {
    /**
     * ����� ArraysClassImplementation.test<br>
     * ��������������� ��� ������������ ������ ��������� ����� ������� Arrays (��� �����).<br>
     * � ����� ����������� ���������� ����� ����� �����, ���� ������������ ����������� ��������� ���������� ��������
     * �� ������� �� ���������� �� �����. ���� ����������� ����� �����, ���� ������������ ����������� ������� �������
     * �������, �������� � ������� �� ����������, ���� ���� ��������� �� ��������, �������� � ������� �� ���� ����������.
     */
    public static void test() {
        int[][] intMatrix = Utils.createIntMatrix();
        Arrays.setAll(intMatrix, i -> getRandomIntArray(intMatrix[0].length));
        System.out.println("Integer matrix:");
        System.out.println(Arrays.deepToString(intMatrix));
        Scanner in = new Scanner(System.in);
        System.out.print("Character: ");
        char ch = in.next().charAt(0);
        String[] stringArray = new String[intMatrix[0].length];
        Arrays.setAll(stringArray, i -> String.valueOf(ch).repeat(Utils.minItemInColumn(intMatrix, i)));
        System.out.println("String array before sorting:");
        System.out.println(Arrays.toString(stringArray));
        Arrays.sort(stringArray, Comparator.comparingInt(String::length));
        System.out.println("String array after sorting:");
        System.out.println(Arrays.toString(stringArray));
    }

    /**
     * ����� getRandomIntArray<br>
     * ������� ����������� ����� ����� �����, �� ���������� ����������� ��������� ���������� �������� �� ��������
     * (������� ������� �� 8 ������� �� 26 ���������).
     *
     * @param length ������� ������������ ������ ����� �����
     * @return ����������� ����� ����� �����, ���������� ���������� ����������� ����������
     */
    public static int[] getRandomIntArray(int length) {
        int[] randomIntArray = new int[length];
        Arrays.setAll(randomIntArray, i -> (new Random().nextInt(26 / 2 - 8 / 2) + 8 / 2) * 2);
        return randomIntArray;
    }
}