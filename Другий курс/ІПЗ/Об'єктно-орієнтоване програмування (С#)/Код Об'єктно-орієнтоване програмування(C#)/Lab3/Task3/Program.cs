using System.Xml.Serialization;

namespace Task3;

public class Program
{
    public static void Main()
    {
        Group group = new("Group name", new Student[]
        {
            new("Alex"),
            new("Den"),
            new("Michael")
        });

        Console.WriteLine("Group serialized to XML-file:\n" + group);

        XmlSerializer serializer = new XmlSerializer(typeof(Group));
        using (TextWriter textWriter = new StreamWriter("Group.xml"))
        {
            serializer.Serialize(textWriter, group);
        }

        Group groupReadFromXml;

        XmlSerializer deserializer = new XmlSerializer(typeof(Group));
        using (TextReader textReader = new StreamReader("Group.xml"))
        {
            groupReadFromXml = (Group)deserializer.Deserialize(textReader);
        }

        Console.WriteLine("\nGroup deserialized from XML-file:\n" + groupReadFromXml);
    }
}