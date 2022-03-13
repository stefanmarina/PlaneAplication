
#include "LoginManager.h"
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

LoginManager::LoginManager()
{
	LoginSuccessful = false;
	

}
bool LoginManager::CheckLog()
{
	return LoginSuccessful;
}

void LoginManager::Logout()
{
	this->LoginSuccessful = false;
	this->IsAdmin = false;
}

bool LoginManager::Admin()
{
	return IsAdmin;
}

void LoginManager::Login() {
	
	login:
	cout  << "User Name: ";
	cin >> UsrAttept;

	


	if (checkUsr(UsrAttept) != 0)
	{
		cout << endl << "Password: ";
		cin >> PwdAttept;

		

		if (checkPwd(PwdAttept))
		{
			if (UsrAttept == "admin@gmail.com")
				this->IsAdmin = true;
			LoginSuccessful = true;
		}
		else
		{
			cout << "Wrong Password!" << endl;
		
		}

	}

	else
	{
		cout << "Wrong User Name!;" << endl;
	}

	if (LoginSuccessful == true)
		cout << "Login Successful!" << endl;
	else
	{
		cout << "Login Unsuccessful!" << endl;
		cout << "Do you want to try again?(y/n)" << endl;
		string YesNo;
		cin >> YesNo;
		if (YesNo == "y")
			goto login;
		else
			return;
	}
	
}

void LoginManager::addUser()
{
	TypeUsername:
	cout << "Please select a username:" << endl;
	string user;
	cin >> user;
	
	if (checkUsr(user) != 0)
	{
		cout << "Username not avaible" << endl;
		goto TypeUsername;
	}
	else if (validUser(user) == false)
	{
		cout << "Wrong username format (___@_.__)" << endl;
		goto TypeUsername;
	}
	
	string password, password1;
	TypePassword:
	cout << "Please select a password:" << endl;
	cin >> password;
	
	
		int p = ValidPWD(password);
		if (p == 0)
		{
			cout << "Valid password!\n";
			int ID = 1 + getLastID();
			saveUsr(user, ID);
			savePwd(password, ID);
			

		}
		else if (p == 1)
		{
			cout << "Parola prea scurta" << endl;
			goto TypePassword;
		}
		else if (p == 2)
		{
			cout << " Parola prea lunga" << endl;
			goto TypePassword;
		}
		else if (p == 3)
		{
			cout << "Parola nu contine litere mari" << endl;
			goto TypePassword;
		}
		else if (p == 4)
		{
			cout << "Parola nu contine caractere speciale" << endl;
			goto TypePassword;
		}

		cout << "Please repeat the password:" << endl;
		cin >> password1;
		if (password != password1)
		{
			cout << "Passwords don't match!" << endl;
			goto TypePassword;
		}
		
	


}

int LoginManager::getLastID()
{
	fstream file;
	file.open("user.txt", ios::in);
	file.seekg(0, ios::end);

	if (file.tellg() == -1)
		return 0;
	string searchID;

	for (int i = -1; searchID.find("#") == string::npos; i--)
	{
		file.seekg(i, ios::end);
		file >> searchID;
	}
	file.close();
	searchID.erase(0, 4);

	int ID;
	istringstream(searchID) >> ID;

	return ID;
}

int LoginManager::checkUsr(string attempt)
{
	string line;
	fstream file;

	
	string currentChar;

	file.open("user.txt", ios::in);
	while (1)
	{
		file >> currentChar;
		if (currentChar.find("#ID:") != string::npos)
		{
			if (attempt == line)
			{
				file.close();
				currentChar.erase(0, 4);
				int ID;
				istringstream(currentChar) >> ID;
				return ID;
			}
			else
			{
				line.erase(line.begin(), line.end());
			}

		}
		else
		{
			
			line += currentChar;
			currentChar = "";
		}

		if (file.peek() == EOF)
		{
			file.close();
			return 0;
		}
	}
}

int LoginManager::checkPwd(string attempt)
{
	string line;
	fstream file;

	string currentChar;
	int encryptedChar;


	
	file.open("password.txt", ios::in);
	while(1)
	{
		file >> currentChar;
		if (currentChar.find("#ID:") != string::npos)
		{
			if (attempt == line)
			{
				file.close();
				currentChar.erase(0, 4);
				int ID;
				istringstream(currentChar) >> ID;
				return ID;
			}
			else
			{
				line.erase(line.begin(), line.end());
			}
			
		}
		else
		{
			istringstream(currentChar) >> encryptedChar;
			line += (char)decryptPassword((int)encryptedChar);
			currentChar = "";
		}

		if (file.peek() == EOF)
		{
			file.close();
			return false;
		}
	}
	
}



void LoginManager::saveUsr(string line, const int& ID)
{
	fstream file;
	file.open("user.txt", ios::app);

	file.seekg(0, ios::end);

	if(file.tellg() != 0)
		file << endl;
	file.seekg(0, ios::beg);

	for (int i = 0; i < line.length(); i++)
	{
		file << line[i];
		file << endl;
	}
	file << "#ID:" << ID;
	file.close();

	file.close();
}

void LoginManager::savePwd(string line, const int& ID)
{
	fstream file;
	file.open("password.txt", ios::app);

	file.seekg(0, ios::end);

	if (file.tellg() != 0)
		file << endl;
	file.seekg(0, ios::beg);

	for (int i = 0; i < line.length(); i++)
	{
		file << encryptPassword((int)line[i]);
		file << endl;
	}
	file << "#ID:"<< ID;
	file.close();
}


int LoginManager::encryptPassword(int latter)
{
	return ((latter + 3) * 76 ) / 4;
}

int LoginManager::decryptPassword(int latter)
{
	return (latter * 4) / 76 - 3;
}



int LoginManager::ValidPWD(string password)
{

	//Functia va returna o valaore int pentru diferite erori care vor fi interpretate in main si afisate pe ecran
	
	bool GoodPassword = false;
	if (password.length() < 8)
		return 1;//parola prea scurta
	else if (password.length() > 20)
		return 2;// parola prea lunga
	
	for (int i = 0; i < password.length(); i++)
	{
		if (isupper(password[i]))
		{
			GoodPassword = true;
			break;
		}
		
	}
	if (GoodPassword == false)
		return 3;// parola nu contine litere mari
	GoodPassword = false;
	for (int i = 0; i < password.length(); i++)
	{
		if ((password[i] > 32 && password[i] < 48) || 
			(password[i] > 57 && password[i] < 65) || 
			(password[i] > 90 && password[i] < 97) ||
			(password[i] > 122 && password[i] < 127))
		{
			GoodPassword = true;
			break;
		}

	}
	if (GoodPassword == false)
		return 4;// parola nu contine caractere speciale
	return 0;
	

}

bool LoginManager::validUser(string username)
{
	// Verificam ca username ul sa fie in formatul dorit
	int i, Parond = 0;
	int arond = 0;
	int dot = 0;
	int n = username.length();
	
	
	
	for (i = 0; i < n; i++)
		if (username[i] == ' ')
			return false;


	for (i = 0; i < n; i++)
		if (username[i] == '@')
		{
			arond++;
			if (arond = 1)
				Parond = i;
		}
	for (i = Parond + 1; i < n; i++)
		if (username[i] == '.')
			dot = 1;

	if (dot == 1 && arond == 1)
		return true;
	else
		return false;
}





