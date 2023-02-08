package task1;

import java.util.*;

/**
 * Клас для представлення першої сутності (Лікар), у якому структурою зберігання даних про послідовність других сутностей
 * (прийомів) визначений список (ArrayList).
 */
class DoctorWithArrayList extends AbstractDoctor {
    private String surname;
    private double workExperience;
    private List<Appointment> appointments;

    public DoctorWithArrayList(String surname, double workExperience, List<Appointment> appointments) {
        this.surname = surname;
        this.workExperience = workExperience;
        this.appointments = appointments;
    }

    @Override
    public String getSurname() {
        return surname;
    }
    @Override
    public void setSurname(String surname) {
        this.surname = surname;
    }
    @Override
    public double getWorkExperience() {
        return workExperience;
    }
    @Override
    public void setWorkExperience(double workExperience) {
        this.workExperience = workExperience;
    }
    @Override
    public Appointment[] getAppointments() {
        return appointments.toArray(new Appointment[0]);
    }
    @Override
    public void setAppointments(Appointment[] appointments) {
        this.appointments = new ArrayList<>(Arrays.asList(appointments));
    }
    @Override
    public Appointment getAppointment(int index) {
        return appointments.get(index);
    }
    @Override
    public void setAppointment(Appointment appointment, int index) {
        this.appointments.set(index, appointment);
    }

    /**
     * Перевизначення методу сортування за першою ознакою (за збільшенням кількості відвідувачів) з використанням методу
     * sort() класу Collections. Позаяк у класі Appointment перевизначений метод compareTo() для порівняння об'єктів за
     * першою ознакою, сортування буде здійснюватись автоматично.
     */
    @Override
    public void sortByVisitorsAscending() {
        Collections.sort(appointments);
    }
    /**
     * Перевизначення методу сортування за другою ознакою (за алфавітом коментаря) з використанням методу sort()
     * інтерфейсу List. Під час виклику методу comparing() інтерфейсу Comparator через посилання на метод явно вказується
     * ознака, за якою треба порівнювати об'єкти в ході сортування.
     */
    @Override
    public void sortByCommentAlphabetically() {
        appointments.sort(Comparator.comparing(Appointment::getComment));
    }

    public static void test() {
        DoctorWithArrayList t = new DoctorWithArrayList("TestSurname", 5, Arrays.asList(
                new Appointment("01.11", 3, "A"),
                new Appointment("02.11", 1, "C"),
                new Appointment("03.11", 2, "B")
        ));

        System.out.println(t);

        t.sortByVisitorsAscending();
        System.out.printf("\nSorted by amount of visitors on appointments:\n%s", t);

        t.sortByCommentAlphabetically();
        System.out.printf("\nSorted by appointments comments alphabetically:\n%s", t);
    }
}
