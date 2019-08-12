#include "third_task.hpp"
#include <string>

std::string digits[] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};

std::string tens_multiple[] = {
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety"
};

std::string tens_power[] = {
    "",
    "thousand",
    "million",
    "billion"
};

std::string two_digits[] = {
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen"
};

uint32_t charToDigit(const char & symbol){
    return symbol - '0';
}

std::string numberToWord(const char & handred, const char & tens, const char & ones){
    std::string result;

    if(handred != '0'){
        result += digits[charToDigit(handred)] + " " + "hundred ";
    }

    if(tens > '1'){
        result += tens_multiple[charToDigit(tens)-2] + " ";
    }

    if((tens > '1' || tens == '0') && ones > '0'){
        result += digits[charToDigit(ones)] + " ";
    }

    if(tens == '1'){
        result += two_digits[charToDigit(ones)] + " ";
    }

    return result;
}

void startThirdTask()
{
    double N = 0.f;
    uint32_t size = 16;

    char source_str[size];

    for(uint32_t i = 0; i < size; i++)
        source_str[i] = '0';
    source_str[size - 1] = '\0';

    std::cout << "Enter a number : ";
    std::cin >> N;

    if(N > 1000000000.001f){
        std::cout << "Value incorrect! Max value 1 billion.\nPlease, reenter the number: ";
        std::cin >> N;
    }

    if(N == 0){
        std::cout << "You don't have a money :(" << std::endl;
        return;
    }

    std::string temp_str = std::to_string(N);

    int k = 0;
    for(uint32_t i = size - (temp_str.length() - 3); i < size - 1; i++)
        source_str[i] = temp_str[k++];

    std::string result_str;

    int p = 3;
    for(uint32_t i = 0; i <= size - 7; i += 3, p--){
        if(!numberToWord(source_str[i], source_str[i+1], source_str[i+2]).empty()){
            result_str += numberToWord(source_str[i], source_str[i+1], source_str[i+2]) + tens_power[p] + " ";
        }
    }
    if(!result_str.empty()){
        result_str += "dollars ";
    }

    result_str += numberToWord('0', source_str[size - 3], source_str[size - 2]);

    if(source_str[size - 3] != '0' || source_str[size - 2] != '0'){
        result_str += "cents";
    }

    std::cout<<result_str<<std::endl;
}
