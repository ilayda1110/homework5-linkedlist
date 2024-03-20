#include "LinkedList_string.h"

LinkedList::LinkedList():head(nullptr){}

LinkedList::LinkedList(const LinkedList& other)
{
    LinkedList res;

}

LinkedList::~LinkedList()
{
    Node *w = head;
    while(w != nullptr)
    {
        Node *p = w;
        w = w->next;
        delete p;
    }
}

string& LinkedList::at(int index)
{
    int counter = 0;
    Node* walk = head;
    while (walk != nullptr)
    {
        if (counter == index)
        {
            return (walk->data);
        }
        counter++;
        walk = walk->next;
    }
}

string& LinkedList::front()
{
    return (head->data);
}

string& LinkedList::back()
{
    Node* walk = head;
    while (walk != nullptr)
    {
        if (walk->next == nullptr)
        {
            return (walk->data);
        }
        walk = walk->next;
    }
}

void LinkedList::push_back(const string& value)
{
    Node* walk = head;
    while (walk != nullptr)
    {
        if (walk->next == nullptr)
        {
            Node* temp = new Node(value);
            walk->next = temp;
        }
        walk = walk->next;
    }
}

void LinkedList::pop_back()
{
    Node* walk = head;
    Node* temp = head;
    while (walk != nullptr)
    {
        if (walk->next == nullptr)
        {
            temp->next = nullptr;
            delete walk;
        }
        temp = walk;
        walk = walk->next;
    }
}

void LinkedList::push_front(const string& value)
{
    Node *node = new Node(value);
    node->next = head;
    head = node;
}

void LinkedList::pop_front()
{
    Node *p = head;
    p = p->next;
    delete head;
    head = p;
}

void LinkedList::insert_at(int index, const string& value)
{
    Node *node = new Node(value);
    int counter = 0;
    Node *w = head, *p = head;
    while(w != nullptr)
    {
        if(counter == index)
        {
            p->next = node;
            node->next = w;
        }
        p = w;
        counter++;
        w = w->next;
    }
}

void LinkedList::insert_after(int index, const string& val)
{
    Node *node = new Node(val);
    int counter = 0;
    Node *w = head, *p = head->next;
    while(w != nullptr)
    {
        if(counter == index)
        {
            w->next = node;
            node->next = p;
        }
        w = p;
        counter++;
        p = p->next;
    }
}

void LinkedList::erase_at(int index)
{
    Node *w = head, *p = head;
    int counter = 0;
    while(w != nullptr)
    {
        if(counter == index)
        {
            Node *temp = w;
            p->next = w->next;
            delete temp;
        }
        p = w;
        counter++;
        w = w->next;
    }
}

void LinkedList::erase(const string& e)
{
    Node *w = head, *p = head;
    while(w != nullptr)
    {
        if(w->data == e)
        {
            Node *temp = w;
            p->next = w->next;
            delete temp;
        }
        p = w;
        w = w->next;
    }
}

void LinkedList::clear()
{
    Node *w = head;
    Node *p = nullptr;
    while(w != nullptr)
    {
        p = w;
        w = w->next;
        delete p;
    }
    w = nullptr;
}

int LinkedList::size() const
{
    Node* walk = head;
    int counter = 0;
    while (walk != nullptr)
    {
        counter++;
        walk = walk->next;
    }
    return counter;
}

bool LinkedList::empty() const{
    return head==nullptr;
}

LinkedList& LinkedList::operator=(const LinkedList& lhs)
{
    // TODO: insert return statement here
}

bool LinkedList::operator==(const LinkedList& lhs) const
{
    return false;
}

ostream& operator<<(ostream& out, const LinkedList& list){

}

LinkedList LinkedList:: operator+(const LinkedList& other)
{
    LinkedList res;
    Node* resW = nullptr;

    if (head == nullptr && other.head == nullptr)
    {
        return res;
    }

    if (head != nullptr)
    {
        res.head = new Node(head->data);
    }
    else if(other.head != nullptr)
    {
        res.head = new Node(other.head->data);
    }

    resW = res.head;
    Node* w = nullptr;

    if (head != nullptr)
    {
        w = head->next;
        while (w != nullptr)
        {
            resW->next = new Node(w->data);
            resW = resW->next;
            w = w->next;
        }
    }
    if (head == nullptr && other.head != nullptr)
    {
        w = other.head->next;
    }
    else
    {
        w = other.head;
        while (w != nullptr)
        {
            resW->next = new Node(w->data);
            resW = resW->next;
            w = w->next;
        }
    }
    return res;
}

/*
LinkedList& LinkedList:: operator+(const string& data)
{
    Node* w = this->head;
    while (w != nullptr)
    {
        if (w->next == nullptr)
        {
            w->next = new Node(data);
            break;
        }
    }
    return *this;
}
 */