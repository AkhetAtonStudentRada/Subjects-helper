#include <iostream>
#include <string>

using namespace std;


struct node
{
    friend ostream& operator << (ostream& out, node& node)
    {
        out << "Ключ: " << node.key << ";" << endl;
        out << "Колiр: ";
        if (node.color == 'r')
            out << "червоний;\n";
        else
            out << "чорний;\n";

        if (node.left != nullptr)
            out << "Лiва дитина: " << node.left->key << ";" << endl;
        else
            out << "Лiвої дитини немає;" << endl;
        if (node.right != nullptr)
            out << "Права дитина: " << node.right->key << ";" << endl;
        else
            out << "Правої дитини немає;" << endl;
        if (node.parent != nullptr)
            out << "Батько: " << node.parent->key << ";" << endl;
        else
            out << "Цей ключ - корiнь;" << endl;
        return out;
    }

    int key;
    node* parent;
    char color;
    node* left;
    node* right;
};

class RBtree
{

private:
    node* root;
    node* q;
public:
    RBtree()
    {
        q = nullptr;
        root = nullptr;
    }
    void insert();
    void insertfix(node*);
    void leftrotate(node*);
    void rightrotate(node*);
    void disp();
    void display(node*);
    void search();
    void min();
};
void RBtree::insert()
{
    int z, i = 0;
    cout << "\nУведiть ключ: ";
    cin >> z;
    node* p, * q;
    node* t = new node;
    t->key = z;
    t->left = nullptr;
    t->right = nullptr;
    t->color = 'r';
    p = root;
    q = nullptr;
    if (root == nullptr)
    {
        root = t;
        t->parent = nullptr;
    }
    else
    {
        while (p != nullptr)
        {
            q = p;
            if (p->key < t->key)
                p = p->right;
            else
                p = p->left;
        }
        t->parent = q;
        if (q->key < t->key)
            q->right = t;
        else
            q->left = t;
    }
    insertfix(t);
    this->min();
}
void RBtree::insertfix(node* t)
{
    node* u;
    if (root == t)
    {
        t->color = 'b';
        return;
    }
    while (t->parent != nullptr && t->parent->color == 'r')
    {
        node* g = t->parent->parent;
        if (g->left == t->parent)
        {
            if (g->right != nullptr)
            {
                u = g->right;
                if (u->color == 'r')
                {
                    t->parent->color = 'b';
                    u->color = 'b';
                    g->color = 'r';
                    t = g;
                }
            }
            else
            {
                if (t->parent->right == t)
                {
                    t = t->parent;
                    leftrotate(t);
                }
                t->parent->color = 'b';
                g->color = 'r';
                rightrotate(g);
            }
        }
        else
        {
            if (g->left != nullptr)
            {
                u = g->left;
                if (u->color == 'r')
                {
                    t->parent->color = 'b';
                    u->color = 'b';
                    g->color = 'r';
                    t = g;
                }
            }
            else
            {
                if (t->parent->left == t)
                {
                    t = t->parent;
                    rightrotate(t);
                }
                t->parent->color = 'b';
                g->color = 'r';
                leftrotate(g);
            }
        }
        root->color = 'b';
    }
}



void RBtree::leftrotate(node* p)
{
    if (p->right == nullptr)
        return;
    else
    {
        node* y = p->right;
        if (y->left != nullptr)
        {
            p->right = y->left;
            y->left->parent = p;
        }
        else
            p->right = nullptr;
        if (p->parent != nullptr)
            y->parent = p->parent;
        if (p->parent == nullptr)
            root = y;
        else
        {
            if (p == p->parent->left)
                p->parent->left = y;
            else
                p->parent->right = y;
        }
        y->left = p;
        p->parent = y;
    }
}
void RBtree::rightrotate(node* p)
{
    if (p->left == nullptr)
        return;
    else
    {
        node* y = p->left;
        if (y->right != nullptr)
        {
            p->left = y->right;
            y->right->parent = p;
        }
        else
            p->left = nullptr;
        if (p->parent != nullptr)
            y->parent = p->parent;
        if (p->parent == nullptr)
            root = y;
        else
        {
            if (p == p->parent->left)
                p->parent->left = y;
            else
                p->parent->right = y;
        }
        y->right = p;
        p->parent = y;
    }
}

void RBtree::disp()
{
    display(root);
}
void RBtree::display(node* p)
{
    if (root == nullptr)
    {
        cout << "\nEmpty Tree.";
        return;
    }
    if (p != nullptr)
    {
        cout << *p;
        if (p->left)
        {
            cout << "\n\nLeft:\n";
            display(p->left);
        }
       
        if (p->right)
        {
            cout << "\n\nRight:\n";
            display(p->right);
        }
        
    }
}
void RBtree::search()
{
    if (root == nullptr)
    {
        cout << "\nДерево пусте\n";
        return;
    }
    int x;
    cout << "\n Уведiть ключ для пошуку: ";
    cin >> x;
    node* p = root;
    int found = 0;
    while (p != nullptr && found == 0)
    {
        if (p->key == x)
            found = 1;
        if (found == 0)
        {
            if (p->key < x)
                p = p->right;
            else
                p = p->left;
        }
    }
    if (found == 0)
        cout << "\nКлюч не знайдено.";
    else
    {
        cout << *p;
        
        if (p->parent != nullptr)
        {
            cout << "Колiр батька: ";
            if (p->parent->color == 'r')
                cout << "червоний;\n";
            else
                cout << "чорний;\n";
        }
    }
}

void RBtree::min()
{
    node* p = root;
    while (p->left != nullptr)
    {
        p = p->left;
    }
    cout << " Мiнiмальний елемент дерева: " << p->key << endl;
    cout << " Колiр: ";
    if (p->color == 'r')
        cout << "червоний" << endl;
    else
        cout << "чорний" << endl;
}

int main()
{
	setlocale(LC_ALL,"UKRAINIAN");
	RBtree tree;
	int N, M;
	cout << " Уведiть кiлькiсть ключiв RB дерева: ";
	cin >> N;
    while (N < 1 || N>256)
    {
        cout << "Error; Уведiть коректну кiлькiсть ключiв: ";
        cin >> N;
    }
	cout << "\n Уведiть "<< N << " ключiв: \n";
	for (int i = 0; i < N; i++)
    {
		tree.insert();
	}
    cout << "\n********************************\n";
    tree.disp();
    cout << "\n********************************\n";
    cout << "\n Уведiть кiлькiсть запитiв пошуку: ";
    cin >> M;
    while (M < 1 || M>256)
    {
        cout << "Error; Уведiть коректну кiлькiсть запитi пошуку: ";
        cin >> M;
    }
    cout << endl;
    for (int i = 0; i < M; i++)
    {
        tree.search();
    }

	return 0;
}