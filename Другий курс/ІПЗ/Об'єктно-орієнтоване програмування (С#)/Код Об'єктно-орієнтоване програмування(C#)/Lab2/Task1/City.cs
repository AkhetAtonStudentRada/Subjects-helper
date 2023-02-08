namespace Task1;

internal class City : Locality
{
    public District[] Districts { get; set; }

    public City(string name, int area, Country country, District[] districts) : base(name, area, country)
    {
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
        string result = base.ToString() + $"\nPopulation: {GetCityPopulation()}\nDistricts:\n";
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

    public static City operator +(City city, District districtToAdd)
    {
        City temp = new City(city.Name, city.Area, city.Country, new District[city.Districts.Length + 1]);
        Array.Copy(city.Districts, temp.Districts, city.Districts.Length);
        temp.Districts[^1] = districtToAdd;
        return temp;
    }

    public static City operator -(City city, District districtToRemove)
    {
        int i = 0, k = 0;
        
        City temp = new City(city.Name, city.Area, city.Country, new District[city.Districts.Length]);
        
        for ( ; i < city.Districts.Length; i++, k++)
        {
            if (city.Districts[i].Equals(districtToRemove))
                k--;
            else
                temp.Districts[k] = city.Districts[i];
        }

        if (i > k)
        {
            District[] tempDistricts = new District[k];
            Array.Copy(temp.Districts, tempDistricts, k);
            temp.Districts = tempDistricts;
        }

        return temp;
    }
}