namespace Task1;

internal class Country
{
    public string Name { get; set; }

    public Country(string name)
    {
        Name = name;
    }

    public override string ToString()
    {
        return Name;
    }
}