package task2;

class Student extends Citizen {
    private String university;
    private String speciality;

    public Student(String name, int age, String citizenship, String university, String speciality) {
        super(name, age, citizenship);
        this.university = university;
        this.speciality = speciality;
    }

    public String getUniversity() {
        return university;
    }

    public void setUniversity(String university) {
        this.university = university;
    }

    public String getSpeciality() {
        return speciality;
    }

    public void setSpeciality(String speciality) {
        this.speciality = speciality;
    }

    @Override
    public String toString() {
        return String.format("%s, studies %s at %s", super.toString(), this.speciality, this.university);
    }
}