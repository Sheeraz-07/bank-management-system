#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;
long long managerCnic = 3550202430343;
string managerName = "MUHAMMAD SHEERAZ";
string managerPassword = "iambeliever07";
    bool isDigitsOnly(const string& str) {
        for (char c : str) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }
class Customer {
private:
    long long cnic;
    string name;
    double balance;
    char accType;
    string password;
    Customer* left;
    Customer* right;

public:
    Customer() {
        cout << "\t\t\t\t\tENTER YOUR CNIC WITHOUT DASHES : ";
        string cnicInput;
        cin >> cnicInput;
        while (!isDigitsOnly(cnicInput) || cnicInput.length() < 13) {
            cout << "\t\t\t\t\tINVALID INPUT. PLEASE ENTER 13-DIGITS FOR CNIC : ";
            cin >> cnicInput;
        }
       	cnic = stoll(cnicInput);
        cin.ignore();
        cout << "\t\t\t\t\tENTER YOUR NAME : ";
        getline(cin, name);
        cout << "\t\t\t\t\tENTER ACCOUNT TYPE(c/s) : ";
        cin >> accType;
        cin.ignore();
        cout << "\t\t\t\t\tENTER A PASSWORD WITHOUT SPACES : ";
        cin >> password;
        while (password.length() < 8) {
            cout << "\t\t\t\t\tPASSWORD TOO SHORT . RE-ENTER 8 OR MORE CHARACTERS PASSWORD : ";
            cin >> password;
        }
        cout << "\t\t\t\t\tENTER YOUR INITIAL DEPOSIT : ";
        string balanceInput;
        cin >> balanceInput;
        while (!isDigitsOnly(balanceInput)) {
            cout << "\t\t\t\t\tINVALID INPUT. PLEASE ENTER DIGITS ONLY FOR BALANCE : ";
            cin >> balanceInput;
        }
        balance = stod(balanceInput);
        left = NULL;
        right = NULL;
    }

    Customer* getLeft() {
        return left;
    }

    void setLeft(Customer* node) {
        left = node;
    }

    Customer* getRight() {
        return right;
    }

    void setRight(Customer* node) {
        right = node;
    }

    long long getCnic() {
        return cnic;
    }

    void setCnic(string cnicInput) {
        while (!isDigitsOnly(cnicInput) || cnicInput.length() < 13) {
            cout << "\t\t\t\t\tINVALID INPUT. PLEASE ENTER 13-DIGITS FOR CNIC : ";
            cin >> cnicInput;
        }
       	cnic = stoll(cnicInput);
    }

    string getName() {
        return name;
    }

    void setName(string input) {
        name = input;
    }

    double getBalance() {
        return balance;
    }

    void setBalance(double bal) {
        balance = bal;
    }

    string getPassword() {
        return password;
    }
	char getAccType(){
		return accType;
	}
    void setPassword(string input) {
        while (input.length() < 8) {
            cout << "PASSWORD TOO SHORT . RE-ENTER 8 OR MORE CHARACTERS PASSWORD : ";
            cin >> input;
        }
        password = input;
    }

};
class bsTree {
private:
    Customer* root;
public:
    bsTree() {
        root = NULL;
    }
    Customer* getRoot(){
    	return root;
	}
    void insert(Customer* node) {
        if (root == NULL) {
            root = node;
            return;
        }
        Customer* fast = root;
        Customer* slow = NULL;
        while (fast != NULL) {
				slow = fast;
            if (node->getCnic() < fast->getCnic()) {
                fast = fast->getLeft();
            } else if (node->getCnic() > fast->getCnic()) {
                slow = fast;
                fast = fast->getRight();
            } else {
                cout << "\t\t\t\t\tACCOUNT ALREADY EXISTS!!!\n";
                return;
            }
        }
        if (node->getCnic() > slow->getCnic()) {
            slow->setRight(node);
        } else if (node->getCnic() < slow->getCnic()) {
            slow->setLeft(node);
        }
    }
    Customer* search(long long input) {
        Customer* fast = root;
        while (fast != NULL && fast->getCnic() != input) {
            if (input < fast->getCnic()) {
                fast = fast->getLeft();
            }
            if (input > fast->getCnic()) {
                fast = fast->getRight();
            }
        }
        return fast;
    }

