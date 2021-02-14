#include <iostream>

using namespace std;

void InputHandler(int& input, bool isTime);
void InputHandler(double& input);
void InputHandler(bool& usedCar, bool& usedTaxi);
double CalcTravelExpenses(bool& usedCar, bool& usedTaxi, double& transpFees, int numOfDays);
double CalcMealExpenses(double& mealFees, int departTime, int arrivalTime, int numOfDays);

int main() {

  int numOfDays, departTime, arrivalTime;
  double airfare, confFees, transpFees, mealFees;
  bool usedCar, usedTaxi;

  cout << "Enter the number of days on your trip: ";
  InputHandler(numOfDays, false);
  cout << endl << endl;
  
  
  cout << "Enter your departure time (just the hour) on the first day in 24-hour format (i.e., 16 for 4pm): ";
  InputHandler(departTime, true);
  
  cout << "Enter your arrival time (just the hour) on the last day in 24-hour format (i.e., 16 for 4pm): ";
  InputHandler(arrivalTime, true);
  cout << endl << endl;
  
  
  cout << "Enter total amount of airfare, in $: ";
  InputHandler(airfare);

  cout << "Enter total conference or seminar fees, in $: ";
  InputHandler(confFees);
  cout << endl << endl;
  
  double totalTravelExcess = CalcTravelExpenses(usedCar, usedTaxi, transpFees, numOfDays);
  double totalMealExcess = CalcMealExpenses(mealFees, departTime, arrivalTime, numOfDays);
  
  double totalFees = airfare + confFees + transpFees + mealFees;
  double totalExcess = totalTravelExcess + totalMealExcess;
  
  return 0;

}

void InputHandler(int& input, bool isTime) {

  cin >> input;
  
  // Makes sure it's an integer
  if (cin.fail()) {
  
    do {
      
      cin.clear();
      cin.ignore(256, '\n');
      cout << endl << "That wasn't a valid input, try again - ";
      cin >> input;
    
    } while (cin.fail());
  
  }
  
  // Recalls input if time isn't real
  if (isTime) {
  
    if (input > 24 || input < 0) {

        cout << endl << "That isn't a real time, try again - ";
        InputHandler(input, true);
    
    }
  
  }

}

void InputHandler (double& input) {

  cin >> input;
  
  // Makes sure it's an integer
  if (cin.fail()) {
  
    do {
      
      cin.clear();
      cin.ignore(256, '\n');
      cout << endl << "That wasn't a valid input, try again - ";
      cin >> input;
    
    } while (cin.fail());
  
  }

}

void InputHandler(bool& usedCar, bool& usedTaxi) {

  int input;
  cin >> input;
  
  // Makes sure it's an integer
  if (cin.fail()) {
  
    do {
      
      cin.clear();
      cin.ignore(256, '\n');
      cout << endl << "That wasn't a valid input, try again - ";
      cin >> input;
    
    } while (cin.fail());
  
  }
  
  // Recalls input if it isn't 1 or 2
  if (input != 1 && input != 2) {
  
    cout << "That wasn't a 1 or 2, try again - ";
    InputHandler(usedCar, usedTaxi);
  
  } else {
  
    usedCar = input == 1 ? true : false;
    usedTaxi = input == 2 ? true : false;
  
  }

}

double CalcTravelExpenses(bool& usedCar, bool& usedTaxi, double& transpFees, int numOfDays) {

  cout << "Did you 1: rent a car or 2: use taxi during your trip? Enter 1 or 2: ";
  InputHandler(usedCar, usedTaxi);
  cout << endl << endl;
  
  double reimbDailyFee;
  
  if (usedCar) {
  
    cout << "Enter your total car rental fee, including gas fee, in $: ";
    InputHandler(transpFees);
    cout << endl << endl;
    
    for (int i = 0; i <= numOfDays-1; i++) {
  
      cout << "Enter your parking fee for day " << i + 1 << ": "; 
      double amount;
      InputHandler(amount);
      transpFees += amount;
      
      reimbDailyFee = amount <= 6 ? amount : 6; 
  
    }
  
  } else if (usedTaxi) {
    
    for (int i = 0; i <= numOfDays-1; i++) {
  
      cout << "Enter your taxi fee for day " << i + 1 << ": ";
      double amount; 
      InputHandler(amount);
      transpFees += amount;
      
      reimbDailyFee = amount <= 6 ? amount : 6;
  
    }
  
  }
  
  cout << endl << endl;
  
  for (int i = 0; i <= numOfDays-2; i++) {
  
    cout << "Enter your hotel fee for night " << i + 1 << " in $: ";
    double amount;
    InputHandler(amount);
    
    reimbDailyFee += amount <= 90 ? amount : 90;
    transpFees += amount;
  
  }
  
  cout << endl << endl;
   
  return transpFees - reimbDailyFee;

}

