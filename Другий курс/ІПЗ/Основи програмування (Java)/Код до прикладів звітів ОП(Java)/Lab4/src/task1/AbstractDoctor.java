package task1;

import java.util.Arrays;
import java.util.Objects;

/**
 * Абстрактний клас для представлення першої сутності (Лікар)
 */
abstract class AbstractDoctor {
    public abstract String getSurname();
    public abstract void setSurname(String surname);
    public abstract int getWorkExperience();
    public abstract void setWorkExperience(int workExperience);
    public abstract Appointment[] getAppointments();
    public abstract void setAppointments(Appointment[] appointments);
    public abstract Appointment getAppointment(int index);
    public abstract void setAppointment(Appointment appointment, int index);

    @Override
    public String toString() {
        String info = String.format("Doctor: %s\nWork experience: %d years\nAppointments:\n", getSurname(), getWorkExperience());
        for (int i = 0; i < getAppointments().length; i++) {
            info += getAppointment(i) + "\n";
        }
        return info;
    }
    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        AbstractDoctor ad = (AbstractDoctor) obj;
        return Objects.equals(this.getSurname(), ad.getSurname()) && Objects.equals(this.getWorkExperience(), ad.getWorkExperience()) && Arrays.equals(this.getAppointments(), ad.getAppointments());
    }
    @Override
    public int hashCode() {
        int result = Objects.hash(this.getSurname(), this.getWorkExperience());
        result = 31 * result + Arrays.hashCode(this.getAppointments());
        return result;
    }

    /**
     * Метод, що реалізує основне завдання (середня кількість відвідувачів)
     *
     * @return середня кількість відвідувачів на всіх прийомах цього лікаря
     */
    public double getAverageVisitors() {
        int sum = 0;
        for (int i = 0; i < getAppointments().length; i++) {
            sum += getAppointment(i).getVisitors();
        }
        return (double) sum / (double) getAppointments().length;
    }
    /**
     * Метод, що реалізує основне завдання (прийом з найменшою кількістю відвідувачів)
     *
     * @return прийом у цього лікаря, на якому була найменша кількість відвідувачів
     */
    public Appointment getAppointmentWithMinVisitors() {
        Appointment min = getAppointments()[0];
        for (int i = 0; i < getAppointments().length; i++) {
            if (getAppointment(i).getVisitors() < min.getVisitors()) {
                min = getAppointment(i);
            }
        }
        return min;
    }
    /**
     * Метод, що реалізує основне завдання (прийом з найдовшим коментарем)
     *
     * @return прийом з найдовшим коментарем
     */
    public Appointment getAppointmentWithLongestComment() {
        Appointment longestComment = getAppointments()[0];
        for (int i = 0; i < getAppointments().length; i++) {
            if (getAppointment(i).getComment().length() > longestComment.getComment().length()) {
                longestComment = getAppointment(i);
            }
        }
        return longestComment;
    }

    /**
     * Метод, що здійснює сортування за першою ознакою (За збільшенням кількості відвідувачів) методом сортування бульбашкою
     */
    public void sortByVisitorsAscending() {
        boolean mustSort = true;
        while (mustSort) {
            mustSort = false;
            for (int i = 1; i < getAppointments().length; i++) {
                if (getAppointment(i).getVisitors() < getAppointment(i - 1).getVisitors()) {
                    Appointment temp = getAppointment(i);
                    setAppointment(getAppointment(i - 1), i);
                    setAppointment(temp, i - 1);
                    mustSort = true;
                }
            }
        }
    }
    /**
     * Метод, що здійснює сортування за другою ознакою (За алфавітом коментаря) методом сортування включенням
     */
    public void sortByCommentAlphabetically() {
        for (int left = 0; left < getAppointments().length; left++) {
            Appointment value = getAppointment(left);
            int i = left - 1;
            for (; i >= 0; i--) {
                if (value.getComment().compareTo(getAppointment(i).getComment()) < 0) {
                    setAppointment(getAppointment(i), i + 1);
                } else {
                    break;
                }
            }
            setAppointment(value, i + 1);
        }
    }

    public static void test(){
        // клас, що успадковує абстрактний клас для того, щоб його протестувати
        class AbstractDoctorTestClass extends AbstractDoctor {
            private String surname;
            private int workExperience;
            private Appointment[] appointments;
            public AbstractDoctorTestClass(String surname, int workExperience, Appointment[] appointments) {
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
        }

        AbstractDoctorTestClass t = new AbstractDoctorTestClass("TestSurname", 5, new Appointment[]{
           new Appointment("01.11", 3, "A"),
           new Appointment("02.11", 1, "C"),
           new Appointment("03.11", 2, "BB")
        });

        // тестування методу toString()
        System.out.println(t);

        // тестування методу equals()
        AbstractDoctorTestClass t2 = new AbstractDoctorTestClass("TestSurname", 5, new Appointment[]{
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