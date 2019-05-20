#include<iostream>
#include<iostream>
#include<string>
#include <cstring>
#include<iomanip>
#include <cctype>
#include <algorithm>


using namespace std;

struct Client
{
	int accountNumber;
	char givenName[50];
	char familyName[50];
	char typeOfAccount[5];
	char address[200];
	double balance;
};

int init_no_Of_Client = 0;  // hold total number of clients available 
const int max_no_Of_Client = 100; // to check maximum allowed client
const int acc_Start_Number = 10000; // account number start from  

void accSortfamilyName(struct Client client[]); // sort accounts by familyName
void accSortgivenName(struct Client client[]); // sort accounts by givenName
void accSortBalance(struct Client client[]); // sort accounts by Balance	
void backToMainMenu(struct Client client[]); // Display main menu
bool checkValidAlphaNumeric(string str);  // Validate Alphanumeric Input
bool checkValidString(string strName);  // Validate string Input
bool checkValidNumeric(); // Validate Numeric Input 

class Bank
{

public:
	void displayMenu(Client client[]);
	void openNewBankAccount(Client client[]);
	void depositMoney(Client client[]);
	void withdrawMoney(Client client[]);
	void displayAllAccounts(Client client[]);
	void displayAccountDetails(Client client[]);
	void deleteAccount(Client client[]);
	void averageOfAccounts(Client client[]);
	void totalBalanceOfAccounts(Client client[]);
	void sortAccountsDetails(Client client[]);

private:

};
int main()
{	
	struct Client client[max_no_Of_Client];
	Bank bnk;
	bnk.displayMenu(client);	
	system("pause");
	return 0;
}



void Bank::averageOfAccounts(struct Client client[])
{
	system("cls");
	double totalBalance = 0, averageOfAccounts;
	if (init_no_Of_Client > 0)
	{
		for (int i = 0; i < init_no_Of_Client; i++)
		{
			totalBalance += client[i].balance;
		}
		averageOfAccounts = totalBalance / init_no_Of_Client;
		cout << "\n\tAverage of accounts blanace is :" << averageOfAccounts << endl;
	}
	else
	{
		cout << "\n\tNo client exist in system..! try again later" << endl;
	}
	backToMainMenu(client);
}

void Bank::totalBalanceOfAccounts(struct Client client[])
{
	system("cls");
	if (init_no_Of_Client > 0)
	{
		double totalBalance = 0;
		for (int i = 0; i < init_no_Of_Client; i++)
		{

			totalBalance += client[i].balance;
		}
		cout << "\n\tTotal of all accounts blanace is : " << totalBalance << endl;
	}
	else 
	{
		cout << "\n\tNo client exist in system..please try again later"<< endl;
	}
	cout << "\n";
	backToMainMenu(client);
}

void Bank::displayMenu(struct Client client[])
{
	
	Bank bnk;
	int choice;
		system("cls");
		cout << "\t" << endl ;
		cout << "\t\t\t\t\t\t Welcome to Banking App" << endl;
		cout << "\n\t***************************************************************************************************" << endl;
		cout << "\n\t\t(1) Open Bank  Account "<< "\n\t\t" <<  "(2) Deposit  Money  " << "\n\t\t"  << "(3) Withdraw  Money";

		cout << "\n\t\t(4) Display Account   " << "\n\t\t" <<  "(5) Delete Account " <<" \n\t\t" <<  "(6) Sort Account Details" ;
		
		cout << "\n\t\t(7) Average Of Accounts " << "\n\t\t" <<  "(8) Total balance of Accounts" << "\n\t\t" << "(9) Display all account details" ;

		cout << "\n\t\t(10) Exit  "<<endl ;
		cout << "\n\t***************************************************************************************************" << endl;

		
   
		flag: cout << "\n\n\t Select the menu option from above : "  ;
      
		cin >> choice;

		if (!checkValidNumeric())
		{
			cout << "\n\t Invalid input please try again..! " << endl;
			cin.clear();
			cin.ignore(512, '\n');
			goto flag;
		}
		switch (choice)
		{
		case 1:
			bnk.openNewBankAccount(client);
			break;
		case 2:
			bnk.depositMoney(client);
			break;
		case 3:
			bnk.withdrawMoney(client);
			break;
		case 4:
			bnk.displayAccountDetails(client);
			break;
		case 5:
			bnk.deleteAccount(client);
			break;
		case 6:
			bnk.sortAccountsDetails(client);
			break;
		case 7:
			bnk.averageOfAccounts(client);
			break;
		case 8:
			bnk.totalBalanceOfAccounts(client);
			break;
		case 9:
			bnk.displayAllAccounts(client);			
			break;
		case 10:
			exit(0);
			break;
		default:
			cout << "This option doesn't exist.! try again.." << endl;
			goto flag;
			break;
		}
		
}

