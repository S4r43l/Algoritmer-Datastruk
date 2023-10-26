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
            
            tree->parent->child.erase(remove(tree->parent->child.begin(), tree->parent->child.end(), tree), tree->parent->child.end());

            //deletes the node
            delete tree;


        }
        else
        {
            cout << "Can't delete the root" << endl << endl;
        }

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



		/*  Graphs - Using Adjacency Matrix  */
class GraphMatrix
{
    struct GraphNodeForMatrix
    {
        string data;
    };

    vector<GraphNodeForMatrix> nodes;

    vector<vector<int>> adjacencyMatrix;


public:

    GraphMatrix(int size) //set the size (number of vertices)
    {
        adjacencyMatrix.assign(size, vector<int>(size, 0));
        nodes.resize(size);  // Resize the "'"nodes" vector to match the size of the graph (Used to store data)
    }

    //insertion

    void addInfoInNodes(string info, int vertex)
    {
        if (vertex >= 0 && vertex < nodes.size())
        {
			nodes[vertex].data = info;
		}
        else
        {
			cout << "invalid vertex" << endl << endl;
		}
    }

    void changeInfoForNodes(string data, int index) //to change the data of a node (info is stored in a vector with the following index as the vertex in the matrix)
    {
        if (index >= 0 && index < nodes.size())
        {
            nodes[index].data = data;
        }
        else
        {
            cout << "Invalid index" << endl << endl;
        }
	}

    void addVertex() //to add a vertex to the graph
    {
        for (int i = 0; i < adjacencyMatrix.size(); i++)
        {
            adjacencyMatrix[i].push_back(0);
        }

        vector<int> temp(adjacencyMatrix.size() + 1, 0);
        adjacencyMatrix.push_back(temp);

        // Add a default empty string for the new vertex.
        nodes.push_back(GraphNodeForMatrix{ "" });

        cout << "Vertex added" << endl << endl;


    }

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

    void deletionOfNode(int vertex) 
    {
        //need to see in the matrix if there is any edges connected to the vertex and set them to 0 (which is no vaule) and then remove from the info vector (nodes)
        if (vertex >= 0 && vertex < adjacencyMatrix.size())
        {
            for (int i = 0; i < adjacencyMatrix.size(); i++)
            {
				adjacencyMatrix[vertex][i] = 0;
				adjacencyMatrix[i][vertex] = 0;
			}
			
            if (vertex >= 0 && vertex < nodes.size())
            {
                changeInfoForNodes("no data/deleted", vertex);
            }
            else
            {
				cout << "Something went wrong" << endl;
			}

		}
        else
        {
			cout << "invalid vertex" << endl << endl;
		}
    }

    //Access functions
    void VertexInfo(int vertex)
    {
        if (vertex >= 0 && vertex < adjacencyMatrix.size())
        {
            cout << "Vertex " << vertex << " Information: " << endl;
            cout << "Edges connected to this vertex:" << endl;

            for (int i = 0; i < adjacencyMatrix.size(); i++)
            {
                if (adjacencyMatrix[vertex][i] != 0)
                {
                    cout << "To vertex " << i << " with weight " << adjacencyMatrix[vertex][i] << endl;
                }
            }

            if (vertex >= 0 && vertex < nodes.size())
            {
                cout << "Data: " << nodes[vertex].data << endl; // Use dot notation to access 'data'.
            }
            else
            {
                cout << "No data" << endl;
            }
        }
        else
        {
            cout << "Invalid vertex" << endl;
        }
        cout << endl;
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
        bool empty = true;
        for (int i = 0; i < adjacencyMatrix.size(); i++)
        {
            for (int j = 0; j < adjacencyMatrix.size(); j++)
            {
                if (adjacencyMatrix[i][j] != 0)
                {
                    empty = false;
                    break;
                }
            }
            if (!empty) {
                break;
            }
        }

        if (empty)
        {
            cout << "The graph is empty" << endl << endl;
        }
        else
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
                if (adjacencyMatrix[current][i] != 0 && !visited[i])
                {
                    queueBFS.push(i);
                    visited[i] = true;
                }
            }
        }
    }
          

    //just to make it easier to see how the graph looks like (displays the matrix)
    void PrintTheMatrix(int size) {
        int i, j;
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};


/*  Graphs - Using List Adjacency   */
class GraphList
{
public:
	
    struct GraphNode
    {
        int data;
        int weight;
        vector<GraphNode*> adjacencyList;
        bool visited = false;
    };
    

