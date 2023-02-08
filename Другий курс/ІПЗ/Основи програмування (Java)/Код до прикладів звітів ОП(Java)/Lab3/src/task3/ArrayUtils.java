package task3;

class ArrayUtils {
    public static <T>void swapSubArrays(T[] array, int index1, int index2, int length) {
        if (array.length == 0 || index2 <= index1 || index1 < 0 || length <= 0 || index1 >= array.length || index2 >= array.length || length >= array.length || index2 + length > array.length || index1 + length > index2)
            return;

        for (int i = 0; i < length; i++) {
            T temp = array[index1 + i];
            array[index1 + i] = array[index2 + i];
            array[index2 + i] = temp;
        }
    }

    public static <T>void swapNeighbourItems(T[] array) {
        for (int i = 0; i < array.length - 1; i += 2) {
            T temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
        }
    }

    public static <T>void setArrayByIndex(T[] array, T[] subArray, int startIndex) {
        if (subArray.length == 0 || startIndex < 0 || startIndex >= array.length || subArray.length > array.length || startIndex + subArray.length > array.length)
            return;

        for (int i = 0; i < subArray.length; i++) {
            array[startIndex + i] = subArray[i];
        }
    }
}