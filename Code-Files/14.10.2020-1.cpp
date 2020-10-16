/*You probably know the "like" system from Facebook and other pages. People can "like" blog posts, pictures or other 
* 
items. We want to create the text that should be displayed next to such an item.

Implement a function likes :: [String] -> String, which must take in input array, containing the names of people 

who like an item. It must return the display text as shown in the examples:

likes {} // must be "no one likes this"
likes {"Peter"} // must be "Peter likes this"
likes {"Jacob", "Alex"} // must be "Jacob and Alex like this"
likes {"Max", "John", "Mark"} // must be "Max, John and Mark like this"
likes {"Alex", "Jacob", "Mark", "Max"} // must be "Alex, Jacob and 2 others like this"

For 4 or more names, the number in and 2 others simply increases.*/

#include <iostream>
#include <vector>

void clearCons() {
    system("CLS");
}



void printOut(const std::vector<std::string> &namesVec, const int &namesAmount) {
    
    switch (namesAmount) {
    case 1:
        std::cout << namesVec[0] << " likes this" << std::endl;
        break;
    case 2:
        std::cout << namesVec[0] << " and " << namesVec[1] << " like this" << std::endl;
        break;
    case 3:
        std::cout << namesVec[0] << ", " << namesVec[1] << " and " << namesVec[2] << " like this" << std::endl;
        break;
    default:
        std::cout << namesVec[0] << ", " << namesVec[1] << " and " << namesAmount - 2 << " other(s)" << " like(s) this " << std::endl;
    }
}

std::vector<std::string> retNamesVec(int &namesAmount) {
    std::vector<std::string> namesVec;

    auto nameLoopIsOver = false;
    while (nameLoopIsOver != true) {
        std::cout << "Type in a name (write 'stop!' when you finished)" << std::endl;
        std::string name;
        std::cin >> name;
        if (name != "stop!") {
            namesVec.push_back(name);
            namesAmount++;
        }
        else {
            nameLoopIsOver = true;
        }
        clearCons();
    }

    return namesVec;
}

int main()
{
    auto namesAmount = 0;
    auto namesVec = retNamesVec(namesAmount);
    printOut(namesVec, namesAmount);

    int eND;
    std::cin >> eND;
    return 0;
}