    //Create node
    GraphNode* CreateNode(int data, GraphNode* Node, int weight)
    {
		GraphNode* newNode = new GraphNode();

		newNode->data = data;
		newNode->weight = weight;
        

        if (Node != nullptr)
        {
            newNode->adjacencyList.push_back(Node);
            Node->adjacencyList.push_back(newNode);
		}
        return newNode;
	}

 //   void addEdge(int from, int to, int weight) //to add an edge between two vertices
 //   {
 //       if (from >= 0 && from < adjacencyList.size() && to >= 0 && to < adjacencyList.size())
 //       {
	//		adjacencyList[from][to] = weight;
	//	}
 //       else
 //       {
	//		cout << "invalid edge" << endl << endl;
	//	}
	//}

    //void deleteEdge(int from, int to) //to delete an edge between two vertices (between "from" to "to")
    //{
    //    if (from >= 0 && from < adjacencyList.size() && to >= 0 && to < adjacencyList.size())
    //    {

    //    }
    //}

 };

int main()
{
    srand(time(0));
    cout <<  "Tree:" << endl;

			/*  TREE */
    TreeNode t;

    TreeNode* root = t.CreateTreeNode(0, nullptr);
    TreeNode* FirstChild = t.CreateTreeNode(1, root);
    TreeNode* SecondChild = t.CreateTreeNode(2, root);
    TreeNode* ThirdChild = t.CreateTreeNode(3, root);
    TreeNode* FourthChild = t.CreateTreeNode(4, SecondChild);
    TreeNode* FifthChild = t.CreateTreeNode(5, SecondChild);
    TreeNode* Sixth = t.CreateTreeNode(5, FifthChild);

    t.GetChildren(SecondChild); 
    t.GetChildren(FirstChild);
    t.GetChildren(ThirdChild);
    t.GetChildren(FourthChild);
    t.GetChildren(FifthChild);
    t.GetChildren(root);

    t.PreorderTraversal(root);

    t.DeleteNode(SecondChild);

    t.PreorderTraversal(root);
    
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

    cout << endl << "Graph:" << endl;

         /* GRAPH using matrix*/
    int graphSize = 4; //sets amount of start vertixes
    int checknewsize= graphSize;
    GraphMatrix g(graphSize); //makes graph
     
    g.isEmpty();

    //adds 4 edges between 4 vertices
    g.addEdge(0, 1, 2);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 0, 6);

    //adds two more edges between vertices with already a existing edge
    g.addEdge(1, 3, 1);
    g.addEdge(0, 2, 2);

    g.PrintTheMatrix(graphSize); //just to visualize

    g.addInfoInNodes("I am zero data",0);
    g.addInfoInNodes("I am number one data",1);
    g.addInfoInNodes("I am that two", 2);
    g.addInfoInNodes("I am a three", 3);

    g.VertexInfo(0);
    g.VertexInfo(1);
    g.VertexInfo(2);
    g.VertexInfo(3);

    g.VerticesInGraph();
    g.EdgesInGraph();
    
    //does a BSF traversal at 0
    cout << "BFS: " << endl;
    g.BFS(0);
    cout << endl << endl;

  /*  g.deleteEdge(0, 1);
    g.deleteEdge(1, 2);
    g.deleteEdge(2, 3);
    g.deleteEdge(3, 0);
    g.deleteEdge(1, 3);
    g.deleteEdge(0, 2);*/

    //g.GetAdjacent(0);

    g.deletionOfNode(2);

    g.VertexInfo(0);
    g.VertexInfo(1);
    g.VertexInfo(2);
    g.VertexInfo(3);

    g.isEmpty();

    //does a BSF traversal at 0
    cout << "BFS: " << endl;
    g.BFS(0);
    cout << endl << endl;

    g.PrintTheMatrix(graphSize); //just to visualize

    g.addVertex(); //adds a vertex
    checknewsize = checknewsize + 1;

    g.PrintTheMatrix(checknewsize+1); //just to visualize

    		/* Functions to use for Graphs*/
    //Graph g(graphSize);
    //g.addInfoInNodes(Vertix_index); //vertix_index is from 0 to size-1 of the graph (ex. 0-3 for a graph with 4 vertices)
    //g.addEdge(FromVertix, ToVertix, Weight);
    //g.deleteEdge(FromVertix, ToVertix);
    //g.deletionOfNode(Vertix_index);
    //g.VertexInfo(Vertix);
    //g.GetAdjacent(Vertix);
    //g.VerticesInGraph();
    //g.EdgesInGraph();
    //g.size();
    //g.isEmpty();
    //g.BFS(StartVertix);
    //g.displayMatrix(graphSize);

    //adds a vertex:
    /*g.addVertex();
    checknewsize = checknewsize + 1;*/
}
