/*
    Name   : Fahad Nazeer
    Roll No: 241372
    Class  : BSAI-F-24-A
*/
#include <iostream>
using namespace std;

template <typename T>
class Node
{
private:
    T element;
    Node<T>* nextNode;

public:

    Node(T val)
    {
        element = val;
        nextNode = NULL;
    }

    T get_element() const
    {
        return element;
    }

    Node<T>* get_next_node() const
    {
        return nextNode;
    }

    void set_element(T value)
    {
        element = value;
    }

    void set_next_node(Node<T>* ptr)
    {
        nextNode = ptr;
    }
};

template <typename T>
class List
{
private:
    Node<T>* head;

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
        for (Node<T>* ptr = head->get_next_node(); ptr != head; ptr = ptr->get_next_node())
        {
            c++;
        }
        return c;
    }

    T front() const
    {
        if (empty())
        {
            throw underflow_error("The list is empty");
        }
        return head->get_element();
    }

    T end() const
    {
        if (empty())
        {
            throw underflow_error("The list is empty");
        }

        Node<T>* ptr = head;
        while (ptr->get_next_node() != head)
        {
            ptr = ptr->get_next_node();
        }

        return ptr->get_element();
    }

    Node<T>* head_ptr() const
    {
        return head;
    }

    int count(T value) const
    {
        if (empty()) return 0;

        int c = 0;
        Node<T>* ptr = head;

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

    void push_front(T val)
    {
        Node<T>* newNode = new Node<T>(val);

        if (empty())
        {
            head = newNode;
            head->set_next_node(head);
        }
        else
        {
            Node<T>* last = head;

            while (last->get_next_node() != head)
            {
                last = last->get_next_node();
            }

            newNode->set_next_node(head);
            last->set_next_node(newNode);
            head = newNode;
        }
    }

    T pop_front()
    {
        if (empty())
        {
            throw underflow_error("The list is empty");
        }

        T val = head->get_element();

        if (head->get_next_node() == head)
        {
            delete head;
            head = NULL;
            return val;
        }

        Node<T>* last = head;
        while (last->get_next_node() != head)
        {
            last = last->get_next_node();
        }

        Node<T>* temp = head;
        head = head->get_next_node();
        last->set_next_node(head);

        temp->set_next_node(NULL);
        delete temp;

        return val;
    }

    void push_back(T val)
    {
        Node<T>* newNode = new Node<T>(val);

        if (empty())
        {
            head = newNode;
            head->set_next_node(head);
        }
        else
        {
            Node<T>* ptr = head;

            while (ptr->get_next_node() != head)
            {
                ptr = ptr->get_next_node();
            }

            ptr->set_next_node(newNode);
            newNode->set_next_node(head);
        }
    }

    T pop_back()
    {
        if (empty())
        {
            throw underflow_error("The list is empty");
        }

        if (head->get_next_node() == head)
        {
            return pop_front();
        }

        T val;

        Node<T>* ptr = head;

        while (ptr->get_next_node()->get_next_node() != head)
        {
            ptr = ptr->get_next_node();
        }

        Node<T>* temp = ptr->get_next_node();
        val = temp->get_element();

        ptr->set_next_node(head);

        delete temp;

        return val;
    }

    void print()
    {
        if (empty()) return;

        Node<T>* ptr = head;

        do
        {
            cout << ptr->get_element() << " ";
            ptr = ptr->get_next_node();
        } while (ptr != head);
    }

    int erase(T value)
    {
        if (empty())
        {
            throw underflow_error("The list is empty");
        }

        int count = 0;

        while (head != NULL && head->get_element() == value)
        {
            pop_front();
            count++;

            if (empty()) return count;
        }

        Node<T>* prev = head;
        Node<T>* curr = head->get_next_node();

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