    void deposit(float amount,Customer* customer) {
        double currentBalance = customer->getBalance();
        customer->setBalance(currentBalance + amount);
        cout << "\t\t\t\t\tDeposit successful. Current balance: " << customer->getBalance() << endl;
    }

    void withdraw(float amount,Customer* customer) {
        double currentBalance = customer->getBalance();
        if (amount > currentBalance) {
            cout << "\t\t\t\t\tInsufficient balance. Withdrawal failed." << endl;
        } else {
            customer->setBalance(currentBalance - amount);
            cout << "\t\t\t\t\tWithdrawal successful. Current balance: " << customer->getBalance() << endl;
        }
    }

    void balanceEnquiry(Customer* customer) {
        cout << "\t\t\t\t\tCurrent balance: " << customer->getBalance() << endl;
    }
    void Iorder(Customer* node){
		if(node!=NULL){
			Iorder(node->getLeft());
			cout<<"\t\t\t\t\t\t----------CUSTOMER DETAILS ARE----------\n";
			cout<<"\t\t\t\t\t\t"<<node->getName()<<endl;
			cout<<"\t\t\t\t\t\t"<<node->getCnic()<<endl;
			cout<<"\t\t\t\t\t\t"<<node->getAccType()<<endl;
			Iorder(node->getRight());
		}
	}
};

class Employee {
private:
    long long cnic;
    string name;
    string password;
    Employee* next;

public:
    Employee() {
        cout << "\t\t\t\t\t\tENTER YOUR CNIC WITHOUT DASHES : ";
        string cnicInput;
        cin >> cnicInput;
        while (!isDigitsOnly(cnicInput) || cnicInput.length() < 13) {
            cout << "\t\t\t\t\t\tINVALID INPUT. PLEASE ENTER 13-DIGITS FOR CNIC : ";
            cin.ignore();
            cin >> cnicInput;
        }
        cnic = stoll(cnicInput);
        cin.ignore();
        cout << "\t\t\t\t\t\tENTER YOUR NAME : ";
        getline(cin, name);
        cout << "\t\t\t\t\t\tENTER A PASSWORD WITHOUT SPACES : ";
        cin >> password;
        while (password.length() < 8) {
            cout << "\t\t\t\t\t\tPASSWORD TOO SHORT. RE-ENTER 8 OR MORE CHARACTERS PASSWORD : ";
            cin.ignore();
            cin >> password;
        }
        next = NULL;
    }

    Employee* getNext() {
        return next;
    }

    void setNext(Employee* n) {
        next = n;
    }

    long long getCnic() {
        return cnic;
    }

    void setCnic(long long id) {
        cnic = id;
    }

    string getName() {
        return name;
    }

    void setName(string input) {
        name = input;
    }

    string getPassword() {
        return password;
    }

    void setPassword(string input) {
        password = input;
    }


};

class EmployeeList {
private:
    Employee* head;

public:
    EmployeeList() {
        head = NULL;
    }

    void insert(Employee* node) {
        if (head == NULL) {
            head = node;
        } else {
            Employee* temp = head;
            while (temp->getNext() != NULL) {
                temp = temp->getNext();
            }
            temp->setNext(node);
        }
    }

    void display() {
        if (head == NULL) {
            cout << "\t\t\t\t\t\tEMPLOYEE LIST IS EMPTY\n";
        } else {
            Employee* temp = head;
            cout << "\t\t\t\t\t\tEMPLOYEE LIST IS \n\n\n";
            while (temp != NULL) {
                cout << "\t\t\t\t\t\tNAME : " << temp->getName() << endl;
                cout << "\t\t\t\t\t\tCNIC : " << temp->getCnic() << endl;
                cout<<"\n\n\n";
                temp = temp->getNext();
            }
            cout << endl;
        }
    }

