#include<iostream>
#include <queue>
using namespace std;
class Node {
public:
	int deger;
	Node* left;
	Node* right;
	Node(int deger) {
		this->deger = deger;
		left = NULL;
		right = NULL;
	}
};
	class binarySearchTree{
	public:
		Node* root;
		binarySearchTree() {
			root = NULL;
		}
		~binarySearchTree()
		{

			deleteAllNodes(root);
		}

		void deleteAllNodes(Node* node)
		{
			if (node == NULL) return;
			if (node->left != NULL)
			{
				deleteAllNodes(node->left);
			}
			if (node->right != NULL)
			{
				deleteAllNodes(node->right);
			}
			delete node;
		}
		bool insertNode(int deger) {
			Node* node = new Node(deger);
			if (root == NULL) {
				root = node;
				return true;
			}
			Node* tmp = root;
			while (true) {
				if (node->deger == tmp->deger)
				{
					cout << "hali hazirda olan kod eklenmeye calisiliyor!" << endl;
					return false;
				}
				if (node->deger < tmp->deger) {
					if (tmp->left == NULL) {
						tmp->left = node;
						return true;
					}
					tmp = tmp->left;
					
				
				}
				else {
					if (tmp->right == NULL)
					{
						tmp->right = node;
						return true;
					}
					tmp = tmp->right;

				
				}
			}
		}
		void DFSPreOrderSearchPrintAllNodes(Node* node)
		{
			cout << node->deger << " , ";
			if (node->left != NULL)
			{
				DFSPreOrderSearchPrintAllNodes(node->left);
			}
			if (node->right != NULL)
			{
				DFSPreOrderSearchPrintAllNodes(node->right);
			}



		}
		Node* DFSPreOrderSearchAra(Node* node,int arananDeger)
		{
			if (node == NULL || node->deger == arananDeger)
			{
				return node;
			}
			if (arananDeger < node->deger)
			{
				return DFSPreOrderSearchAra(node->left, arananDeger);

			}
			else 
			{
				return DFSPreOrderSearchAra(node->right, arananDeger);
			}

			


		}
		void DFSPostOrderSearchPrintAllNodes(Node* node)
		{
			
				if (node->left != NULL)
				{
					DFSPostOrderSearchPrintAllNodes(node->left);
				}
				if (node->right != NULL)
				{
					DFSPostOrderSearchPrintAllNodes(node->right);
				}

				cout << node->deger << " , ";

			
			
		}
		void DFSInOrderSearchPrintAllNodes(Node* node)
		{

			if (node->left != NULL)
			{
				DFSInOrderSearchPrintAllNodes(node->left);
				
			}
			cout << node->deger << " , ";
			if (node->right != NULL)
			{
				DFSInOrderSearchPrintAllNodes(node->right);
			}

			
			
		}
		void BreadthFirstSearch()
		{
			queue<Node*> queue1;
			queue1.push(root);
			while (queue1.size() > 0)
			{
				Node* node = queue1.front();
				queue1.pop();
				cout << node->deger <<" , " ;
				if (node->left != NULL)
				{
					queue1.push(node->left);
				}
				if (node->right != NULL)
				{
					queue1.push(node->right);
				}
			}
			cout << endl;
		}
	};

	int main() {
		binarySearchTree* bst = new binarySearchTree();
		// 52,27,15,30,78,65,53
		bst->insertNode(52);
		bst->insertNode(27);
		bst->insertNode(15);
		bst->insertNode(30);
		bst->insertNode(78);
		bst->insertNode(65);
		bst->insertNode(53);
		
		
		cout << endl << "DFS Post Order " << endl; 
		
		bst->DFSPostOrderSearchPrintAllNodes(bst->root); // 15 , 30 , 27 , 53 , 65 , 78 , 52 ,
		cout << endl << "DFS In Order " << endl;

		bst->DFSInOrderSearchPrintAllNodes(bst->root); // 15 ,27 , 30 , 52 , 53 , 65 , 78 ,
		cout<< endl << "BFS" << endl;
		
		bst->BreadthFirstSearch(); //52 , 27 , 78 , 15 , 30 , 65 , 53 ,
		delete bst;
	}
