#include "LinkedList_string.h"

LinkedList::LinkedList():head(nullptr){}

LinkedList::LinkedList(const LinkedList& other)
{
    head = nullptr;
    Node *p = other.head;
    while(p != nullptr)
    {
        push_front(p->data);
        p = p->next;
    }
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
    Node *temp = new Node(value);
    Node* walk = head;
    if(walk == nullptr)
    {
        head = temp;
    }
    else
    {
        while(walk != nullptr)
        {
            if (walk->next == nullptr)
            {
                walk->next = temp;
                return;
            }
            walk = walk->next;
        }
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
    if(w == nullptr && index == 0)
    {
        head = node;
    }
    else if(w != nullptr && index == 0)
    {
        head = node;
        node ->next = w;
    }
    else
    {
        while(w != nullptr)
        {
            if(w->next == nullptr && counter+1 == index)
            {
                w->next = node;
                return;
            }
            else if(counter == index)
            {
                p->next = node;
                node->next = w;
            }
            p = w;
            counter++;
            w = w->next;
        }
    }
}

void LinkedList::insert_after(int index, const string& val)
{
    Node *node = new Node(val);
    int counter = 0;
    Node *w = head, *p = head->next;
    if(w == nullptr)
    {
        head = node;
    }
    else
    {
        while(w != nullptr)
        {
            if(counter == index)
            {
                w->next = node;
                node->next = p;
                return;
            }
            w = p;
            counter++;
            p = p->next;
        }
    }
}

void LinkedList::erase_at(int index)
{
    Node *w = head, *p = head;
    int counter = 0;
    if(w == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    while(w != nullptr)
    {
        if(counter==index && w->next == nullptr)
        {
            head = nullptr;
            return;
        }
        else if(counter == index)
        {
            Node *temp = w;
            p->next = w->next;
            delete temp;
            return;
        }
        p = w;
        counter++;
        w = w->next;
    }
}

void LinkedList::erase(const string& e)
{
    Node *w = head, *p = head;
    if(w == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
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
    Node *p = head;
    while(w != nullptr)
    {
        p = w;
        w = w->next;
        delete p;
    }
    head = nullptr;
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

Node* LinkedList::findMiddleNode()
{
    int size = this->size();
    if(size == 0)
    {
        return nullptr;
    }
    int middle, counter=1;
    middle = size/2;
    Node *middleNode = head;

    if(size%2 != 0)
    {
        while(counter-1 != middle)
        {
            middleNode = middleNode->next;
            counter++;
        }
        return middleNode;
    }
    else
    {
        while(counter != middle)
        {
            middleNode = middleNode->next;
            counter++;
        }
        return (middleNode->next);
    }
}

Node* LinkedList::getSmallestNode()
{
    if(this->head == nullptr)
    {
        return nullptr;
    }
    Node *smallest = head, *w = head->next;
    int index;
    bool recursion;

    while(w != nullptr)
    {
        index = 0;
        recursion = true;
        while(recursion)
        {
            if(w->data.at(index) == smallest->data.at(index) && (w->data.size() == index+1))
            {
                smallest = w;
                recursion = false;
            }
            if(w->data.at(index) == smallest->data.at(index) && (smallest->data.size() == index+1))
            {
                recursion = false;
            }
            if(w->data.at(index) < smallest->data.at(index) && (w->data.size() == index+1))
            {
                smallest = w;
                recursion = false;
            }
            if(w->data.at(index) < smallest->data.at(index))
            {
                smallest = w;
                recursion = false;
            }
            if(w->data.at(index) > smallest->data.at(index))
            {
                recursion= false;
            }
            index++;
        }
        w = w->next;
    }
    return smallest;
}

void LinkedList::moveSmallestToFront()
{
    Node *smallest = this->getSmallestNode();
    if(head == nullptr || head == smallest)
    {
        return;
    }
    Node *w = head;
    while(w->next != smallest)
    {
        w = w->next;
    }
    w->next = smallest->next;
    Node *temp = head;
    head = smallest;
    smallest ->next = temp;
}

LinkedList& LinkedList::operator=(const LinkedList& lhs)
{
    Node *w1 = lhs.head;
    int counter=0;

    if(lhs.head == nullptr)
    {
        return *this;
    }
    while(w1 != nullptr)
    {
        insert_at(counter, w1->data);
        erase_at(counter+1);
        counter++;
        w1 = w1->next;
    }
    return *this;
}

bool LinkedList::operator==(const LinkedList& lhs) const
{
    Node *w1, *w2;
    int c1=0, c2=0;
    w1 = head;
    w2 = lhs.head;
    while(w1 != nullptr && w2 != nullptr)
    {
        if(w1->data != w2->data)
        {
            return false;
        }
        w1 = w1->next;
        w2 = w2->next;
        c1++;
        c2++;
    }
    if(c1 != c2)
    {
        return false;
    }
    return true;
}

ostream& operator<<(ostream& out, const LinkedList& list)
{
    Node *w = list.head;
    out << "Head -> ";
    if(w == nullptr)
    {
        out << "nullptr" << endl;
    }
    else
    {
        while(w != nullptr)
        {
            out << w->data << " -> ";
            w = w->next;
        }
        out << " nullptr" << endl;
    }
    return out;
}