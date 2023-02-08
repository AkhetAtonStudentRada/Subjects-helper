package task3.v2;

class FunctionMinFinder {
    public static double getMin(double xStart, double xEnd, double xStep, FunctionInterface fi) {
        double min = fi.f(xStart);

        for (double x = xStart; x <= xEnd; x += xStep) {
            if (fi.f(x) < min) {
                min = fi.f(x);
            }
        }

        return min;
    }

    public static void test(FunctionInterface fi) {
        double xStart = -3;
        double xEnd = 3;
        double xStep = 1;

        System.out.printf("Minimum of function on [%.2f; %.2f] with a step %.2f = %.2f\n", xStart, xEnd, xStep, FunctionMinFinder.getMin(xStart, xEnd, xStep, fi));
    }
}
