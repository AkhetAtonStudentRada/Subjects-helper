package task3;

public class Main {
    public static void main(String[] args) {
        // ��������� ��'����
        AcademGroup academGroup = new AcademGroup("SomeGroup", new Student[] {
                new Student("Alex"),
                new Student("Michael"),
                new Student("Peter")
        });

        System.out.println("Object serialized to XML-file:\n" + academGroup);

        String fileName = "AcademGroup.xml";

        // ���������� ��'���� � XML-����
        academGroup.writeToXMLFile(fileName);

        // ��������� ���������� ��'����
        AcademGroup newAcademGroup = new AcademGroup();

        // ������������ ��'���� � XML-�����
        newAcademGroup.readFromXMLFile(fileName);

        System.out.println("Object deserialized from XML-file:\n" + newAcademGroup);
    }
}
