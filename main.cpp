#include <exception>
#include <iostream>
#include <stdexcept>

class PrimeException : public std::invalid_argument
{
private:
    int invalid_number;

public:
    PrimeException(const char* msg, int num)
    : std::invalid_argument(msg), invalid_number(num)
    {

    }

    const char* what() const noexcept override
    {
        return std::invalid_argument::what();
    }

    void error_print() const
    {
        std::cout << "Error: " << what() << " - " << invalid_number << " is not prime" << std::endl;
    }
};

class PrimeNumber
{
private:
    int value;

    bool check(int num)
    {
        if (num <= 1) return true;
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0) return true;
        }
        return false;
    }

public:
    PrimeNumber(int num)
    {
        if (check(num))
        {
            throw PrimeException("Invalid prime number", num);
        }
        value = num;
        std::cout << "Successfully created prime number" << std::endl;
    }

    void print()
    {
        std::cout << "Prime number: " << value << std::endl;
    }
};

int main()
{
    // Без исключения
    try
    {
        std::cout << "Creating prime number 7..." << std::endl;
        PrimeNumber p1(7);
        p1.print();
    }
    catch (PrimeException e)
    {
        e.error_print();
    }

    std::cout << std::endl;

    // С исключением
    try
    {
        std::cout << "Creating prime number 1..." << std::endl;
        PrimeNumber p2(1);
        p2.print();
    }
    catch (PrimeException e)
    {
        e.error_print();
    }

    std::cout << std::endl;

    // С исключением
    try
    {
        std::cout << "Creating prime number 4..." << std::endl;
        PrimeNumber p3(4);
        p3.print();
    }
    catch (PrimeException e)
    {
        e.error_print();
    }
    return 0;
}
