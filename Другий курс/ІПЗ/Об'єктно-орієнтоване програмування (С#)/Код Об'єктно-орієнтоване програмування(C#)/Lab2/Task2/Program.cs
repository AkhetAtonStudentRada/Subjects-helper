namespace Task2;

class Program
{
    public static void Main()
    {
        string str = "lorem  ipsum dolor  sit    amet";

        string formatted = str.DeleteRedundantSpaces();

        Console.WriteLine($"String with redundant spaces:\t\t\"{str}\"");
        Console.WriteLine($"String without redundant scapes:\t\"{formatted}\"");
    }
}