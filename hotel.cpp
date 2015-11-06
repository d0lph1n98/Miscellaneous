#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    char username[200],password[200];
    string type,main,purchase;
    int opt;
    float pax_num,o,i,u,price;

    cout << "Welcome to \"Long Islands\" Company Special Travel Promotion System !\n\n";
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    cout << "\n";

    if((!strcmp(username,"Shaba") && !strcmp(password,"Shaba234") || (!strcmp(username,"Lily") && !strcmp(password,"Lily123")) || (!strcmp(username,"Jolene") && !strcmp(password,"Yee123123"))))
    {
main:
        if(!strcmp(username,"Shaba"))
        {
            cout << "Welcome back, Mr. Shaba Bin Zakir\n\n";
        }

        if(!strcmp(username,"Lily"))
        {
            cout << "Welcome back, Ms. Lily Shakira Binti Latip\n\n";
        }

        if(!strcmp(username,"Jolene"))
        {
            cout << "Welcome back, Mrs. Jolene Yee\n\n";
        }
        cout << "Special Langkawi Packages: \n\n";
        cout << "1. Information of Package A\n";
        cout << "2. Information of Package B\n";
        cout << "3. Information of Package C\n";
        cout << "4. Travel Package Booking System\n";
        cout << "5. Quit\n";

        cout << "\n";

        cout << "Enter your choice (1 - 5) : ";
        cin >> opt;

        if((opt > 5) && (opt < 0))
        {
            cout << "Please enter 1 number only.\n";
            cout << "Thank you for being our valued customer..See you again!\n";
        }

        switch(opt)
        {
        case(1):
            cout << "\n\n";
            cout << "Langkawi 3 Days 2 Nights Free and Easy Package (2 pax to go)\n";
            cout << "Travel Fee per person : RM 488 / pax\n";
            cout << "Fee inclusive : Hotel 2 nights, Transportation (Hotel from / to airport)\n";
            cout << "\n\n";
            goto main;
            break;
        case(2):
            cout << "\n\n";
            cout << "Langkawi 3 Days 2 Nights Free and Easy + Snokerling Package (2 pax to go)\n";
            cout << "Travel Fee per person : RM 688 / pax\n";
            cout << "Fee inclusive : Hotel 2 nights, Transportation (Hotel from / to airport), 1 day snokerling package.\n";
            cout << "\n\n";
            goto main;
            break;
        case(3):
            cout << "\n\n";
            cout << "Langkawi 4 Days 3 Nights Free and Easy + Snokerling Package (2 pax to go)\n";
            cout << "Travel Fee per person : RM 888 / pax\n";
            cout << "Fee inclusive : Hotel 2 nights, Transportation (Hotel from / to airport), 2 days snokerling package.\n";
            cout << "\n\n";
            goto main;
            break;
        case(4):
            cout << "\n\n";
            cout << "Enter Package: ";
            cin >> type;
            cout << "Enter number of pax: ";
            cin >> pax_num;

            cout << "Price Estimation Table:\n";
            cout << "========================================================================================================\n";

            if(type == "A")
            {
                // price for package A
                price = 488.00;
                // total including GST
                o = (pax_num * price) + (price * pax_num * 0.06);
                // recalculate if the total is over RM3000
                if(o > 3000)
                {
                    i = o * 0.05;
                    u = o - i;
                    cout << "Package Name\tPax No.\tPrice/Pax\tTotal(GST 6%)\tTotal(After Discount)\n";
                    cout << "3D2N F&E\t" << pax_num << "\tRM 488.00\tRM" << o << "\t" << "\tRM" << u << "\t";
                } else {
                    cout << "Package Name\tPax No.\tPrice/Pax\tTotal(GST 6%)\n";
                    cout << "3D2N F&E\t" << pax_num << "\tRM 488.00\tRM" << o << "\t";
                }
                cout << "\n\n";
                // prompt for confirmation
                cout << "Would you like to purchase it? (1.Yes 2.No)\n";
                cin >> purchase;
                cout << "You have purchased the package A. Thank you.\n";
                cout << "\n";
                // prompt for another packages
                cout << "Would you like to purchase other package too? (1.Yes 2.No)\n";
                cin >> main;

                // exit the program successfully
                if(main == "1")
                {
                    goto main;
                } else exit(0);
            }

            if(type == "B")
            {
                price = 688.00;
                o = (pax_num * price) + (price * pax_num * 0.06);
                if(o > 3000)
                {
                    i = o * 0.05;
                    u = o - i;
                    cout << "Package Name\tPax No.\tPrice/Pax\tTotal(GST 6%)\tTotal(After Discount)\n";
                    cout << "3D2N F&E + S\t" << pax_num << "\tRM 688.00\tRM" <<  o << "\t" << "\tRM" << u << "\t";
                } else {
                    cout << "Package Name\tPax No.\tPrice/Pax\tTotal(GST 6%)\n";
                    cout << "3D2N F&E + S\t" << pax_num << "\tRM 688.00\tRM" << o << "\t";
                }
                cout << "\n\n";
                cout << "Would you like to purchase it? (1.Yes 2.No)\n";
                cin >> purchase;
                cout << "You have purchased the package B. Thank you.\n";
                cout << "\n";
                cout << "Would you like to purchase other package too? (1.Yes 2.No)\n";
                cin >> main;

                if(main == "1")
                {
                    goto main;
                } else exit(0);
            }

            if(type == "C")
            {
                // price for package C
                price = 888.00;
                o = (pax_num * price) + (price * pax_num * 0.06);
                if(o > 3000)
                {
                    i = o * 0.05;
                    u = o - i;
                    cout << "Package Name\tPax No.\tPrice/Pax\tTotal(GST 6%)\tTotal(After Discount)\n";
                    cout << "4D3N F&E + S\t" << pax_num << "\tRM 888.00\tRM" <<  o << "\t" << "\tRM" << u << "\t";
                } else {
                    cout << "Package Name\tPax No.\tPrice/Pax\tTotal(GST 6%)\n";
                    cout << "4D3N F&E + S\t" << pax_num << "\tRM 888.00\tRM" << o << "\t";
                }
                cout << "\n\n";
                cout << "Would you like to purchase it? (1.Yes 2.No)\n";
                cin >> purchase;
                cout << "You have purchased the package C. Thank you.\n";
                cout << "\n";
                cout << "Would you like to purchase other package too? (1.Yes 2.No)\n";
                cin >> main;

                if(main == "1")
                {
                    goto main;
                } else exit(0);
            }
        }
    } else cout << "You are not our VIP member. Thank you.\n";

    return 0;
}
