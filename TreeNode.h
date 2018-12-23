#ifndef TREENODE_H_
#define TREENODE_H_

template<class T>
class TreeNode{
public:
	TreeNode():parent(0), leftChild(0),rightChild(0),key(T()){} //default c'tor
	TreeNode(T key): parent(0), leftChild(0),rightChild(0){ //c'tor
		this->key=key;
	}
	TreeNode(const TreeNode<T>& rhs){ // copy c'tor
		if (rhs.getLeftChild()){
			leftChild = new TreeNode<T>(*rhs.getLeftChild());
			leftChild->setParent(this);
		}
		if(rhs.getRightChild()){
			rightChild = new TreeNode<T>(*rhs.getRightChild());
			rightChild->setParent(this);
		}
		setParent(NULL);
		key=rhs.key;
	}

	TreeNode<T>& operator=(const TreeNode<T>& rhs){ //TODO: finish function
		if (this != &rhs){
		    return *this;
		}
		return *this;
	}
	void setKey(T key){this->key=key;}

	void setLeftChild(TreeNode<T> *leftChild){
		this->leftChild=leftChild;
	}
	void setRightChild(TreeNode<T> *rightChild){
		this->rightChild=rightChild;
	}
	void setParent(TreeNode<T> *parent){
		this->parent=parent;}
    bool isLeaf() {
        return leftChild == NULL && rightChild == NULL;
    }
	TreeNode<T> * getLeftChild()const{return leftChild;}			//get left
	TreeNode<T> * getRightChild()const{return rightChild;} 		//get right
	TreeNode<T> * getParent()const{return parent;} 		// get parent
	T getKey()const {return key;}			//get key data
	~TreeNode(){} //d'tor
private:
    TreeNode<T> *parent, *leftChild, *rightChild; // pointers to left and right children, and to parent of current node
    T key; // value of node. pointer instead of a T type object allows inherited objects to be a part of the tree
};




#endif /* TREENODE_H_ */
