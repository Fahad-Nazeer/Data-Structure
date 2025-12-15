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

    Node(T val, Node<T>* ptr = NULL)
    {
        element = val;
        nextNode = ptr;
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
        int c = 0;
        for (Node<T>* ptr = head; ptr != NULL; ptr = ptr->get_next_node())
        {
            c++;
        }
        return c;
    }

    T front() const
    {
        if (empty())
        {
            throw "The list is empty";
        }
        return head->get_element();
    }

    T end() const
    {
        if (empty())
        {
            throw "The list is empty";
        }

        T last;

        for (Node<T>* ptr = head; ptr != NULL; ptr = ptr->get_next_node())
        {
            last = ptr->get_element();
        }

        return last;
    }

    Node<T>* head_ptr() const
    {
        return head;
    }

    int count(T value) const
    {
        int c = 0;
        for (Node<T>* ptr = head; ptr != NULL; ptr = ptr->get_next_node())
        {
            if (ptr->get_element() == value)
            {
                c++;
            }
        }
        return c;
    }

    void push_front(T val)
    {
        Node<T>* newNode = new Node<T>(val);

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

    T pop_front()
    {
        if (empty())
        {
            throw "The list is empty";
        }

        T a = front();

        Node<T>* temp = head;
        head = head->get_next_node();
        temp->set_next_node(NULL);
        delete temp;

        return a;
    }

    void push_back(T val)
    {
        Node<T>* newNode = new Node<T>(val);

        if (empty())
        {
            head = newNode;
        }
        else
        {
            for (Node<T>* ptr = head; ptr != NULL; ptr = ptr->get_next_node())
            {
                if (ptr->get_next_node() == NULL)
                {
                    ptr->set_next_node(newNode);
                    break;
                }
            }
        }
    }

    T pop_back()
    {
        if (empty())
        {
            throw "The list is empty";
        }

        if (size() == 1)
        {
            return pop_front();
        }

        T val;

        for (Node<T>* ptr = head; ptr != NULL; ptr = ptr->get_next_node())
        {
            if (ptr->get_next_node() != NULL &&
                ptr->get_next_node()->get_next_node() == NULL)
            {
                Node<T>* temp = ptr->get_next_node();
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
        for (Node<T>* ptr = head; ptr != NULL; ptr = ptr->get_next_node())
        {
            cout << ptr->get_element() << " ";
        }
    }

    int erase(T value)
    {
        int count = 0;

        if (empty())
        {
            throw "The list is empty";
        }
        for (Node<T>* ptr = head; head != NULL && head->get_element() == value; ptr = head)
        {
            Node<T>* temp = head;
            head = head->get_next_node();
            temp->set_next_node(NULL);
            delete temp;
            count++;
        }
        Node<T>* prev = head;

        for (Node<T>* ptr = (head != NULL ? head->get_next_node() : NULL); ptr != NULL; ptr = ptr->get_next_node())
        {
            if (ptr->get_element() == value)
            {
                prev->set_next_node(ptr->get_next_node());
                Node<T>* temp = ptr;
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

template <typename T>
class Queue
{

private:

    List<T> l;

public:

    bool empty() const;

    T top() const;

    void push(T);

    T pop();

};

template <typename T>
bool Queue<T>::empty() const
{

    return l.empty();

}

template <typename T>
void Queue<T>::push(T obj)
{

    l.push_back(obj);

}

template <typename T>
T Queue<T>::top() const {

    if (empty()) {

        throw "The list is empty";

    }

    return l.front();

}

template <typename T>
T Queue<T>::pop() {

    if (empty()) {

        throw "The list is empty";

    }

    return l.pop_front();

}

template <typename Type>
class Binary_tree
{
private:
    Type element;
    Binary_tree* left_child;
    Binary_tree* right_child;

public:
    Binary_tree(Type const& obj = Type()) 
        : element(obj), left_child(NULL), right_child(NULL)
    {
    }

    Type retrieve() const
    {
        return element;
    }

    Binary_tree* left() const
    {
        return left_child;
    }

    Binary_tree* right() const
    {
        return right_child;
    }

    int degree() const
    {
        int d = 0;
        if (left_child != NULL) d++;
        if (right_child != NULL) d++;
        return d;
    }

    bool is_leaf() const
    {
        return (degree() == 0);
    }

    void insert(Type const& obj)
    {
        if (left_child == NULL)
        {
            left_child = new Binary_tree(obj);
        }
        else if (right_child == NULL)
        {
            right_child = new Binary_tree(obj);
        }
    }

    int size() const
    {
        int s = 1;
        if (left_child != NULL) s += left_child->size();
        if (right_child != NULL) s += right_child->size();
        return s;
    }

    int height() const
    {
        int hl = 0;
        int hr = 0;
        if (left_child != NULL) hl = 1 + left_child->height();
        if (right_child != NULL) hr = 1 + right_child->height();
        
        return (hl > hr) ? hl : hr;
    }

    void depth_first_traversal() const
    {
        cout << retrieve() << "\t";
        if (left_child != NULL) left_child->depth_first_traversal();
        if (right_child != NULL) right_child->depth_first_traversal();
    }

    void breadth_first_traversal()
    {
        Queue<Binary_tree*> q;
        q.push(this);
        while (!q.empty())
        {
            Binary_tree* p = q.pop();
            cout << p->retrieve() << "\t";
            if (p->left_child != NULL) q.push(p->left_child);
            if (p->right_child != NULL) q.push(p->right_child);
        }
    }
};

int main()
{
 
}
