#include <iostream>
#include <ctime> // Include the ctime library to work with date and time
using namespace std;

// Function to calculate age
int calculateAge(int birthYear, int birthMonth, int birthDay) {
    // Get the current time
    time_t t = time(0);   
    tm* now = localtime(&t);

    // Extract the current year, month, and day
    int currentYear = now->tm_year + 1900; // tm_year gives years since 1900
    int currentMonth = now->tm_mon + 1;    // tm_mon is months since January (0-11)
    int currentDay = now->tm_mday;         // tm_mday is the day of the month (1-31)

    // Calculate age
    int age = currentYear - birthYear;

    // Adjust age if the current date is before the birthday this year
    if (birthMonth > currentMonth || (birthMonth == currentMonth && birthDay > currentDay)) {
        age--;
    }

    return age;
}

int main() {
    int birthYear, birthMonth, birthDay;
    char choice;

    do {
        // Get the user's date of birth
        cout << "Enter your date of birth:" << endl;
        cout << "Year: ";
        cin >> birthYear;
        cout << "Month (1-12): ";
        cin >> birthMonth;
        cout << "Day (1-31): ";
        cin >> birthDay;

        // Calculate the user's age
        int age = calculateAge(birthYear, birthMonth, birthDay);

        // Display the result
        cout << "You are " << age << " years old." << endl;

        // Ask if the user wants to calculate another age
        cout << "Do you want to calculate another age? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the program!" << endl;

    return 0;
}
