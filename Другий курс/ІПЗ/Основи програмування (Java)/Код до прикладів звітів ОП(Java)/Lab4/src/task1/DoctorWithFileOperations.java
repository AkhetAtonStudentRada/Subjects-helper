package task1;

public abstract class DoctorWithFileOperations extends DoctorWithArray {
    public DoctorWithFileOperations(String surname, int workExperience, Appointment[] appointments) {
        super(surname, workExperience, appointments);
    }

    public abstract void readFromFile(String fileName);

    public abstract void writeToFile(String fileName);

    public static void test(DoctorWithFileOperations doctor, String fileName) {
        System.out.println(doctor);
        doctor.writeToFile(fileName);

        doctor.sortByVisitorsAscending();
        System.out.println("Sorted by amount of visitors:\n" + doctor);
        doctor.writeToFile("FirstSorted" + fileName);

        doctor.sortByCommentAlphabetically();
        System.out.println("Sorted by comment alphabetically:\n" + doctor);
        doctor.writeToFile("SecondSorted" + fileName);

        doctor.setSurname(null);
        doctor.setWorkExperience(0);
        doctor.setAppointments(null);

        doctor.readFromFile(fileName);
        System.out.println(doctor);

        doctor.readFromFile("FirstSorted" + fileName);
        System.out.println("Sorted by amount of visitors:\n" + doctor);

        doctor.readFromFile("SecondSorted" + fileName);
        System.out.println("Sorted by comment alphabetically:\n" + doctor);
    }
}