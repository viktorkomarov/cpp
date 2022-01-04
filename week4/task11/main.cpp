#include <iostream>
#include <set>
#include <string>
#include <map>
#include <stdexcept>
#include <vector>

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
        if (denominator == 0 ) throw std::invalid_argument("denominator == 0");
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
    if ( lhs.Denominator()*rhs.Numerator() == 0) throw std::domain_error("is eual 0");
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

bool operator < (const Rational& lhs, const Rational& rhs) {
    return (lhs - rhs).Numerator() < 0;
}

int main() {
    try{
        Rational rat1;
        std::cin >> rat1;
        char ops;
        std::cin >> ops;
        Rational rat2;
        std::cin >> rat2;

        if (ops == '+') {
            std::cout << (rat1 + rat2) << std::endl;
        } else if(ops == '-') {
            std::cout << (rat1 - rat2) << std::endl;
        } else if(ops == '*') {
            std::cout << (rat1 * rat2) << std::endl;
        } else if (ops == '/') {
            std::cout << (rat1 / rat2) << std::endl;
        }
    } catch(std::invalid_argument&) {
        std::cout << "Invalid argument" << std::endl;
    }   catch(std::domain_error&) {
        std::cout << "Division by zero" << std::endl;
    }
}