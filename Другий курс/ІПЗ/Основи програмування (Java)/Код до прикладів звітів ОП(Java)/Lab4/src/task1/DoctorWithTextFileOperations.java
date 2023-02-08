package task1;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class DoctorWithTextFileOperations extends DoctorWithFileOperations {
    public DoctorWithTextFileOperations(DoctorWithArray doctor) {
        this(doctor.getSurname(), doctor.getWorkExperience(), new ArrayList<>(Arrays.stream(doctor.getAppointments()).toList()).toArray(new Appointment[0]));
    }
    public DoctorWithTextFileOperations(String surname, int workExperience, Appointment[] appointments) {
        super(surname, workExperience, appointments);
    }

    @Override
    public void readFromFile(String fileName) {
        try (Scanner scanner = new Scanner(new FileReader(fileName))) {
            setSurname(scanner.nextLine());
            setWorkExperience(scanner.nextInt());
            List<Appointment> appointments = new ArrayList<>();
            while (scanner.hasNext()) {
                String day = scanner.next();
                int visitors = scanner.nextInt();
                String comment = scanner.next();
                appointments.add(new Appointment(day, visitors, comment));
            }
            setAppointments(appointments.toArray(new Appointment[0]));
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public void writeToFile(String fileName) {
        try (PrintWriter out = new PrintWriter(new FileWriter(fileName))) {
            out.println(getSurname());
            out.println(getWorkExperience());
            for (Appointment appointment : getAppointments()) {
                out.println(appointment.getDay());
                out.println(appointment.getVisitors());
                out.println(appointment.getComment());
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
