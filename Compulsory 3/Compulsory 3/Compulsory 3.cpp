// Compulsory 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

		/*  TREES  */
class TreeNode
{
public:
    int data;
	TreeNode* parent;
	vector<TreeNode*>child;
};

//Insertion
TreeNode* CreateTreeNode(int data, TreeNode* parent)
{
    TreeNode* newNode = new TreeNode();

    newNode->data = data;
    newNode->parent = parent;

    if (parent != nullptr)
    {
        parent->child.push_back(newNode);
    }

    return newNode;
}

//Deletion (deletes node + all children and their decendants
void deleteNode(TreeNode* tree)
{
        // Delete the children and their descendants first
    while (!tree->child.empty())
    {
        deleteNode(tree->child.back());
    }

    if (tree != nullptr && tree->parent != nullptr)
    {
        //removes the node
		tree->parent->child.erase(remove(tree->parent->child.begin(),tree->parent->child.end(), tree), tree->parent->child.end());
        //deletes the node
        delete tree;

        
	}
    else
    {
		cout << "Can't delete the root" << endl << endl;
	}
	cout << endl;
}


//Access functions
TreeNode* GetRoot(TreeNode* tree)
{
    while (tree->parent != nullptr)
    {
        tree = tree->parent;
    }

    cout  << tree->data << ",is root" << endl;
    cout << endl;

    return tree;
}

TreeNode* GetParent(TreeNode* tree)
{
    if (tree->parent != nullptr)
    {
        tree = tree->parent;
        cout << tree->data << " is the parent" << endl << endl;
        return tree->parent;
    }
    else
    {
		cout << "Doesn't have a parent" << endl << endl;
        return nullptr;
	}
    cout << endl;
}

void GetChildren(TreeNode* tree)
{
   
    if (tree->child.empty())
    {
        cout << "It has no children" << endl;
       
    }

    else
    {
        cout << "Children: ";
        for (TreeNode* child : tree->child)
        {
            cout << child->data << " ";
        }
        cout << endl;
    }
    cout << endl;
    
}

//Query Functions
void Size(TreeNode* tree)
{
    int size = 0;
    stack<TreeNode*> Stack;

    Stack.push(tree);

    while (!Stack.empty()) 
    {
		TreeNode* temp = Stack.top();
		Stack.pop();

		size++;

        for (int i = temp->child.size() - 1; i >= 0; i--)
        {
			Stack.push(temp->child[i]);
		}
	}
    cout << "Size of tree: " << size << endl << endl;

}

void Depth(TreeNode* tree)
{
	int depth = 1;
    while (tree->parent != nullptr)
    {
		tree = tree->parent;
		depth++;
	}
    	cout << "Depth of tree: " << depth << endl << endl;
}

void isEmpety(TreeNode* tree)
{
    if (tree->child.empty())
    {
        cout << "it is empty" << endl << endl;
    }
    else
    {
        cout << "it is not empty" << endl << endl;
    }
}

void isRoot(TreeNode* tree)
{
    if (tree->parent != nullptr)
    {
        cout << "no, its not root!" << endl << endl;
    }
    else
    {
        cout << "yes, its root" << endl <<endl;
    }
}

void isLeaf(TreeNode* tree)
{
    if (tree->child.size() == 0)
    {
		cout << "yes, its leaf" << endl << endl;
	}
    else
    {
		cout << "no, its not leaf" << endl << endl;
	}

}

//Traversal
void preorderTraversal(TreeNode* root)
{
    //DLR - data, left, right (preorder)
    stack<TreeNode*> Stack;

    Stack.push(root);

    while (!Stack.empty()) {

        TreeNode* temp = Stack.top();
        Stack.pop();

        cout << temp->data << " ";

        for (int i = temp->child.size() - 1; i >= 0; i--) 
        {
            Stack.push(temp->child[i]);
        }

    }


    cout << endl;
}

		/*  Graphs  */
class Graph
{
	
          
};



int main()
{

			/*  TREES */
    TreeNode* Root = CreateTreeNode(1, nullptr);
    TreeNode* FirstChild = CreateTreeNode(2, Root);
    TreeNode* SecondChild = CreateTreeNode(3, Root);
    TreeNode* ThirdChild = CreateTreeNode(42, Root);
    TreeNode* FourthChild = CreateTreeNode(5, SecondChild);
    TreeNode* FifthChild = CreateTreeNode(6, SecondChild);

    
           /* Functions to use for Trees*/

    //GetRoot(INSERTANODE);

    //GetChildren(INSERTANODE);
   
    //GetParent(INSERTANODE);

    //Size(INSERTANODE);

    //Depth(INSERTANODE);

    //isEmpety(INSERTANODE);

    //isRoot(INSERTANODE);

    //isLeaf(INSERTANODE)

    //deleteNode(INSETANODE);

    //preorderTraversal(INSERTANODE);

         /* Functions to use for Graphs*/


}
