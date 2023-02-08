namespace Task4;

public static class GenericUtils
{
    // methods for arrays

    public static void Swap<T>(ref T[] arr1, ref T[] arr2)
    {
        T[] temp = arr1;
        arr1 = arr2;
        arr2 = temp;
    }

    public static void SwapPairs<T>(T[] arr)
    {
        for (int i = 0; i < arr.Length - 1; i += 2)
        {
            T temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    public static void Insert<T>(ref T[] arr, T[] arrToInsert, int index)
    {
        T[] result = new T[arr.Length + arrToInsert.Length];

        for (int i = 0; i < index; i++)
            result[i] = arr[i];

        for (int i = 0; i < arrToInsert.Length; i++)
            result[index + i] = arrToInsert[i];
        

        for (int i = index; i < arr.Length; i++)
            result[arrToInsert.Length + i] = arr[i];

        arr = result;
    }

    public static void Replace<T>(ref T[] arr, T[] arrToReplace, int index)
    {
        for (int i = 0; i < arrToReplace.Length; i++)
            arr[index + i] = arrToReplace[i];
    }


    // methods for lists

    public static void Swap<T>(ref List<T> list1, ref List<T> list2)
    {
        List<T> temp = list1;
        list1 = list2;
        list2 = temp;
    }

    public static void SwapPairs<T>(List<T> list)
    {
        for (int i = 0; i < list.Count - 1; i += 2)
        {
            T temp = list[i];
            list[i] = list[i + 1];
            list[i + 1] = temp;
        }
    }

    public static void Insert<T>(ref List<T> list, List<T> listToInsert, int index)
    {
        List<T> result = new List<T>();

        for (int i = 0; i < index; i++)
            result.Add(list[i]);

        for (int i = 0; i < listToInsert.Count; i++)
            result.Add(listToInsert[i]);

        for (int i = index; i < list.Count; i++)
            result.Add(list[i]);

        list = result;
    }

    public static void Replace<T>(ref List<T> list, List<T> listToReplace, int index)
    {
        List<T> result = new List<T>();

        for (int i = 0; i < index; i++)
            result.Add(list[i]);

        for (int i = 0; i < listToReplace.Count; i++)
            result.Add(listToReplace[i]);

        for (int i = result.Count; i < list.Count; i++)
            result.Add(list[i]);

        list = result;
    }
}