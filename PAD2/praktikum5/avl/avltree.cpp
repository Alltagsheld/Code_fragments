/*
 * Author: S. Rapp (2020)
 *
 * This is based on the first google hit of "AVL in C++"
 * https://www.tutorialspoint.com/cplusplus-program-to-implement-avl-tree
 * by Karthikeya Boyini
 *
 * NOTE: It used to have a weird notion of right and left and partly some
 * 'C-ish old-style' that I fixed mostly. I also added a value field to make
 * it more interesting / useful. The root is now inside the AVLTree class
 * and not a global variable any more.
 */

#include <iostream>
#include <fstream>
#include "avltree.h"


using namespace std;

AVLTree::AVLTree() : root(nullptr)
{
}
void AVLTree::checkInsert(int key, string value)
{
    probe(key, value);
}

void AVLTree::clear()
{
    if(clear(root))
    {
        //cout <<"\nTree deleted" << endl;
        root=nullptr;
    }
}
bool AVLTree::clear(Node* p)
{
    if (p == NULL)
    {
        return true;
    }
    clear(p->left);
    clear(p->right);
    //cout << "\n Deleting node: " << p->key;
    if(p==root)
    {
        root->left = nullptr;
        root->right=nullptr;
        return true;
    }
    delete p;
}
/*void AVLTree::remove(Node* p,int key)
{
    Node* root = this->root;
    Node* parent;
    Node* max;

    if(p==nullptr)
    {
        return;
    }
    else if(key<p->key)
    {
        remove(p->left, key);
    }
    else if(key>p->key)
    {
        remove(p->right, key);
    }
    else
    {
        //no child
        if(p->left==nullptr && p->right == nullptr)
        {
            if(key==root->key)
            {
                this->root=nullptr;
            }
            else
            {
                parent = findParent(root, key);
                if(p==parent->left)
                {
                    parent->left = nullptr;
                }
                else
                {
                    parent->right = nullptr;
                }
                delete p;
                p=NULL;
            }
        }
        //case 2: one child
        else if(p->left == NULL||p->right==NULL)
        {
            if(key==root->key)
            {
                Node* temp = p;
                this->root=p->left;
                delete temp;
            }
            else
            {
                Node *temp = p;
                parent = findParent(root, key);
                if(parent->right == p)
                {
                    p = p->right;
                    parent->right = p;
                }
                if(parent->left==p)
                {
                    p = p->left;
                    parent->left = p;
                }
                delete temp;
            }
        }
        else
        {
            //case 3: two children
            if(key==root->key)
            {
                //insert(this->root, root->right->key, root->right->value);
                parent=findMax(p->left);
                parent->right=root->right;
                this->root=p->left;
                balance(root);
                delete p;
            }
            else
            {
                Node *temp = p;
                parent = findParent(root, key);
                if(parent->right == p)
                {
                    parent->right = p->left;
                    insert(this->root, p->right->key, p->right->value);
                }
                if(parent->left==p)
                {
                    parent->left = p->right;
                    insert(this->root, p->left->key, p->left->value);
                }
                delete p;
                Node* temp = findMin(p->right);
            }
        }
    }
}*/
void AVLTree::remove(int key){

    Node* tmp ;
    if(member(key))
    {
        tmp = remove(root,key);
        root = balance(tmp);
    }
    else
    {
        //cout<<"u cant delete something that does not exist"<<endl;
    }

}

Node* AVLTree::remove(Node *&p, int key){
    if(key < p->key){
        remove(p->left,key);
    }
    if(key > p->key){
        remove(p->right,key);
    }

    if(key == p->key){
        Node* tmp = nullptr;

        if(p->left == nullptr || p->right == nullptr ){

            if(p->left == nullptr && p->right != nullptr){ // right child
                tmp = p->right;
                p = nullptr;
                p = tmp;
                return p;
            }
            if(p->left != nullptr && p->right == nullptr ){ //left child
                tmp = p->left;
                p = nullptr;
                p = tmp;
                return p;

            }
            if (p->left == nullptr && p->right == nullptr){ // no child

                p = nullptr;
                root = balance(root);
                return p;
            }
        }
        if(p->left != nullptr && p->right != nullptr){ // 2 children
            tmp = Biggest_left(p->left);

            p->key = tmp->key;

            p->value=tmp->value;

            p->left = remove(p->left,tmp->key);
        }
        return p = balance(p);
    }
    p=balance(p);
    return p;
}


