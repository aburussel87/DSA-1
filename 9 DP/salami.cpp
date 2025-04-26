#include <iostream>
using namespace std;

int main()
{
    int students;
    int roll;
    cin >> students;
    while (students < 0)
    {
        cout << "Enter valid student numbers (greater than 0 : ";
        cin >> students;
    }
    cin >> roll;
    while (roll > students)
    {
        cout << "Enter valid roll(less than " << students << " ): ";
        cin >> roll;
    }
    int Need_to_pay = roll * (students - 1);
    int will_obtain = (students * (students + 1) / 2) - roll;
    cout << "you will need to pay: " << Need_to_pay << " and you will obtain: " << will_obtain << endl;

    cout <<"Students before roll "<< ((students + 1) / 2) - (1 / students)<< "(inclusive) will be on profit";
    return 0;
}