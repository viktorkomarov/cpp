#include <iostream>

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

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            std::cout << "Rational(3, 10) != 3/10" << std::endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            std::cout << "Rational(8, 12) != 2/3" << std::endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            std::cout << "Rational(-4, 6) != -2/3" << std::endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            std::cout << "Rational(4, -6) != -2/3" << std::endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            std::cout << "Rational(0, 15) != 0/1" << std::endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            std::cout << "Rational() != 0/1" << std::endl;
            return 5;
        }
    }
        std::cout << "OK" << std::endl;
    return 0;
}