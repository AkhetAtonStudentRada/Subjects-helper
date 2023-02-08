namespace Task5;

public class SpecialArray<T>
{
    private T[] arr = new T[0];

    public int From { get; }
    public int To { get { return From + arr.Length; } }

    public SpecialArray(int from, int to)
    {
        From = from;
        arr = new T[to - from];
    }

    public SpecialArray(int from, params T[] arr)
    {
        From = from;
        this.arr = arr;
    }

    public T this[int index]
    {
        get { return arr[index - From]; }
        set { arr[index - From] = value; }
    }

    public static implicit operator string(SpecialArray<T> arr)
    {
        string result = "";
        foreach(T item in arr)
            result += item + " ";
        result += "\b\b";
        return result;
    }

    public IEnumerator<T> GetEnumerator()
    {
        foreach (var item in arr)
            yield return item;
    }

    public void Add(T itemToAdd)
    {
        Array.Resize(ref arr, arr.Length + 1);
        arr[^1] = itemToAdd;
    }

    public void RemoveLast()
    {
        Array.Resize(ref arr, arr.Length - 1);
    }
}