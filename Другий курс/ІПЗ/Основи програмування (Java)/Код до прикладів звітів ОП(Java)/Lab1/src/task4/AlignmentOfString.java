package task4;

import java.util.StringTokenizer;

class AlignmentOfString {
    public static String alignString(String stringToAlign, int length) {
        StringTokenizer stringTokenizer = new StringTokenizer(stringToAlign);
        if (!stringTokenizer.hasMoreTokens()) {
            return stringToAlign + " ".repeat(length - stringToAlign.length());
        }
        int spacesInString = 0;
        for (int i = 0; i < stringToAlign.length(); i++) {
            if (stringToAlign.charAt(i) == ' ') {
                spacesInString++;
            }
        }
        String alignedString = "";
        int needToAddSpaces = length - (stringToAlign.length() - spacesInString);
        if (stringTokenizer.countTokens() == 1) {
            if (needToAddSpaces % 2 != 0)
                alignedString = " " + alignedString;
            alignedString += " ".repeat(needToAddSpaces / 2);
            alignedString += stringTokenizer.nextToken();
            alignedString += " ".repeat(needToAddSpaces / 2);
        }
        else {
            int addBetweenEachWords = needToAddSpaces / (stringTokenizer.countTokens() - 1);
            int remainderFromDivision = needToAddSpaces % (stringTokenizer.countTokens() - 1);
            for (int i = 0; i <= stringTokenizer.countTokens(); i++) {
                String token = stringTokenizer.nextToken();
                alignedString += token;
                alignedString += " ".repeat(addBetweenEachWords);
                if (remainderFromDivision > 0) {
                    alignedString += " ";
                    remainderFromDivision--;
                }
            }
            alignedString += stringTokenizer.nextToken();
        }
        return alignedString;
    }
}