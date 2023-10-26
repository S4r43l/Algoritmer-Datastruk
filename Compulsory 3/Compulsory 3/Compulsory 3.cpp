// Compulsory 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

		/*  TREES  */
class TreeNode
{
public:
    int data;
	TreeNode* parent;
	vector<TreeNode*>child;

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

    //void InsertRandomNode(int data, TreeNode* tree)
    //{
    //    TreeNode* newNode = CreateTreeNode(data, tree); //create new

    //    int random= rand() % (tree->child.size() + 1); //random number between 0 and the number of children

    //    auto placement = tree->child.begin(); //iterator

    //    for (int i = 0; i < random; ++i) { //inserts the node in a random position
    //        if (placement == tree->child.end()) {

    //            break;
    //        }
    //        ++placement;
    //    }
    //    tree->child.insert(placement, newNode); //inserts the node
    //}

    //Deletion (deletes node + all children and their decendants
    void DeleteNode(TreeNode* tree)
    {
        // Delete the children and their descendants first
        while (!tree->child.empty())
        {
            DeleteNode(tree->child.back());
        }

        if (tree != nullptr && tree->parent != nullptr)
        {
            //removes the node
            tree->parent->child.erase(remove(tree->parent->child.begin(), tree->parent->child.end(), tree), tree->parent->child.end());
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

        cout << tree->data << ",is root" << endl;
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
            cout << "yes, its root" << endl << endl;
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
    void PreorderTraversal(TreeNode* root)
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

};



		/*  Graphs  */
class Graph
{
    vector<vector<int>> adjacencyMatrix;

public:
    Graph(int size) //set the size (number of vertices)
    {
        adjacencyMatrix.assign(size, vector<int>(size, 0));
    }

    //insertion
    void addEdge(int from, int to, int weight) //to add an edge between two vertices
    {
        if (from >= 0 && from < adjacencyMatrix.size() && to >= 0 && to < adjacencyMatrix.size())
        {
            adjacencyMatrix[from][to] = weight;
        }
        else
        {
			cout << "invalid edge" << endl << endl;
		}
    }

    //deletion
    void deleteEdge(int from, int to) //to delete an edge between two vertices (between "from" to "to")
    {
        if (from >= 0 && from < adjacencyMatrix.size() && to >= 0 && to < adjacencyMatrix.size())
        {
			adjacencyMatrix[from][to] = 0; //set the edge to 0 (deletes it)
		}
        else
        {
            cout << "invalid edge" << endl << endl;
        }

	}

    //Access functions
    void VertexInfo() 
    {

    }

    void GetAdjacent(int vertex) //to get the adjacent vertices of a vertex
    {
        if (vertex >= 0 && vertex < adjacencyMatrix.size())
        {
			cout << "Adjacent vertices of " << vertex << ": ";

            for (int i = 0; i < adjacencyMatrix.size(); i++)
            {
                if (adjacencyMatrix[vertex][i] != 0)
                {
					cout << i << " ";
				}
			}
			cout << endl << endl;
		}
        else
        {
			cout << "invalid vertex" << endl << endl;
		}
	}

    void VerticesInGraph() //to get the number of vertices in the graph
    {
        cout << "Number of vertices in graph: " << adjacencyMatrix.size() << endl << endl;
    }

    void EdgesInGraph()
    {
        int edges = 0;

        for (int i = 0; i < adjacencyMatrix.size(); i++)
        {
            for (int j = 0; j < adjacencyMatrix.size(); j++)
            {
                if (adjacencyMatrix[i][j] != 0)
                {
			        edges++;
				}
			}
		}
		cout << "Number of edges in graph: " << edges << endl << endl;
    }

    //Query Functions
    void size() //to get the size of the graph
    {
		cout << "Size of graph: " << adjacencyMatrix.size() << endl << endl;
	}

    void isEmpty() //to check if the graph is empty
    {
        if (adjacencyMatrix.size() == 0)
        {
			cout << "The graph is empty" << endl << endl;
		}
       
        {
			cout << "The graph is not empty" << endl << endl;
		}
	}

    //Traversal
    void BFS(int start) //Breadth First Search
    {
        if (start < 0 || start >= adjacencyMatrix.size())
        {
            cout << "invalid start node" << endl << endl;
            return;
        }

        vector<bool> visited(adjacencyMatrix.size(), false);
        queue<int> queueBFS;

        queueBFS.push(start);
        visited[start] = true;

        while (!queueBFS.empty())
        {
            int current = queueBFS.front();
            queueBFS.pop();

            cout << current << " ";

            for (int i = 0; i < adjacencyMatrix.size(); i++)
            {
                if (adjacencyMatrix[current][i] == 1 && !visited[i])
                {
                    queueBFS.push(i);
                    visited[i] = true;
                }
            }
        }
    }
          
};


int main()
{
    
			/*  TREE */
    TreeNode t;

    TreeNode* root = t.CreateTreeNode(0, nullptr);
    TreeNode* FirstChild = t.CreateTreeNode(1, root);
    TreeNode* SecondChild = t.CreateTreeNode(2, root);
    TreeNode* ThirdChild = t.CreateTreeNode(3, root);
    TreeNode* FourthChild = t.CreateTreeNode(4, SecondChild);
    TreeNode* FifthChild = t.CreateTreeNode(5, SecondChild);

    //t.InsertRandomNode(8, root); 
    t.GetChildren(root); 

    
           /* Functions to use for Trees*/

    //t.GetRoot(INSERTANODE);

    //t.GetChildren(INSERTANODE);
   
    //t.GetParent(INSERTANODE);

    //t.Size(INSERTANODE);

    //t.Depth(INSERTANODE);

    //t.isEmpety(INSERTANODE);

    //t.isRoot(INSERTANODE);

    //t.isLeaf(INSERTANODE)

    //t.DeleteNode(INSETANODE);

    //t.PreorderTraversal(INSERTANODE);

         /* GRAPH*/
    int graphSize = 4;
    Graph g(graphSize);

    //adds 4 edges between 4 vertices
    g.addEdge(0, 1, 2);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 0, 6);

    //adds two more edges between vertices with already a existing edge
    g.addEdge(1, 3, 1);
    g.addEdge(0, 2, 2);

    //does a BSF traversal at 0
    cout << "BFS: " << endl;
    g.BFS(0);
    cout << endl << endl;

}