void Bank::sortAccountsDetails(struct Client client[])
{
	system("cls");
	Bank bnk;
	int choice;
	
	cout << "\n\t*******************************************************" << endl;
	cout << "\n\t (1) Sort account details by balance " << endl;
	cout << "\n\t (2) Sort account details by familyname" << endl;
	cout << "\n\t (3) Sort account details by givenname " << endl;
	cout << "\n\t (4) Go back to previous menu" << endl;
	cout << "\n\t*******************************************************" << endl;
    flag:cout << "\n\tSelect the option from above to sort customer details :";
	cin >> choice;
	if (!checkValidNumeric())
	{
		cout << "\n\tInvalid input please try again..! " << endl;
		cin.clear();
		cin.ignore(512, '\n');
		goto flag;
	}
	switch (choice)
	{
	case 1:		
		accSortBalance(client);
		break;
	case 2: 
		accSortfamilyName(client);
		break;
	case 3: 
		accSortgivenName(client);
		break;
	case 4:
		bnk.displayMenu(client);
		break;
	default:
		cout << "\n\tThis option doesn't exist.! try again.." << endl;
		goto flag;
		break;
	}
	cout << "\n";
	backToMainMenu(client);
}

void Bank :: deleteAccount(struct Client client[])
{
	system("cls");
	int accountNumber, flag=0;
	flag:cout << "\n\tPlease enter the account number  to delete account :"<< endl;
	cin >> accountNumber;
	if (accountNumber == NULL) 
	{
		cout << "Please enter client's account number..!" << endl;
		cin.clear();
		cin.ignore(512, '\n');
		goto flag;
	}
	if (!checkValidNumeric())
	{
		cout << "\n\tInvalid input please try again..! " << endl;
		cin.clear();
		cin.ignore(512, '\n');
		goto flag;
	}
	for (int i = 0; i < init_no_Of_Client; i++)
	{
		if (client[i].accountNumber = accountNumber)
		{
			for (int j = i; j < (init_no_Of_Client - 1); j++)
			{
				client[j].accountNumber = client[j + 1].accountNumber;
				client[j].familyName[50] = client[j + 1].familyName[50];
				client[j].givenName[50] = client[j + 1].givenName[50];
				client[j].typeOfAccount[5] = client[j + 1].typeOfAccount[5];
				client[j].balance = client[j + 1].balance;
				client[j].address[200] = client[j + 1].address[200];
			 }
			flag++;
			init_no_Of_Client--;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "\n\tAccount doesn't exist..please enter the valid account" << endl;
	}
	else
	{
		cout << "\n\t Account has been deleted successfully!" << endl;
	}
	cout << "\n";
	backToMainMenu(client);
}

 void Bank :: openNewBankAccount(struct  Client client[] )
{ 
	 string givenName, familyName, accty;
	 double balance;
	 char address[200];
	  
	 system("cls");
	
	 if (init_no_Of_Client == max_no_Of_Client)
	 {
		 cout << "\n\tCustomer capacity reached .. no more client allowed to add" << endl;
	 }
	 else
	 {
		 if (init_no_Of_Client == 0)
		 {
			 client[init_no_Of_Client].accountNumber = acc_Start_Number;
		 }
		 else
		 {
			 client[init_no_Of_Client].accountNumber = client[init_no_Of_Client - 1].accountNumber + 1;
		 }
		 cout << "\n\tCustomer account number is :" << client[init_no_Of_Client].accountNumber << endl;
		 cout << "--------------------------------------------------" << endl;

	     gName: cout << "\n\tEnter client's given Name :";
		 cin >> givenName;

		 if (givenName.empty()) {

			 cout << "Please enter client's givenname..!" << endl;
			 cin.clear();
			 cin.ignore(512, '\n');
			 goto gName;
		 }

		 if (!checkValidString(givenName))
		 {
			 cout << "\n\t Invalid input please try again..! " << endl;
			 cin.clear();
			 cin.ignore(512, '\n');
			 goto gName;
		 }

		 transform(givenName.begin(), givenName.end(), givenName.begin(), ::toupper);
		 strcpy_s(client[init_no_Of_Client].givenName, givenName.c_str());

	     fName: cout << "\n\tEnter client's family name :";
		 cin >> familyName;

		 if (familyName.empty()) {

			 cout << "\n\t please enter client familyname..! " << endl;
			 cin.clear();
			 cin.ignore(512, '\n');
			 goto fName;
		 }

		 if (!checkValidString(familyName))
		 {
			 cout << "\n\tInvalid input please try again..! " << endl;
			 cin.clear();
			 cin.ignore(512, '\n');
			 goto fName;
		 }
		 transform(familyName.begin(), familyName.end(), familyName.begin(), ::toupper);
		 strcpy_s(client[init_no_Of_Client].familyName, familyName.c_str());

	     laddress: cout << "\n\tEnter customer's Address : ";		
		 cin.clear();
		 cin.ignore(512, '\n');
		 cin.getline(address, sizeof(address));

		 if (address[0]== '\0')
		 {
			 cout << "\n\t please enter client address..! " << endl;
			 cin.clear();
			 cin.ignore(512, '\n');
			 goto laddress;
		 }

		 if (!checkValidAlphaNumeric(address)) {
			 cout << "\n\tInvalid input please try again..! " << endl;
			 cin.clear();
			 cin.ignore(512, '\n');
			 goto laddress;
		 }

		 strcpy_s(client[init_no_Of_Client].address, address);


	     acctyp: cout << "\n\tType of account wants to open saving (s) or current (c) ? :  ";
		 /*cin.clear();
		 cin.ignore(512, '\n');*/
		 cin >> accty;

		 if (accty.empty())
		 {
			 cout << "\n\t please enter account type..! " << endl;
			 cin.clear();
			 cin.ignore(512, '\n');
			 goto acctyp;
		 }
  

		// accty = toupper(accty);
		 if (accty == "s" || accty == "c" || accty == "S" || accty == "C")
		 {
			 strcpy_s(client[init_no_Of_Client].typeOfAccount, accty.c_str());			 
		 }
		 else
		 {
			 cout << "\n\tInvalid input please try again..! " << endl;
			 cin.clear();
			 cin.ignore(512, '\n');
			 goto acctyp;
		 }

		damount: cout << "\n\tEnter amount for deposite : $ ";
		 cin >> balance;
		 if (!checkValidNumeric()) {

			 cout << "\n\tInvalid input please try again..! " << endl;
			 cin.clear();
			 cin.ignore(512, '\n');
			 goto damount;
		 }
		  client[init_no_Of_Client].balance= balance;

		 cout << "\n\tYour account is created ! " << endl;

		 init_no_Of_Client++;
	 }
	 cout << "\n";
	 backToMainMenu(client);
	
}


 void Bank :: depositMoney(struct Client client[])
{
	 system("cls");
	
	 int depositAmount;
	 int accountNumber, flag=0, counter=0;
	 if (init_no_Of_Client==0)
	 {
		 cout << "No client exist in system to deposite amount" << endl;
		 backToMainMenu(client);
	}
	 else
	 {
		 do {
		 acc: cout << "\n\t Please enter the account number to deposite amount : ";
			 cin >> accountNumber;

			 if (accountNumber == NULL)
			 {
				 cout << "\n\t Please enter the client's account number..! " << endl;
				 cin.clear();
				 cin.ignore(512, '\n');
				 goto acc;
			 }
			 if (!checkValidNumeric())
			 {
				 cout << "\n\t Invalid input please try again..! " << endl;
				 cin.clear();
				 cin.ignore(512, '\n');
				 goto acc;
			 }

			 for (int i = 0; i < init_no_Of_Client; i++)
			 {
				 if (client[i].accountNumber == accountNumber) {
					 cout << "\n\n\tEnter deposite amoumt : " ;
					 cin >> depositAmount;
					 client[i].balance += depositAmount;
					 cout << "\n\n\tTotal Amount client deposite : $" << depositAmount << endl;
					 cout << "\n\t New Balance in customer :" << client[i].givenName << "'s account is : $" << client[i].balance << endl;

					 flag++;
					 counter = 0;
				 }
			 }
			 if (flag == 0)
			 {
				 cout << "\n\tAccount number doesn't exist, please enter the valid account number..!" << endl;
				 counter = 1;
			 }
			 cout << "\n"  ;
			 backToMainMenu(client);
		 } while (counter);
	 }
	 
	 
		 
}

 void Bank :: displayAccountDetails(struct Client client[])

 {
	 system("cls");
	 
	 int accountNumber, flag=0 , counter=0;

	 if (init_no_Of_Client > 0) {
		 do {
			acc: cout << "\n\n\t Please enter the account number to display customer details : ";
			 cin >> accountNumber;

			 if (accountNumber == NULL)
			 {
				 cout << "\n\t Please enter the client's account number..! " << endl;
				 cin.clear();
				 cin.ignore(512, '\n');
				 goto acc;
			 }

			 if (!checkValidNumeric())
			 {
				 cout << "\n\t Invalid input please try again..! " << endl;
				 cin.clear();
				 cin.ignore(512, '\n');
				 goto acc;
			 }

			 for (int i = 0; i < init_no_Of_Client; i++)
			 {
				 if (client[i].accountNumber == accountNumber) {
					 cout << "**********************************************************************************************************************" << endl;
					 cout << setw(7) << " AccountNumber" << setw(15) << " FullName" << setw(20) << " Address" << setw(20) << " Type Of Account" << setw(30) << " Balance" << endl;
					 cout << "**********************************************************************************************************************" << endl;
					 cout << setw(7) << client[i].accountNumber << setw(15) << client[i].givenName << " " << client[i].familyName << setw(20) << client[i].address << setw(20) << client[i].typeOfAccount << setw(20) <<"$ " << client[i].balance << endl;

					 flag++;
				 }

			 }
			 if (flag == 0)
			 {

				 cout << "\n\tAccount number doesn't exist, please enter the valid account number..!" << endl;
				 counter = 1;
			 }
		 } while (counter);
	 }
	 else
	 {
		 cout << "\n\tNo account is available to display..!";
	 }
	
	 cout << "\n";
	 backToMainMenu(client);
 }


 void Bank :: displayAllAccounts(struct Client client [])
 {
	 system("cls");
	 
	 if (init_no_Of_Client > 0) 
	 {
		 cout << "**********************************************************************************************************************" << endl;
		 cout << setw(7) << " AccountNumber" << setw(15) << " FullName" << setw(20) << " Address" << setw(20) << " Type Of Account" << setw(20) << " Balance" << endl;
		 cout << "**********************************************************************************************************************" << endl;
		
			 for (int i = 0; i < init_no_Of_Client; i++)
			 {
				 cout << setw(7) << client[i].accountNumber << setw(15) << client[i].givenName << " " << client[i].familyName << setw(20) << client[i].address << setw(15) << client[i].typeOfAccount << setw(20) << "$ " << client[i].balance << endl;
			 }
	 }
	 else
	 {
		 cout << "\n\tNo client account is exist to display.!" << endl;
	 }
	 cout << "\n";
	 backToMainMenu(client);
	 
 }

 void Bank :: withdrawMoney( struct Client client[])
 {
	
	 int withdrawAmount, flag = 0;
	 int accountNumber;
	 
	 system("cls");
	
		acc: cout << "\n\t Please enter the account number to withdraw money : $"  ;
		 cin >> accountNumber;

		 if (accountNumber == NULL)
		 {

			 cout << "\n\t Please enter the client's account number..! " << endl;
			 cin.clear();
			 cin.ignore(512, '\n');
			 goto acc;
		 }
		 if (!checkValidNumeric())
		 {
			 cout << "\n\t Invalid input please try again..! " << endl;
			 cin.clear();
			 cin.ignore(512, '\n');
			 goto acc;
		 }

		 for (int i = 0; i < init_no_Of_Client; i++)
		 {
			 if (client[i].accountNumber == accountNumber)
			 {
				 cout << "\n\tEnter withdraw amoumt :  $ " << endl;
				 cin >> withdrawAmount;
				 if (client[i].balance > withdrawAmount) 
				 {
					 client[i].balance -= withdrawAmount;
					 cout << "\n\t Amount withdraw : $" << withdrawAmount << endl;
					 cout << "\n\tBalance left in customer :" << client[i].givenName << "'s account is : $" << client[i].balance << endl;
					 flag++;
					// break;
				 }
				 else
				 {
					 cout << "Insufficent fund available in client's  account..! " << endl;
					 flag++;
					
				 }
			 }
		 }
		 if (flag == 0)
		 {
			 cout << "\n\tAccount number doesn't exist, please enter the valid account number..!" << endl;
			 goto acc;
		 }
	
		 cout << "\n";
	 backToMainMenu(client);

 }

 void accSortfamilyName(struct Client client[])
 {
	 system("cls");
	 Bank bnk;

	 int j, i;
	 Client temp;
	 if (init_no_Of_Client > 0)
	 {																											

		 for (i = 0; i < init_no_Of_Client - 1; ++i)
		 {
			 for (j = i + 1; j < init_no_Of_Client; ++j)
			 {
				 if (strcmp(client[i].familyName, client[j].familyName) > 0)
				 {
					 temp = client[i];
					 client[i] = client[j];
					 client[j] = temp;
				 };
			 }
		 }

		 bnk.displayAllAccounts(client);
	 }
	 else
	 {
		 cout << "No client account exist in system..try again later" << endl;
	 }
	 cout << "\n";
	 backToMainMenu(client);
 }

 void accSortgivenName(struct Client client[])
 {
	 system("cls");
	 Bank bnk;
	 int j, i;
	 Client temp;
	 if (init_no_Of_Client > 0)
	 {
		 for (i = 0; i < init_no_Of_Client - 1; ++i)
		 {
			 for (j = i + 1; j < init_no_Of_Client; ++j)
			 {
				 if (strcmp(client[i].givenName, client[j].givenName) > 0)
				 {
					 temp = client[i];
					 client[i] = client[j];
					 client[j] = temp;
				 };
			 }
		 }
		 bnk.displayAllAccounts(client);
	 }
	 else
	 {
		 cout << "No client account exist in system..try again later" << endl;
	 }
	 cout << "\n";
	 backToMainMenu(client);
 }

 void accSortBalance(struct Client client[]) {
	 system("cls");
	 Bank bnk;
	 if (init_no_Of_Client > 0)
	 {
		 int j, i;
		 Client temp;
		 for (i = 0; i < init_no_Of_Client - 1; ++i)
		 {
			 for (j = i + 1; j < init_no_Of_Client; ++j)
			 {
				 if (client[i].balance > client[j].balance)
				 {
					 temp = client[i];
					 client[i] = client[j];
					 client[j] = temp;
				 };
			 }
		 }

		 bnk.displayAllAccounts(client);
	 }
	 else
	 {
		 cout << "No client account exist in system..try again later" << endl;
	 }
	 cout << "\n";
	 backToMainMenu(client);
 }

 void backToMainMenu(struct Client client[])
 {
	 Bank bnk;
	 char backMainMenu;
	 cout << "\n";
	 cout << " Back to main menu (y/n) : ";
	 cin >> backMainMenu;

	 if (tolower(backMainMenu) == 'y')
	 {
		 bnk.displayMenu(client);
		 
	 }
	 else
	 {
		 exit(0);
	 }
 }

 bool checkValidString(string strName)
 {
	
		 bool bRejected = false;


		 for (unsigned int nIndex = 0; nIndex < strName.length() && !bRejected; ++nIndex)
		 {
			 // If the current character is an alpha character, that's fine
			 if (isalpha(strName[nIndex]))
				 continue;

			 // If it's a space, that's fine too
			 if (strName[nIndex] == ' ')
				 continue;

			 // Otherwise we're rejecting this input
			 bRejected = true;
		 }

		 if (bRejected) {

			 return false;
		 }
		 else
		 {
			 return true;
		 }
	 
	
		 
 }

 bool checkValidAlphaNumeric(string str) 
 {
	 bool bRejected = false;


	 for (unsigned int nIndex = 0; nIndex < str.length() && !bRejected; ++nIndex)
	 {
		 // If the current character is an alpha character, that's fine
		 if (isalnum(str[nIndex]))
			 continue;

		 // If it's a space, that's fine too
		 if (str[nIndex] == ' ')
			 continue;

		 // If it's a comma , that's fine too (for Address)
		 if (str[nIndex] == ',')
			 continue;

		
		 // Otherwise we're rejecting this input
		 bRejected = true;
	 }
	 
	 if (bRejected) {

		 return false;
	 }
	 else
	 {
		 return true;
	 }

 }

 bool checkValidNumeric()
 {
	 if (cin.fail() || cin.peek() != '\n') 
	 {
		 return false;
	 }
	 else
	 {
		 return true;
	 }

 }



