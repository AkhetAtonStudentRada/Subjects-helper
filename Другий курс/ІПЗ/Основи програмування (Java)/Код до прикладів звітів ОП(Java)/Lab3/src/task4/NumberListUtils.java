package task4;

import java.util.List;

class NumberListUtils {
    public static <T extends Number>int firstIndexOfZero(List<T> list) {
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).doubleValue() == 0.0) {
                return i;
            }
        }
        return -1;
    }

    public static <T extends Number>int amountOfNegatives(List<T> list) {
        int result = 0;
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).doubleValue() < 0) {
                result++;
            }
        }
        return result;
    }

    public static <T extends Number>T lastNegative(List<T> list) {
        T lastNegative = null;
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).doubleValue() < 0) {
                lastNegative = list.get(i);
            }
        }
        return lastNegative;
    }
}