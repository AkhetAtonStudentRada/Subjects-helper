package task1;

import java.util.Arrays;
import java.util.Comparator;

/**
 * ���� ��� ������������� ����� ������� (˳���) � ��������������� �������� ���������� �� ��������
 */
class DoctorWithSorting extends DoctorWithArray {
    public DoctorWithSorting(String surname, int workExperience, Appointment[] appointments) {
        super(surname, workExperience, appointments);
    }

    /**
     * �����, �� ����������� ���������� �� ������ ������� (�� ���������� ������� ����������)
     */
    @Override
    public void sortByVisitorsAscending() {
        Arrays.sort(getAppointments());
    }

    /**
     * �����, �� ����������� ���������� �� ������ ������� (�� �������� ���������)
     */
    @Override
    public void sortByCommentAlphabetically() {
        Arrays.sort(getAppointments(), new Comparator<Appointment>() {
            @Override
            public int compare(Appointment o1, Appointment o2) {
                return o1.getComment().compareTo(o2.getComment());
            }
        });
    }

    public static void test() {
        DoctorWithSorting t = new DoctorWithSorting("TestSurname", 5, new Appointment[]{
                new Appointment("01.11", 3, "A"),
                new Appointment("02.11", 1, "C"),
                new Appointment("03.11", 2, "B")
        });

        // ���������� ������ toString()
        System.out.printf("Unsorted:\n%s\n", t);

        // ���������� ������, �� ��������� ���������� �� ��������
        t.sortByVisitorsAscending();
        System.out.printf("Sorted by amount of visitors on appointments:\n%s\n", t);
        t.sortByCommentAlphabetically();
        System.out.printf("Sorted by appointments comments alphabetically:\n%s\n", t);
    }
}