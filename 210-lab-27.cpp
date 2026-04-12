// COMSC-210 | Lab 27 | Noel Mier-Luna
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagers; // Map of villager's friendship level, species, and a catch phrase.

    // insert elements into the map
    // note how the right-hand side of the assignment are the tuple elements.
    villagers["Chip"] = make_tuple(1, "Beaver", "This island is small!");
    villagers["Augie"] = make_tuple(2, "Armadillo", "I left my sunscreen at home.");
    villagers.insert({"Bubbles", make_tuple(3, "Capybara", "Do jellyfish have bones?")});

    // access the map using a range-based for loop
    cout << "Villagers and their friend levels, species, and catch phrases (range-based for loop):" << endl;
    
 
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerColors.begin(); 
                                               it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}