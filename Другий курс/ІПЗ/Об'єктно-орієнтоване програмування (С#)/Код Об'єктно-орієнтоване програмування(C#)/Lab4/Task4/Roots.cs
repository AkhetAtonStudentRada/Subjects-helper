namespace Task4;

internal class Roots
{
    public delegate double F(double x);

    public static double[] GetRoots(double xStart, double xEnd, double xStep, F function)
    {
        var roots = new List<double>();

        for (double x = xStart; x <= xEnd - xStep; x += xStep)
        {
            if ((function(x) > 0 && function(x + xStep) < 0) || (function(x) < 0 && function(x + xStep) > 0))
            {
                roots.Add(x);
            }
        }

        return roots.ToArray();
    }
}