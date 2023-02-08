package task1;

public class Main {
    public static void main(String[] args) {
        DoctorWithArray doctor = new DoctorWithArray("TestSurname", 5, new Appointment[] {
                new Appointment("01.11", 3, "A"),
                new Appointment("02.11", 1, "C"),
                new Appointment("03.11", 2, "B")
        });

        DoctorWithTextFileOperations txtDoctor = new DoctorWithTextFileOperations(doctor);
        DoctorWithDataFileOperations datDoctor = new DoctorWithDataFileOperations(doctor);

        DoctorWithFileOperations.test(txtDoctor, "Doctor.txt");
        DoctorWithFileOperations.test(datDoctor, "Doctor.dat");
    }
}