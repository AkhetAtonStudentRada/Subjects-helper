package task3.v1;

abstract class AbstractFunctionToFindMin {
    public abstract double f(double x);

    public double getMin(double xStart, double xEnd, double xStep) {
        double min = f(xStart);

        for (double x = xStart; x <= xEnd; x += xStep) {
            if (f(x) < min) {
                min = f(x);
            }
        }

        return min;
    }

    public void test() {
        double xStart = -3, xEnd = 3, xStep = 1;
        System.out.printf("Minimum of function on [%.2f; %.2f] with a step %.2f = %.2f\n", xStart, xEnd, xStep, this.getMin(xStart, xEnd, xStep));
    }
}
