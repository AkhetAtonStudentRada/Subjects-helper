package task2;

public class Main {
    public static void main(String[] args) {
        Month month = Month.NOVEMBER;

        System.out.println("Month: " + month.name());
        System.out.println("Amount of days: " + month.getAmountOfDays());
        System.out.println("Season: " + month.getSeason());
        System.out.println("Next month:\t\t" + month.getNext());
        System.out.println("Previous month:\t" + month.getPrevious());
        System.out.println("All months:");
        Month.printAll();

        System.out.println();

        System.out.println("̳����: " + month.getMonthUkrainian());
        System.out.println("ʳ������ ���: " + month.getAmountOfDays());
        System.out.println("���� ����: " + month.getSeasonUkrainian());
        System.out.println("��������� �����:\t" + month.getNext().getInfoUkrainian());
        System.out.println("��������� �����:\t" + month.getPrevious().getInfoUkrainian());
        System.out.println("�� �����:");
        Month.printAllUkrainian();
    }
}