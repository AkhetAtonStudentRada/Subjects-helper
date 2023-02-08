namespace Task4;

internal class Vector
{
    public double[] Values { get; set; }
    public Vector(int length)
    {
        Values = new double[length];
    }
    public Vector(double[] values)
    {
        Values = values;
    }

    public double this[int index]
    {
        get { return Values[index]; }
        set { Values[index] = value; }
    }

    public static Vector operator+(Vector v1, Vector v2)
    {
        if (v1.Values.Length != v2.Values.Length)
            throw new Exception("Impossible operation");

        Vector result = new Vector(v1.Values.Length);

        for (int i = 0; i < v1.Values.Length; i++)
            result[i] = v1[i] + v2[i];

        return result;
    }

    public static Vector operator-(Vector v1, Vector v2)
    {
        if (v1.Values.Length != v2.Values.Length)
            throw new Exception("Can't subtract these two vectors!");

        Vector result = new Vector(v1.Values.Length);

        for (int i = 0; i < v1.Values.Length; i++)
            result[i] = v1[i] - v2[i];

        return result;
    }

    public static double operator*(Vector v1, Vector v2)
    {
        if (v1.Values.Length != v2.Values.Length)
            throw new Exception("Can't multiply these two vectors!");

        double result = 0;

        for (int i = 0; i < v1.Values.Length; i++)
            result += v1[i] * v2[i];

        return result;
    }

    public static Vector operator*(Vector v, int n)
    {
        Vector result = new Vector(v.Values.Length);

        for (int i = 0; i < v.Values.Length; i++)
            result[i] = v[i] * n;

        return result;
    }

    public static double operator/(Vector v, int n)
    {
        double result = 0;

        for (int i = 0; i < v.Values.Length; i++)
            result += v[i] / n;

        return result;
    }

    public override string ToString()
    {
        string result = "[ ";

        for (int i = 0; i < Values.Length; i++)
            result += $"{Values[i]} ";

        result += "]";

        return result;
    }
}