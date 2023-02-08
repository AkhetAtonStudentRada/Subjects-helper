namespace Task2;

internal static class StringExtensionMethods
{
    public static string DeleteRedundantSpaces(this string str)
    {
        for (int i = 0; i < str.Length - 1; i++)
        {
            if (str[i] == ' ' && str[i + 1] == ' ')
            {
                str = str.Remove(i, 1);
                i--;
            }
        }

        return str;
    }
}