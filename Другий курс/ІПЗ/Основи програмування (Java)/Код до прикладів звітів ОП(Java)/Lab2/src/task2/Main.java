//          2. Ієрархія класів
//
//  Реалізувати класи "Людина", "Громадянин", "Студент", "Співробітник". Створити масив посилань на різні об'єкти
// ієрархії. Для кожного об'єкта вивести на екран рядок даних про нього.
//
//  Примітка: слід створити класи зі змістовними іменами.

package task2;

public class Main {
    public static void main(String[] args) {
        Human[] people = new Human[]{
                new Human("Alex", 20),
                new Citizen("Pier", 30, "French"),
                new Student("Mary", 19, "English", "Harvard", "math"),
                new Worker("Taras", 25, "Ukrainian", "NTU KhPI", "software development", "Google", "developer")
        };

        for (Human person : people) {
            System.out.println(String.format("%s\t%s.\n", person.getClass().toString(), person));
        }
    }
}