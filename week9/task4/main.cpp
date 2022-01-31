#include <iostream>
#include <string>
#include <vector>


class Person{
public:
    explicit Person(const std::string& name, const std::string& type)
    :_profession(type), _name(name){};
    std::string Name() const {return _name;}
    virtual void Walk(const std::string& destination) const {
        std::cout << _profession << ": " << Name() << " walks to: " << destination << std::endl;
    };
    std::string Profession() const {return _profession;}

private:
    const std::string _profession;
    const std::string _name;
};

class Student : public Person{
public:
    explicit Student(const std::string& name, const std::string& favourite_song) : 
    Person(name, "Student"), _favourite_song(favourite_song) {};

    void Learn() const {
        std::cout <<  Profession() <<": " << Name() << " learns" << std::endl;
    }

    void Walk(const std::string& destination) const override {
        std::cout<<  Profession() <<": "  << Name() << " walks to: " << destination << std::endl;
        SingSong();
    }

    void SingSong() const {
        std::cout<<  Profession() <<": "  << Name() << " sings a song: " << _favourite_song << std::endl;
    }

private:
    const std::string _favourite_song;
};


class Teacher : public Person {
public:
    explicit Teacher(const std::string& name, const std::string& subject):
    Person(name, "Teacher"), _subject(subject) {};

    void Teach() const {
        std::cout << Profession() <<": "  << Name() << " teaches: " << _subject << std::endl;
    }
private:
    const std::string _subject;
};


class Policeman : public Person{
public:
    explicit Policeman(const std::string& name):
    Person(name, "Policeman") {};

    void Check(const Person& person) const {
        std::cout << Profession() <<": "  << Name() << " checks "<< person.Profession() <<
            "." << person.Profession() <<"'s name is: " 
            << person.Name() << std::endl;   
    }
};


void VisitPlaces(const Person& person, std::vector<std::string> places) {
    for (auto p : places) {
        person.Walk(p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
