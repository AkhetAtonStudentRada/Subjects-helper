namespace Task2;

internal class ArrayDynamic
{
    public static dynamic Sum(dynamic[] array)
    {
        dynamic sum = 0;

        foreach (var item in array)
        {
            sum += item;
        }

        return sum;
    }

    public static dynamic Average(dynamic[] array)
    {
        return Sum(array) / array.Length;
    }
}