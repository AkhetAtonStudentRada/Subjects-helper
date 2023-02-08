namespace Task4;

public class Program
{
    public static void Main()
    {
        int[] arr1 = { 1, 2, 3 };
        int[] arr2 = { 4, 5, 6 };

        foreach (var item in arr1)
            Console.Write(item + "  ");
        Console.WriteLine();
        foreach (var item in arr2)
            Console.Write(item + "  ");
        Console.WriteLine();

        GenericUtils.Swap(ref arr1, ref arr2);

        foreach (var item in arr1)
            Console.Write(item + "  ");
        Console.WriteLine();
        foreach (var item in arr2)
            Console.Write(item + "  ");
        Console.WriteLine();

        GenericUtils.SwapPairs(arr1);
        foreach (var item in arr1)
            Console.Write(item + "  ");
        Console.WriteLine();

        GenericUtils.Insert(ref arr1, new int[]{ 0, 0, 0 }, 1);
        foreach (var item in arr1)
            Console.Write(item + "  ");
        Console.WriteLine();

        GenericUtils.Replace(ref arr1, new int[]{ 1, 1, 1 }, 1);
        foreach (var item in arr1)
            Console.Write(item + "  ");
        Console.WriteLine();


        Console.WriteLine();


        List<int> list1 = new List<int> { 1, 2, 3 };
        List<int> list2 = new List<int> { 4, 5, 6 };

        GenericUtils.Swap(ref list1, ref list2);

        foreach (var item in list1)
            Console.Write(item + "  ");
        Console.WriteLine();
        foreach (var item in list2)
            Console.Write(item + "  ");
        Console.WriteLine();

        GenericUtils.SwapPairs(list1);
        foreach (var item in list1)
            Console.Write(item + "  ");
        Console.WriteLine();

        GenericUtils.Insert(ref list1, new List<int>{ 0, 0, 0 }, 1);
        foreach (var item in list1)
            Console.Write(item + "  ");
        Console.WriteLine();

        GenericUtils.Replace(ref list1, new List<int>{ 1, 1, 1 }, 1);
        foreach (var item in list1)
            Console.Write(item + "  ");
        Console.WriteLine();
    }
}