namespace Task3;

public class Program
{
    public static int fileNameLength;
    public static void Main()
    {
        Console.WriteLine("Enter name of directory:");
        string dirName = Console.ReadLine();

        Console.WriteLine("Enter length of file name:");
        fileNameLength = int.Parse(Console.ReadLine());

        DirectoryInfo dir = new DirectoryInfo(dirName);
        FileWalker walker = new FileWalker();
        walker.FoundEvent += FileFound;
        walker.WalkFiles(dir);
    }

    static void FileFound(FileInfo fi)
    {
        if (fi.Name.Length > fileNameLength)
        {
            Console.WriteLine(fi.Name);
        }
    }
}