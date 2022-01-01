#include <iostream>
#include <sstream>

int nod(int a, int b) {
    return (a % b  == 0) ?  b : nod(b, a%b);
}

class Rational {
public:
    Rational() {
        num = 0;
        den = 1;
    };
    Rational(int numerator, int denominator) {
        num = numerator;
        den = denominator;
        if (num == 0) {
            den = 1;
            return;
        }

        int mi = std::min(num ,den);
        int ma = std::max(num ,den);
        if (mi != 0) {
            int n = nod(ma, mi);
            num /= n;
            den /= n;
        }

        if (den < 0 && num < 0 || den < 0 && num > 0) {
            den = -den;
            num = -num;
        }
    };

    int Numerator() const {return num;};
    int Denominator() const {return den;};
private:
    int num;
    int den;
};

Rational operator+(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.Numerator() * rhs.Denominator() + rhs.Numerator()*lhs.Denominator(), lhs.Denominator()*rhs.Denominator());
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator()*lhs.Denominator(), lhs.Denominator()*rhs.Denominator());
}

bool operator==(const Rational& lhs, const Rational& rhs)
{
    return lhs.Numerator() == rhs.Numerator() && rhs.Denominator() == lhs.Denominator();
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.Numerator()*rhs.Numerator(), lhs.Denominator()*rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.Numerator()*rhs.Denominator(), lhs.Denominator()*rhs.Numerator());
}

std::ostream& operator<<(std::ostream& stream, const Rational& rat) {
    stream << rat.Numerator() << "/" << rat.Denominator();
    return stream;
}

std::istream& operator>>(std::istream& stream, Rational& rat) {
    int n, d;
    if (!(stream >> n)) {
        return stream;
    }
    char op;
    if (!(stream >> op) || (op != '/')){
        return stream;
    }
    if (!(stream >> d)){
        return stream;
    }
    rat = Rational(n,d);
    return stream;
}


int main() {
    {
        std::ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            std::cout << "Rational(-6, 8) should be written as \"-3/4\"" << std::endl;
            return 1;
        }
    }

    {
        std::istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            std::cout << "5/7 is incorrectly read as " << r << std::endl;
            return 2;
        }
    }

    {
        std::istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            std::cout << "Read from empty stream works incorrectly" << std::endl;
            return 3;
        }
    }

    {
        std::istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            std::cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << std::endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            std::cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << std::endl;
            return 5;
        }
    }

    {
        std::istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            std::cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << std::endl;

            return 6;
        }
    }

    std::cout << "OK" << std::endl;
    return 0;
}