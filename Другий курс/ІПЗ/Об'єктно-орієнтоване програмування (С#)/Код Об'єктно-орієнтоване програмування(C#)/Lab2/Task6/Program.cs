namespace Task6;

class Program
{
    public static void Main()
    {
        Point3D point = new Point3D(1, 2, 3);

        Console.WriteLine("Point coordinates:  " + point);
        Console.WriteLine("Distance to origin = " + point.GetDistanceToOrigin());
    }
}