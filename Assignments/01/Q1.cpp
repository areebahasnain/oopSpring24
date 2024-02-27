/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>
#include <vector>

using namespace std;

class Pet
{
public:
    string species;
    string healthStatus;
    int hungerLevel, happinessLevel;
    vector<string> specialSkills;

    Pet(string species, string health, int hunger, int happiness, vector<string> skills) : species(species), healthStatus(health), hungerLevel(hunger), happinessLevel(happiness), specialSkills(skills) {}

    void displayPetDetails() const
    {
        cout << "Species: " << species << endl;
        cout << "Health Status: " << healthStatus << endl;
        cout << "Hunger Level: " << hungerLevel << endl;
        cout << "Happiness Level: " << happinessLevel << endl;
        cout << "Special Skills:" << endl;
        for (string skill : specialSkills)
            cout << "- " << skill << endl;
    }

    void updateHappiness(int happiness)
    {
        happinessLevel += happiness;
        if (happinessLevel < 0)
            happinessLevel = 0; // happiness scale is from 0 to 10
    }

    void updateHealth(string health)
    {
        healthStatus = health;
    }

    void updateHunger(int hunger)
    {
        hungerLevel += hunger;
        // The hunger scale is from 0 to 10, where 0 represents being well-fed and 10 represents being hungry.
        if (hunger <= 5)
        {
            happinessLevel += 5 - hungerLevel; // If hunger is 5, happiness increases by 1; if hunger is 4, happiness increases by 2; and so on.
        }
        else
        {
            // Decrease happiness by 1 if hunger is more than 5
            happinessLevel--;
        }
    }
};

class Adopter
{
public:
    string adopterName, adopterMobileNum;
    vector<Pet> adoptedPetRecords;

    Adopter(string name, string num) : adopterName(name), adopterMobileNum(num) {}

    void adoptPet(Pet pet)
    {
        adoptedPetRecords.push_back(pet);
        cout << "Pet adopted successfully!" << endl;
    }

    void returnPet(string species)
    {
        bool petFound = false;
        for (auto it = adoptedPetRecords.begin(); it != adoptedPetRecords.end();)
        {
            if (it->species == species)
            {
                it = adoptedPetRecords.erase(it);
                petFound = true;
            }
            else
            {
                ++it;
            }
        }

        if (!petFound)
        {
            cout << "No" << species << "found in records." << endl;
        }
    }

    void displayAdoptedPets() const
    {
        cout << "Adopted Pets:" << std::endl;
        for (const auto &pet : adoptedPetRecords)
        {
            pet.displayPetDetails();
            cout << endl;
        }
    }
};

int main()
{

    cout << "-------------------------------------------" << endl;
    cout << "\tNAME: AREEBA HASNAIN SHAIKH" << endl
         << "\tSTUDENT ID: K23-0059" << endl;
    cout << "-------------------------------------------" << endl;

    Pet cat("Cat", "Healthy", 4, 3, {"Acrobatics", "Purring"});
    Adopter adopter1("Areeba", "123456789");
    adopter1.adoptPet(cat);
    cout << "Adopter 1's Pets:" << std::endl;
    adopter1.displayAdoptedPets();
    cout << endl;

    Pet dog("Dog", "Injured", 7, 6, {"Herding", "Barking"});
    Adopter adopter2("Emman", "0987654231");
    adopter2.adoptPet(dog);
    cout << "Adopter 2's Pets:" << endl;
    adopter2.displayAdoptedPets();
    cout << endl;

    adopter1.returnPet("Cat");

    cout << "Adopter 1's Pets after returning a pet:" << endl;
    adopter1.displayAdoptedPets();

    return 0;
}