    Employee* search(long long id) {
        Employee* temp = head;
        while (temp != NULL) {
            if (temp->getCnic() == id) {
                return temp;
            }
            temp = temp->getNext();
        }
        return NULL;
    }
	void deleteEmployee(long long id){
		Employee* curr=search(id);
		Employee* prev=NULL;
		while(curr->getNext()!=NULL && curr->getCnic()!=id){
			prev=curr;
			curr=curr->getNext();
		}
		if(curr->getCnic()!=id){
			cout<<"\t\t\t\t\t\tRECORD NOT FOUND\n";
			return;
		}
		prev->setNext(curr->getNext());
		cout<<"\t\t\t\t\t\tTHE EMPLOYEE RECORD HAS BEEN DELETED\n";
	}
};

bsTree cust;
EmployeeList employeeList;
static void loginPage();
static void employeeMenu();
static void CustomerMenu(Customer* customer);
void employeeLogin(){

	int count=0;
    string id;
    string pass;
    cout << "\n\n\t\t\t\t\t======================\n";
    cout << "\t\t\t\t\t   EMPLOYEE LOGIN\n";
    cout << "\t\t\t\t\t======================\n";
    cout << "\t\t\t\t\tENTER YOUR CNIC : ";
    cin >> id;
        while (!isDigitsOnly(id) || id.length() < 13) {
            cout << "INVALID INPUT. PLEASE ENTER 13-DIGITS FOR CNIC : ";
            cin >> id;
            count++;
            if(count>3){
            	cout<<"TOO MANY WRONG INPUTS . RETURNING TO MAIN MENU\n";
            	loginPage();
			}
        }
        long long cnic = stoll(id);
        cin.ignore();
        count=0;
    cout << "\t\t\t\t\tENTER YOUR PASSWORD : ";
    cin >> pass;
        while (pass.length() < 8) {
            cout << "PASSWORD TOO SHORT . RE-ENTER 8 OR MORE CHARACTERS PASSWORD : ";
            cin >> pass;
            count++;
            if(count>3){
            	cout<<"RETURNING TO MAIN MENU TRY AGAIN AFTER SOMETIME\n";
            	sleep(5);
            	loginPage();
			}
        }
    Employee* employee = employeeList.search(cnic);
    if (employee == NULL || pass != employee->getPassword()) {
        cout << "\t\t\t\t\tLOGIN FAILED. INVALID CREDENTIALS.\n";
        sleep(5);
        loginPage();
        return;
    }
    if(employee!=NULL && pass==employee->getPassword()){
    	employeeMenu();
	}

}
void employeeMenu() {

    string choiceStr;
    int choice;
    int count=0;
    system("CLS");
    cout << "\n\n\t\t\t\t\t======================\n";
    cout << "\t\t\t\t\t      EMPLOYEE MENU\n";
    cout << "\t\t\t\t\t======================\n";
    cout << "\t\t\t\t\tSELECT AN OPTION\n";
    cout << "\t\t\t\t\t1. Create Customer Account\n";
    cout << "\t\t\t\t\t2. Delete Customer Account\n";
    cout << "\t\t\t\t\t3. Modify Customer Account\n";
    cout << "\t\t\t\t\t4. EXIT\n";
    cout << "\t\t\t\t\tENTER YOUR CHOICE : ";
    cin >> choiceStr;
        while (!isDigitsOnly(choiceStr) ) {
            cout << "\t\t\t\t\tINVALID INPUT. PLEASE RE-ENTER CHOICE AGAIN : ";
            cin >> choiceStr;
            count++;
            if(count>3){
            	cout<<"\t\t\t\t\tTOO MANY WRONG INPUTS . RETURNING TO MAIN MENU\n";
            	sleep(5);
            	loginPage();
			}
        }
        choice = stoll(choiceStr);
    switch (choice) {
        case 1: {
            Customer* newCustomer = new Customer();
            cust.insert(newCustomer); 
            cout<<"\t\t\t\t\tCUSTOMER INSERTED SUCCESSFULLY\n";
            sleep(5);
            employeeMenu();
            break;
        }
        case 2: {
            string cnicToDelete;
            count=0;
            cout << "\t\t\t\t\tENTER CNIC OF THE CUSTOMER TO DELETE: ";
            cin >> cnicToDelete;
        while (!isDigitsOnly(cnicToDelete) || cnicToDelete.length() < 13) {
            cout << "\t\t\t\t\tINVALID INPUT. PLEASE ENTER 13-DIGITS FOR CNIC : ";
            cin >> cnicToDelete;
            count++;
            if(count>3){
            	cout<<"\t\t\t\t\tTOO MANY WRONG ATTEMPTS . RETURNING TO MAIN MENU\n";
            	sleep(5);
            	loginPage();
			}
        }
        long long cnic = stoll(cnicToDelete);
        count=0;
            Customer* customerToDelete = cust.search(cnic); 
            if (customerToDelete != NULL) {
            	cout<<"\t\t\t\t\t\tCUSTOMER DELETED SUCCESFULLY\n";
            	delete customerToDelete;
        		sleep(5);
        		employeeMenu();
            } else {
                cout << "\t\t\t\t\tCUSTOMER NOT FOUND.\n";
                sleep(5);
                employeeMenu();
            }
            break;
        }
        case 3: {
            string cnicToModify;

        cout << "\t\t\t\t\tENTER CNIC WITHOUT DASHES FOR MODIFICATION OF ACCOUNT: ";
        cin >> cnicToModify;
        while (!isDigitsOnly(cnicToModify) || cnicToModify.length() < 13) {
            cout << "\t\t\t\t\tINVALID INPUT. PLEASE ENTER 13-DIGITS FOR CNIC : ";
            cin >> cnicToModify;
        }
       	long long cnic = stoll(cnicToModify);
            Customer* customerToModify = cust.search(cnic); 
            if (customerToModify != NULL) {
            	string verify;
            	cout<<"\t\t\t\t\t\tENTER PASSWORD FOR CONFIRMATION : ";
            	cin>>verify;
            	if(customerToModify->getPassword()==verify){
            	string newId;
            	string name;
            	string newPass;
            	cin.ignore();
            	cout<<"\t\t\t\t\t\tENTER NEW NAME: ";
				getline(cin,name);
				cin.ignore();
				cout<<"\t\t\t\t\t\tENTER NEW CNIC : ";
				cin>>newId;
				cout<<"\t\t\t\t\t\tENTER NEW PASSWORD: ";
				cin>>newPass;
				customerToModify->setName(name);
				customerToModify->setCnic(newId);
				customerToModify->setPassword(newPass);
				cout<<"\t\t\t\t\tACCOUNT SUCCESSFULLY MODIFIED\n";
				sleep(5);
				employeeMenu();
            }
            } else {
                cout << "\t\t\t\t\tCUSTOMER NOT FOUND.\n";
                sleep(5);
                employeeMenu();
            }
            break;
        }
        case 4:
        	{
        		loginPage();
        		break;
			}
        default:
            cout << "\t\t\t\t\tINVALID OPTION.\n";
            break;
    }
}

