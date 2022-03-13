
#include <iostream>
#include "LoginManager.h"
#include <fstream>
#include "Flights.h"


int main()
{
    LoginManager User1;
    Flights flight1;


    ///User admin
    ///User1.saveUsr("admin@gmail.com",1);
    /// User1.savePwd("Adminpwd@", 1);

    std::cout << "Welcome to flights reservation page \n";
    MeniuPrincipal:
    std::cout << "Select your option: \n 1 to log in \n 2 to sing up \n 3 to exit \n";
    int i;
    std::string j;
    std::cin >> i;
    if (i == 1)
    {
        User1.Login();
    }
    else if (i == 2)
    {
        User1.addUser();

        std::cout << "Now please log in!\n";
        User1.Login();
    }

    else if (i == 3)
        return 0;

    if (User1.CheckLog())
    {
        if (User1.Admin())
        {
        MeniuAdmin:
            std::cout << "Now please select another option:\n 1 to log out \n 2 to add a flight \n 3 to delet a flight \n ";
            std::cin >> i;
            if (i == 1)
            {
                User1.Logout();
                goto MeniuPrincipal;
            }
            else if (i == 2)
            {
                AddFlight:
                std::cout << "Adauga zbor \n";
                flight1.SaveFlight();
                std::cout << "Do you want to add another flight?(y/n)";
                std::cin >> j;
                if (j == "y")
                    goto AddFlight;
                else
                    goto MeniuAdmin;
            }
            else if (i == 3)
            {
                std::cout << "Sterge zbor \n";
                std::cout << "Still not here :(((\n";
                goto MeniuAdmin;
            }
            
        }
        else
        {
            MenuUser:
            std::cout << "Now please select another option:\n 1 to log out \n 2 to search flight \n 3 to book flight \n";
            std::cin >> i;
            if(i == 1)
            {
                User1.Logout();
                goto MeniuPrincipal;
            }
            else if (i == 2)
            {
                std::cout << "Cautare zbor \n";
                std::cout << "Still not here :(((\n";
                goto MenuUser;
            }
            else if (i == 2)
            {
                std::cout << "Rezervare zbor \n";
                std::cout << "Still not here :(((\n";
                goto MenuUser;
            }

        }
    }
    else
    {
        goto MeniuPrincipal;
    }



   

    

    
    
    
    return 0;
}


