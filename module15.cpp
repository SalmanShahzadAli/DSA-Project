// stack for storing th borrowed books
#include <iostream>
#include <windows.h>
using namespace std;

class Nodeforborrowedbooks
{
public:
    int regnumber;
    string nameofbook;
    int ISBN;
    Nodeforborrowedbooks *next;

    Nodeforborrowedbooks(int regnumber, string nameofbook, int ISBN)
    {
        this->regnumber = regnumber;
        this->nameofbook = nameofbook;
        this->ISBN = ISBN;
        next = nullptr;
    }
};

class StackforBorrowedbooks
{
private:
    Nodeforborrowedbooks *top;
    int height;

public:
    StackforBorrowedbooks()
    {
        top = nullptr;
    }

    ~StackforBorrowedbooks()
    {
        Nodeforborrowedbooks *temp = top;
        while (top)
        {
            top = top->next;
            delete temp;
            temp = top;
        }
    }

    void printStack()
    {
        Nodeforborrowedbooks *temp = top;
        while (temp)
        {
            Sleep(200);
            cout << "Reg-Number: " << temp->regnumber << endl;
            cout << "Name of Book: " << temp->nameofbook << endl;
            cout << "ISBN: " << temp->ISBN << endl;
            temp = temp->next;
        }
    }

    void getHeight()
    {
        cout << "Height: " << height << endl;
    }

    void push(int regnumber, string nameofbook, int ISBN)
    {
        Nodeforborrowedbooks *newNode = new Nodeforborrowedbooks(regnumber, nameofbook, ISBN);
        newNode->next = top;
        top = newNode;
        height++;
    }
};

int main()
{

    StackforBorrowedbooks *myStack = new StackforBorrowedbooks();

    cout << "StackforBorrowedbooks before push(1):\n";
    cout << "---------------------\n";
    myStack->printStack();
    cout << endl;

    // myStack->getTop();
    // myStack->getHeight();

    myStack->push(2023504,"Enid Blyton",5432);

    cout << "\n\nStack after push(1):\n";
    cout << "--------------------\n";
    myStack->printStack();
    cout << endl;

    // myStack->getTop();
    // myStack->getHeight();

    /*
        EXPECTED OUTPUT:

        StackforBorrowedbooks before push(1):
        --------------------
        2

        Top: 2
        Height: 1


        LL after prepend(1):
        --------------------
        1
        2

        Top: 1
        Height: 2

    */
}