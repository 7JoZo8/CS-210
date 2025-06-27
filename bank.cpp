#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <stdexcept>

using namespace std;

// Investment calculator class
class Banking {
public:
    void SetInitial(double value) { total = value; }
    void SetMonthly(double value) { monthly = value; }
    void SetInterest(double value) { rate = value; }
    void SetYears(int value) { years = value; }

    double GetInitial() const { return total; }
    double GetMonthly() const { return monthly; }
    double GetInterest() const { return rate; }
    int GetYears() const { return years; }

    // Calculates and displays results without monthly deposits
    void ShowNoMonthly() {
        double balance = total;

        cout << "\n  Balance and Interest Without Monthly Deposits\n";
        cout << string(60, '=') << endl;
        cout << "Year     Year-End Balance     Earned Interest\n";
        cout << string(60, '-') << endl;

        for (int i = 1; i <= years; ++i) {
            double interest = balance * (rate / 100);
            balance += interest;

            cout << setw(4) << i << "      $"
                << fixed << setprecision(2) << balance
                << "             $" << interest << endl;
        }
    }

    // Calculates and displays results with monthly deposits
    void ShowWithMonthly() {
        double balance = total;

        cout << "\n  Balance and Interest With Monthly Deposits\n";
        cout << string(60, '=') << endl;
        cout << "Year     Year-End Balance     Earned Interest\n";
        cout << string(60, '-') << endl;

        for (int i = 1; i <= years; ++i) {
            double yearlyInterest = 0;

            for (int m = 0; m < 12; ++m) {
                double interest = (balance + monthly) * ((rate / 100) / 12);
                balance += monthly + interest;
                yearlyInterest += interest;
            }

            cout << setw(4) << i << "      $"
                << fixed << setprecision(2) << balance
                << "             $" << yearlyInterest << endl;
        }
    }

private:
    double total;
    double monthly;
    double rate;
    int years;
};

// Function declarations
void GetUserInput(Banking& account);
int GetValidInt();
double GetValidDouble();

// Main program
int main() {
    Banking account;
    char choice;

    do {
        system("cls");
        GetUserInput(account);

        account.ShowNoMonthly();
        account.ShowWithMonthly();

        cout << "\nEnter 'q' to quit or any other key to run again: ";
        cin >> choice;

    } while (choice != 'q');

    return 0;
}

// Get and validate user input
void GetUserInput(Banking& account) {
    try {
        double initial, monthly, interest;
        int years;

        cout << "**********************************\n";
        cout << "********** Data Input ************\n";

        cout << "Initial Investment: $";
        initial = GetValidDouble();
        if (initial < 0) throw runtime_error("Negative value not allowed.");
        account.SetInitial(initial);

        cout << "Monthly Deposit: $";
        monthly = GetValidDouble();
        if (monthly < 0) throw runtime_error("Negative value not allowed.");
        account.SetMonthly(monthly);

        cout << "Annual Interest (%): ";
        interest = GetValidDouble();
        if (interest < 0) throw runtime_error("Negative value not allowed.");
        account.SetInterest(interest);

        cout << "Number of Years: ";
        years = GetValidInt();
        if (years <= 0) throw runtime_error("Enter at least 1 year.");
        account.SetYears(years);

        system("PAUSE");
    }
    catch (runtime_error& e) {
        cout << "Error: " << e.what() << endl;
        system("PAUSE");
        system("cls");
        GetUserInput(account);
    }
}

// Validates and returns a whole number
int GetValidInt() {
    int x;
    while (!(cin >> x)) {
        cout << "Please enter a valid whole number: ";
        cin.clear();
        while (cin.get() != '\n');
    }
    return x;
}

// Validates and returns a decimal number
double GetValidDouble() {
    double x;
    while (!(cin >> x)) {
        cout << "Please enter a valid number: ";
        cin.clear();
        while (cin.get() != '\n');
    }
    return x;
}