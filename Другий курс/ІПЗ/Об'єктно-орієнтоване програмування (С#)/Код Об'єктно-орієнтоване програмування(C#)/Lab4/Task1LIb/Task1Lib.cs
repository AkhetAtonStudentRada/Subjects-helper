using System.Xml.Serialization;

namespace Task1Lib;

public class Locality<T>
{
    [XmlAttributeAttribute]
    public string Name { get; set; }
    [XmlAttributeAttribute]
    public int Area { get; set; }
    public T Country { get; set; }

    public Locality() { }
    public Locality(string name, int area, T country)
    {
        Name = name;
        Area = area;
        Country = country;
    }

    public override string ToString()
    {
        return $"Locality: {Name}, {Country}\nArea: {Area}km^2";
    }
}

public class City<T> : Locality<T>
{
    public List<District> Districts { get; set; }

    public City() { }
    public City(string name, int area, T country, List<District> districts) : base(name, area, country)
    {
        Districts = districts;
    }

    public int GetCityPopulation()
    {
        int sum = 0;
        for (int i = 0; i < Districts.Count; i++)
        {
            sum += Districts[i].Population;
        }
        return sum;
    }

    public override string ToString()
    {
        string result = base.ToString() + $"\nType: city\nPopulation: {GetCityPopulation()}\nDistricts:\n";
        for (int i = 0; i < Districts.Count; i++)
        {
            result += "\t" + Districts[i] + "\n";
        }
        return result;
    }

    public List<District> GetDistrictsWithName(string name)
    {
        List<District> result = new List<District>();

        for (int i = 0; i < Districts.Count; i++)
        {
            if (Districts[i].Name.ToLower() == name.ToLower())
            {
                result.Add(Districts[i]);
            }
        }

        return result;
    }
    public List<District> GetDistrictsWithPopulation(int from, int to)
    {
        List<District> result = new List<District>();

        if (to < from || to < 0)
        {
            return result;
        }

        for (int i = 0; i < Districts.Count; i++)
        {
            if (Districts[i].Population >= from && Districts[i].Population <= to)
            {
                result.Add(Districts[i]);
            }
        }

        return result;
    }

    public static City<T> operator +(City<T> city, District districtToAdd)
    {
        city.Districts.Add(districtToAdd);
        return city;
    }
    public static City<T> operator -(City<T> city, District districtToRemove)
    {
        while (city.Districts.Remove(districtToRemove)) ;
        return city;
    }

    public void SortByNameAlphabeticallyDescending()
    {
        Districts = new List<District>(from district in Districts orderby district.Name descending select district);
    }
    public void SortByPopulation()
    {
        Districts = new List<District>(from district in Districts orderby district.Population select district);
    }

    public void WriteToXml(string fileName)
    {
        XmlSerializer serializer = new(typeof(List<District>));

        using TextWriter textWriter = new StreamWriter(fileName);

        serializer.Serialize(textWriter, Districts);
    }
    public void ReadFromXml(string fileName)
    {
        XmlSerializer deserializer = new(typeof(List<District>));
        using TextReader textReader = new StreamReader(fileName);
        Districts = (List<District>)deserializer.Deserialize(textReader);
    }
}

public class District
{
    [XmlAttributeAttribute]
    public string Name { get; set; }
    [XmlAttributeAttribute]
    public int Population { get; set; }

    public District() { }
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

public struct CountryStruct
{
    [XmlAttributeAttribute]
    public string Name { get; set; }

    public CountryStruct(string name)
    {
        Name = name;
    }

    public override string ToString()
    {
        return Name;
    }
}

public class CountryClass
{
    [XmlAttributeAttribute]
    public string Name { get; set; }

    public CountryClass(string name)
    {
        Name = name;
    }

    public override string ToString()
    {
        return Name;
    }
}