package task2;

enum Month {
    JANUARY(31),
    FEBRUARY(28),
    MARCH(31),
    APRIL(30),
    MAY(31),
    JUNE(30),
    JULY(31),
    AUGUST(31),
    SEPTEMBER(30),
    OCTOBER(31),
    NOVEMBER(30),
    DECEMBER(31);

    private final int amountOfDays;

    Month(int amountOfDays) {
        this.amountOfDays = amountOfDays;
    }

    public int getAmountOfDays() {
        return amountOfDays;
    }
    public String getSeason() {
        return switch (this) {
            case DECEMBER, JANUARY, FEBRUARY -> "Winter";
            case MARCH, APRIL, MAY -> "Spring";
            case JUNE, JULY, AUGUST -> "Summer";
            case SEPTEMBER, OCTOBER, NOVEMBER -> "Autumn";
        };
    }

    public Month getNext() {
        if (this == DECEMBER)
            return JANUARY;

        return values()[ordinal() + 1];
    }
    public Month getPrevious() {
        if (this == JANUARY)
            return DECEMBER;

        return values()[ordinal() - 1];
    }

    @Override
    public String toString() {
        return String.format("Month: %s  Season: %s  Amount of days: %d", name(), getSeason(), amountOfDays);
    }

    public static void printAll() {
        for (int i = 0; i < Month.values().length; i++)
            System.out.println(Month.values()[i]);
    }

    public String getMonthUkrainian() {
        return switch (this) {
            case JANUARY -> "Січень";
            case FEBRUARY -> "Лютий";
            case MARCH -> "Березень";
            case APRIL -> "Квітень";
            case MAY -> "Травень";
            case JUNE -> "Червень";
            case JULY -> "Липень";
            case AUGUST -> "Серпень";
            case SEPTEMBER -> "Вересень";
            case OCTOBER -> "Жовтень";
            case NOVEMBER -> "Листопад";
            case DECEMBER -> "Грудень";
        };
    }
    public String getSeasonUkrainian() {
        return switch (this) {
            case DECEMBER, JANUARY, FEBRUARY -> "Зима";
            case MARCH, APRIL, MAY -> "Весна";
            case JUNE, JULY, AUGUST -> "Літо";
            case SEPTEMBER, OCTOBER, NOVEMBER -> "Осінь";
        };
    }
    public String getInfoUkrainian() {
        return String.format("Місяць: %s  Пора року: %s  Кількість днів: %d", getMonthUkrainian(), getSeasonUkrainian(), amountOfDays);
    }

    public static void printAllUkrainian() {
        for (int i = 0; i < Month.values().length; i++)
            System.out.println(Month.values()[i].getInfoUkrainian());
    }
}