package task3.v3;

interface FunctionToFindMin {
    double f(double x);

    static double getMin(double xStart, double xEnd, double xStep, FunctionToFindMin fftm) {
        double min = fftm.f(xStart);

        for (double x = xStart; x <= xEnd; x += xStep) {
            if (fftm.f(x) < min) {
                min = fftm.f(x);
            }
        }

        return min;
    }
}
