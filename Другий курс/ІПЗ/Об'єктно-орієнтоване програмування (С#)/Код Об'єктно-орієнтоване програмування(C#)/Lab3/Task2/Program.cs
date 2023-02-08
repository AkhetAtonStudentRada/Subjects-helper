using System.Text;

namespace Task2;

public class Program
{
    public static void Main()
    {
        Console.Write("Length of strings to copy: ");
        int length = int.Parse(Console.ReadLine());

        try
        {
            using (StreamReader reader = new StreamReader("src.txt", Encoding.Default))
            {
                using (StreamWriter writer = new StreamWriter("dest.txt"))
                {
                    string str;
                    while ((str = reader.ReadLine()) != null)
                        if (str.Length <= length)
                            writer.WriteLine(str);
                }
            }
        }
        catch (FileNotFoundException)
        {
            Console.WriteLine("File not found!");
        }
    }
}