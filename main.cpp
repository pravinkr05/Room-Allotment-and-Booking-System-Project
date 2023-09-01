#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

static int p = 0;

// create Hotel template containing different function booking, availability of room and etc.
class Hotel
{
    char roomn[6] = {"Empty"}, host[10] = {"Empty"}, start[6] = {"Empty"}, send[6] = {"Empty"}, from[10] = {"Empty"}, to[10] = {"Empty"};
    char chair[8][4][10]; // chair number with their customer name given by host(booking karne wala)

public:
    void Registration();
    void allotment();
    void empty();
    void show();
    void available();
    void position(int i);

} room[32]; // room[32] is array of objects.

// draws a horizontal line
void vline(char ch)
{
    for (int i = 80; i > 0; i--)
        cout << ch;
}

// Asked user details while registration
void Hotel::Registration()
{
    cout << "Enter Room no: ";
    cin >> room[p].roomn;
    int n;

    // checking room number
    for (n = 0; n < p; n++)
    {
        if (strcmp(room[n].roomn, room[p].roomn) == 0)
            break;
    }
    // if room number is correct then host details will be show
    if (n < p)
    {
        if (room[n].host != "Empty")
            cout << "\nHost name : " << room[n].host << endl;
    }
    else
    {
        cout << "\nEnter Host's name: ";
        cin >> room[p].host;
    }

    cout << "\nStart time: ";
    cin >> room[p].start;
    cout << "\nSession Ends at: ";
    cin >> room[p].send;
    cout << "\nFrom: \t\t";
    cin >> room[p].from;
    cout << "\nTo: \t\t";
    cin >> room[p].to;
    room[p].empty();
    p++; // it keeps track the empty rooms
    cout << endl
         << endl;
}

// Allocating the chair in the registered room
void Hotel::allotment()
{
    int chairNum;
    char number[5];
top:
    cout << "Room no: ";
    cin >> number;
    int n;

    // check is room number is given same, allocated while registration
    for (n = 0; n <= p; n++)
    {
        if (strcmp(room[n].roomn, number) == 0)
            break;
    }

    // after matching room number, allocating chair
    while (n <= p)
    {
        cout << "\nChair Number: ";
        cin >> chairNum;
        if (chairNum > 32)
        {
            cout << "\nThere are only 32 Chair available in this Room. [chair number <= 32]";
        }
        else
        {
            // if given chair number is empty or not reserved
            if (strcmp(room[n].chair[chairNum / 4][(chairNum % 4) - 1], "Empty") == 0)
            {
                cout << "Enter traveller's name: ";
                cin >> room[n].chair[chairNum / 4][(chairNum % 4) - 1];
                break;
            }
            else
                cout << "The Chair no. is already reserved.\n";
        }
    }

    // if given room number is not registered
    if (n > p)
    {
        cout << "Enter correct Room no.\n";
        goto top;
    }

    cout << endl
         << endl;
}

// empty all the left old reserved chair in a room while registering
void Hotel::empty()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            strcpy(room[p].chair[i][j], "Empty");
        }
    }
}

// display the specific user details with their reserved room  by room number
void Hotel::show()
{
    int n;
    char number[5];
    cout << "\nEnter Room no: ";
    cin >> number;
    cout << "\n";

    // check your room number is correct or not
    for (n = 0; n <= p; n++)
    {
        if (strcmp(room[n].roomn, number) == 0)
            break;
    }
    // if room number is correct then host details will be show
    while (n <= p)
    {
        vline('*');
        cout << "\nRoom no: " << room[n].roomn
             << "\nHost : " << room[n].host << "\t\tStart time: "
             << room[n].start << "\t\tEnd time: " << room[n].send
             << "\nFrom : " << room[n].from << "\t\tTo : " << room[n].to << "\n\n";

        vline('*');

        room[0].position(n);

        // show the reserved chair number
        int a = 1;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                a++;
                if (strcmp(room[n].chair[i][j], "Empty") != 0)
                    cout << "\nThe Chair no " << (a - 1) << " is reserved for " << room[n].chair[i][j] << ".";
            }
        }
        break;
    }
    // if room number is not correct
    if (n > p)
        cout << "Enter correct Room no: ";

    cout << endl
         << endl;
}

// show the room and chair status which is empty or full
void Hotel::available()
{
    cout << endl
         << endl;
    for (int n = 0; n <= p; n++)
    {
        cout << n + 1 << ".\n";
        vline('_');

        cout << "\n\nRoom no: " << room[n].roomn << "\nHost : " << room[n].host
             << "\t\tStart time: " << room[n].start << "\t\tEnd time: "
             << room[n].send << "\nFrom : " << room[n].from << "\t\tTo : "
             << room[n].to << "\n";

        vline('_');
        cout << "\n\n\n\n";
    }
}

// show reserved chair position and availabilty of chair
void Hotel::position(int l)
{
    int s = 0;
    p = 0;
    for (int i = 0; i < 8; i++)
    {
        cout << "\n";
        for (int j = 0; j < 4; j++)
        {
            s++;
            if (strcmp(room[l].chair[i][j], "Empty") == 0)
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << room[l].chair[i][j];
                p++;
            }
            else
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << room[l].chair[i][j];
            }
        }
    }
    cout << "\n\nThere are " << p << " Chairs empty in Room No: " << room[l].roomn;
}

// main code start from here

int main()
{
    system("cls"); // used for clear terminal screen
    int w;
    cout << "\n___________________GRAND WELCOME IN OUR VIRTUAL HOTEL___________________\n\n ";

    // run all function of class hotel
    while (1)
    {
        // cout << "\n\n\n\n\n";

        // show the optiuons
        cout << "\t\t\t"
             << "1.Registration"
             << "\n\t\t\t"
             << "2.Reservation"
             << "\n\t\t\t"
             << "3.Show"
             << "\n\t\t\t"
             << "4.Rooms Available"
             << "\n\t\t\t"
             << "5.Exit";

        // select option which function wants to execute
        cout << "\n\t\t\t"
             << "Enter your choice:-> ";
        cin >> w;
        switch (w)
        {
        case 1:
            room[p].Registration();
            break;
        case 2:
            room[p].allotment();
            break;
        case 3:
            room[0].show();
            break;
        case 4:
            room[0].available();
            break;
        case 5:
            cout << " \n\n "
                 << "we hope,\n all enjoyed our service and wish you all the best for your next journey. \nThank you"
                 << " \n\n\n\n ";
            exit(0);
        }
    }
    return 0;
}
