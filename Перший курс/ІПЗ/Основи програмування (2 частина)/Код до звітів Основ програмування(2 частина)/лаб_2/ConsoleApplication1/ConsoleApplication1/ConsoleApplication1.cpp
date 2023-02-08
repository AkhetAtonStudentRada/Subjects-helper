#pragma warning(disable:4996)
#include <iostream>
#include <cstring>

using namespace std;

class human {
private:
    char name[30];
    char surname[30];
    char gender;
    int age;
public:
    human(){
        strcpy(this->name, "");
        strcpy(this->surname, "");
        gender = ' ';
        age = 0;
    }
    human(const char* name, const char* surname, char gender, int age)
    {
        strcpy(this->name, name);
        strcpy(this->surname, surname);
        this->gender = gender;
        this->age = age;
    }
    char* getName()
    {
        return name;
    }
    char* getSurname()
    {
        return surname;
    }
    char getGender() 
    {
        return gender;
    }
    int getAge() const
    {
        return age;
    }


    virtual void inform() {
        cout << "Ім'я: " << name << ".\t Прізвище: " << surname <<  ".\t Вік: " << age << ".\t Гендер: " << gender;
    }

    virtual ~human() { }
};

class citizen : public human {
private: 
    char citizenship[30];
public:
    citizen(const char* name, const char* surname, char gender, int age, const char* citizenship)
        : human(name, surname, gender, age) {
        strcpy(this->citizenship, citizenship);
    }

    char* getCitizenship() {
        return citizenship;
    }

     void inform() override {
         human::inform();
         cout << "\t Громадянство: " << citizenship;
    }
};

class student : public citizen {
private: 
    char faculty[30];
    int course;
public:
    student(const char* name, const char* surname, char gender, int age, const char* citizenship, const char* faculty, int course)
        : citizen(name, surname, gender, age, citizenship) {
        strcpy(this->faculty, faculty);
        this->course = course;
    }
    
    char* getFaculty() {
        return faculty;
    }
    int getCourse() const {
        return course;
    }

    void inform() override {
        citizen::inform();
        cout << "\t Факультет: " << faculty << ".\t Курс:" << course;
    }
};

class employee : public citizen {
private: 
    char job[30];
public:
    employee(const char* name, const char* surname, char gender, int age, const char* citizenship, const char* job)
        : citizen(name, surname, gender, age, citizenship) {
        strcpy(this->job, job);
}

    char* getJob() {
        return job;
    }

    void inform() override {
        citizen::inform();
        cout <<"\t Місто праці:" << job;
    }
};

int main()
{
    setlocale(LC_ALL, "UKRAINIAN");

    const int n = 4;
    human *arr[n] = {
        new citizen ("Ivan", "Ivanov",'m', 19,"Ukaine"),
        new student("Ivan", "Ivanov",'m', 19,"Ukaine", "Faculty of Physical Technology", 1),
        new human("Ivan", "Ivanov",'m', 19),
        new employee("Ivan", "Ivanov",'m', 19,"Ukaine", "Electrican"),
    };

    for (int i = 0; i < n; i++)
    {
        cout << "1) ";
        arr[i]->inform();
        cout << "\n \n";
    }
    for (int i = 0; i < n; i++)
    {
        delete arr[i];
    }

    system("pause");
    return 0;
}