void managerMenu();

void managerLogin() {
		string cnicInput;
		int count=0;
		string password;
        cout << "\t\t\t\t\tENTER YOUR CNIC WITHOUT DASHES : ";
        cin >> cnicInput;
        while (!isDigitsOnly(cnicInput) || cnicInput.length() < 13 || cnicInput.length()>13) {
            cout << "\t\t\t\t\tINVALID INPUT. PLEASE ENTER 13-DIGITS FOR CNIC : ";
            cin.ignore();
            cin >> cnicInput;
            count++;
            if(count>3){
            	cout<<"\t\t\t\t\tTOO MANY WRONG INPUTS . RETURNING TO MAIN MENU\n";
            	sleep(5);
            	loginPage();
			}
        }
        count=0;
       long long cnic = stoll(cnicInput);
        cin.ignore();
        cout << "\t\t\t\t\tENTER A PASSWORD WITHOUT SPACES : ";
        cin >> password;
        while (password.length() < 8) {
            cout << "\t\t\t\t\tPASSWORD TOO SHORT. RE-ENTER 8 OR MORE CHARACTERS PASSWORD : ";
            cin.ignore();
            cin >> password;
            count++;
            if(count>3){
            	cout<<"\t\t\t\t\tTOO MANY WRONG INPUTS . RETURNING TO MAIN MENU\n";
            	sleep(5);
            	loginPage();
			}
        }
    if (cnic == managerCnic && password == managerPassword) {
        managerMenu();
    }
    else{
    	loginPage();
	}
}
void CustomerLogin(){
	
    long long id;
    string pass;
    cout << "\n\n\t\t\t\t\t======================\n";
    cout << "\t\t\t\t\tCUSTOMER LOGIN\n";
    cout << "\t\t\t\t\t======================\n";
    cout << "\t\t\t\t\tENTER YOUR CNIC : ";
    cin >> id;
    cout << "\t\t\t\t\tENTER YOUR PASSWORD : ";
    cin >> pass;
    Customer* customer = cust.search(id);
    if (customer == NULL) {
        cout << "\t\t\t\t\tRECORD NOT FOUND\n";
        sleep(5);
        CustomerLogin();
        return;
    }
    if(customer!=NULL && customer->getPassword()!=pass ){
    	loginPage();
	}
    if (id == customer->getCnic() && pass == customer->getPassword()) {
        CustomerMenu(customer);
}
	else{
		loginPage();
	}
}
void CustomerMenu(Customer* customer) {
        string choiceStr;
        int choice;
        int count=0;
		system("CLS");
        cout << "\n\n\t\t\t\t\t======================\n";
        cout << "\t\t\t\t\t\tCUSTOMER MENU\n";
        cout<<"\t\t\t\t\t======================\n";
        cout << "\t\t\t\t\tSELECT AN OPTION\n";
        cout << "\t\t\t\t\t1. WITHDRAW\n";
        cout << "\t\t\t\t\t2. CASH DEPOSIT\n";
        cout << "\t\t\t\t\t3. BALANCE ENQUIRY\n";
        cout << "\t\t\t\t\t4. EXIT\n";
        cout << "\t\t\t\t\tENTER YOUR CHOICE : ";
        cin >> choiceStr;
        while (!isDigitsOnly(choiceStr) ) {
            cout << "\t\t\t\t\tINVALID INPUT. PLEASE RE-ENTER CHOICE AGAIN : ";
            cin.ignore();
            cin >> choiceStr;
            count++;
            if(count>3){
            	cout<<"\t\t\t\t\tTOO MANY WRONG INPUTS . RETURNING TO MAIN MENU\n";
            	sleep(5);
            	loginPage();
			}
        }
        choice = stoll(choiceStr);
        switch (choice) {
                float amount;
            case 1:
            	{
                cout << "\t\t\t\t\tENTER WITHDRAWAL AMOUNT : ";
                cin >> amount;
                cust.withdraw(amount,customer);
                cout<<"\t\t\t\t\tMONEY WITHDRAW SUCCESSFUL\n";
                sleep(5);
                CustomerMenu(customer);
                break;
            }
            case 2:
            	{
                cout << "\t\t\t\t\tENTER DEPOSIT AMOUNT : ";
                cin >> amount;
                cust.deposit(amount,customer);
                cout<<"\t\t\t\t\tMONEY DEPOSIT SUCCESSFUL\n";
                sleep(5);
                CustomerMenu(customer);
                break;
            }
            case 3:
            	{
                cout << "\t\t\t\t\tBALANCE: " << customer->getBalance() << endl;
				int choice;
				cout<<"\t\t\t\t\tENTER -1 TO RETURN : ";
				cin>>choice;
				if(choice==-1){
					CustomerMenu(customer);
				}
				else{
					CustomerLogin();
				}
                break;
            }
            case 4:
                loginPage();
                break;
            default:
                cout << "\t\t\t\t\tOOPS! YOU ENTERED A WRONG CHOICE\n";
                sleep(5);
                CustomerMenu(customer);
                break;
        }
    }


