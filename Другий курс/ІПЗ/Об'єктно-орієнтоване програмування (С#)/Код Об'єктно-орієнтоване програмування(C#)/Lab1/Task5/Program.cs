namespace Task5;

class Program
{
    public static void Main()
    {
        Console.WriteLine("Enter size of 2D-array: ");
        int rows = int.Parse(Console.ReadLine());
        int cols = int.Parse(Console.ReadLine());

        int[,] twodimensArr = new int[rows, cols];

        Random random = new Random();
        for (int i = 0; i < twodimensArr.GetLength(0); i++)
            for (int j = 0; j < twodimensArr.GetLength(1); j++)
                twodimensArr[i, j] = random.Next(1, 10);

        Console.WriteLine("2-D array:");
        for (int i = 0; i < twodimensArr.GetLength(0); i++)
        {
            for (int j = 0; j < twodimensArr.GetLength(1); j++)
                Console.Write(twodimensArr[i, j] + " ");
            Console.WriteLine();
        }

        int[][] jaggedArr = new int[rows][];
        for (int i = 0; i < jaggedArr.Length; i++)
        {
            jaggedArr[i] = new int[0];
            for (int j = 0; j < cols; j++)
                if (twodimensArr[i, j] % 2 == 0)
                {
                    Array.Resize(ref jaggedArr[i], jaggedArr[i].Length + 1);
                    jaggedArr[i][^1] = twodimensArr[i, j];
                }
        }

        Console.WriteLine("Jagged 2-D array:");
        for (int i = 0; i < jaggedArr.Length; i++)
        {
            for (int j = 0; j < jaggedArr[i].Length; j++)
                Console.Write(jaggedArr[i][j] + " ");
            Console.WriteLine();
        }
    }
}