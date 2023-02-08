namespace Task5;

internal static class LinqListUtils
{
    public static IEnumerable<int> GetSquares(this List<int> list)
    {
        return from x in list where x == Math.Pow(Convert.ToInt32(Math.Sqrt(x)), 2) select x;
    }

    public static void SortByAbsDescending(this List<int> list)
    {
        var temp = new List<int>(from x in list orderby Math.Abs(x) descending select x);
        list.Clear();
        list.AddRange(temp);
    }
}