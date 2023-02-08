namespace Task1;

internal class Locality
{
    public string Name { get; set; }
    public int Area { get; set; }
    public Country Country { get; set; }

    public Locality(string name, int area, Country country)
    {
        Name = name;
        Area = area;
        Country = country;
    }

    public override string ToString()
    {
        return $"City: {Name}, {Country}\nArea: {Area}km^2";
    }
}