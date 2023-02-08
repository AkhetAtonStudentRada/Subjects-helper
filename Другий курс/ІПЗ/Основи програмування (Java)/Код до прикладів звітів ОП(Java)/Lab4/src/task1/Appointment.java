package task1;

import java.util.Objects;

/**
 * Клас для представлення другої сутності (Прийом)
 */
class Appointment implements Comparable {
    private String day;
    private int visitors;
    private String comment;
    public Appointment(String day, int visitors, String comment) {
        this.day = day;
        this.visitors = visitors;
        this.comment = comment;
    }
    public String getDay() {
        return day;
    }
    public void setDay(String day) {
        this.day = day;
    }
    public int getVisitors() {
        return visitors;
    }
    public void setVisitors(int visitors) {
        this.visitors = visitors;
    }
    public String getComment() {
        return comment;
    }
    public void setComment(String comment) {
        this.comment = comment;
    }

    @Override
    public String toString() {
        return String.format("\tDay: %s\n\tAmount of visitors: %d\n\tComment: \"%s\"", day, visitors, comment);
    }
    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Appointment appointment = (Appointment) obj;
        return Objects.equals(visitors, appointment.visitors) && Objects.equals(day, appointment.day) && Objects.equals(comment, appointment.comment);
    }
    @Override
    public int hashCode() {
        return Objects.hash(day, visitors, comment);
    }

    /**
     * Перевизначення методу compareTo() інтерфейсу Comparable для природного порівняння об'єктів за кількістю відвідувачів на прийомі
     *
     * @param o об'єкт для порівняння
     * @return від'ємне ціле значення, нуль, або додатне ціле значення, якщо об'єкт, для якого викликаний метод менший, дорівнює, або більший за o
     */
    @Override
    public int compareTo(Object o) {
        Appointment a = (Appointment) o;
        return Integer.compare(this.visitors, a.visitors);
    }

    public static void test() {
        Appointment a = new Appointment("01.11", 1, "A");

        // тестування методу toString()
        System.out.println(a);

        // тестування методу equals()
        Appointment a2 = new Appointment("01.11", 1, "A");
        System.out.println(a.equals(a2));
        a2.setVisitors(2);
        System.out.println(a.equals(a2));

        // тестування методу hashCode()
        System.out.printf("\nHashcode: %d\n", a.hashCode());

        // тестування методу compareTo()
        System.out.println(a.compareTo(a2));
        System.out.println(a2.compareTo(a));
        a2.setVisitors(1);
        System.out.println(a.compareTo(a2));
    }
}