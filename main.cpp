#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include <math.h> //for 'pow'

int totalDigits(std::string uservalue) 
{
    char dot{'.'}; 
    std::size_t found{uservalue.find(dot)}; 
    uservalue.erase(0, found+1); 
    return uservalue.length(); 
}

double gcd(int a, int b) // Taken from tutorialspoint
{
   if (b == 0)
   return a;
   /*(else)*/ return gcd(b, a % b);
}

std::string getInput()
{
    std::cout << "Enter a decimal: ";
    std::string input{}; 
    std::getline(std::cin, input);
    input.erase(std::remove_if(input.begin(), input.end(), isalpha), input.end());
    
    return input; 
}

void convertToFraction(int decimal, const std::string &s) 
{
    double total{pow(10.0, static_cast<double>(decimal))};
    double stringToDouble{std::stod(s)}; // stod is a STL function that lives in the <string> library. It can be used to convert (in this case) a string to a double.
    double numerator{stringToDouble*total}; 
    
    double denominator{total * 1};
    double greatestCommonDivisor{gcd(numerator, denominator)};
    std::cout << "Fraction: " << numerator/greatestCommonDivisor << '/' << denominator/greatestCommonDivisor;
}



int main()
{
    std::string userinput{getInput()};
    int totaldigits = totalDigits(userinput);
    convertToFraction(totaldigits, userinput);
}
