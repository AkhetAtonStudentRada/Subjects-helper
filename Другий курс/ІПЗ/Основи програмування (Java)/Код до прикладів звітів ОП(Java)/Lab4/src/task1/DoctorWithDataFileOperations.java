package task1;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class DoctorWithDataFileOperations extends DoctorWithFileOperations {
    public DoctorWithDataFileOperations(DoctorWithArray doctor) {
        this(doctor.getSurname(), doctor.getWorkExperience(), new ArrayList<>(Arrays.stream(doctor.getAppointments()).toList()).toArray(new Appointment[0]));
    }
    public DoctorWithDataFileOperations(String surname, int workExperience, Appointment[] appointments) {
        super(surname, workExperience, appointments);
    }

    @Override
    public void readFromFile(String fileName) {
        try (DataInputStream in = new DataInputStream(new FileInputStream(fileName))) {
            setSurname(in.readUTF());
            setWorkExperience(in.readInt());
            List<Appointment> appointments = new ArrayList<>();
            int count = in.readInt();
            for (int i = 0; i < count; i++) {
                String day = in.readUTF();
                int visitors = in.readInt();
                String comment = in.readUTF();
                appointments.add(new Appointment(day, visitors, comment));
            }
            setAppointments(appointments.toArray(new Appointment[0]));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public void writeToFile(String fileName) {
        try (DataOutputStream out = new DataOutputStream(new FileOutputStream(fileName))) {
            out.writeUTF(getSurname());
            out.writeInt(getWorkExperience());
            out.writeInt(getAppointments().length);
            for (int i = 0; i < getAppointments().length; i++) {
                out.writeUTF(getAppointments()[i].getDay());
                out.writeInt(getAppointments()[i].getVisitors());
                out.writeUTF(getAppointments()[i].getComment());
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}