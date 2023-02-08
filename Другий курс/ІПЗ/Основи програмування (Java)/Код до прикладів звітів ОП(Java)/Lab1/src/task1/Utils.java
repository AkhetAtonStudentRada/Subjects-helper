package task1;

import java.util.Scanner;

/**
 *  лас Utils<br>
 * ћ≥стить сп≥льн≥ дл€ обох клас≥в методи (щоб не повторювавс€ код).
 */
class Utils {
    /**
     * ћетод createIntMatrix<br>
     * —творюЇ двовим≥рний масив ц≥лих чисел, к≥льк≥сть р€дк≥в та стовпц≥в €кого встановлюЇ користувач.
     *
     * @return двовим≥рний масив ц≥лих
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
     * ћетод minItemInColumn<bp>
     * «находить м≥н≥мальний елемент вказаного стовпц€ у двовим≥рному масив≥ ц≥лих чисел.
     *
     * @param intMatrix двовим≥рний масив ц≥лих чисел
     * @param column номер стовпц€
     * @return м≥н≥мальний елемент вказаного стовпц€
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