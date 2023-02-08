package task1;

/**
 * Клас для представлення першої сутності (Лікар)
 */
class DoctorWithArray extends AbstractDoctor {
    private String surname;
    private int workExperience;
    private Appointment[] appointments;

    public DoctorWithArray(String surname, int workExperience, Appointment[] appointments) {
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
    public int getWorkExperience() {
        return workExperience;
    }
    @Override
    public void setWorkExperience(int workExperience) {
        this.workExperience = workExperience;
    }
    @Override
    public Appointment[] getAppointments() {
        return appointments;
    }
    @Override
    public void setAppointments(Appointment[] appointments) {
        this.appointments = appointments;
    }
    @Override
    public Appointment getAppointment(int index) {
        return appointments[index];
    }
    @Override
    public void setAppointment(Appointment appointment, int index) {
        appointments[index] = appointment;
    }

    public static void test() {
        DoctorWithArray t = new DoctorWithArray("TestSurname", 5, new Appointment[]{
                new Appointment("01.11", 3, "A"),
                new Appointment("02.11", 1, "C"),
                new Appointment("03.11", 2, "BB")
        });

        // тестування методу toString()
        System.out.println(t);

        // тестування методу equals()
        DoctorWithArray t2 = new DoctorWithArray("TestSurname", 5, new Appointment[]{
                new Appointment("01.11", 3, "A"),
                new Appointment("02.11", 1, "C"),
                new Appointment("03.11", 2, "BB")
        });
        System.out.println(t.equals(t2));
        t2.setWorkExperience(0);
        System.out.println(t.equals(t2));

        // тестування методу hashCode()
        System.out.printf("\nHashcode: %d\n", t.hashCode());

        System.out.printf("Average amount of visitors on appointment: %.2f\n", t.getAverageVisitors());
        System.out.printf("Appointment with minimum amount of visitors:\n%s\n", t.getAppointmentWithMinVisitors());
        System.out.printf("Appointment with longest comment:\n%s\n", t.getAppointmentWithLongestComment());

        // тестування методів, що здійснюють сортування за ознаками
        t.sortByVisitorsAscending();
        System.out.printf("\nSorted by amount of visitors on appointments:\n%s", t);
        t.sortByCommentAlphabetically();
        System.out.printf("\nSorted by appointments comments alphabetically:\n%s", t);
    }
}