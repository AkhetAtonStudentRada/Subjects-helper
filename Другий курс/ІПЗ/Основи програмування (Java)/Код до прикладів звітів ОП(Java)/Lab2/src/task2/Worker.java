package task2;

class Worker extends Student {
    private String company;
    private String position;

    public Worker(String name, int age, String citizenship, String university, String speciality, String company, String position) {
        super(name, age, citizenship, university, speciality);
        this.company = company;
        this.position = position;
    }

    public String getCompany() {
        return company;
    }

    public void setCompany(String company) {
        this.company = company;
    }

    public String getPosition() {
        return position;
    }

    public void setPosition(String position) {
        this.position = position;
    }

    @Override
    public String toString() {
        return String.format("%s, works %s at \'%s\'", super.toString(), this.position, this.company);
    }
}