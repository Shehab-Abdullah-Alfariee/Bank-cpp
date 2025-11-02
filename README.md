# CRUD Bank Management System (C++)

A simple bank management system built using C++ and file handling.  
This console-based application allows you to manage bank clients by performing basic CRUD operations (Create, Read, Update, Delete).

---

🚀 Features

✅ Display client list
✅ Add new client
✅ Update client information
✅ Delete client
✅ Search for a client by account number
✅ Deposit money
✅ Withdraw money (with balance validation)
✅ View total bank balances
✅ Persistent storage using a text file (Clients.txt)

---
🧠 What I Learned

Working with structs (sClient).
CRUD implementation in C++.
Input validation.
File handling (fstream).
String parsing and splitting.
Clean console UI.
Using vectors to store records.
Data persistence.

## 🧬 Data Structure
Each client consists of:
- Account Number
- PIN Code
- Full Name
- Phone Number
- Account Balance


Data is stored in `Clients.txt` using a custom delimiter `#//#`.

🏷 Data Format (Clients.txt)
AccountNumber#//#PinCode#//#Name#//#Phone#//#Balance
1234#//#7788#//#John Doe#//#999999#//#1500

---

🖥 Interface (Menu Preview)

===========================================
            Main Menu Screen
===========================================
    [1] Show Client List.
    [2] Add New Client.
    [3] Delete Client.
    [4] Update Client Info.
    [5] Find Client.
    [6] Transactions.
    [7] Exit.
===========================================

Transactions Menu

===========================================
        Transactions Menu Screen
===========================================
    [1] Deposit.
    [2] Withdraw.
    [3] Total Balances.
    [4] Main Menu.
===========================================


📥 Example Deposit Screen

-----------------------------------
        Deposit Screen
-----------------------------------
Please enter AccountNumber? 1234

The following are the client details:
-----------------------------------
Account Number : 1234
Pin Code       : 7788
Name           : John Doe
Phone          : 999999
Account Balance: 1500
-----------------------------------

Please enter deposit amount? 2000

Done Successfully. New balance is: 3500

-----------------------------------

## 🛠️ Technologies Used
- C++ (Standard Library)
- File Handling STL (vector, string, fstream, iomanip)
- Vectors
- Console UI
- File-based database

---

## 📌 How to Use
1. Run the program
2. Choose from the main menu:
   - Show clients
   - Add new client
   - Update client
   - Delete client
   - Search for client
   - Exit

All changes are automatically saved to the file.

🧩 How It Works

✔ Loads client records from a text file
✔ Parses text into a struct vector
✔ Updates account balances or info
✔ Saves changes back to the text file
✔ Supports soft deletes using flags
---

## 🚀 Future Improvements
- Encryption for PIN code
- Sorting and filtering options
- Switch to database storage

---

## 🧑‍💻 Author
Developed as a practice project for learning:
- File storage systems
- CRUD logic flows
- Struct & Vector concepts
- Text-based database management

---

✅ *Simple, clean, and efficient C++ project for beginners learning file-based CRUD systems.*
