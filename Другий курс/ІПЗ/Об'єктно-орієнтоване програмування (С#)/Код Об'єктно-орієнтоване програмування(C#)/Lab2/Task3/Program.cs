namespace Task3;

class Program
{
    public static void Main()
    {
        Complex a = new Complex
        {
            A = 1,
            B = 1
        };
        Complex b = new Complex
        {
            A = 2,
            B = 2
        };

        Console.WriteLine("a = " + a);
        Console.WriteLine("b = " + b);

        Console.WriteLine();

        Console.WriteLine($"a + b = " + (a + b));
        Console.WriteLine($"a - b = " + (a - b));
        Console.WriteLine($"a * b = " + (a * b));
        Console.WriteLine($"a / b = " + (a / b));
    }
}