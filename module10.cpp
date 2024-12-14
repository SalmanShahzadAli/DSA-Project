// in this module we will implement that ofr example the user wants to order a book or the case that the user has any request for a book that is not present in the library and that we can arrange.
// we will have a singly linked list to store all request made.
#include <iostream>
#include <windows.h>
using namespace std;

class Nodefororderbook
{
public:
    int urgency_level;
    string book_name;
    string author_name;
    string category;
    Nodefororderbook *next;

    Nodefororderbook(int urgency_level, string book_name, string author_name, string category)
    {
        this->urgency_level = urgency_level;
        this->author_name = author_name;
        this->book_name = book_name;
        this->category = category;
        next = nullptr;
    }
};

class LinkedListBookRequests
{
private:
    Nodefororderbook *head;
    Nodefororderbook *tail;
    int length;

public:
    LinkedListBookRequests() : head(nullptr), tail(nullptr), length(0) {}

    ~LinkedListBookRequests()
    {
        Nodefororderbook *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList()
    {
        Nodefororderbook *temp = head;
        while (temp != nullptr)
        {
            Sleep(500);
            cout << endl;
            cout << "\t\t\t\t\tAuthor Name: " << temp->author_name << endl;
            cout << "\t\t\t\t\tBook Name: " << temp->book_name << endl;
            cout << "\t\t\t\t\tCategory: " << temp->category << endl;
            cout << "\t\t\t\t\tUrgency Level: " << temp->urgency_level << endl;
            temp = temp->next;
        }
    }

    void getLength()
    {
        cout << "Length: " << length << endl;
    }

    void append(int urgency_level, string book_name, string author_name, string category)
    {
        Nodefororderbook *newNode = new Nodefororderbook(urgency_level, book_name, author_name, category);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void deleteLast()
    {
        if (length == 0)
            return;
        Nodefororderbook *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Nodefororderbook *pre = head;
            while (temp->next)
            {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    Nodefororderbook *get(int index)
    {
        if (index < 0 || index >= length)
            return nullptr;
        Nodefororderbook *temp = head;
        for (int i = 0; i < index; ++i)
        {
            temp = temp->next;
        }
        return temp;
    }
};
void orderBookOnDemand(LinkedListBookRequests &request)
{
    string name;
    string author_name;
    string category;
    int urgency_level;
    cout << endl;
    cout << "\t\t\t\t\tRequesting Book Form is as follows" << endl;
    Sleep(1000);
    cout << "\t\t\t\t\tPLease Enter the category of the book: " << endl;
    cout << "\t\t\t\t\t\tFor Example" << endl;
    cout << "\t\t\t\t\t\tEducational " << endl;
    cout << "\t\t\t\t\t\tFiction" << endl;
    cout << "\t\t\t\t\t\tNon-Fiction" << endl;
    cout << "\t\t\t\t\t\tPoetry And Drama" << endl;
    cout << "\t\t\t\t\t\tYoung Adult" << endl;
    cout << "\t\t\t\t\t\tCategory: ";
    cin >> category;
    cout << "\t\t\t\t\tPlease Enter The name of the book: ";
    cin.ignore(); // To ignore any newline character left by previous inputs
    getline(cin, name);
    cout << "\t\t\t\t\tPlease Enter The Author Name: ";
    cin >> author_name;
    cout << "\t\t\t\t\tPlease Enter The Urgency Level between 0-5: ";
    cin >> urgency_level;
    while (urgency_level > 5 || urgency_level < 0)
    {
        cout << "\t\t\t\t\tPlease Enter A Valid Urgency Level between 0-5: ";
        cin >> urgency_level;
    }
    request.append(urgency_level, name, author_name, category);
}
int main()
{
    LinkedListBookRequests request;
    orderBookOnDemand(request);
    request.printList();
    return 0;
}