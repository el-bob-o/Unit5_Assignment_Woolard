#ifndef ORDER_H_INCLUDED
#define ORDER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <ctime>
#include "Input_Validation_Extended.h"
#include "colors.h"

using namespace std; 


class MenuItem {
  private:
    string name;
    double itemCost; 
    string desc; 
    char addLetter; 
    char removeLetter;
    int count;
  public:
    MenuItem() {
      name = "Default";
      itemCost = 0.00;
      desc = "delicious";
      addLetter = ' ';
      removeLetter = ' ';
      count = 0;
    }
    void setName(string n) { name = n; }
    void setItemCost(double ic) { itemCost = ic; }
    void setDesc(string d) { desc = d; }
    void setAddLetter(char a) { addLetter = a; }
    void setRemoveLetter(char r) { removeLetter = r; }
    void setCount(int c) { count = c; }
    
    string getName() { return name; }
    double getItemCost() { return itemCost; }
    string getDesc() { return desc; }
    char getAddLetter() { return addLetter; }
    char getRemoveLetter() { return removeLetter; }
    int getCount() { return count; }
};

//function definitions
void populateMenu(vector<MenuItem> &entireMenu)
{
  //put some default values in our Menu
  const int numItems = 7; 
  MenuItem Item1; 
  MenuItem Item2;
  MenuItem Item3; 
  MenuItem Item4;
  MenuItem Item5;
  MenuItem Item6;
  MenuItem Item7;    

  entireMenu.push_back(Item1); //add to the end of list the Item1
  entireMenu.push_back(Item2); //add to the end of list the Item2
  entireMenu.push_back(Item3); //add to the end of list the Item3
  entireMenu.push_back(Item4); //add to the end of list the Item4
  entireMenu.push_back(Item5); //add to the end of list the Item5
  entireMenu.push_back(Item6); //add to the end of list the Item6
  entireMenu.push_back(Item7); //add to the end of list the Item7

  vector<string> defaultMenuNames = {"Green Tea", "Burrito", "Hamburger", "Taco", "Chicken",
                                     "Pizza", "Caviar"}; 
  vector<char> defaultAddLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; 
  vector<char> defaultRemoveLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'}; 

  for(int i = 0; i < numItems; i++)
  {
    //add each item to the default list efficiently 
    entireMenu[i].setName(defaultMenuNames[i]); 
    entireMenu[i].setAddLetter(defaultAddLetters[i]); 
    entireMenu[i].setRemoveLetter(defaultRemoveLetters[i]); 
    entireMenu[i].setItemCost(3.00 + i); //set a random starter cost for each item
    entireMenu[i].setCount(0); //initialze all counts to 0
    entireMenu[i].setDesc("delicious"); //set all default desc to "delicous"
  }


}

void showMenu(vector<MenuItem> &m)
{
  cout << fixed << setprecision(2);//set doubles to 2 decimal places
  cout << KBLU << UNDL("DrT's Effcient Restaurant Menu") << RST << endl; 
  cout << KCYN << BOLD("ADD  \tNAME \t COST \tREMOVE\tCOUNT\tDESC")<<RST<<endl; 
  for(int i = 0; i < m.size(); i++)
  {
    cout << KGRN << m[i].getAddLetter() << ")" << setw(10) << m[i].getName() 
    << setw(5) << "$" << m[i].getItemCost() << setw(5) << "(" << m[i].getRemoveLetter()
    << ")" << setw(7) << m[i].getCount() << setw(13) << m[i].getDesc() << RST
    <<endl; 
  }

}

