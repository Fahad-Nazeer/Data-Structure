/*
    Name    : Fahad Nazeer
    Roll No : 241372
    Class   : BSAI-F-24-A
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
class Binary_search_node {
private:
    Type element;
    Binary_search_node* left_tree;
    Binary_search_node* right_tree;

public:
    Binary_search_node(Type const& obj);

    Type retrieve() const;
    void setdata(Type obj);

    Binary_search_node* left() const;
    Binary_search_node* right() const;

    void setleft(Binary_search_node<Type>* obj);
    void setright(Binary_search_node<Type>* obj);

    bool empty() const { return this == NULL; }
    bool is_leaf() const { return ((left() == NULL) && (right() == NULL)); }

    int size() const {
        if (empty()) return 0;
        return 1 + ((left() == NULL) ? 0 : left()->size()) + ((right() == NULL) ? 0 : right()->size());
    }

    int height() const {
        if (empty()) return -1;
        int leftH = (left() == NULL) ? -1 : left()->height();
        int rightH = (right() == NULL) ? -1 : right()->height();
        return 1 + std::max(leftH, rightH);
    }

    Type front() const;
    Type back() const;
    bool find(Type const&) const;
    void clear(Binary_search_node<Type>*& ptr);
    bool insert(Type const&, Binary_search_node*&);
    bool erase(Type const&, Binary_search_node*&);

    // Breadth First Traversal using your Queue
    void breadth_first_traversal() {
        Queue<Binary_search_node<Type>*> q;
        q.push(this);
        while (!q.empty()) {
            Binary_search_node<Type>* curr = q.pop();
            cout << curr->retrieve() << " ";
            if (curr->left() != NULL) q.push(curr->left());
            if (curr->right() != NULL) q.push(curr->right());
        }
        cout << endl;
    }
};



template <typename Type>
Binary_search_node<Type>::Binary_search_node(Type const& obj)
    : element(obj), left_tree(NULL), right_tree(NULL) {
}

template <typename Type>
Type Binary_search_node<Type>::retrieve() const {
    return element;
}

template <typename Type>
void Binary_search_node<Type>::setdata(Type obj) {
    element = obj;
}

template <typename Type>
Binary_search_node<Type>* Binary_search_node<Type>::left() const {
    return left_tree;
}

template <typename Type>
Binary_search_node<Type>* Binary_search_node<Type>::right() const {
    return right_tree;
}

template <typename Type>
void Binary_search_node<Type>::setleft(Binary_search_node<Type>* obj) {
    left_tree = obj;
}

template <typename Type>
void Binary_search_node<Type>::setright(Binary_search_node<Type>* obj) {
    right_tree = obj;
}

template <typename Type>
Type Binary_search_node<Type>::front() const {
    if (empty()) throw "Underflow";
    return (left() == NULL) ? retrieve() : left()->front();
}

template <typename Type>
Type Binary_search_node<Type>::back() const {
    if (empty()) throw "Underflow";
    return (right() == NULL) ? retrieve() : right()->back();
}

template <typename Type>
bool Binary_search_node<Type>::find(Type const& obj) const {
    if (empty()) return false;
    else if (retrieve() == obj) return true;
    return (obj < retrieve()) ? ((left() == NULL) ? false : left()->find(obj))
        : ((right() == NULL) ? false : right()->find(obj));
}

template <typename Type>
void Binary_search_node<Type>::clear(Binary_search_node<Type>*& ptr) {
    if (ptr != NULL) {
        clear(ptr->left_tree);
        clear(ptr->right_tree);
        delete ptr;
        ptr = NULL;
    }
}

template <typename Type>
bool Binary_search_node<Type>::insert(Type const& obj, Binary_search_node*& ptr_to_this) {
    if (ptr_to_this == NULL) {
        ptr_to_this = new Binary_search_node<Type>(obj);
        return true;
    }
    else if (obj < retrieve()) {
        return left()->insert(obj, left_tree);
    }
    else if (obj > retrieve()) {
        return right()->insert(obj, right_tree);
    }
    else {
        return false; // Duplicate
    }
}

template <typename Type>
bool Binary_search_node<Type>::erase(Type const& obj, Binary_search_node*& ptr_to_this) {
    if (ptr_to_this == NULL) {
        return false;
    }
    else if (obj == retrieve()) {
        if (is_leaf()) {
            delete this;
            ptr_to_this = NULL;
        }
        else if (left() != NULL && right() != NULL) {
            element = right()->front();
            right()->erase(element, right_tree);
        }
        else {
            Binary_search_node<Type>* temp = (left() != NULL) ? left() : right();
            ptr_to_this = temp;
            left_tree = NULL;
            right_tree = NULL;
            delete this;
        }
        return true;
    }
    else if (obj < retrieve()) {
        return left()->erase(obj, left_tree);
    }
    else {
        return right()->erase(obj, right_tree);
    }
}

template <typename Type>
class Binary_search_tree {
private:
    Binary_search_node<Type>* root_node;

public:
    Binary_search_tree();
    ~Binary_search_tree();

    Binary_search_node<Type>* root() const;
    bool empty() const;
    int size() const;
    int height() const;
    Type front() const;
    Type back() const;
    void clear();
    bool insert(Type const& obj);
    bool erase(Type const& obj);

    void print_breadth_first() {
        if (root_node != NULL)
            root_node->breadth_first_traversal();
    }
};

template <typename Type>
Binary_search_tree<Type>::Binary_search_tree() : root_node(NULL) {
}

template <typename Type>
Binary_search_tree<Type>::~Binary_search_tree() {
    clear();
}

template <typename Type>
void Binary_search_tree<Type>::clear() {
    if (root_node != NULL)
        root_node->clear(root_node);
}

template <typename Type>
Binary_search_node<Type>* Binary_search_tree<Type>::root() const {
    return root_node;
}

template <typename Type>
bool Binary_search_tree<Type>::empty() const {
    return root_node == NULL;
}

template <typename Type>
int Binary_search_tree<Type>::size() const {
    return (root_node == NULL) ? 0 : root_node->size();
}

template <typename Type>
int Binary_search_tree<Type>::height() const {
    return (root_node == NULL) ? -1 : root_node->height();
}

template <typename Type>
Type Binary_search_tree<Type>::front() const {
    if (root_node == NULL) throw "Underflow";
    return root_node->front();
}

template <typename Type>
Type Binary_search_tree<Type>::back() const {
    if (root_node == NULL) throw "Underflow";
    return root_node->back();
}

template <typename Type>
bool Binary_search_tree<Type>::insert(Type const& obj) {
    if (root_node == NULL) { 
        root_node = new Binary_search_node<Type>(obj);
        return true;
    }
    return root_node->insert(obj, root_node);
}

template <typename Type>
bool Binary_search_tree<Type>::erase(Type const& obj) {
    if (root_node == NULL) return false;
    return root_node->erase(obj, root_node);
}

int main()
{
    Binary_search_tree<int> tree;

    tree.insert(42);
    tree.insert(15);
    tree.insert(50);
    tree.insert(10);
    tree.insert(22);

    cout << "Breadth First Traversal: ";
    tree.print_breadth_first();

    cout << "Min value (front): " << tree.front() << endl;
    cout << "Max value (back): " << tree.back() << endl;
    cout << "Tree Height: " << tree.height() << endl;

    tree.erase(15);
    cout << "After erasing 15: ";
    tree.print_breadth_first();

    return 0;
}