// Compulsory 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

		/*  TREES  */
class Node
{
public:
	int data;
	Node* parent;
	vector<Node*>child;


};


Node* CreateTreeNode(int data, Node* parent)
{
    Node* newNode = new Node();

    newNode->data = data;
    newNode->parent = parent;

    if (parent != nullptr)
    {
        parent->child.push_back(newNode);
    }

    return newNode;
}

Node* GetParent(Node* tree)
{
    if (tree !=nullptr)
    {
        return tree->parent;
    }
    
}

void isRoot(Node* tree)
{
    if (tree->parent != nullptr)
    {
        cout << "no its not root!";
    }
    else
    {
        cout << "yes its root";
    }
}


Node* GetRoot(Node* tree)
{
	while(tree->parent != nullptr)
	{
        tree = tree->parent;
	}
    return tree;
}

Node* GetChildren(Node* tree)
{
    //?
    return 0;
}

void isLeaf(Node* tree)
{
    //?
}


void isEmpety(Node* tree)
{
	//?
}

void preorderTraversal(Node* root)
{
    stack<Node*> Stack;

    // 'Preorder'-> contains all the
    // visited nodes
    vector<int> Preorder;

    Stack.push(root);

    while (!Stack.empty()) {
        Node* temp = Stack.top();
        Stack.pop();
        // store the key in preorder vector(visited list)
        Preorder.push_back(temp->data);
        // Push all of the child nodes of temp into
        // the stack from right to left.
        for (int i = temp->child.size() - 1; i >= 0; i--) {
            Stack.push(temp->child[i]);
        }
    }
    for (auto i : Preorder) {
        cout << i << " ";
    }
    cout << endl;

    //DOEST WORK WHY THO :(
}

		/*  Graphs  */
class Edge
{
	
};





int main()
{
    //std::cout << "Hello World!\n";


			/*  TREES */
    Node* Root = CreateTreeNode(1, nullptr);
    Node* FirstChild = CreateTreeNode(2, Root);
    Node* SecondChild = CreateTreeNode(3, Root);
    Node* ThreeChild = CreateTreeNode(42, Root);
    Node* FourthChild = CreateTreeNode(5, SecondChild);
    Node* FifthChild = CreateTreeNode(6, SecondChild);

    isRoot(Root);
    isRoot(FifthChild);
    preorderTraversal(Root);
}
