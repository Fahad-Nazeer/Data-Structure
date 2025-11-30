/*
    Name   : Fahad Nazeer
    Roll No: 241372
    Class  : BSAI-F-24-A
*/
#include <iostream>
using namespace std;

//Class to create a node
class Node
{
private:
    int element;
    Node* nextNode;

public:

    Node(int val)
    {
        element = val;
        nextNode = NULL;
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

//Class to create a circular singly list
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
        if (empty()) return 0;

        int c = 1;
        for (Node* ptr = head->get_next_node(); ptr != head; ptr = ptr->get_next_node())
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

        Node* ptr = head;
        while (ptr->get_next_node() != head)
        {
            ptr = ptr->get_next_node();
        }

        return ptr->get_element();
    }

    Node* head_ptr() const
    {
        return head;
    }

    int count(int value) const
    {
        if (empty()) return 0;

        int c = 0;
        Node* ptr = head;

        do
        {
            if (ptr->get_element() == value)
            {
                c++;
            }
            ptr = ptr->get_next_node();
        } while (ptr != head);

        return c;
    }

    void push_front(int val)
    {
        Node* newNode = new Node(val);

        if (empty())
        {
            head = newNode;
            head->set_next_node(head);
        }
        else
        {
            Node* last = head;

            while (last->get_next_node() != head)
            {
                last = last->get_next_node();
            }

            newNode->set_next_node(head);
            last->set_next_node(newNode);
            head = newNode;
        }
    }

    int pop_front()
    {
        if (empty())
        {
            throw underflow_error("The list is empty");
        }

        int val = head->get_element();

        if (head->get_next_node() == head)
        {
            delete head;
            head = NULL;
            return val;
        }

        Node* last = head;
        while (last->get_next_node() != head)
        {
            last = last->get_next_node();
        }

        Node* temp = head;
        head = head->get_next_node();
        last->set_next_node(head);

        temp->set_next_node(NULL);
        delete temp;

        return val;
    }

    void push_back(int val)
    {
        Node* newNode = new Node(val);

        if (empty())
        {
            head = newNode;
            head->set_next_node(head);
        }
        else
        {
            Node* ptr = head;

            while (ptr->get_next_node() != head)
            {
                ptr = ptr->get_next_node();
            }

            ptr->set_next_node(newNode);
            newNode->set_next_node(head);
        }
    }

    int pop_back()
    {
        if (empty())
        {
            throw underflow_error("The list is empty");
        }

        if (head->get_next_node() == head)
        {
            return pop_front();
        }

        int val;

        Node* ptr = head;

        while (ptr->get_next_node()->get_next_node() != head)
        {
            ptr = ptr->get_next_node();
        }

        Node* temp = ptr->get_next_node();
        val = temp->get_element();

        ptr->set_next_node(head);

        delete temp;

        return val;
    }

    void print()
    {
        if (empty()) return;

        Node* ptr = head;

        do
        {
            cout << ptr->get_element() << " ";
            ptr = ptr->get_next_node();
        } while (ptr != head);
    }

    int erase(int value)
    {
        if (empty())
        {
            throw underflow_error("The list is empty");
        }

        int count = 0;

        // delete head occurrences
        while (head != NULL && head->get_element() == value)
        {
            pop_front();
            count++;

            if (empty()) return count;
        }

        Node* prev = head;
        Node* curr = head->get_next_node();

        while (curr != head)
        {
            if (curr->get_element() == value)
            {
                prev->set_next_node(curr->get_next_node());
                delete curr;

                curr = prev->get_next_node();
                count++;

                if (curr == head)
                {
                    break;
                }
            }
            else
            {
                prev = curr;
                curr = curr->get_next_node();
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

}
