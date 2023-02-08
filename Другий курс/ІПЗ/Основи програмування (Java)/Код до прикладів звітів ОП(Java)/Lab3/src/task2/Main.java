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

        System.out.println("Місяць: " + month.getMonthUkrainian());
        System.out.println("Кількість днів: " + month.getAmountOfDays());
        System.out.println("Пора року: " + month.getSeasonUkrainian());
        System.out.println("Наступний місяць:\t" + month.getNext().getInfoUkrainian());
        System.out.println("Попередній місяць:\t" + month.getPrevious().getInfoUkrainian());
        System.out.println("Усі місяці:");
        Month.printAllUkrainian();
    }
}