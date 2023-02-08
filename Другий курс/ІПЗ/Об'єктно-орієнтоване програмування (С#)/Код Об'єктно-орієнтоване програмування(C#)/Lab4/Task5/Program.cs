namespace Task5;

public class Program
{
    public static void Main()
    {
        List<int> list = new List<int>() { 1, 2, 3, 4, 5, 6, 7 };
        Console.WriteLine(string.Join(" ", list));

        Console.WriteLine(string.Join(" ", LambdaListUtils.GetSquares(list)));

        var temp1 = new List<int>(list);
        LambdaListUtils.SortByAbsDescending(temp1);
        Console.WriteLine(string.Join(" ", temp1));


        Console.WriteLine(string.Join(" ", LinqListUtils.GetSquares(list)));

        var temp2 = new List<int>(list);
        LinqListUtils.SortByAbsDescending(temp2);
        Console.WriteLine(string.Join(" ", temp2));
    }
}