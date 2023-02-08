//          4. Реалізація масиву точок через масиви дійсних чисел
//
//  Реалізувати функціональність абстрактного класу AbstractArrayOfPoints, наведеного в прикладі 3.2, у два способи:
//   1. Через використання двовимірного масиву дійсних чисел: кожен рядок масиву має відповідати точці;
//   2. Через використання одновимірного масиву дійсних чисел: кожна пара чисел у масиві має відповідати точці.
//  Здійснити тестування створених класів.
//  Примітка: не слід вносити зміни у код класу AbstractArrayOfPoints (за винятком імені пакету і реалізації методу sortByY()).

package task4;

public class Main {
    public static void main(String[] args) {
        System.out.println("2-dimensional array of points:\n");
        new TwoDimensionalArrayOfPoints().test();
        System.out.println("1-dimensional array of points:\n");
        new OneDimensionalArrayOfPoints().test();
    }
}