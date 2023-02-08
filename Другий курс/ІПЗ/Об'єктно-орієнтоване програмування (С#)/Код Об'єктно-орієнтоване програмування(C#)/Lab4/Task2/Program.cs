namespace Task2;

public class Program
{
    public static void Main()
    {
        dynamic[] array = new dynamic[] { 1.1, 2.2, 3.3 };
        Console.WriteLine("Double array: " + string.Join("  ", array));
        Console.WriteLine("Sum: " + ArrayDynamic.Sum(array));
        Console.WriteLine("Average: " + ArrayDynamic.Average(array));

        Console.WriteLine();

        array = new dynamic[] { new Fraction(1, 1), new Fraction(1, 2), new Fraction(1, 3) };
        Console.WriteLine("Fraction array: " + string.Join("  ", array));
        Console.WriteLine("Sum: " + ArrayDynamic.Sum(array));
        Console.WriteLine("Average: " + ArrayDynamic.Average(array));
    }
}