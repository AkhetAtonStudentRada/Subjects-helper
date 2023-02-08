package task6;

import java.util.Map;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) {
        Map<String, String> users = new TreeMap<>();
        users.put("UserName1", "0000");
        users.put("UserName2", "1234");
        users.put("UserName3", "qwerty");
        users.put("UserName4", "qwerty0");
        users.put("UserName5", "qwerty123456");

        for (Map.Entry<String, String> entry : users.entrySet()) {
            if (entry.getValue().length() > 6) {
                System.out.printf("Username: \'%s\'\t\tpassword: \"%s\"\n", entry.getKey(), entry.getValue());
            }
        }
    }
}