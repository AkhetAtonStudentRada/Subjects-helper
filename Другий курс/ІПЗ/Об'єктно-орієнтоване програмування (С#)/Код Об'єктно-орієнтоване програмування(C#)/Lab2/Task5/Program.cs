namespace Task5;

class Program
{
    public static void Main()
    {
        Function1 f1 = new Function1();
        double[] roots1 = f1.GetRoots(-5, 5, 0.01);

        Console.WriteLine("Math.sin(x) [-5; 5] roots: ");
        for (int i = 0; i < roots1.Length; i++)
        {
            Console.WriteLine(roots1[i]);
        }

        Console.WriteLine();

        Function2 f2 = new Function2();
        double[] roots2 = IRootsFinder.GetRoots(-5, 5, 0.01, f2);
        
        Console.WriteLine("Math.cos(x) [-5; 5] roots: ");
        for (int i = 0; i < roots2.Length; i++)
        {
            Console.WriteLine(roots2[i]);
        }
    }
}