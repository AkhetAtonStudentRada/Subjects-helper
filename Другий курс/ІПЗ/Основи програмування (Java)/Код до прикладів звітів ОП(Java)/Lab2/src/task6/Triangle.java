package task6;

class Triangle {
    private double a, b, c;
    public Triangle(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public double area() {
        return 0.25 * Math.sqrt((a + b + c) * (b + c - a) * (a + c - b) * (a + b - c));
    }

    @Override
    public String toString() {
        return String.format("Triangle{a = %.0f, b = %.0f, c = %.0f, area = %.2f}", this.a, this.b, this.c, this.area());
    }
}