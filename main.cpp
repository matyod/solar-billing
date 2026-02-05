#include <iostream>
#include <iomanip>
#include <limits> // library for int limit
using namespace std;

int main() {
  cout << endl;
  cout << "+-------------------------------------------+" << endl;
  cout << "| Welcome to Energy Consumption Calculator! |" << endl;
  cout << "+-------------------------------------------+" << endl << endl;

  const int MAX_SIZE = 10;
  int numBills = 0, accountNumberList[MAX_SIZE];;
  char userChoice, consumptionCodeList[MAX_SIZE];
  float kWhUsageList[MAX_SIZE], totalBillList[MAX_SIZE], amountDue = 0, totalAmountDue = 0;

  do {
    int accNum;
   	bool invalidInput = false;
    do {
      invalidInput = false;
      cout << "Enter account number (9-digit): ";
      cin >> accNum;

      if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        invalidInput = true;
      } else if (accNum >= numeric_limits<int>::max()) {
        invalidInput = true;
      }

      if (invalidInput) {
        cout << "Invalid account number. Please try again." << endl << endl;
      }
    } while (invalidInput);

    char consumptionCode;
    do {
      string input;
      cout << "Enter consumption code (c/h): ";
      cin >> input;

      if (input.length() == 1 && (input[0] == 'c' || input[0] == 'h')) {
        consumptionCode = input[0];
        break;
      } else {
       	cout << "Invalid code. Re-enter code." << endl << endl;
      }
    } while (true);

    float kWhUsage;
    bool kWhUsageInvalid;
    do {
      kWhUsageInvalid = false;
      cout << "Enter kWh usage: ";

      if (!(cin >> kWhUsage)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        kWhUsageInvalid = true;
        cout << "Invalid input format. Please enter a number." << endl << endl;
      }
    } while (kWhUsageInvalid);

    if (consumptionCode == 'h') {
      if (kWhUsage <= 200.00) {
        amountDue = kWhUsage * 0.218;
      } else {
        amountDue = (kWhUsage - 200) * 0.526 + (200.00 * 0.218);
      }
    } else if (consumptionCode == 'c') {
      if (kWhUsage <= 10000) {
        amountDue = kWhUsage * 0.10;
      } else {
        amountDue = (kWhUsage - 10000) * 0.25 + (10000 * 0.10);
      }
    }

    cout << fixed << setprecision(2) << "Amount Due: RM " << amountDue << endl;

    totalBillList[numBills] = amountDue;
    accountNumberList[numBills] = accNum;
    consumptionCodeList[numBills] = consumptionCode;
    kWhUsageList[numBills] = kWhUsage;
    numBills++;

    do {
      string input;
      cout << endl << "Do you want to calculate another bill? (y/n): ";
      cin >> input;

      if (input.length() == 1 && (input[0] == 'y' || input[0] == 'Y' || input[0] == 'n' || input[0] == 'N')) {
        userChoice = input[0];
        break;
      } else {
       	cout << "Invalid command." << endl;
      }
    } while (true);

    cout << endl;
  } while (userChoice == 'y' || userChoice == 'Y');

  cout << "\t+------------------------------------------------+" << endl;
  cout << "\t|             SOLAR BILL COMPANY                 |" << endl;
  cout << "\t|     Your Trust is Built on Our Capability      |" << endl;
  cout << "\t+------------------------------------------------+" << endl;
  cout << endl;
  cout << "\t\tGood Day and Greetings Valued Customer" << endl;
  cout << endl;
  cout << endl;
  cout << "\tYour Bill List:" << endl;
  cout << endl;

  for (int i = 0; i < numBills; i++) {
    cout << "\tBill " << (i + 1) << ":" << endl;
    cout << "\tAccount Number: " << accountNumberList[i] << endl;
    cout << "\tConsumption Code: " << consumptionCodeList[i] << endl;
    cout << "\tEnergy Consumption (kWh): " << kWhUsageList[i] << endl;
    cout << "\tAmount Due: RM " << fixed << setprecision(2) << totalBillList[i] << endl;
    cout << endl;
  }
  cout << endl;

  for (int i = 0; i < numBills; i++) {
    totalAmountDue += totalBillList[i];
  }
  cout << "\tTotal amount due for all the bills: RM " << fixed << setprecision(2) << totalAmountDue << endl;
  cout << endl;

  cout << "\t+------------------------------------------------+" << endl;
  cout << "\t|        Thank You For Using Our Service         |" << endl;
  cout << "\t|                See You Again                   |" << endl;
  cout << "\t+------------------------------------------------+" << endl;
  cout << endl;

  return 0;
}
