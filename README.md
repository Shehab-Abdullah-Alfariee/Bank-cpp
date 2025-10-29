# CRUD Bank Management System (C++)

A simple bank management system built using C++ and file handling.  
This console-based application allows you to manage bank clients by performing basic CRUD operations (Create, Read, Update, Delete).

---

## 🧾 Features
- Display all clients with formatted table view
- Add new client with validation (no duplicated account numbers)
- Delete existing client safely
- Update client information interactively
- Search for a client by account number
- Persistent data storage using `Clients.txt`
- Clean console UI with reusable helper functions

---

## 🧬 Data Structure
Each client consists of:
- Account Number
- PIN Code
- Full Name
- Phone Number
- Account Balance

Data is stored in `Clients.txt` using a custom delimiter `#//#`.

---

### Example client record:

---

## 🛠️ Technologies Used
- C++ (Standard Library)
- File Handling (`fstream`)
- Vectors
- Console UI

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

---

## 📂 Project Structure

---

## 🚀 Future Improvements
- Add deposit/withdraw operations
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
