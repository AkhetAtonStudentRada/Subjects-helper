namespace Task1;

internal struct Country
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