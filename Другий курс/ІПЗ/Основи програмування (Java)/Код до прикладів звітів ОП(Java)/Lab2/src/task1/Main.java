package task1;

/**
 * Клас для запуску програми
 */
public class Main {
    /**
     * Метод для запуску програми
     */
    public static void main(String[] args) {
        DoctorWithArray doctor = new DoctorWithArray("House", 10, new Appointment[]{
                new Appointment("01.11", 3, "A"),
                new Appointment("02.11", 1, "C"),
                new Appointment("03.11", 2, "BB")
        });
        System.out.println(doctor);
        System.out.printf("Average amount of visitors on appointment: %.2f\n", doctor.getAverageVisitors());
        System.out.printf("Appointment with minimum amount of visitors:\n%s\n", doctor.getAppointmentWithMinVisitors());
        System.out.printf("Appointment with longest comment:\n%s\n", doctor.getAppointmentWithLongestComment());

        doctor.sortByVisitorsAscending();
        System.out.printf("\nSorted by amount of visitors on appointments:\n%s", doctor);
        doctor.sortByCommentAlphabetically();
        System.out.printf("\nSorted by appointments comments alphabetically:\n%s", doctor);

        //Appointment.test();

        //AbstractDoctor.test();

        //DoctorWithArray.test();

        //DoctorWithSorting.test();
    }
}