#include<string>
#include <iostream>
#include<fstream>
#include<iomanip>
#include <cctype>
#include <vector>
using namespace std;

enum enOpretion { ShowClient = 1, AddClient = 2, DeleteClient = 3, UpdateClient = 4, FindClient = 5, Exit = 6};

const string ClientFileName = "Clients.txt";

struct stClient {
	string AccountNumber;
	string PinCode;
	string Name;
	string PhoneNumber;
	double AccountPalance;
	bool MarkForDelet = false;
};

void PrintHeader(string HeaderName) {
	cout << "=================================================";
	cout << "\n\t\t"<< HeaderName <<"\t\t";
	cout << "\n=================================================\n";
}

void PrintMainMenuScreen() {
	system("cls");
	PrintHeader("Main Menu Screen");
    cout << "\n\t[1] Show Client List.";
    cout << "\n\t[2] Add New Client.";
    cout << "\n\t[3] Delete Client.";
    cout << "\n\t[4] Update Client Info.";
    cout << "\n\t[5] Find Client.";
    cout << "\n\t[6] Exit.";
    cout << "\n==================================================\n";


}

enOpretion ReadNumberOfOpretion() {
    short Choos;
	do {
		cout << "Choos what you want to do? [1 to 6] : ";
		cin >> Choos;
	} while (Choos > 6 || Choos <= 0);
    return (enOpretion)Choos;
}

void PrintClientRecord(stClient Client) {

	cout << "| " << left << setw(15) << Client.AccountNumber;
	cout << "| " << left << setw(10) << Client.PinCode;
	cout << "| " << left << setw(20) << Client.Name;
	cout << "| " << left << setw(12) << Client.PhoneNumber;
	cout << "| " << left << setw(12) << Client.AccountPalance;


}

void PrintAllClientsData(vector<stClient> vClients) {
	
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n--------------------------------------------------------";
	cout << "-----------------------------------------\n";
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(20) << "Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n---------------------------------------------------------";
	cout << "-----------------------------------------\n";

	for (stClient Client : vClients) {

		PrintClientRecord(Client);
		cout << endl;

	}
	cout << "\n---------------------------------------------------------";
	cout << "-----------------------------------------\n";
}

vector<string> SplitString(string S1, string delim) {
	short pos = 0;
	string Word;
	vector<string> vString;
	while ((pos = S1.find(delim)) != std::string::npos) {

		Word = S1.substr(0, pos);

		if (Word != "") {
			vString.push_back(Word);
		}
		S1.erase(0, pos + delim.length());
	}
	if (S1 != "") {
		vString.push_back(S1);
	}
	return vString;
}

stClient ConvertLineToRecord(string Line, string delim = "#//#" ) {

	stClient Clint;
	vector<string> vClintData;

	vClintData = SplitString(Line,delim);
	
	Clint.AccountNumber = vClintData[0];
	Clint.PinCode = vClintData[1];
	Clint.Name = vClintData[2];
	Clint.PhoneNumber = vClintData[3];
	Clint.AccountPalance = stod(vClintData[4]);

	
	return Clint;

}

vector<stClient> LoadDataFromFileToVector(string FileName) {

	vector<stClient> vClients;
	fstream MyFile;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) {
		string Line;
		stClient Clients;

		while (getline(MyFile , Line)) {

			Clients = ConvertLineToRecord(Line);
			vClients.push_back(Clients);
		}
		MyFile.close();
	}
	return vClients;
}

bool FindClientByAccountNumber(string AccountNumber, stClient& Client) {

	vector<stClient> vClients = LoadDataFromFileToVector(ClientFileName);
	for (stClient C : vClients) {

		if (C.AccountNumber == AccountNumber) {
			Client = C;
			return true;
		}

	}
	return false;
}

stClient ReadNewClient() {

	stClient data;

	cout << "Enter Account Number? ";
	getline(cin >> ws, data.AccountNumber);
	while (FindClientByAccountNumber(data.AccountNumber, data)) {
		cout << "Account Allready Exist . ";
		cout << "Please Enter Other Account Number? ";
		getline(cin >> ws, data.AccountNumber);
	}
	cout << "Enter PinCode? ";
	getline(cin, data.PinCode);

	cout << "Enter Name ? ";
	getline(cin, data.Name);

	cout << "Enter Phone Number? ";
	getline(cin, data.PhoneNumber);

	cout << "Enter Account Palnace ? ";
	cin >> data.AccountPalance;

	
	return data;
}

void AddDataLineToFile(string FileName, string stDataLine) {

	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open()) {
		MyFile << stDataLine << endl;
		MyFile.close();
	}
}

string ConvertToString(stClient ClintData, string Seperator = "#//#") {

	string stClintRecord = "";

	stClintRecord += ClintData.AccountNumber + Seperator;
	stClintRecord += ClintData.PinCode + Seperator;
	stClintRecord += ClintData.Name + Seperator;
	stClintRecord += ClintData.PhoneNumber + Seperator;
	stClintRecord += to_string(ClintData.AccountPalance);

	return  stClintRecord;
}

void AddNewClients() {
	stClient Client;
	Client = ReadNewClient();
	AddDataLineToFile(ClientFileName, ConvertToString(Client));

}

void AddClients() {
		system("cls");
		PrintHeader("Adding New Client");

		AddNewClients();
		cout << "\nClient Added Successfully.";
	
}

