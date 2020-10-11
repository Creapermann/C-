//PRINTER ERRORS
/*In a factory a printer prints labels for boxes. For one kind of boxes the printer has to use colors which, for the sake of simplicity, are named with letters from a to m.
The colors used by the printer are recorded in a control string. For example a "good" control string would be aaabbbbhaijjjm meaning that the printer used three times color a,
four times color b, one time color h then one time color a...
Sometimes there are problems: lack of colors, technical malfunction and a "bad" control string is produced e.g. aaaxbbbbyyhwawiwjjjwwm with letters not from a to m.
You have to write a function printer_error which given a string will return the error rate of the printer as a string representing a rational whose numerator is the number
of errors and the denominator the length of the control string. Don't reduce this fraction to a simpler expression.*/

#include <iostream>
#include <string>
#include <vector>


int retAmountOfErrors(std::string inputString) {

    int amountOfErrors = 0;

    std::vector<char> stringVec(inputString.begin(), inputString.end());

    for (int i = 0; i < stringVec.size(); i++) {
        switch (stringVec[i]) {
        case 'a':
            break;
        case 'b':
            break;
        case 'c':
            break;
        case 'd':
            break;
        case 'e':
            break;
        case 'f':
            break;
        case 'g':
            break;
        case 'h':
            break;
        case 'i':
            break;
        case 'j':
            break;
        case 'k':
            break;
        case 'l':
            break;
        case 'm':
            break;
        default:
            amountOfErrors++;
        }
    }

    return amountOfErrors;
}


int main(){
    
    std::string inputString;
    std::cin >> inputString;

    int amountOfErrors = retAmountOfErrors(inputString);
    std::cout << "error_printer(s) => '" << std::to_string(amountOfErrors) << "/" << inputString.length() << "'";

    int eND;
    std::cin >> eND;
    return 0;
}
