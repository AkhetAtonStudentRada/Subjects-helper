namespace Task1;

internal class District
{
    public string Name { get; set; }
    public int Population { get; set; }

    public District(string name, int population)
    {
        Name = name;
        Population = population;
    }

    public override string ToString()
    {
        return $"{Name}, population: {Population}";
    }

    public override bool Equals(object? obj)
    {
        return obj is District district && Name == district.Name && Population == district.Population;
    }
}