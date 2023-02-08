namespace Task5;

abstract internal class AbstractRootsFinder
{
    public abstract double Function(double x);

    public double[] GetRoots(double from, double to, double step)
    {
        double[] roots = new double[0];

        for (double x = from; x <= to - step; x += step)
        {
            if ((Function(x) > 0 && Function (x + step) < 0) || (Function(x) < 0 && Function(x + step) > 0))
            {
                double root = (x + x + step) / 2;
                Array.Resize<double>(ref roots, roots.Length + 1);
                roots[^1] = root;
            }
        }

        return roots;
    }
}