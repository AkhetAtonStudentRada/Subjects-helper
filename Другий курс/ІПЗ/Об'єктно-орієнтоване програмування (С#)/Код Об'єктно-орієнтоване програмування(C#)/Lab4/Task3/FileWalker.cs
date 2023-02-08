namespace Task3;

public delegate void FileEvent(FileInfo fi);
internal class FileWalker
{
    public event FileEvent FoundEvent;

    public void WalkFiles(DirectoryInfo dir)
    {
        FileInfo[] files = dir.GetFiles();
        foreach (FileInfo f in files)
        {
            FoundEvent(f);
        }
        DirectoryInfo[] dirs = dir.GetDirectories();
        foreach (DirectoryInfo d in dirs)
        {
            WalkFiles(d);
        }
    }
}