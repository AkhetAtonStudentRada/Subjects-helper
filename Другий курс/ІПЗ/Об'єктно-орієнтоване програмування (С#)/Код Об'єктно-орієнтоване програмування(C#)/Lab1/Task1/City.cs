namespace Task1;

internal class City
{
    public string Name { get; set; }
    public int Area { get; set; }
    public Country Country { get; set; }
    public District[] Districts { get; set; }

    public City(string name, int area, Country country, District[] districts)
    {
        Name = name;
        Area = area;
        Country = country;
        Districts = districts;
    }

    public int GetCityPopulation()
    {
        int sum = 0;
        for (int i = 0; i < Districts.Length; i++)
        {
            sum += Districts[i].Population;
        }
        return sum;
    }

    public override string ToString()
    {
        string result = $"City: {Name}, {Country}\nArea: {Area}km^2\nPopulation: {GetCityPopulation()}\nDistricts:\n";
        for (int i = 0; i < Districts.Length; i++)
        {
            result += "\t" + Districts[i] + "\n";
        }
        return result;
    }

    public District[] GetDistrictsWithName(string name)
    {
        District[] result = new District[0];

        for (int i = 0; i < Districts.Length; i++)
        {
            if (Districts[i].Name.ToLower() == name.ToLower())
            {
                Array.Resize(ref result, result.Length + 1);
                result[^1] = Districts[i];
            }
        }

        return result;
    }

    public District[] GetDistrictsWithPopulation(int from, int to)
    {
        District[] result = new District[0];

        if (to < from || to < 0)
        {
            return result;
        }

        for (int i = 0; i < Districts.Length; i++)
        {
            if (Districts[i].Population >= from && Districts[i].Population <= to)
            {
                Array.Resize(ref result, result.Length + 1);
                result[^1] = Districts[i];
            }
        }

        return result;
    }
}