// COMSC-210 | Lab 27 | Noel Mier-Luna
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    // declarations
    map<string, tuple<int, string, string>> villagers; // Map of villager's friendship level, species, and a catch phrase.

    // insert elements into the map
    // note how the right-hand side of the assignment are the tuple elements.
    villagers["Chip"] = make_tuple(1, "Beaver", "This island is small!");
    villagers["Augie"] = make_tuple(2, "Armadillo", "I left my sunscreen at home.");
    villagers.insert({"Bubbles", make_tuple(9, "Capybara", "Do jellyfish have bones?")});

    // Initial display of villagers and their friendship levels, species, and catch phrases.
    for (const auto &pair : villagers)
    {
        cout << pair.first << ": " << get<0>(pair.second) << ", " // to access tuple elements, we use get<index>.
             << get<1>(pair.second) << ", " << get<2>(pair.second) << endl;;
    }
    // Menu for increasing/decreasing friendship levels, displaying villagers, and exiting the program.
    int choice;
    do
    {
        cout << "\n1. Add Villager" << endl;
        cout << "2. Delete Villager" << endl;
        cout << "3. Increase Friendship" << endl; 
        cout << "4. Decrease Friendship" << endl;
        cout << "5. Search for Villager" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if 

        if (choice == 3 || choice == 4 || choice == 5)
        {
            string name;
            cout << "Enter the name of the villager: ";
            cin >> name;
            // Use .find() to search for the villager in the map. If found, increase or decrease the friendship level based on the user's choice.
            auto it = villagers.find(name);
            if (it != villagers.end())
            {
                if (choice == 3)
                { // Increase friendship level. Maxes out at 10.
                    if (get<0>(it->second) < 10)
                    {
                        get<0>(it->second)++;
                        cout << "Increased " << name << "'s friendship level to " << get<0>(it->second) << ".\n"
                             << endl;
                    }
                    else
                    {
                        cout << name << "'s friendship level is already at the maximum of 10.\n"
                             << endl;
                    }
                    for (const auto &pair : villagers)
                    {
                        cout << pair.first << ": " << get<0>(pair.second) << ", " // to access tuple elements, we use get<index>.
                             << get<1>(pair.second) << ", " << get<2>(pair.second) << endl;
                    }
                }
                else if (choice == 4)
                { // Decrease friendship level. Mins out at 0.
                    if (get<0>(it->second) > 0)
                    {
                        get<0>(it->second)--;
                        cout << "Decreased " << name << "'s friendship level to " << get<0>(it->second) << ".\n"
                             << endl;
                    }
                    else
                    {
                        cout << name << "'s friendship level is already at the minimum of 0.\n"
                             << endl;
                    }
                    for (const auto &pair : villagers)
                    {
                        cout << pair.first << ": " << get<0>(pair.second) << ", " // to access tuple elements, we use get<index>.
                             << get<1>(pair.second) << ", " << get<2>(pair.second) << endl;
                    }
                }
            }
            else
            { // If map iterates to end without finding name, displays not found message.
                cout << "Villager not found." << endl;
                for (const auto &pair : villagers)
                {
                    cout << pair.first << ": " << get<0>(pair.second) << ", " //
                         << get<1>(pair.second) << ", " << get<2>(pair.second) << endl;
                }
            }
            // If the user chooses to search for a villager, display their information if found.
            cout << name << "'s info: ";
            cout << "\nFriendship Level: " << get<0>(it->second) << endl;
            cout << "Species: " << get<1>(it->second) << endl;
            cout << "Catch Phrase: " << get<2>(it->second) << endl;
        }
    } while (choice != 6 || choice < 1 || choice > 6);

    // Loop until the user chooses to exit or enters an invalid choice.
    /*
        // access the map using a range-based for loop
        cout << "Villagers and their friendship levels, species, and catch phrases:" << endl;
        for (const auto &pair : villagers)
        {                                                             // pair is the string (name) and details (tuple).
            cout << pair.first << ": " << get<0>(pair.second) << ", " // to access tuple elements, we use get<index>.
                 << get<1>(pair.second) << ", " << get<2>(pair.second) << endl;
        }

        // access the map using iterators
        cout << "\nVillagers and their details (iterators):" << endl;
        for (map<string, tuple<int, string, string>>::iterator it = villagers.begin();
             it != villagers.end(); ++it)
        {
            cout << it->first << ": " << get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second) << endl;
        }
        cout << endl;

        // delete an element
        villagers.erase("Augie");

        // search for an element using .find() to avoid errors
        string searchKey = "Bubbles";
        auto it = villagers.find(searchKey);
        if (it != villagers.end())
        { // the iterator points to beyond the end of the map
          // if searchKey is not found
            cout << "\nFound " << searchKey << "'s info: ";
            cout << "\nFriendship Level: " << get<0>(it->second) << endl;
            cout << "Species: " << get<1>(it->second) << endl;
            cout << "Catch Phrase: " << get<2>(it->second) << endl;
        }
        else
            cout << endl
                 << searchKey << " not found." << endl;

        // report size, clear, report size again to confirm map operations
        cout << "\nSize before clear: " << villagers.size() << endl;
        villagers.clear();
        cout << "Size after clear: " << villagers.size() << endl;
    */
    return 0;
}