void managerMenu() {
	int count=0;
    int choice;
    string choiceStr;
    system("CLS");
    cout << "\n\n\t\t\t\t\t======================\n";
    cout << "\t\t\t\t\t\tMANAGER MENU\n";
    cout << "\t\t\t\t\t======================\n";
    cout << "\t\t\t\t\t1. ALL EMPLOYEE LIST\n";
    cout << "\t\t\t\t\t2. ALL ACCOUNT HOLDER LIST\n";
    cout << "\t\t\t\t\t3. ADD EMPLOYEES\n";
    cout << "\t\t\t\t\t4. EXIT\n";
    cout << "\t\t\t\t\tENTER YOUR CHOICE : ";
    cin >> choiceStr;
        while (!isDigitsOnly(choiceStr) ) {
            cout << "\t\t\t\t\tINVALID INPUT. PLEASE RE-ENTER CHOICE AGAIN : ";
            cin.ignore();
            cin >> choiceStr;
            count++;
            if(count>3){
            	cout<<"\t\t\t\t\tTOO MANY WRONG INPUTS . RETURNING TO MAIN MENU\n";
            	sleep(5);
            	loginPage();
			}
        }
//        count=0;
        choice = stoll(choiceStr);
    switch (choice) {
        case 1:
        	int option;
            employeeList.display();
            cout<<"\t\t\t\t\t\tENTER -1 TO EXIT : ";
            cin>>option;
            if(option==-1){
            managerMenu();
			}
            break;
        case 2:// IMPLEMENTATION LEFT
        	int option1;
			cust.Iorder(cust.getRoot());
			cout<<"\t\t\t\t\tENTER -1 TO EXIT: ";
			cin>>option1;
			if(option1==-1){
				managerMenu();
			}
			else{
				loginPage();
			}
        	break;
        case 3:
        	{
        	Employee* newEmployee=new Employee();
        	employeeList.insert(newEmployee);
        	cout<<"\t\t\t\t\tEMPLOYEE ADDED SUCCESSFULLY\n";
        	sleep(5);
        	managerMenu();
            break;
        }
        case 4:
        	  loginPage();
        	break;
        default:
            cout << "\t\t\t\t\tOOPS! WRONG CHOICE\n";
            sleep(5);
            managerMenu();
            break;
    }
}

