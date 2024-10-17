#include <iostream>
#include <stdlib.h>
#include <assert.h>

using namespace std;

template <class dataType>
class BinaryTree {
      public:
             BinaryTree( );
             bool isEmpty ();
             dataType getData();
             void insert (const dataType & d);
             BinaryTree * left();
             BinaryTree * right();
             void makeLeft (BinaryTree * T1);
             void makeRight (BinaryTree *T1);
       private:
              bool nullTree;
              dataType treeData;
              BinaryTree * leftTree;
              BinaryTree * rightTree;
};

template <class dataType>   //constructor
BinaryTree<dataType>::BinaryTree()
{
     nullTree = true;
     leftTree = NULL;
     rightTree = NULL;
}

template <class dataType>
bool BinaryTree<dataType>::isEmpty()
{
     return nullTree;
}

template <class dataType>
dataType BinaryTree<dataType>::getData()
{
     assert (!isEmpty());
     return treeData;

}

template <class dataType>
void BinaryTree <dataType>::insert (const dataType & d)
{
     //create empty children and insert data
     treeData = d;
     if (nullTree) {
        nullTree = false;
        leftTree = new BinaryTree;
        rightTree = new BinaryTree;
     }
}

template <class dataType>
BinaryTree <dataType> * BinaryTree<dataType> :: left()
{
           assert (!isEmpty());
           return leftTree;
}
template <class dataType>
BinaryTree <dataType> * BinaryTree<dataType> :: right()
{
           assert (!isEmpty());
           return rightTree;
}

template <class dataType>
void BinaryTree <dataType> :: makeLeft (BinaryTree * T1)
{
     assert (!isEmpty());
     //assert (left()->isEmpty());
     leftTree = T1;
}

template <class dataType>
void BinaryTree <dataType> :: makeRight (BinaryTree * T1)
{
     assert (!isEmpty());
     //assert (right()->isEmpty());
     rightTree = T1;
}
template <class dataType>
void preOrderTraverse (BinaryTree <dataType> * bt)
{
     if (!bt->isEmpty())
     {
        //visit tree
        cout << bt->getData() <<"\t";
        //traverse left child
        preOrderTraverse (bt->left());
        //traverse right child
        preOrderTraverse (bt->right());
     }
}

template <class dataType>
void inOrderTraverse (BinaryTree <dataType> * bt)
{
     if (!bt->isEmpty())
     {
        //traverse left child
        inOrderTraverse (bt->left());
        //visit tree
        cout << bt->getData() <<"\t";
        //traverse right child
        inOrderTraverse (bt->right());
     }
}
template <class dataType>
void postOrderTraverse (BinaryTree <dataType> * bt)
{
     if (!bt->isEmpty())
     {
        //traverse left child
        postOrderTraverse (bt->left());
        //traverse right child
        postOrderTraverse (bt->right());
        //visit tree
        cout << bt->getData() <<"\t";
     }
}

template <class dataType>
void postOrderFree(BinaryTree <dataType> * bt)
{
  //insert post order free code here!!!
}

 
template <class dataType>
void swapSubTrees ( BinaryTree <dataType> * bt )
{
     //insert swpsubtrees code here
}

 
int main()
{
	typedef BinaryTree <char> charTree;
	typedef charTree * charTreePtr;
	//Create left subtree ( rooted at B )
	//Create B's left subtree
	charTreePtr bt1 = new charTree;
	bt1->insert ( 'D' );
	//Create B's right subtree
	charTreePtr bt2 = new charTree;
	bt2->insert ( 'E' );

	//Create node containing B, and link up to subtrees
	charTreePtr bt3 = new charTree;
	bt3->insert ( 'B' );
	bt3->makeLeft ( bt1 );
	bt3->makeRight ( bt2 );
	//** done creating left subtree

	//Create right subtree
	//Create C's right subtree
	charTreePtr bt4 = new charTree;
	bt4->insert ( 'F' );
	//Create node containing C and link up its right subtree;
	charTreePtr bt5 = new charTree;
	bt5->insert ( 'C' );
	bt5->makeRight ( bt4 );
	//** done creating right subtree

	//Create the root of the tree and link together
	charTreePtr bt6 = new charTree;
	bt6->insert('A');
	bt6->makeLeft ( bt3 );
	bt6->makeRight ( bt5 );
	//print out the root
	cout<< "Root containts: " <<
	bt6->getData( ) <<endl;
	//print out the left subtree
	cout <<"Left subtree root: " <<
	bt6->left( ) ->getData( ) <<endl;

	//print out the right subtree
	cout <<"Right subtree root: "
	<< bt6->right( )->getData( ) <<endl;
	//print out left most child in tree
	cout <<"Left most child is: "<<
	bt6->left( )->left( )->getData( ) <<endl;
	//print out right most child in tree
	cout <<"Left most child is: "<<
	bt6->right( )->right( )->getData( ) <<endl;

    cout<<"\nInOrderTraverse"<<endl;
	inOrderTraverse(bt6);
	cout<<"\n\nPreOrderTraverse"<<endl;
	preOrderTraverse(bt6);
	cout<<"\n\nPostOrderTraverse"<<endl;
	postOrderTraverse(bt6);



    system("PAUSE");
    return 0;
}
