# CRUD Bank Management System (C++)

A simple bank management system built using C++ and file handling.  
This console-based application allows you to manage bank clients by performing basic CRUD operations (Create, Read, Update, Delete).

---

## 🚀 Features

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
<br>

## 🧠 What I Learned

✅ Working with structs (sClient).

✅ CRUD implementation in C++.

✅ Input validation.

✅ File handling (fstream).

✅ String parsing and splitting.

✅ Clean console UI.

✅ Using vectors to store records.

✅ Data persistence.

<br>

## 🧬 Data Structure
Each client consists of:
- Account Number
- PIN Code
- Full Name
- Phone Number
- Account Balance
<br>

## Data is stored in `Clients.txt` using a custom delimiter `#//#`.

🏷 Data Format (Clients.txt)

- AccountNumber#//#PinCode#//#Name#//#Phone#//#Balance

- A150#//#197008#//#Shehab Abdullah#//#0536242467#//#20000

---
<br>

## 🖥 Interface (Menu Preview)

===========================================<br>
          Main Menu Screen<br>
===========================================<br>

    [1] Show Client List.
    [2] Add New Client.
    [3] Delete Client.
    [4] Update Client Info.
    [5] Find Client.
    [6] Transactions.
    [7] Exit.
=========================================== <br>

## Transactions Menu<br>

=========================================== <br>
        Transactions Menu Screen<br>
===========================================<br>

    [1] Deposit.
    [2] Withdraw.
    [3] Total Balances.
    [4] Main Menu.
    
===========================================

## 📥 Example Deposit Screen
=========================================== <br>
        Deposit Screen<br>
===========================================<br>

Please enter AccountNumber? A150

The following are the client details:
-----------------------------------
Account Number : A150<br>
Pin Code       : 197008<br>
Name           : Shehab Abdullah<br>
Phone          : 0536242467<br>
Account Balance: 20000<br>
-----------------------------------

Please enter deposit amount? 2500

Done Successfully.<br>
New balance is: 22500

-----------------------------------
<br>

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
<br>

## 🧩 How It Works
✔ Loads client records from a text file<br>
✔ Parses text into a struct vector<br>
✔ Updates account balances or info<br>
✔ Saves changes back to the text file<br>
✔ Supports soft deletes using flags<br>
---
<br>

## 🚀 Future Improvements
- Encryption for PIN code
- Sorting and filtering options
- Switch to database storage

---
<br>

## 🧑‍💻 Author
Developed as a practice project for learning:
- File storage systems
- CRUD logic flows
- Struct & Vector concepts
- Text-based database management

---

✅ *Simple, clean, and efficient C++ project for beginners learning file-based CRUD systems.*