static void loginPage() {
    string choiceStr;
    int count=0;
    system("CLS");
    cout << "\n\n\t\t\t\t\t======================\n";
    cout << "\t\t\t\t\tBANK MANAGEMENT SYSTEM\n";
    cout << "\t\t\t\t\t======================\n";
    cout << "\t\t\t\t\tSELECT YOUR ROLE\n";
    cout << "\t\t\t\t\t1. MANAGER\n";
    cout << "\t\t\t\t\t2. EMPLOYEE\n";
    cout << "\t\t\t\t\t3. CUSTOMER\n";
    cout << "\t\t\t\t\t4. EXIT\n";
    cout << "\t\t\t\t\tENTER YOUR CHOICE : ";
    cin >> choiceStr;
        while (!isDigitsOnly(choiceStr) ) {
            cout << "\t\t\t\t\tINVALID INPUT. PLEASE RE-ENTER CHOICE AGAIN : ";
            cin.ignore();
            cin >> choiceStr;
            count++;
            if(count>3){
            	cout<<"\t\t\t\t\tTOO MANY WRONG INPUTS . RETURNING TO MAIN MENU\n";
            	sleep(5);
            	loginPage();
			}
        }
//        count=0;
       int choice = stoll(choiceStr);
//       if(choice>4){
//       	cout<<"\t\t\t\t\tWRONG CHOICE RETRY : ";
//       	sleep(5);
//       	loginPage();
//	   }
    
    switch (choice) {
        case 1:
            managerLogin();
            break;
        case 2:
        	system("CLS");
            employeeLogin();
            break;
        case 3:
        	system("CLS");
            CustomerLogin();
            break;
        case 4:
        	system("CLS");
        	cout<<"\n\n\n\t\t\t\t\t\tPOWERED BY MODERN SYNCS\n";
        	break;
        default:
            cout << "\t\t\t\t\tOOPS! YOU ENTERED A WRONG CHOICE!!!\n";
            sleep(5);
			loginPage();
            break;
    }
}

int main() {
    loginPage();
    return 0;
}