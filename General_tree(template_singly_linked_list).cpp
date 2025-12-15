/*
    Name   : Fahad Nazeer
    Roll No: 241372
    Class  : BSAI-F-24-A
*/

#include <iostream>
#include <algorithm>
#include <stdexcept>
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
            throw underflow_error("The list is empty");
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
            throw underflow_error("The list is empty");
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
            throw underflow_error("The list is empty");
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

        throw underflow_error("The list is empty");

    }

    return l.front();

}

template <typename T>
T Queue<T>::pop() {

    if (empty()) {

        throw underflow_error("The list is empty");

    }

    return l.pop_front();

}

template <typename Type>
class Simple_tree
{
private:
    Type element;
    Simple_tree* parent_node;
    List<Simple_tree*> children;

public:
    Simple_tree(Type const& obj = Type(), Simple_tree* p = NULL) : element(obj), parent_node(p)
    {
    }

    Type retrieve() const
    {
        return element;
    }

    Simple_tree* parent() const
    {
        return parent_node;
    }

    bool is_root() const
    {
        return (parent() == NULL);
    }

    Simple_tree* child(int n) const
    {
        if (n < 1 || n > degree())
        {
            return NULL;
        }
        Node<Simple_tree*>* ptr = children.head_ptr();
        for (int i = 1; i < n; ++i)
        {
            ptr = ptr->get_next_node();
        }
        return ptr->get_element();
    }

    int degree() const
    {
        return children.size();
    }

    bool is_leaf() const
    {
        return (degree() == 0);
    }

    void insert(Type const& obj)
    {
        children.push_back(new Simple_tree(obj, this));
    }

    int size() const
    {
        int s = 1;
        for (Node<Simple_tree*>* ptr = children.head_ptr(); ptr != NULL; ptr = ptr->get_next_node())
        {
            s += ptr->get_element()->size();
        }
        return s;
    }

    int height() const
    {
        int h = 0;
        for (Node<Simple_tree*>* ptr = children.head_ptr(); ptr != NULL; ptr = ptr->get_next_node())
        {
            h = std::max(h, 1 + ptr->get_element()->height());
        }
        return h;
    }

    void detach()
    {
        if (is_root())
        {
            return;
        }
        parent()->children.erase(this);
        parent_node = NULL;
    }

    void attach(Simple_tree<Type>* tree)
    {
        if (!tree->is_root())
        {
            tree->detach();
        }
        tree->parent_node = this;
        children.push_back(tree);
    }

    void depth_first_traversal() const
    {
        cout << retrieve() << "\t";
        for (Node<Simple_tree*>* ptr = children.head_ptr(); ptr != NULL; ptr = ptr->get_next_node())
        {
            ptr->get_element()->depth_first_traversal();
        }
    }

    void breadth_first_traversal()
    {
        Queue<Simple_tree*> q;
        q.push(this);
        while (!q.empty())
        {
            Simple_tree* p = q.pop();
            cout << p->retrieve() << "\t";
            for (Node<Simple_tree*>* ptr = p->children.head_ptr(); ptr != NULL; ptr = ptr->get_next_node())
            {
                q.push(ptr->get_element());
            }
        }
    }
};

int main()
{
    Simple_tree<string>* root = new Simple_tree<string>("Fahad");

    root->insert("Nazeer");
    root->insert("BSAI");
    root->insert("241372");

    Simple_tree<string>* child1 = root->child(1);
    child1->insert("Node_A");
    child1->insert("Node_B");

    cout << "Depth First Traversal: ";
    root->depth_first_traversal();
    cout << endl;

    cout << "Breadth First Traversal: ";
    root->breadth_first_traversal();
    cout << endl;

    cout << "Tree Size: " << root->size() << endl;
    cout << "Tree Height: " << root->height() << endl;

    return 0;
}