namespace Task6;

public class Program
{
    public static void Main()
    {
        Console.WriteLine("Size of set: ");
        int length = int.Parse(Console.ReadLine());
        Console.WriteLine("Range of numbers:");
        int from = int.Parse(Console.ReadLine());
        int to = int.Parse(Console.ReadLine());

        SortedSet<int> set = new SortedSet<int>();

        Random random = new Random();
        for (int i = 0; i < length; i++)
        {
            int add = random.Next(from, to);
            while (!set.Add(add))
                add = random.Next(from, to);
        }

        foreach (int number in set)
            Console.Write(number + " ");
    }
}