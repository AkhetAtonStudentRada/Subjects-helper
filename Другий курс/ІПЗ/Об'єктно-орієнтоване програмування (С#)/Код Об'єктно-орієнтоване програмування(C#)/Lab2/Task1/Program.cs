namespace Task1;

class Program
{
    public static void Main()
    {
        City kharkiv = new City("Kharkiv", 350, new Country("Ukraine"), new District[]
        {
            new District("Industrialniy", 155_800),
            new District("Kyivskiy", 188_700),
            new District("Nemyshlyanskiy", 144_200),
            new District("Novobavarskiy", 111_200),
            new District("Osnovyanskiy", 96_500),
            new District("Saltivskiy", 310_300),
            new District("Slobidskiy", 149_800),
            new District("Kholodnogirskiy", 93_800),
            new District("Shevchenkivskiy", 220_600)
        });

        Console.WriteLine(kharkiv);

        kharkiv += new District("belgorodskiy", 0);

        Console.WriteLine(kharkiv);

        kharkiv -= kharkiv.Districts[^1];

        Console.WriteLine(kharkiv);

        Console.Write("Districts with name: ");
        string nameToFind = Console.ReadLine();
        var districtsWithName = kharkiv.GetDistrictsWithName(nameToFind);
        foreach (var district in districtsWithName)
        {
            Console.WriteLine("\t" + district);
        }

        Console.WriteLine("\nDistricts with population");
        Console.Write("From: ");
        int from = int.Parse(Console.ReadLine());
        Console.Write("To: ");
        int to = int.Parse(Console.ReadLine());
        var districtsWithPopulation = kharkiv.GetDistrictsWithPopulation(from, to);
        foreach (var district in districtsWithPopulation)
        {
            Console.WriteLine("\t" + district);
        }
    }
}