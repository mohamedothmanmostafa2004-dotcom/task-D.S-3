#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct Node
{
    int data;
    Node* prev;
    Node* next;
    Node(int v): data(v), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;
    int sz;

    Node* nodeAt(int position)
    {
        if (position < 1 || position > sz) return nullptr;
        Node* cur;
        if (position <= sz/2)
        {
            cur = head;
            int i = 1;
            while (i < position)
            {
                cur = cur->next;
                ++i;
            }
        }
        else
        {
            cur = tail;
            int i = sz;
            while (i > position)
            {
                cur = cur->prev;
                --i;
            }
        }
        return cur;
    }

public:
    DoublyLinkedList(): head(nullptr), tail(nullptr), sz(0) {}

    ~DoublyLinkedList()
    {
        Node* cur = head;
        while (cur)
        {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    int size() const
    {
        return sz;
    }

    void insertLeft(int value)
    {
        Node* nn = new Node(value);
        if (!head)
        {
            head = tail = nn;
        }
        else
        {
            nn->next = head;
            head->prev = nn;
            head = nn;
        }
        ++sz;
        cout << "Inserted at left: " << value << endl;
    }

    void insertRight(int value)
    {
        Node* nn = new Node(value);
        if (!tail)
        {
            head = tail = nn;
        }
        else
        {
            tail->next = nn;
            nn->prev = tail;
            tail = nn;
        }
        ++sz;
        cout << "Inserted at right: " << value << endl;
    }

    void insertAtPosition(int position, int value)
    {
        if (position < 1 || position > sz + 1)
        {
            cout << "Invalid position. Must be between 1 and " << (sz + 1) << endl;
            return;
        }
        if (position == 1)
        {
            insertLeft(value);
            return;
        }
        if (position == sz + 1)
        {
            insertRight(value);
            return;
        }

        Node* after = nodeAt(position);
        Node* before = after->prev;
        Node* nn = new Node(value);

        before->next = nn;
        nn->prev = before;
        nn->next = after;
        after->prev = nn;
        ++sz;
        cout << "Inserted at position " << position << ": " << value << endl;
    }

    void removeLeft()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node* toDelete = head;
        int val = toDelete->data;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        delete toDelete;
        --sz;
        cout << "Removed left: " << val << endl;
    }

    void removeRight()
    {
        if (!tail)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node* toDelete = tail;
        int val = toDelete->data;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete toDelete;
        --sz;
        cout << "Removed right: " << val << endl;
    }

    void removeAtPosition(int position)
    {
        if (position < 1 || position > sz)
        {
            cout << "Invalid position. Must be between 1 and " << sz << endl;
            return;
        }
        if (position == 1)
        {
            removeLeft();
            return;
        }
        if (position == sz)
        {
            removeRight();
            return;
        }

        Node* target = nodeAt(position);
        Node* before = target->prev;
        Node* after = target->next;
        before->next = after;
        after->prev = before;
        int val = target->data;
        delete target;
        --sz;
        cout << "Removed at position " << position << ": " << val << endl;
    }

    vector<int> search(int value)
    {
        vector<int> positions;
        Node* cur = head;
        int pos = 1;
        while (cur)
        {
            if (cur->data == value) positions.push_back(pos);
            cur = cur->next;
            ++pos;
        }
        if (positions.empty())
        {
            cout << "Value " << value << " not found." << endl;
        }
        else
        {
            cout << "Value " << value << " found at positions: ";
            for (size_t i = 0; i < positions.size(); ++i)
            {
                cout << positions[i] << (i+1<positions.size() ? ", " : "");
            }
            cout << endl;
        }
        return positions;
    }

    void editAtPosition(int position, int newValue)
    {
        Node* target = nodeAt(position);
        if (!target)
        {
            cout << "Invalid position. Cannot edit." << endl;
            return;
        }
        int old = target->data;
        target->data = newValue;
        cout << "Edited position " << position << " from " << old << " to " << newValue << endl;
    }

    void print() const
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        cout << "List forward (" << sz << "): ";
        Node* cur = head;
        while (cur)
        {
            cout << cur->data;
            if (cur->next) cout << " <-> ";
            cur = cur->next;
        }
        cout << endl;
    }

    void printReverse() const
    {
        if (!tail)
        {
            cout << "List is empty." << endl;
            return;
        }
        cout << "List reverse (" << sz << "): ";
        Node* cur = tail;
        while (cur)
        {
            cout << cur->data;
            if (cur->prev) cout << " <-> ";
            cur = cur->prev;
        }
        cout << endl;
    }
};

#endif // DOUBLY_LINKED_LIST_H
