#include<iostream>

using namespace std;

//Tree node
template<class T>
class Bnode
{
    public:
        T data;
        Bnode<T> *left;
        Bnode<T> *right;
        Bnode(const T &value)
        {
            data = value;
            left = NULL;
            right = NULL;
        }

};

//LinkedList Node
template<class T>
class Node
{
    public:
        Bnode<T> *data;
        Node<T> *next;
        Node()
        {   data = NULL;
            next = NULL;
        }

};


//Queue....... 
template<class T>
class Queue
{
    public:
        Node<T> *Top;
        int size;
        Queue()
        {
            Top = NULL;
            size = 0;
        }

        Queue<T> &push(Bnode<T> *node)
        {   size ++;
            Node<T> *newNode = new Node<T>;
            newNode->data = node;

            if(Top == NULL)
            {
                Top = newNode;
            }
            else
            {
                newNode->next = Top;
                Top = newNode;
            }
        return *this;
        }

        Node<T> *pop()
        {   size--;
            Node<T> *curr = Top;
            Node<T> *prev = NULL;
            while(curr->next)
            {
                prev = curr;
                curr = curr->next;
            }
            if(prev == NULL)
            {
                Top = curr->next;
                return curr;
            }
            else
            {
                 prev->next = curr->next;
                 return curr;
            }
           
        }


        int sos()
        {
            return size;
        }




        void Show()
        {
           Node<T> *actualNode = Top;
           Bnode<T> *temp;
        //    temp = actualNode->data;
        //    cout << temp->data << endl;
        //    cout << actualNode << endl;
           while(actualNode)
           {   temp = actualNode->data;
               cout << temp->data << endl;
               actualNode = actualNode->next;
           }
        }



};


//Binary Search Tree
template<class T>
class BTree
{
    public:
    Bnode<T> *root;
    int len;

    BTree()
    {
        root = NULL;
        len = 0;
    }

    Bnode<T> *insert(const T & val)
    {
        root = insertNode(val, root);
    }

    Bnode<T> *insertNode(const T &val, Bnode<T> *node)
    {   Bnode<T> *newNode = new Bnode<T>(val);
        if(node == NULL)
        {
            return newNode;
        }
        
        if(val < node->data)
        {
            node->left = insertNode(val, node->left);
        }
        if(val > node->data)
        {
            node->right = insertNode(val, node->right);
        }
        return node;
    }


    void display()
    {
        traverseinorder(root);
    }

    void traverseinorder(Bnode<T> *node)
    {
        if(node->left)
        {
            traverseinorder(node->left);
        }

        cout << node->data << endl;

        if(node->right)
        {
            traverseinorder(node->right);
        }
    }

};

template<class T>
class BreadthFirstSearchAlgo
{
    public:
        BTree<int> bin;
        Queue<int> que;
        int elem;
        int n;
        void treevalueentry()
        {   cout << "Enter the number of elements in a tree.." << endl;
            cin >> n;
            for(int i=0; i<n; i++)
            {   cin >> elem;
                bin.insert(elem);
            }
            cout << "Entered Tree is " << endl;
            bin.display();
        }

        void traversal()
        {   cout << "Testing traversal" << endl;
            Bnode<T> *temp,*test;
            Node<T> *vin;
            temp = bin.root;
            que.push(temp);
            while(que.sos() != 0)
            {
                vin = que.pop();
                test = vin->data;
                cout << test->data << endl;

                if(test->left)
                {
                    que.push(test->left);
                }
                if(test->right)
                {
                    que.push(test->right);
                }
                

            } 
        }
};






int main()
{
BreadthFirstSearchAlgo<int> bfs;
bfs.treevalueentry();

bfs.traversal();
    return 0;
}
