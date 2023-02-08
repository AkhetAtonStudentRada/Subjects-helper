namespace Task2;

class Program
{
    public static void Main()
    {
        Console.Write("Enter number: ");
        double n = double.Parse(Console.ReadLine());

        double squareRoot = GetSquareRoot(n, out int errorCode) ?? -1;
        Console.WriteLine(errorCode == -1 ? $"Can't get square root of negative number {n}" : $"Square root ({n}) = {squareRoot}");
    }

    static double? GetSquareRoot(double x, out int errorCode)
    {
        if (x < 0)
        {
            errorCode = -1;
            return null;
        }

        double root = x;
        double y = 1;
        double eps = 0.001;

        while (root - y > eps)
        {
            root = (root + y) / 2;
            y = x / root;
        }

        errorCode = 0;
        return root;
    }
}