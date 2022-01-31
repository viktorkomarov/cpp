#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

class Figure{
public:
    // Name, Perimeter и Area;
    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
    virtual ~Figure() {};
};

class Triangle: public Figure{
public:
    Triangle(double a, double b, double c) :
         _type("TRIANGLE"),
         _a(a), _b(b), _c(c){};
    string Name() const override {return _type;}
    double Perimeter() const override {return _a+_b+_c;}
    double Area() const  override {
        double p = Perimeter() / 2;
        return sqrt(p * (p - _a) * (p - _b) * (p - _c));
    }
private:
    const string _type;
    double _a, _b, _c;
};

class Rect: public Figure{
public:
    Rect(double a, double b) :
         _type("RECT"),
         _a(a), _b(b){};
    string Name() const override {return _type;}
    double Perimeter() const override {return (_a+_b) * 2;}
    double Area() const override {return _a*_b;}
private:
    const string _type;
    double _a, _b; 
};

class Circle: public Figure{
public:
    Circle(double r) :
         _type("CIRCLE"), r(r) {};
    string Name() const override {return _type;}
    double Perimeter() const override {return 2 * 3.14 * r;}
    double Area() const override {return 3.14 * r * r;}
private:
    const string _type;
    double r; 
};

shared_ptr<Figure> CreateFigure(istringstream& is)
{
    string type;
    is >> type;
    if(type == "RECT") {
        double a, b;
        is >> a >> b;
        return make_shared<Rect>(a, b);
    } else if(type == "TRIANGLE") {
        double a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(a, b,c);
    }
    // CIRCLE
    double r;
    is >> r;
    return make_shared<Circle>(r);
}

int main() {
  vector<shared_ptr<Figure> > figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}