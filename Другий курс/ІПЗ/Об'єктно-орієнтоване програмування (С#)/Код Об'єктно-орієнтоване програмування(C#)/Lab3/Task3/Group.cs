namespace Task3;

public class Group
{
    public string GroupName { get; set; }
    public Student[] Students { get; set; }

    public Group() { }
    public Group(string groupName, Student[] students)
    {
        GroupName = groupName;
        Students = students;
    }

    public override string? ToString()
    {
        return $"Group: {GroupName}\nStudents:\n{string.Join("\n", (object[])Students)}";
    }
}