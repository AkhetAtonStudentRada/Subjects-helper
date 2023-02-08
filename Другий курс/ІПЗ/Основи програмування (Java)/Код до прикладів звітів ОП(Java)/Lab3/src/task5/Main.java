package task5;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter sentence: ");
        String sentence = in.nextLine();
        in.close();

        StringTokenizer words = new StringTokenizer(sentence);
        Set<Character> delimiters = new HashSet<>(Arrays.asList(' ', '.', ',', ':', ';', '?', '!', '-', '(', ')', '\"'));
        Set<String> wordsInSet = new TreeSet<>();
        while (words.hasMoreTokens()) {
            String currentWord = words.nextToken();
            String clearWord = "";
            for (int i = 0; i < currentWord.length(); i++) {
                if (!delimiters.contains(currentWord.charAt(i))) {
                    clearWord += currentWord.charAt(i);
                }
            }
            wordsInSet.add(clearWord);
        }

        System.out.printf("Sentence: \"%s\"%n", sentence);
        System.out.printf("Sorted words: %s%n", Arrays.toString(wordsInSet.toArray()));;
    }
}