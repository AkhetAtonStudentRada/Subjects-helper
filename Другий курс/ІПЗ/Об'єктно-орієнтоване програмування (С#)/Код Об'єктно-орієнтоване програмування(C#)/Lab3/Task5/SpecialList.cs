namespace Task5;

public class SpecialList<T>
{
    private List<T> list = new List<T>();

    public int From { get; }
    public int To { get { return From + list.Count; } }

    public SpecialList(int from, int to)
    {
        From = from;
        list = new List<T>(to - from);
    }

    public SpecialList(int from, params T[] list)
    {
        From = from;
        this.list = new List<T>(list);
    }

    public T this[int index]
    {
        get { return list[index - From]; }
        set { list[index - From] = value; }
    }

    public static implicit operator string(SpecialList<T> list)
    {
        string result = "";
        foreach (T item in list.list)
            result += item + " ";
        result += "\b\b";
        return result;
    }

    public IEnumerator<T> GetEnumerator()
    {
        foreach (var item in list)
            yield return item;
    }

    public void Add(T itemToAdd)
    {
        list.Add(itemToAdd);
    }

    public void RemoveLast()
    {
        list.RemoveAt(list.Count - 1);
    }
}