Node* AVLTree::Biggest_left(Node *current)
{
    if(current->right != nullptr){
        return Biggest_left(current->right);
    }
    if(current->right == nullptr){
        return current;
    }
    return current;
}
bool AVLTree::member(int key)
{
    return(member(root, key));
}
bool AVLTree::member(Node* p, int key)   // check if key is present
{
    if(p == nullptr)
    {
        return false;
    }
    if(p->key == key)
    {
        //cout <<"nodes height: "<<p->height<<"\n"<<endl;
        return true;
    }
    if(p->key < key)
    {
        member(p->right, key);
    }
    else if(p->key > key)
    {
        member(p->left, key);
    }
}
//(avl.find(80,s))
bool AVLTree::find(int key, string &value)
{
    return(find(root, key, value));
}
bool AVLTree::find(Node* p, int key, string &value)// check if key is present and return the value for it // (assumes unique keys)
{
    if(p==nullptr)
    {
        return false;
    }

    if(p!= nullptr)
    {
        if(p->key==key)
        {
            value = p->value;
            return true;
        }
        if(p->key<key)
        {
            find(p->right, key, value);
        }
        if(p->key>key)
        {
            find(p->left, key, value);
        }
    }
}
bool AVLTree::set(int key, string value)
{
    if(set(root, key, value))
    {
        return true;
    }
    return false;
}
bool AVLTree::set(Node* p, int key, string value)    //check if key is present and replace value if it is // (assumes unique keys)
{
    if(p->key<key)
    {
        set(p->right, key, value);
    }
    else if(p->key>key)
    {
        set(p->left, key, value);
    }
    if(p->key==key)
    {
        //cout <<"Found the Key and replaced it's value: "<< p->value;
        p->value = value;
        //cout <<" with: "<< p->value<<endl;
        return true;
    }
}
//if (!avl.probe(42,"an answer"))
bool AVLTree::probe(int key, string value)
{
    return(probe(root, key, value));
}
bool AVLTree::probe(Node *p, int key, string value)
{
    if(p == nullptr)
    {
        root=insert(root, key, value);
        calculateNodeHeight(root);
        return true;
    }
    if(p!=nullptr)
    {
        if(p->key == key)
        {
            //cout<<"\nvalue not inserted, it already exists\n"<<endl;
            return false;
        }
        if(p->key < key)
        {
            probe(p->right, key, value);
        }
        else if(p->key > key)
        {
            probe(p->left, key, value);
        }
    }
    p = balance(p);
}

Node* AVLTree::getParent(Node* p, int key)
{
    if(p != nullptr)
    {
        if((p->left != nullptr && p->left->key == key)||(p->right!=nullptr&&p->right->key==key))
        {
            return p;
        }
        if(p->key < key)
        {
            getParent(p->right, key);
        }
        else if(p->key > key)
        {
            getParent(p->left, key);
        }
    }
    return p;
}
void AVLTree::calculateNodeHeight(Node* p)
{
    root->height=1;
    Node* parent;
    if(p != nullptr)
    {
        //this->highest->height=p->height;
        //cout<<"highest: "<<highest->height<<endl;
        if(p->right!=nullptr)
        {
            parent = getParent(p, p->key);
            p->right->height= 1+ parent->height;
            //cout <<"\nheight of new node: "<<p->right->height<<"\n"<<endl;
            calculateNodeHeight(p->right);
        }
        if(p->left!=nullptr)
        {
            parent = getParent(p, p->key);
            p->left->height= 1+ parent->height;
            //cout <<"\nheight of new node: "<<p->left->height<<"\n"<<endl;
            calculateNodeHeight(p->left);
        }
    }
}

Node* AVLTree::height(Node* t) const
{
    int h = 0;
    Node* l=new Node(0, "", nullptr, nullptr);
    Node* r=new Node(0, "", nullptr, nullptr);
    Node* result=new Node(0, "", nullptr, nullptr);
    if (nullptr != t)
    {
        l =height(t->left);
        r =height(t->right);

        result->height = max(l->height, r->height);
        result->height = result->height +1;
    }
    l->~Node();
    r->~Node();
    return result;
    /*int h = 0;
    if (nullptr != t) {
        int l_height = height(t->left);
        int r_height = height(t->right);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;*/
}

int AVLTree::difference(Node* t)
{
    Node* l_height=height(t->left);
    Node* r_height=height(t->right);
    int result = r_height->height - l_height->height;
    l_height->~Node();
    r_height->~Node();
    return result;
    /*int l_height = height(t->left);
    int r_height = height(t->right);
    return r_height - l_height;*/
}

Node* AVLTree::left_rotation(Node* parent)
{
    //cout<<"Left Rotation on " << parent->key << endl;
    Node *t;
    t = parent->right;          // this will be our new root
    parent->right = t->left;    // hand over subtree
    t->left = parent;           // rotate parent down
    calculateNodeHeight(t);
    return t;                   // return new root
}

Node* AVLTree::right_rotation(Node* parent)
{
    //cout<<"Right Rotation on " << parent->key << endl;
    Node *t;
    t = parent->left;           // this will be our new root
    parent->left = t->right;    // hand over subtree
    t->right = parent;          // rotate parent down
    calculateNodeHeight(t);
    return t;                   // return new root
}

