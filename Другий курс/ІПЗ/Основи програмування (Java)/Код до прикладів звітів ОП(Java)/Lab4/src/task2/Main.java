package task2;

import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        try {
            SortingIntsFromFile.readAndWriteToFile("in.txt", "firstOut.txt", "secondOut.txt");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
