Bank Management System
A C++ based Bank Management System that offers functionalities for employees, customers, and managers. It includes account management features such as account creation, modification, deletion, and various banking operations such as withdrawals, deposits, and balance enquiry. The system implements a secure login system for each role and utilizes object-oriented principles for effective data management.

Table of Contents
Introduction
Features
Technologies Used
How It Works
Functionality Details
Manager Menu
Employee Menu
Customer Menu
Setup & Installation
License
Acknowledgments
Introduction
The Bank Management System is designed to manage customer accounts, perform banking operations, and allow managers and employees to handle system users effectively. This project demonstrates the use of object-oriented programming (OOP) concepts such as inheritance, polymorphism, and encapsulation to maintain and process the bank data efficiently.

Features
Customer Operations:

Create, modify, and delete customer accounts.
Perform withdrawals, deposits, and balance inquiries.
Employee Operations:

Manage customer accounts.
Handle the insertion, deletion, and modification of customer data.
Manager Operations:

View employee and account holder lists.
Add new employees to the system.
Login System:

Role-based login system for Manager, Employee, and Customer.
Secure Data Handling:

Password protection for account modifications and secure login processes.
Technologies Used
C++ (Standard)
Object-Oriented Programming (OOP)
File Handling (for data persistence, not shown in the provided code but suggested for future use)
How It Works
Login Process:
Upon launching the program, users are prompted to choose their role: Manager, Employee, or Customer.
Each role has its own login mechanism:
Manager: Requires a valid CNIC and password.
Employee: Requires a valid CNIC and password.
Customer: Requires a valid CNIC and password.
After successful login, the user is granted access to their respective menu to perform different operations.

Customer Operations:
Withdraw: Customers can perform withdrawals from their account by providing the amount.
Deposit: Customers can deposit money into their account by entering the deposit amount.
Balance Inquiry: Customers can check their account balance.
Employee Operations:
Employees can manage customer accounts, including:
Creating new customer accounts.
Deleting existing customer accounts.
Modifying customer details such as name, CNIC, and password.
Manager Operations:
Managers can:
View the list of employees and account holders.
Add new employees to the system.
Functionality Details
Manager Menu
Option 1: View the list of all employees.
Option 2: View all account holders (customer list).
Option 3: Add a new employee to the system.
Option 4: Exit the manager menu.
The manager can view detailed information about employees and customer accounts and add new employees as needed.

Employee Menu
Option 1: Create a new customer account.
Option 2: Delete an existing customer account.
Option 3: Modify customer account details.
Option 4: Exit the employee menu.
Employees can manage customer accounts by performing CRUD operations (Create, Read, Update, Delete).

Customer Menu
Option 1: Withdraw money from the account.
Option 2: Deposit money into the account.
Option 3: Check account balance.
Option 4: Exit the customer menu.
Customers can perform basic banking operations like withdrawal, deposit, and balance inquiry.
