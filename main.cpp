//A  Restaurant Project Struct style Dr_T Dr. Tyson McMillan 10-2-2019

#include "order.h"

int main() 
{
  char transaction = 'Y';
  do{
    vector<MenuItem> wholeMenu; 
    populateMenu(wholeMenu); //put some default values in the menu
    showMenu(wholeMenu); //print the current data of the menu on screen 
    acceptOrder(wholeMenu);
    cout << "\n\nWould you like to make another transaction?" << endl;
    cout << "Enter any key for another transaction or N (n) for No: ";
    cin >> transaction;
    system("clear");
    } while(transaction != 'N' && transaction != 'n');

  cout << "\nThank you for placing your order.\n" << endl;
    
  return 0; 
}