double CalcMealExpenses(double& mealFees, int departTime, int arrivalTime, int numOfDays) {

  double reimbDailyFee;

  for (int i = 0; i <= numOfDays-1; i++) {
    
    double amount;
    cout << "Day " << i + 1 << endl; 
    if (i == 0) {
      
      int meals = 0;
      meals = departTime <= 7 ? meals+1: meals;
      meals = departTime <= 12 ? meals+1: meals;
      meals = departTime <= 18 ? meals+1: meals; 
      switch (meals) {
      
        case 0:
          cout << "Your breakfast for day 1 is not allowed for reimbursement." << endl;
          cout << "Your lunch for day 1 is not allowed for reimbursement." << endl;
          cout << "Your dinner for day 1 is not allowed for reimbursement." << endl << endl;
          break;
        
        case 1:
          cout << "Enter breakfast fee, in $: ";
          InputHandler(amount);
          mealFees += amount;
          reimbDailyFee = amount <= 9 ? amount : 9;
          
          cout << "Your lunch for day 1 is not allowed for reimbursement." << endl;
          cout << "Your dinner for day 1 is not allowed for reimbursement." << endl << endl;
          break;
          
        case 2:
          cout << "Enter breakfast fee, in $: ";
          InputHandler(amount);
          mealFees += amount;
          reimbDailyFee = amount <= 9 ? amount : 9;
          
          cout << "Enter lunch fee, in $: ";
          InputHandler(amount);
          mealFees += amount;
          reimbDailyFee = amount <= 12 ? amount : 12;
          
          cout << "Your dinner for day 1 is not allowed for reimbursement." << endl << endl;
          break;
        
        case 3:
          cout << "Enter breakfast fee, in $: ";
          InputHandler(amount);
          mealFees += amount;
          reimbDailyFee = amount <= 9 ? amount : 9;
          
          cout << "Enter lunch fee, in $: ";
          InputHandler(amount);
          mealFees += amount;
          reimbDailyFee = amount <= 12 ? amount : 12;
          
          cout << "Enter dinner fee, in $: ";
          InputHandler(amount);
          mealFees += amount;
          reimbDailyFee = amount <= 12 ? amount : 12;
          
          cout << endl << endl;
          break;
      }

    } else if (i == numOfDays-1) {
      
      int meals = 0;
      meals = departTime >= 8 ? meals+1: meals;
      meals = departTime >= 13 ? meals+1: meals;
      meals = departTime >= 19 ? meals+1: meals; 
      switch (arrivalTime) {
      
        case 0:
          cout << "Your breakfast for day 1 is not allowed for reimbursement." << endl;
          cout << "Your lunch for day 1 is not allowed for reimbursement." << endl;
          cout << "Your dinner for day 1 is not allowed for reimbursement." << endl << endl;
          break;
        
        case 1:
          cout << "Enter breakfast fee, in $: ";
          InputHandler(amount);
          mealFees += amount;
          reimbDailyFee = amount <= 9 ? amount : 9;
          
          cout << "Your lunch for day 1 is not allowed for reimbursement." << endl;
          cout << "Your dinner for day 1 is not allowed for reimbursement." << endl << endl;
          break;
          
        case 2:
          cout << "Enter breakfast fee, in $: ";
          InputHandler(amount);
          mealFees += amount;
          reimbDailyFee = amount <= 9 ? amount : 9;
          
          cout << "Enter lunch fee, in $: ";
          InputHandler(amount);
          mealFees += amount;
          reimbDailyFee = amount <= 12 ? amount : 12;
          
          cout << "Your dinner for day 1 is not allowed for reimbursement." << endl << endl;
          break;
        
        case 3:
          cout << "Enter breakfast fee, in $: ";
          InputHandler(amount);
          mealFees += amount;
          reimbDailyFee = amount <= 9 ? amount : 9;
          
          cout << "Enter lunch fee, in $: ";
          InputHandler(amount);
          mealFees += amount;
          reimbDailyFee = amount <= 12 ? amount : 12;
          
          cout << "Enter dinner fee, in $: ";
          InputHandler(amount);
          mealFees += amount;
          reimbDailyFee = amount <= 12 ? amount : 12;
          
          cout << endl << endl;
          break;
      
      }
       
    } else {
      
      cout << "Enter breakfast fee, in $: ";
      InputHandler(amount);
      mealFees += amount;
      reimbDailyFee += amount <= 9 ? amount : 9;
        
      cout << "Enter lunch fee, in $: ";
      InputHandler(amount);
      mealFees += amount;
      reimbDailyFee += amount <= 12 ? amount : 12;
        
      cout << "Enter dinner fee, in $: ";
      InputHandler(amount);
      mealFees += amount;
      reimbDailyFee += amount <= 12 ? amount : 12;
      
      cout << endl << endl;
    }
  
  }
  
  
  return mealFees - reimbDailyFee;

}
