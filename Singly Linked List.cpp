just convert this code to template doing minimum changes i dont need any improvement just convert it to "/*
    Name   : Fahad Nazeer
    Roll No: 241372
    Class  : BSAI-F-24-A
*/

#include <iostream>
using namespace std;


class Node
{
private:
    int element;
    Node* nextNode;
  

public:

    Node(int val,Node*ptr=NULL)
    {
        element = val;
        nextNode = ptr;
    }

    int get_element() const
    {
        return element;
    }

    Node* get_next_node() const
    {
        return nextNode;
    }

    void set_element(int value)
    {
        element = value;
    }

    void set_next_node(Node* ptr)
    {
        nextNode = ptr;
    }


};


class List
{
private:
    Node* head;

public:

    List()
    {
        head = NULL;
    }

    bool empty() const
    {
        return (head == NULL);
    }

    int size() const
    {
        int c = 0;
        for (Node* ptr = head; ptr != NULL; ptr = ptr->get_next_node())
        {
            c++;
        }
        return c;
    }

    int front() const
    {
        if (empty())
        {
            throw underflow_error("The list is empty");
        }
        return head->get_element();
    }

    int end() const
    {
        if (empty())
        {
            throw underflow_error("The list is empty");
        }

        int last;

        for (Node* ptr = head; ptr != NULL; ptr = ptr->get_next_node())
        {
            last = ptr->get_element();
        }

        return last;
    }

    Node* head_ptr() const
    {
        return head;
    }

    int count(int value) const
    {
        int c = 0;
        for (Node* ptr = head; ptr != NULL; ptr = ptr->get_next_node())
        {
            if (ptr->get_element() == value)
            {
                c++;
            }
        }
        return c;
    }

    void push_front(int val)
    {
        Node* newNode = new Node(val);

        if (empty())
        {
            head = newNode;
        }
        else
        {
            newNode->set_next_node(head);
            head = newNode;
        }
    }

    int pop_front()
    {
        if (empty())
        {
            throw underflow_error("The list is empty");
        }

        int a = front();

        Node* temp = head;
        head = head->get_next_node();
        temp->set_next_node(NULL);
        delete temp;

        return a;
    }

    void push_back(int val)
    {
        Node* newNode = new Node(val);

        if (empty())
        {
            head = newNode;
        }
        else
        {
            for (Node* ptr = head; ptr != NULL; ptr = ptr->get_next_node())
            {
                if (ptr->get_next_node() == NULL)
                {
                    ptr->set_next_node(newNode);
                    break;
                }
            }
        }
    }

    int pop_back()
    {
        if (empty())
        {
            throw underflow_error("The list is empty");
        }

        if (size() == 1)
        {
            return pop_front();
        }

        int val;

        for (Node* ptr = head; ptr != NULL; ptr = ptr->get_next_node())
        {
            if (ptr->get_next_node() != NULL &&
                ptr->get_next_node()->get_next_node() == NULL)
            {
                Node* temp = ptr->get_next_node();
                val = temp->get_element();

                ptr->set_next_node(NULL);

                delete temp;
                break;
            }
        }

        return val;
    }

    void print()
    {
        for (Node* ptr = head; ptr != NULL; ptr = ptr->get_next_node())
        {
            cout << ptr->get_element() << " ";
        }
    }

    int erase(int value)
    {
        int count = 0;

        if (empty())
        {
            throw underflow_error("The list is empty");
        }
        for (Node* ptr = head; head != NULL && head->get_element() == value; ptr = head)
        {
            Node* temp = head;
            head = head->get_next_node();
            temp->set_next_node(NULL);
            delete temp;
            count++;
        }
        Node* prev = head;

        for (Node* ptr = head->get_next_node(); ptr != NULL; ptr = ptr->get_next_node())
        {
            if (ptr->get_element() == value)
            {
                prev->set_next_node(ptr->get_next_node());
                Node* temp = ptr;
                ptr = prev;
                temp->set_next_node(NULL);
                delete temp;
                
                count++;
            }
            else
            {
                prev = ptr;
            }
        }

        return count;
    }

    ~List()
    {
        while (!empty())
        {
            pop_front();
        }
    }
};

int main()
{
}"