Node* AVLTree::rightLeft_rotation(Node* parent)
{
    //cout<<"Right-Left Rotation on " << parent->key << endl;
    parent->right = right_rotation(parent->right);  // right rotation on lower
    return left_rotation(parent);                   // and left rotation on upper
}

Node* AVLTree::leftRight_rotation(Node* parent)
{
    //cout<<"Left-Right Rotation on " << parent->key << endl;
    parent->left = left_rotation(parent->left);     // left rotation on lower
    return right_rotation(parent);                  // and right rotation on upper
}

Node* AVLTree::balance(Node* t)
{
    int d = difference(t);
    if (d < -1) {
        // trouble is in left side
        if (difference(t->left) < 0)
        {
            // trouble is left-left, need to rotate right to balance.
            t = right_rotation(t);
        }
        else
        {
            // trouble is left-right, need to rotate left-right to balance.
            t = leftRight_rotation(t);
        }
    }
    else if (d > 1)
    {
        // trouble is in right side
        if (difference(t->right) > 0)
        {
            // trouble is right-right, need to rotate left to balance.
            t = left_rotation(t);
        }
        else
        {
            // trouble is right-left, need to rotate right-left to balance.
            t = rightLeft_rotation(t);
        }
    }
    return t;
}

Node* AVLTree::insert(Node* p, int key, const string &value)
{
    if (p == nullptr) {
        // we can insert a new node
        p = new Node(key,value,nullptr,nullptr);
        return p=balance(p);
    } else if (key< p->key) {
        p->left = insert(p->left, key, value);
        p = balance(p);
    } else if (key >= p->key) {
        p->right = insert(p->right, key, value);
        p = balance(p);
    }
    return p;
}

void AVLTree::show(Node* p, int l) const
{
    // tree is printed sideways. top line is right-most entry.
    // indentation according to level.
    int i;
    if(p!= nullptr)
    {
        if(p->right!=nullptr)
        {
            show(p->right, l + 1);
        }
        for (i = 0; i < l; i++)
            cout << "    ";
        cout << p->key << endl;
        if(p->left!=nullptr)
        {
            show(p->left, l + 1);
        }
    }
}

void AVLTree::inorder(Node* t) const
{
    if (t == nullptr)
        return;
    inorder(t->left);
    cout << t->key << " " << t->value << endl;
    inorder(t->right);
}

void AVLTree::preorder(Node* t) const
{
    if (t == nullptr)
        return;
    cout << t->key << " " << t->value << endl;
    preorder(t->left);
    preorder(t->right);
}

void AVLTree::postorder(Node* t) const
{
    if (t == nullptr)
        return;
    postorder(t ->left);
    postorder(t ->right);
    cout << t->key << " " << t->value << endl;
}

// writeDot dumps the graph into a file that is usable with AT&T's Graphviz package
// see https://de.wikipedia.org/wiki/Graphviz
// and http://graphviz.org/download/
//
// NOTE: assumes that all keys are different.
// It kind of works with trees that have multiple nodes with the same key, but
// the image is wrong (as it then uses the same graphical node)
void AVLTree::writeDot(const string &filename) const
{
    ofstream fs(filename);
    fs << "digraph avl {" << endl;
    fs << "node [nodesep=0.8]" << endl;
    writeDot(fs, root);
    fs << "}" << endl;
}

void AVLTree::writeDot(ostream &fs, Node *p) const
{
    static int ctr=0; // counter for the faked null nodes

    if (nullptr==p) return;

    // recursively write out left subtree
    writeDot(fs, p->left);

    // write the current node
    // we will write also "white color" nullptrs as separate fake nodes
    // to be able to better differentiate 'only left' from 'only right'
    // nodes that would otherwise be rendered the same in dot's automatic layout.
    // To remove any ambiguity, we also color the non null childs
    // red or green (as in navigation lights used for ships and airplanes)
    if (p->left)
    {
        fs << "   " << p->key << " -> " << p->left->key << "[color=red]" << endl;
    }
    else
    {
        fs << "   " << p->key << " -> n" << ++ctr << "[color=white]" << endl;
        fs << "   n" << ctr << "[color=white, fontcolor=white]" << endl;
    }
    if (p->right)
    {
        fs << "   " << p->key << " -> " << p->right->key << "[color=darkgreen]" << endl;
    }
    else
    {
        fs << "   " << p->key << " -> n" << ++ctr << "[color=white]"  << endl;
        fs << "   n" << ctr << "[color=white, fontcolor=white]" << endl;
    }

    // recursively write out right subtree
    writeDot(fs, p->right);
    //separate nodes
    fs << endl;
}
