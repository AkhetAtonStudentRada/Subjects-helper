namespace Task3;

public class Student
{
    public string Name { get; set; }

    public Student() { }
    public Student(string name)
    {
        Name = name;
    }

    public override string? ToString()
    {
        return Name;
    }
}