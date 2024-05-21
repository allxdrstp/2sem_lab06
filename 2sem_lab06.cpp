#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;
class NotPrimeException : public invalid_argument {
private:
    int value;
public:
    NotPrimeException(int v) : invalid_argument("Не простое число"), value(v) {}
    void printInvalidValue() const {
        std::cout << "ОШИБКА 404" << endl;
    }
};
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
class PrimeNumber {
private:
    int value;
public:
    PrimeNumber(int v) : value(v) {
        if (!isPrime(v)) {
            throw NotPrimeException(v);
        }
    }
    int getValue() const {
        return value;
    }
    void print() const {
        std::cout << value << " простое" << std::endl;
    }
};

int main() {
    try {
        PrimeNumber p1(17);
        p1.print();
        PrimeNumber p2(18);
    }
    catch (const NotPrimeException& e) {
        std::cout << "Исключение " << e.what() << std::endl;
        e.printInvalidValue();
    }

    try {
        PrimeNumber p3(19);
        p3.print();
    }
    catch (const NotPrimeException& e) {
        std::cout << "Исключение" << e.what() << std::endl;
        e.printInvalidValue();
    }
    return 0;
}