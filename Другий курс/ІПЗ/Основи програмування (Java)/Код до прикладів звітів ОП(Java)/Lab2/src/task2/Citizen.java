package task2;

class Citizen extends Human {
    private String citizenship;

    public Citizen(String name, int age, String citizenship) {
        super(name, age);
        this.citizenship = citizenship;
    }

    public String getCitizenship() {
        return citizenship;
    }

    public void setCitizenship(String citizenship) {
        this.citizenship = citizenship;
    }

    @Override
    public String toString() {
        return String.format("%s, %s", super.toString(), this.citizenship);
    }
}