namespace Task7;

public class Program
{
    public static void Main()
    {
        SortedDictionary<char, int> d = new SortedDictionary<char, int>();

        Console.Write("Sentence: ");
        string sentence = Console.ReadLine();

        string[] arr = sentence.Split();

        foreach (string word in arr)
        {
            foreach (char c in word)
            {
                int count = d.ContainsKey(c) ? d[c] : 0;
                d[c] = count + 1;
            }
        }

        foreach (var pair in d)
            Console.WriteLine(pair.Key + " " + pair.Value);
    }
}