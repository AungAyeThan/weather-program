#ifndef BST_H
#define BST_H
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

template<class elemType>
struct nodeType
{
    elemType info;
    nodeType<elemType> *lLink;
    nodeType<elemType> *rLink;
};

template <class elemType>
class BST
{
	/**
	 * @class BST
	 * @brief  Contains all the methods to store for BST
	 *
	 * BST method such as search, insert, empty , full, inorder traversal, pre-order traversal, post-order traversal, destroy and print function
	 * insert method is to push the data into the bst
	 * search method is to search the location of array parameter of the data.
	 * inorder method is to get the in order arrangement list 
	 * pre order method is to get pre order arrangement list
	 * post order method is to return the length of the vector
	 *
	 * @author Aung Aye Than
	 * @version 01
	 * @date 1/04/2017
	 *
	 * @author Aung Aye Than
	 * @version 02
	 * @date 5/04/2017 Error checking and adding doxygen comments.
	 *
	 * @bug There aren't any bugs in the data headers. Everything tested out correctly.
	 *
	 */
    public:
		/**
		 * @brief  Default constructor
		 *
		 * Default constructor with initial values and create the bst data with initial capcaity
		 *
		 *
		 * @pre no data is added inside . NULL record
		 * @post Values will vary depanding on the insert method function
		 *
		 */
        BST();


		/**
		 * @brief  search Method
		 *
		 * A method to search the data inside into the vector by taking the value from the user to search
		 *
		 * @param  searchItem - const template parameter to take the input
		 *
		 * @post search result vary according to the user input.
		 *
		 * @return bool
		 */
        bool search(const elemType& searchItem) const;


		/**
		 * @brief  insert Method
		 *
		 * A method to insert the data inside into the vector
		 *
		 * @param  insertItem - const template parameter to take the input
		 *
		 * @return void
		 *
		 */
        void insert(const elemType& insertItem);


		/**
		 * @brief  empty Method
		 *
		 * A method to return true where there is no data inside the bst
		 *
		 * @param  insertItem - const template parameter to take the input
		 *
		 * @return bool
		 */
        bool isEmpty() const;


		/**
		 * @brief  in order traversal Method
		 *
		 * A method to sort the data from the smallest to largest.
		 *
		 * @return void
		 *
		 */
        void inorderTraversal() const;

		/**
		 * @brief  pre order traversal Method
		 *
		 * A method to sort the data as the pre-order ( node, left , right)
		 *
		 * @param  insertItem - const template parameter to take the input
		 *
		 * @return void
		 */
        void preorderTraversal() const;

		/**
		 * @brief  post order traversal Method
		 *
		 * A method to sort the data as the post-order ( left, right, node)
		 *
		 * @return void
		 */
        void postorderTraversal() const;

		/**
		 * @brief  destroy Method
		 *
		 * A method to destroy the bst record.
		 *
		 * @param 
		 * @return void
		 */
        void destroy(nodeType<elemType>* &p) const;

		/**
		 * @brief  print Method
		 *
		 * A method to print the bst as the in order recursive 
		 *
		 * @param outputFile - ofstream type to print into the txt file
		 *
		 * @return void
		 */
		void print(ofstream& outputFile);

    private:
        void inorder(nodeType<elemType> *p) const; // inorder method which take the nodeType parameter
        void preorder(nodeType<elemType> *p) const;// preorder method which take the nodeType parameter
        void postorder(nodeType<elemType> *p) const;// post-order method which take the nodeType parameter
		void printMax(nodeType<elemType> *p, ofstream& outputFile);// print method which take the nodeType parameter
        nodeType<elemType> *root; // root
};

//Implementation, default constructor
template <class elemType>
BST<elemType>::BST()
{
    root = NULL;
}

// insert method
template <class elemType>
void BST<elemType>::insert(const elemType& insertItem)
{
    nodeType<elemType> *current; // point the current address as the pointer
    nodeType<elemType> *trailCurrent = NULL; 
    nodeType<elemType> *newNode; // get the new node 

    newNode = new nodeType<elemType>; // creating the new node template type
    newNode-> info = insertItem; // point out to the insert item
    newNode-> lLink = NULL ; // initialise the left link as the null
    newNode-> rLink = NULL;// initialise the right link as the null

    if(root == NULL) // condition to check whether root is null or not
    {
        root = newNode; // give the root as the new node
    }
    else
    {
        current = root; // get the current address as the current 
        while(current != NULL) //  condition to check the whether current is null or not, to process only when the 
        {
            trailCurrent = current;  
            if(insertItem == current->info)
            {
				return;
            }
            else if(insertItem < current->info)
            {
                current = current->lLink;
            }
            else
            {
                current = current ->rLink;
			}

        }
		if(insertItem < trailCurrent->info)
		{
			   trailCurrent->lLink = newNode;
		}
		else
		{
			   trailCurrent->rLink = newNode;
		}
    }
}


// empty method to check whether the data is empty or not
template <class elemType>
bool BST<elemType>::isEmpty() const
{
    return (root == NULL);
}


// preorder traversal which take the private preorder method
template <class elemType>
void BST<elemType>::preorderTraversal() const
{
    preorder(root);
}


// inorderTraversal which take the private inorder method
template <class elemType>
void BST<elemType>::inorderTraversal() const
{
    inorder(root);
}

// post order method which takes the private post order method
template <class elemType>
void BST<elemType>::postorderTraversal() const
{
    postorder(root);
}


// post order method which takes the private preorder method
template <class elemType>
void BST<elemType>::preorder(nodeType<elemType>* p) const
{
    if(p != NULL)
    {
        cout<< p->info << " ";
        preorder(p->lLink);
        preorder(p->rLink);
    }
}


// post order method which takes the private inorder method
template <class elemType>
void BST<elemType>::inorder(nodeType<elemType>* p) const
{
    if(p != NULL)
    {
        inorder(p->lLink);
        cout<< p->info << " ";
        inorder(p->rLink);
    }
}



// method to do the post order sorting
template <class elemType>
void BST<elemType>::postorder(nodeType<elemType>* p) const
{
    if(p != NULL)
    {
        postorder(p->lLink);
        postorder(p->rLink);
        cout<< p->info << " ";
    }
}


// method to do destory the node
template <class elemType>
void BST<elemType>::destroy(nodeType<elemType>* &p) const
{
    if(p != NULL)
    {
        destroy(p->lLink);
        destroy(p->rLink);
        delete p;
        p = NULL;
    }

}


// method to do the searching with the values
template<class elemType>
bool BST<elemType>::search(const elemType& searchItem) const
{
    nodeType<elemType> *current;
    bool found = false;
    if(root == NULL)
    {
        cout << "Cannot search an empty tree " << endl;
    }
    else
    {
        current = root;
        while(current != NULL && !found) // condition to check whether current is not null or data is avaliable or not
        {
            if(searchItem == current -> info)
            {
                found = true;
            }
            else if(searchItem < current->info)
            {
                current = current->lLink;
            }
            else
            {
                current = current->rLink;
            }
        }
    }
    return found;
}


//print method which will take the private printMax method
template<class elemType>
void BST<elemType>::print (ofstream &outFile)
{
	printMax(root, outFile);
}


// private print max method which will do in order recursive
template<class elemType>
void BST<elemType>::printMax (nodeType<elemType> * p , ofstream &outFile)
{
	if (p!= NULL)
	{
		printMax(p -> lLink, outFile);
		outFile << p ->info <<endl;
		printMax( p->rLink, outFile);
	}
} 
#endif // BST_H
