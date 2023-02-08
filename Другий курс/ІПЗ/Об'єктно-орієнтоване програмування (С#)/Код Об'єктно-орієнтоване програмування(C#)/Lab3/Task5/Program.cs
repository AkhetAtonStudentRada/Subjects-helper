namespace Task5;

public class Program
{
    public static void Main()
    {
        int[] array = { 1, 2, 3, 4, 5 };
        SpecialArray<int> sArray = new SpecialArray<int>(0, array);
        foreach (var item in sArray)
            Console.Write(item + " ");
        Console.WriteLine();

        Console.WriteLine(sArray);

        sArray.RemoveLast();
        Console.WriteLine(sArray);

        sArray.Add(0);
        Console.WriteLine(sArray);


        Console.WriteLine();

        List<int> list = new List<int>() { 1, 2, 3, 4, 5 };
        SpecialList<int> sList = new SpecialList<int>(0, list.ToArray());
        foreach (var item in sList)
            Console.Write(item + " ");
        Console.WriteLine();

        Console.WriteLine(sList);

        sList.RemoveLast();
        Console.WriteLine(sList);

        sList.Add(0);
        Console.WriteLine(sArray);
    }
}