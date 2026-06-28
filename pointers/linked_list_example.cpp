#include "iostream"

using namespace std;

// link class
class link
{
    int data;
    link *next;

    friend class linklist;
};

// linklist class
class linklist
{

private:
    link *first;

public:
    linklist() : first(NULL)
    {
    }

    ~linklist()
    {
        link *current = first;
        while (current != NULL)
        {
            link *nextNode = current->next; // 1. Save the address of the next node
            delete current;                 // 2. Safely delete the current node
            current = nextNode;             // 3. Move to the next node
        }
        first = NULL; // Good practice
    }

    void additem(int d)
    {
        link *newlink = new link;
        newlink->data = d;
        newlink->next = first;
        first = newlink;
    }

    void display() const
    {

        link *current = first;

        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{

    linklist li;

    li.additem(3);
    li.additem(4);
    li.additem(6);
    li.additem(8);

    li.display();

    return 0;
}