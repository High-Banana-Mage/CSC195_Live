#include <iostream>
using namespace std;

int main()
{
    const float TAX = 0.035f; // 3.5% tax rate

    cout << "Enter first name: ";
    string name;
    cin >> name;

    cout << "Enter initial of last name: ";
    char initial;
    cin >> initial;

    cout << "Enter age: ";
    short age;
    cin >> age;
    bool isAdult = (age >= 18);  // Determine adulthood status

    cout << "Enter zipcode: ";
    unsigned int zipcode;
    cin >> zipcode;

    cout << "Enter hourly wage: ";
    float wage;
    cin >> wage;

    cout << "Enter number of days worked (max 7): ";
    short daysWorked;
    cin >> daysWorked;

    float hoursWorkedPerDay[7];

    float totalHours = 0;

    for (int i = 0; i < daysWorked; i++) {
        cout << "Enter hours worked for day " << (i + 1) << ": ";
        cin >> hoursWorkedPerDay[i];

        totalHours += hoursWorkedPerDay[i];  // Accumulate total hours
    }

    float grossIncome = totalHours * wage;
    float taxAmount = grossIncome * TAX;
    float netIncome = grossIncome - taxAmount;

    cout << "\nEmployee Payroll Summary\n";
    cout << "-------------------------\n";
    cout << "Name: " << name << " " << initial << ".\n";
    cout << "Age: " << age << " (Adult: " << (isAdult ? "Yes" : "No") << ")\n";
    cout << "Zipcode: " << zipcode << "\n";
    cout << "Hourly Wage: $" << wage << " per hour\n";
    cout << "Total Hours Worked: " << totalHours << " hours\n";
    cout << "Gross Income: $" << grossIncome << "\n";
    cout << "Tax Amount: $" << taxAmount << "\n";
    cout << "Net Income: $" << netIncome << "\n";
}