#ifndef GTREE_H_
#define GTREE_H_
#include <iostream>
#include "TreeNode.h"
using namespace std;

template <class T>
class GTree {
private:
	TreeNode<T>* root;
	int numOfNodes(TreeNode<T> *root);
    void clear(TreeNode<T> *temp);
    TreeNode<T>* search(TreeNode<T>* root, T key) const ; //find element
    TreeNode<T>* min(TreeNode<T>* temp) const; //go to minimum
    TreeNode<T>* max(TreeNode<T>* root) const; // go to maximum
    void print(TreeNode<T> *temp) const;
    void remove(T key,TreeNode<T>* node);
    TreeNode<T> * insert(T key, TreeNode<T> *temp);

public:
	GTree();  //  default c'tor
	GTree(const GTree<T>& rhs);   //  copy c'tor
	GTree<T>& operator=(const GTree<T>& rhs); //  =operator
	void insert(T key); //add element
	void clear(); //clear tree
    TreeNode<T>* search(T key) const;
    TreeNode<T>* min() const; //go to minimum
    TreeNode<T>* max() const; // go to maximum
    void remove(T key);
	int whatIsTheNumOfNodes();
	virtual ~GTree(); //d'tor
	void print() const;
    T getPlayerById(int id, TreeNode<T> *temp) const;
    T getPlayerById(int id) const;
    TreeNode<T> *getRoot() const;
};
template<class T>
void GTree<T>::insert(T key){
    root = insert(key, root);
}

template<class T>
GTree<T>::GTree() : root(NULL){
}

template<class T>
void GTree<T>::clear() {
    clear(root);
	if(!root){ // nothing to clear
		return;
	}

	delete root;
}

template <class T>
TreeNode<T>* GTree<T>::search(TreeNode<T> *root, T key) const {
	if(key==root->getKey())
		return this;
	if(root->getKey() < key)
		return search(root->getRightChild(),key);
	else if (root->getKey() > key) {
        return search(root->getLeftChild(), key);
    } else {
	    return NULL;
	}
}


template <class T>
TreeNode<T>* GTree<T>::min(TreeNode<T>* temp)const{
	if(temp==NULL){
		return NULL;
	}
	if(temp->getLeftChild()==NULL){
		return temp;
	}
	return min(temp->getLeftChild());
}



template <class T>
TreeNode<T>* GTree<T>::max(TreeNode<T>* root) const{
	if(root==NULL){
		return NULL;
	}
	if(root->getRightChild()==NULL){
		return root;
	}
	return max(root->getRightChild());
}
template<class T>
int GTree<T>::numOfNodes(TreeNode<T>* root){
	if (!root)
		return 0;
	return 1+numOfNodes(root->getLeftChild())+numOfNodes(root->getRightChild());
}

template <class T>
int GTree<T>::whatIsTheNumOfNodes(){
	return numOfNodes(root);
}

template <class T>
void GTree<T>::print(TreeNode<T>* temp)const{
	if(temp==NULL) //nothing to print
		return;
	print(temp->getLeftChild());
	std::cout << *(temp->getKey()) << std::endl;
	print(temp->getRightChild());
}

template <class T>
void GTree<T>::remove(T key, TreeNode<T>* node){
	if (node==NULL)
		return;

	if (*key < *(node->getKey())) {
        remove(key,node->getLeftChild());
	} else if (*key > *(node->getKey())) {
        remove(key,node->getRightChild());
	} else {
		if (node->isLeaf()) {
		    if (node->getParent() != NULL) {
                if (node->getParent()->getLeftChild() == node) {
                    node->getParent()->setLeftChild(NULL);
                } else {
                    node->getParent()->setRightChild(NULL);
                }
		    } else {
		        root = NULL; //if leaf & no parent, we are root
		    }
            delete node;
		} else if (node->getRightChild() && !node->getLeftChild()){
			if (node->getParent()->getLeftChild()==node){
				node->getParent()->setLeftChild(node->getRightChild());
			} else {
				node->getParent()->setRightChild(node->getRightChild());
			}
			node->getRightChild()->setParent(node->getParent());
			delete node;
		} else if (!node->getRightChild()&& node->getLeftChild()){
			if (node->getParent()->getLeftChild()==node){
				node->getParent()->setLeftChild(node->getLeftChild());
			} else{
				node->getParent()->setRightChild(node->getLeftChild());
			}
			node->getLeftChild()->setParent(node->getParent());
			delete node;
		} else {
			TreeNode<T> *successor = min(node->getRightChild());
			T temp = successor->getKey();
			successor->setKey(node->getKey());
			node->setKey(temp);
			remove(key, node->getRightChild());
		}
	}
}

template<class T>
TreeNode<T>* GTree<T>::insert(const T key, TreeNode<T> *temp) {
    if (!temp) {
    	return new TreeNode<T>(key);
    }
    if (*(key) > *(temp->getKey())) {
    	temp->setRightChild(insert(key, temp->getRightChild()));
    	temp->getRightChild()->setParent(temp);
    } else if (*key < *(temp->getKey())) {
        temp->setLeftChild(insert(key, temp->getLeftChild()));
        temp->getLeftChild()->setParent(temp);
    } else {
        delete temp->getKey();
        temp->setKey(key);
    }
    return temp;
}

template<class T>
void GTree<T>::clear(TreeNode<T> *temp) {
    if (!temp) {
        return;
    }
    if (temp->isLeaf()) {
        delete temp;
        return;
    }
    clear(temp->getLeftChild());
    clear(temp->getRightChild());
    delete temp;
}

template<class T>
TreeNode<T> *GTree<T>::search(T key) const {
    return search(root, key);
}

template<class T>
TreeNode<T> *GTree<T>::min() const {
    return min(root);
}

template<class T>
TreeNode<T> *GTree<T>::max() const {
    return max(root);
}

template<class T>
void GTree<T>::print() const{
    print(root);
}

template<class T>
void GTree<T>::remove(T key) {
    remove(key, root);
}

template<class T>
GTree<T>::~GTree() {clear(root);}

template<class T>
T GTree<T>::getPlayerById(int id) const {
    return getPlayerById(id, root);
}

template<class T>
T GTree<T>::getPlayerById(int id, TreeNode<T> *temp) const {
    if (temp == NULL) {
        return NULL;
    }
    if (static_cast<Player*>(temp->getKey())->getId() == id) {
        return temp->getKey();
    }
    if (id > static_cast<Player*>(temp->getKey())->getId()) {
        return getPlayerById(id, temp->getRightChild());
    }
    return getPlayerById(id, temp->getLeftChild());
}

template<class T>
GTree<T>::GTree(const GTree<T> &rhs) {
    root = rhs.getRoot(); // only shallow copy is supported
}

template<class T>
TreeNode<T> *GTree<T>::getRoot() const {
    return root;
}

template<class T>
GTree<T> &GTree<T>::operator=(const GTree<T> &rhs) {
    if (&rhs == this) {
        return *this;
    }
    root = rhs.getRoot();
    return *this;
}


#endif /* GTREE_H_ */
