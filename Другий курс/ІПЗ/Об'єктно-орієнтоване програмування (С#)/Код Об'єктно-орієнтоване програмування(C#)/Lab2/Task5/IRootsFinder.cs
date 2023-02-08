namespace Task5;

public interface IRootsFinder
{
    double Function(double x);

    static double[] GetRoots(double from, double to, double step, IRootsFinder f)
    {
        double[] roots = new double[0];

        for (double x = from; x <= to - step; x += step)
        {
            if ((f.Function(x) > 0 && f.Function(x + step) < 0) || (f.Function(x) < 0 && f.Function(x + step) > 0))
            {
                double root = (x + x + step) / 2;
                Array.Resize<double>(ref roots, roots.Length + 1);
                roots[^1] = root;
            }
        }

        return roots;
    }
}