void payment(double &total) //payment method handling
{
  double cash; //variable for cash amount
  int payChoice;
  
  do {
    cout <<KBLU<<BOLD("\nYour total amount due is $")<<KBLU<<total<<RST<<endl;
    cout << "\nWould like to pay using Cash or a Card?" << endl;
    cout << KMAG <<"1) Cash" << endl;
    cout << "2) Card" << RST << endl;
    cout << "Please make a selection: ";
    payChoice = validateInt(payChoice);
    
    while(payChoice < 1 || payChoice > 2) {
      cout << "Please make a valid choice." << endl;
      cout << "Would like to pay using Cash or a Card?" << endl;
      cout << KMAG <<"1) Cash" << endl;
      cout << "2) Card" << RST << endl;
      cout << "Enter 1 or 2: ";
      payChoice = validateInt(payChoice);
    }

  switch (payChoice) {
    case 1:
            cout << "Total due: $" << total << endl;
            cout << "Please enter the amount of cash tendered: ";
            cin >> cash;

            if (cash > total) {
              cout << "Your change is: $" << cash - total << endl;
              return;
            }
            else {
              cout << "Please enter an amount equal to or greater than: $" << total << endl;
              break;
            }
    case 2:
            cout << "Please swipe your card." << endl;
            return;
    }
  } while (payChoice >= 1 && payChoice <= 2);
  return;
} 

void tipMenu(double &subtotal, double &total) //menu to calculate tip
{
  int choice;
  double tip = 0.00;

  if(subtotal <= 0) {
    exit(0);
  }
  
  cout << KCYN << "Please select an amount to tip." << RST << endl;
  cout << KMAG << "1) 20%: $" << subtotal * 0.20 << ": Total (with tax) = $" << subtotal * 1.28 << endl;
  cout << "2) 25%: $" << subtotal * 0.25 << ": Total (with tax) = $" << subtotal * 1.33 << endl;
  cout << "3) 30%: $" << subtotal * 0.30 << ": Total (with tax) = $" << subtotal * 1.38 << endl;
  cout << "4) Custom amount." << RST << endl;

  do {
    cout << "Please make a selection: ";
    cin >> choice;
  
    while(choice < 1 || choice > 4){
      cout << "Please make a valid selection." << endl;
      cout << KCYN << "Please select an amount to tip." << RST << endl;
      cout << KMAG << "1) 20%: $" << subtotal * 0.20 << ": Total (with tax) = $" << subtotal * 1.28 << endl;
      cout << "2) 25%: $" << subtotal * 0.25 << ": Total (with tax) = $" << subtotal * 1.33 << endl;
      cout << "3) 30%: $" << subtotal * 0.30 << ": Total (with tax) = $" << subtotal * 1.38 << endl;
      cout << "4) Custom amount." << RST << endl;
      cout << "Enter 1, 2, 3 or 4: ";
      choice = validateInt(choice);
    }

  switch (choice) {
    case 1:
            total = subtotal * 1.28;
            payment(total);
            return;
    case 2:
            total = subtotal * 1.33;
            payment(total);
            return;
    case 3:
            total = subtotal * 1.38;
            payment(total);
            return;
    case 4:
            cout << "Please enter a tip amount: $";
            cin >> tip;
            if (tip >= 0.00) {
              total = (subtotal * 1.08 + tip);
              payment(total);
              return;
            }
            else {
              cout << "Please enter an amount equal to or greater than 0: $";
              tip = validateDouble(tip);
            }
    }
    } while (choice >= 1 && choice <= 4);
      return;
}

