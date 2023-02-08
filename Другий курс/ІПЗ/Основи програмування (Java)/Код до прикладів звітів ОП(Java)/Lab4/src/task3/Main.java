package task3;

public class Main {
    public static void main(String[] args) {
        // створення об'єкту
        AcademGroup academGroup = new AcademGroup("SomeGroup", new Student[] {
                new Student("Alex"),
                new Student("Michael"),
                new Student("Peter")
        });

        System.out.println("Object serialized to XML-file:\n" + academGroup);

        String fileName = "AcademGroup.xml";

        // серіалізація об'єкту в XML-файл
        academGroup.writeToXMLFile(fileName);

        // створення порожнього об'єкту
        AcademGroup newAcademGroup = new AcademGroup();

        // десеріалізація об'єкту з XML-файлу
        newAcademGroup.readFromXMLFile(fileName);

        System.out.println("Object deserialized from XML-file:\n" + newAcademGroup);
    }
}
