#include <iostream>
using namespace std;

class Person
{
    string name;
    int number;
    int height;

public:
    Person() {}
    Person(string iname, int inumber, int iheight)
    {
        name = iname;
        number = inumber;
        height = iheight;
    }
    void display()
    {
        cout << name << " " << number << " " << height << endl;
    }
    void friend swapper(Person **obj1, Person **obj2);
};
void swapper(Person **obj1, Person **obj2)
{
    Person one;
    Person two;
    Person temp;
    5
    temp.name=**obj1.name;
    // temp.name = **obj1->name;
    // *obj2->name = *obj1->name;
    // obj1->name = obj2.name;
    // temp.number = obj1->number;
    // obj1->number = obj2.number;
    // temp.height = obj1->height;
    // obj1->height = obj2.height;
    // obj2.name = temp.name;
    // obj2.number = temp.number;
    // obj2.height = temp.height;
}

int main()
{
    int t; //for n test cases
    cin >> t;
    while (t--)
    {
        string name1;
        int number1, height1;
        cin >> name1;
        cin >> number1;
        cin >> height1;

        string name2;
        int number2, height2;
        cin >> name2;
        cin >> number2;
        cin >> height2;

        Person *p1 = new Person(name1, number1, height1);
        Person *p2 = new Person(name2, number2, height2);
        p1->display();
        p2->display();
        swapper(&p1, &p2);
        p1->display();
        p2->display();
    }
    return 0;
}