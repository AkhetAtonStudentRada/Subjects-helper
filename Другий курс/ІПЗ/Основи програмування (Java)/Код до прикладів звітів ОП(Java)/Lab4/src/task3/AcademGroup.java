package task3;

import java.beans.XMLDecoder;
import java.beans.XMLEncoder;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class AcademGroup {
    private String name;
    private Student[] students;

    public AcademGroup() {}
    public AcademGroup(String name, Student[] students) {
        this.name = name;
        this.students = students;
    }

    public Student[] getStudents() {
        return students;
    }
    public void setStudents(Student[] students) {
        this.students = students;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        String result = "Group: " + name + "\nStudents:\n";
        for (Student student : students) {
            result += student + "\n";
        }
        return result;
    }

    public void writeToXMLFile(String fileName) {
        try (XMLEncoder xmlEncoder = new XMLEncoder(new FileOutputStream(fileName))) {
            xmlEncoder.writeObject(this);
            xmlEncoder.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public void readFromXMLFile(String fileName) {
        try (XMLDecoder xmlDecoder = new XMLDecoder(new FileInputStream(fileName))) {
            AcademGroup academGroup = (AcademGroup) xmlDecoder.readObject();
            this.name = academGroup.name;
            this.students = academGroup.students;
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