void PrintClintData(stClient Clint) {

	cout << "\nThe Following are the Client details:";
	cout << "\n\nAccount Number : " << Clint.AccountNumber;
	cout << "\nAccount PinCode : " << Clint.PinCode;
	cout << "\nAccount Name : " << Clint.Name;
	cout << "\nPhone Number : " << Clint.PhoneNumber;
	cout << "\nAccount Palance : " << Clint.AccountPalance << endl;
}

bool MarkClientForDeletByAccountNumber(string ClientAccountNumber, vector<stClient>& vClients) {

	for (stClient& C : vClients) {

		if (C.AccountNumber == ClientAccountNumber) {
			C.MarkForDelet = true;
			return true;
		}
	}
	return false;
}

vector<stClient> SaveClientDataToFile(string FileName, vector<stClient>& vClients) {

	fstream MyFile;
	string DataLine;
	MyFile.open(FileName, ios::out);

	if (MyFile.is_open()) {
		string Line;
		for (stClient C : vClients) {
			if (C.MarkForDelet == false) {
				DataLine = ConvertToString(C);
				MyFile << DataLine << endl;

			}
		}
	}
	return vClients;

}

bool DeleteClientByAccountNumber(string ClientAccountNumber, vector<stClient>& vClients) {
	char Answer = 'n';

	stClient Client;
	system("cls");
	PrintHeader("Delete Client");
	if (FindClientByAccountNumber(ClientAccountNumber, Client))
	{
		PrintClintData(Client);
		cout << "\n\nAre you sure you want to delet this client? y/n ?";
		cin >> Answer;
		if (toupper(Answer) == 'Y') {

			MarkClientForDeletByAccountNumber(ClientAccountNumber, vClients);
			SaveClientDataToFile(ClientFileName, vClients);

			vClients = LoadDataFromFileToVector(ClientFileName);

			cout << "\n\nClient Deleted Successfully.";
			return true;
		}

	}
	else {
		cout << "\nClient with Account Number (" << ClientAccountNumber << ") Not Found!";
	}
}

string ReadAccountNumber() {
	string ClientNumber;
	cout << "Enter Account Number ? ";
	cin >> ClientNumber;

	return ClientNumber;
}

bool FindClientByAccountNumber( string AccountNumber) {

	stClient Client;
	if (FindClientByAccountNumber(AccountNumber, Client)) {
		system("cls");
		PrintHeader("Find Client");
		PrintClintData(Client);
	}
	else {
		cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!";
	}

	vector<stClient> vClients = LoadDataFromFileToVector(ClientFileName);
	for (stClient C : vClients) {

		if (C.AccountNumber == AccountNumber) {
			Client = C;
			return true;
		}
		
	}
	return false;
}

stClient ChangeClientRecord(string AccountNumber) {
	stClient Client;  

	Client.AccountNumber = AccountNumber;     
	cout << "\n\nEnter PinCode? ";     
	getline(cin >> ws, Client.PinCode);     
	cout << "Enter Name? ";     
	getline(cin, Client.Name);     
	cout << "Enter Phone? ";     
	getline(cin, Client.PhoneNumber);     
	cout << "Enter AccountBalance? ";     
	cin >> Client.AccountPalance; 

	return Client; 

}

bool FindClientByAccountNumberToUpdate(string AccountNumber , vector<stClient> vClients , stClient& Client) {

	
	if (FindClientByAccountNumber(AccountNumber, Client)) {
		system("cls");
		PrintHeader("Find Client");
		PrintClintData(Client);
	}
	else {
		cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!";
	}

	vClients = LoadDataFromFileToVector(ClientFileName);
	for (stClient C : vClients) {

		if (C.AccountNumber == AccountNumber) {
			Client = C;
			return true;
		}

	}
	return false;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector<stClient>& vClients)
{
	stClient Client; 
	char Answer = 'n';
	if (FindClientByAccountNumberToUpdate(AccountNumber, vClients, Client))
	{
		
		cout << "\n\nAre you sure you want update this client? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			for (stClient& C : vClients)
			{
				if (C.AccountNumber == AccountNumber) {
					C = ChangeClientRecord(AccountNumber);
					break;
				}
			}
			SaveClientDataToFile(ClientFileName, vClients);
			cout << "\n\nClient Updated Successfully.";
			return true;
		}
		else
		{
			cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
			return false;
		}
	}
}

int ChoosClientOpreation(short Choos) {
    vector<stClient> vClients = LoadDataFromFileToVector(ClientFileName);
	
    if (Choos == enOpretion::ShowClient)
	{
        system("cls");
        PrintAllClientsData(vClients);
    }
	else if (Choos == enOpretion::AddClient)
	{
		AddClients();
	}
	else if (Choos == enOpretion::DeleteClient)
	{
		string ClientAccountNumber = ReadAccountNumber();
		DeleteClientByAccountNumber(ClientAccountNumber, vClients);
	}
	else if (Choos == enOpretion::UpdateClient)
	{
		string ClientAccountNumber = ReadAccountNumber();
		UpdateClientByAccountNumber(ClientAccountNumber, vClients);
		
	}
	else if (Choos == enOpretion::FindClient)
	{
		string ClientAccountNumber = ReadAccountNumber();
		FindClientByAccountNumber(ClientAccountNumber);
	}
	else {
		return 0;
	}
	cout << "\n\nPress any key to bake to main screen...";
	system("pause>0");
}

void StartBank() {
	short Choos;
		
	do {
		PrintMainMenuScreen();
		Choos = ReadNumberOfOpretion();
		ChoosClientOpreation(Choos);
	} while (Choos != 6);
}

int main()
{

    StartBank();

}



 