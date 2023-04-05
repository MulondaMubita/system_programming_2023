/**
 * ID:790980/10/1
 * Name:MULONDA
 * Last Name:MUBITA
 * Course:Sytem Programming
 * Program:Compter Science
 * Term: three
 * Year: second year
 */
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Train
{
public:
    Train();
    void SetName(string nm) { name = nm; }
    void SetSource(string src) { source = src; }
    void SetDestination(string dst) { destination = dst; }
    void SetData(int yr, int m, int d);
    void SetCapacity(unsigned int c) { capacity = c; }
    void Display();

private:
    string name;
    string source;
    string destination;
    tm date;
    unsigned int capacity;
};

Train::Train()
{
    name = "N/A";
    source = "Unknown";
    destination = "Unknown";
    capacity = 0;
    date.tm_year = 0;
    date.tm_mon = 0;
    date.tm_mday = 1;
}

void Train::SetData(int yr, int m, int d)
{
    if (yr > 100)
    {
        date.tm_year = yr - 1900;
    }
    else
    {
        date.tm_year = 100 + yr;
    }
    if (m >= 1 && m <= 12)
    {
        date.tm_mon = m - 1;
    }
    else
    {
        date.tm_mon = 0;
    }
    if (d >= 1 && d <= 31)
    {
        date.tm_mday = d;
    }
    else
    {
        date.tm_mday = 1;
    }
}

void Train::Display()
{
    char buf[80];
    cout << "Train:        " << name << endl;
    cout << "From:         " << source << endl;
    cout << "To:           " << destination << endl;
    strftime(buf, 80, "%D", &date);
    cout << "Journay Date: " << buf << endl;
    cout << "Capacity:     " << capacity << endl
         << endl;
}

int main()
{
    Train train;
    train.SetName("Muby Trains Express");
    train.SetSource("Speedy way");
    train.SetDestination("Lusaka");
    train.SetData(2023, 17, 12);
    train.SetCapacity(400);

    train.Display();
}