#ifndef _LoginManager_
#define _LoginManager_


#include <iostream>
#include <fstream>
#include "./RSA.h"




class LoginManager {
private:

	bool LoginSuccessful = false;
	std::string UsrAttept;
	std::string PwdAttept;
	bool IsAdmin = false;

public:


	LoginManager();
	void Login();
	void Logout();
	bool Admin();

	void addUser();
	int checkUsr(std::string attepmt);
	int checkPwd(std::string attempt);
	void saveUsr(std::string line, const int& ID);
	void savePwd(std::string line, const int& ID);

	int encryptPassword(int latter);
	int decryptPassword(int latter);

	int ValidPWD(std::string password);
	bool validUser(std::string username);


	int  getLastID();

	bool CheckLog();

};


#endif
	

