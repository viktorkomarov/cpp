#include <iostream>
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


int main() {
}