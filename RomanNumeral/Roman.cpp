#include <iostream>
#include <string>
#include <map>

int romanToDecimal(const std::string& str) {
    // Create a lookup table for Roman numerals and their values
    std::map<char, int> romanValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int total = 0;

    for (int i = 0; i < str.length(); i++) {
        // Get the value of the current Roman numeral character
        int currentValue = romanValues[str[i]];

        // Check if there is a next character
        if (i + 1 < str.length()) {
            // Get the value of the next Roman numeral character
            int nextValue = romanValues[str[i + 1]];

            // Compare the values of the current and next characters
            if (currentValue < nextValue) {
                // If the current character is smaller than the next, subtract its value
                total -= currentValue;
            } else {
                // Otherwise, add its value
                total += currentValue;
            }
        } else {
            // If there is no next character, simply add the current character's value
            total += currentValue;
        }
    }

    return total;
}

int main() {
    std::string romanNumeral0 = "MMMCMXCIX";
    std::string romanNumeral1 = "IX";
    std::string romanNumeral2 = "CDXLIV";
    std::string romanNumeral3 = "XCIV";
    std::string romanNumeral4 = "CXXIII";

    int decimalValue = romanToDecimal(romanNumeral0);
    int decimalValue1 = romanToDecimal(romanNumeral1);
    int decimalValue2 = romanToDecimal(romanNumeral2);
    int decimalValue3 = romanToDecimal(romanNumeral3);
    int decimalValue4 = romanToDecimal(romanNumeral4);

    std::cout << "Roman numeral " << romanNumeral0 << " is equal to " << decimalValue << std::endl;
    std::cout << "Roman numeral " << romanNumeral1 << " is equal to " << decimalValue1 << std::endl;
    std::cout << "Roman numeral " << romanNumeral2 << " is equal to " << decimalValue2 << std::endl;
    std::cout << "Roman numeral " << romanNumeral3 << " is equal to " << decimalValue3 << std::endl;
    std::cout << "Roman numeral " << romanNumeral4 << " is equal to " << decimalValue4 << std::endl;


    return 0;
}
