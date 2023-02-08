namespace Task5;

internal static class LambdaListUtils
{
    public static IEnumerable<int> GetSquares(this List<int> list)
    {
        return list.FindAll(x => x == Math.Pow(Convert.ToInt32(Math.Sqrt(x)), 2));
    }

    public static void SortByAbsDescending(this List<int> list)
    {
        list.Sort((x1, x2) => -Math.Abs(x1).CompareTo(Math.Abs(x2)));
    }
}