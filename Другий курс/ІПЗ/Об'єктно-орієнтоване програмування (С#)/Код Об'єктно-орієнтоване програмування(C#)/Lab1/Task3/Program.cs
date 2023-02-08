namespace Task3;

class Program
{
    public static void Main()
    {
        static void GCD(ref int n1, ref int n2)
        {
            while (n1 != 0 && n2 != 0)
            {
                if (n1 > n2)
                    n1 -= n2;
                else
                    n2 -= n1;
            }

            n1 = n2 = n1 + n2;
        }

        Console.Write("n1 = ");
        int n1 = Convert.ToInt32(Console.ReadLine());
        Console.Write("n2 = ");
        int n2 = Convert.ToInt32(Console.ReadLine());

        GCD(ref n1, ref n2);
        int gcd = n1 = n2;

        Console.WriteLine("GCD(n1, n2) = " + gcd);
    }
}