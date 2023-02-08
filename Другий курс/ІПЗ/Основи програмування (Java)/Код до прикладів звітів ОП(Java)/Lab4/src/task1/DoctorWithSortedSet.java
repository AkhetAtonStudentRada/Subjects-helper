package task1;

import java.util.Arrays;
import java.util.Comparator;
import java.util.SortedSet;
import java.util.TreeSet;

/**
 * ���� ��� ������������� ����� ������� (˳���), � ����� ���������� ��������� ����� ��� ����������� ������ ���������
 * (�������) ��������� ������� (SortedSet).
 */
public class DoctorWithSortedSet extends AbstractDoctor {
    private String surname;
    private int workExperience;
    private SortedSet<Appointment> appointments;

    public DoctorWithSortedSet(String surname, int workExperience, SortedSet<Appointment> appointments) {
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
        return appointments.toArray(new Appointment[0]);
    }
    @Override
    public void setAppointments(Appointment[] appointments) {
        this.appointments = new TreeSet<>(Arrays.asList(appointments));
    }
    @Override
    public Appointment getAppointment(int index) {
        return appointments.toArray(new Appointment[0])[index];
    }
    @Override
    public void setAppointment(Appointment appointment, int index) {
        this.appointments.toArray()[index] = appointment;
    }

    /**
     * �������������� ������ ���������� �� ������ ������� (�� ���������� ������� ����������). ���������� �����������
     * ������ ��������� ���� appointments ������ ��'���� TreeSet, �� ��� ��������� ����� �� ������ comparing() ����������
     * Comparator ����� ��������� �� ����� ���� ��������� ������, �� ���� ����� ���������� ��'���� � ��� ����������.
     */
    @Override
    public void sortByVisitorsAscending() {
        SortedSet<Appointment> temp = new TreeSet<>(Comparator.comparing(Appointment::getVisitors));
        temp.addAll(appointments);
        appointments = temp;
    }

    /**
     * �������������� ������ ���������� �� ������ ������� (�� �������� ���������). ���������� ����������� ������ ���������
     * ���� appointments ������ ��'���� TreeSet, �� ��� ��������� ����� �� ������ comparing() ���������� Comparator �����
     * ��������� �� ����� ���� ��������� ������, �� ���� ����� ���������� ��'���� � ��� ����������.
     */
    @Override
    public void sortByCommentAlphabetically() {
        SortedSet<Appointment> temp = new TreeSet<>(Comparator.comparing(Appointment::getComment));
        temp.addAll(appointments);
        appointments = temp;
    }

    public static void test() {
        DoctorWithSortedSet t = new DoctorWithSortedSet("TestSurname", 5, new TreeSet<>(Arrays.asList(
                new Appointment("01.11", 3, "A"),
                new Appointment("02.11", 1, "C"),
                new Appointment("03.11", 2, "B")
        )));

        System.out.println(t);

        t.sortByVisitorsAscending();
        System.out.printf("\nSorted by amount of visitors on appointments:\n%s", t);

        t.sortByCommentAlphabetically();
        System.out.printf("\nSorted by appointments comments alphabetically:\n%s", t);
    }
}