void printReceipt(vector<MenuItem> &m, double &subtotal, double &total)
{
  //the following is variable will enable useing the current date in the output file
  //The file will be appended to until a new day rolls around and then a new file will be created
  time_t t = time(NULL);
  tm* tPtr = localtime(&t);
  int day = tPtr->tm_mday;
  int month = tPtr->tm_mon + 1;
  int year = tPtr->tm_year + 1900;
  int hour = tPtr->tm_hour;
  int minute = tPtr->tm_min;
  int second = tPtr->tm_sec;
  
  string currentDate = to_string(day) + "-" + to_string(month) + "-" + to_string(year) + "-"
          + to_string(hour) + "-" + to_string(minute) + "-" + to_string(second);

  cout << KRED << UNDL("\n\nReceipt") << RST << endl;
  cout << KBLU << BOLD("Quantity         Item           Price") << RST << endl;
  for(int i = 0; i < m.size(); i++) {
    if(m[i].getCount() > 0) {
      cout << setw(5) << "x" << m[i].getCount() 
        << setw(17) <<  m[i].getName() << setw(10) << "$" <<
        m[i].getItemCost() * m[i].getCount() <<  endl;
    }
  }
  cout << "Subtotal: $" << setprecision(2) << fixed << subtotal << endl;
  cout << "Tax: $" << setprecision(2) << fixed << subtotal * .08 << endl;
  cout << "Tip: $" << setprecision(2) << fixed << total - (subtotal * 1.08) << endl;
  cout << KBLU << BOLD("Total: $") << setprecision(2) << fixed << KBLU << total << RST << endl;
  
  ofstream myFile;
  myFile.open ("receipt" + currentDate + ".html"); //creating html file with current date
  myFile << "<!DOCTYPE html><html><head></head><body>";
  myFile << "<h1>Restaurant Reciept</h1>" << endl;
  myFile << "<pre style='color:green; font-size:150%;'>Quantity     Item       Price</pre>" << endl;
  for(int i = 0; i < m.size(); i++) {
    if(m[i].getCount() > 0) {
      myFile << "<pre style='color:red; font-size:120%;'>" << setw(5) << "x" << m[i].getCount() 
        << setw(17) <<  m[i].getName() << setw(10) << "$" <<
        m[i].getItemCost() * m[i].getCount() << "</pre>" << endl;
    }
  }
  myFile << "<p>Subtotal: $" << setprecision(2) << fixed << subtotal << "</p>" << endl;
  myFile << "<p>Tax: $" << setprecision(2) << fixed << subtotal * .08 << "</p>" << endl;
  myFile << "<p>Tip: $" << setprecision(2) << fixed << total - (subtotal * 1.08) << "</p>" << endl;
  myFile << "<p style='color:blue; font-size:130%;'>Total: $" << setprecision(2) << fixed 
        << total << "</p>" << endl;

  myFile.close();
  
}

void acceptOrder(vector<MenuItem> &m)
{
  char option;// the user-selected menu item
  double subtotal = 0.0;
  double total;
    
  do
  {
    cout << "\nPlease choose an item (x to Exit): ";
    cin >> option; 

    for(int i=0; i < m.size(); i++)
    {
      if(option == m[i].getAddLetter())
      {
        cout << "\nMenu Item " << m[i].getAddLetter() << " selected."; 
        m[i].setCount(m[i].getCount() +1); //increment the count by 1
        cout << "\033[2J\033[1;1H"; //clear screen 
        cout << "\n1 UP on " << m[i].getName() << endl;
        subtotal += m[i].getItemCost(); //increment the subtotal by the cost of the item 
        showMenu(m); //show the updated menu
        cout << "\nSubtotal: $" << subtotal << endl;  
      }
      else if(option == m[i].getRemoveLetter())
      {
        cout << "\nRemove Item " << m[i].getRemoveLetter() << " selected."; 
        if(m[i].getCount() > 0) //subtract if and only if the count is > 0
        {
          m[i].setCount(m[i].getCount() -1); //decrement the count by 1
          cout << "\033[2J\033[1;1H"; //clear screen 
          cout << "\n1 DOWN on " << m[i].getName() << endl;
          subtotal -= m[i].getItemCost(); //decrement the subtotal by the cost of the item
          showMenu(m); //show the updated menu
          cout << "\nSubtotal: $" << subtotal << endl;  
        }
        else //the the user why you blocked item removal 
        {
            
            cout << "\nItem count must be > 0 to remove: " << m[i].getName() << endl;
        }
      }
      else if(
                option != m[i].getAddLetter() && 
                option != m[i].getRemoveLetter() &&
                option != 'x' &&
                option != 'X' 
            ) //test for all of my valid inputs
            {
              if(i == 0)
              {
                cout << "\nInvalid input (" << option << "). Please try again." << endl; 
              }  
            }
    }
  }while(option != 'x' && option != 'X'); 
      cout << "\nThank you for placing your order.\n" << endl; 
      //handle the tip process here
      tipMenu(subtotal, total);    
  
      //handle reciept generation here
      printReceipt(m, subtotal, total);
          
}

#endif