namespace Task4;

public class Program
{
    public static void Main()
    {
        var roots = Roots.GetRoots(-2, 2, 0.001, Math.Cos);
        foreach (var root in roots)
        {
            Console.WriteLine(root);
        }
    }
}