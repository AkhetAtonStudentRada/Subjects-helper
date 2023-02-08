namespace Task5;

internal class Function1 : AbstractRootsFinder
{
    public override double Function(double x)
    {
        return Math.Sin(x);
    }
}