namespace Task4;

class Program
{
    public static void Main()
    {
        Vector v1 = new Vector(new double[] { 1, 1, 1, 1, 1 });
        Vector v2 = new Vector(new double[] { 2, 2, 2, 2, 2 });
        Vector v3 = new Vector(new double[] { 3, 3, 3, 3, 3 });

        Console.WriteLine($"v1 = {v1}");
        Console.WriteLine($"v2 = {v2}");
        Console.WriteLine($"v3 = {v3}");

        Console.WriteLine();

        Console.WriteLine($"v1 + v2 = {v1 + v2}");
        Console.WriteLine($"v3 - v2 = {v3 - v2}");
        Console.WriteLine($"v2 * 2  = {v2 * 2}");
        Console.WriteLine($"v1 * v3 = {v1 * v3}");
        Console.WriteLine($"v2 / 2  = {v2 / 2}");
    }
}