/*************************************************
 * AlgoExpert Prob: BST Construction
 * !!!! - This program is merely for my own learning - !!!!
 * 
 * Possible Routes:
 * 
 * 
 * My Notes (Inline will have {DO - } on it.):
 * 
 * Big O : 
 *************************************************/

/**************************************************
 * Disclaimer - This is the approach I took for
 * learning, this does not mean this is the only way.
 * Some of These answers might be the same as what algo
 * uses, but you won't get the entire learning by copying
 * answers and not understanding the question. Please
 * help support clement and do the work.
 **************************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST {
    public:
        int value;
        BST *left;
        BST *right;

    BST(int val) {
        value = val;
        left = NULL;
        right = NULL;
    }

    BST &insert(int val) {
        //if the val incoming is less than the current node value
        if (val < value) { //QUESTION - why no concern for larger?
        //LOOK TO SEE WHICH SIDE IS EMPTY

        //LEFT SIDE!
            //check if the left=NULL, if so.....
            if (left == NULL){
                //...nothing is lower, then make a new node which will default left.
                BST *newBST = new BST(val);
                left = newBST;
            }else{
                //put the value at right
                left->insert(val);
            }
        //RIGHT SIDE
            //check if the right=NULL, if so.....
            if (right == NULL){
                //...nothing is lower, then make a new node which will default left.
                BST *newBST = new BST(val);
                right = newBST;
            }else{
                //put the value at right
                right->insert(val);
            }
        }
        return *this;
        }

    bool contains(int val) {
        if (val < value){
            if(left == NULL){
                return false;
            }else{
            return left->contains(val);//recursive back to next val
            }
        }else if(val > value){
            if(right == NULL){
                return false;
            }else{
                return right->contains(val);//recursive for next val
            }
        }
        return true;
    }

    int getMinValue(){
        //check left as that is lower
        if (left == NULL){ //if nothing is there....
            //that is currently your lowest value.
            return value;
        }else{
            return left->getMinValue();//recurse to find lowest
        }
    }

//!!!!!! YOU ARE HERE !!!!!!!!!!!!!!!!!!!!!!!!!
    //push in the current value and the parent
    BST &remove(int val, BST *parent=NULL) {
    //ThingsToDo: Check if on right, check if on left, then
    //if root, you need to traverse the tree to find the smaller value.
        if (val < value){
            //if the left is not empty
            if (left != NULL){
                //move down the left with val and new parent
                left -> remove(val, this);
            }
        }else if(val > value){ //looks like we are heading right
            //if right is not empty
            if (right != NULL){
                //move down the right with val and new parent
                right -> remove(val,this);
            }
        }else{//well it looks like its not a leaf.....
            if (left != NULL && right != NULL){
                value = right->getMinValue(); //QUESTION - Why go right?
                //head right and chase the remove?
                right->remove(value, this);

            //THIS WHOLE BIT CONFUSEDS THE F*CK OUT OF ME    
            }else if(parent == NULL){
            if(left!=NULL){
                value = left->value;
                right = left->right;
                left = left->left;
            }else if(parent == NULL){
                value = right->value;
                right = right->left;
                right = right->right;
            }else{
                //this is a single-node tree; do nothing.
            }
            }else if(parent->left == this){
                parent->left = left != NULL ? left:right; //ternary, YAY I KNOW SOMETHING!
            }else if(parent->right == this){
                parent->right = right != NULL ? left:right; //ternary, YAY I KNOW SOMETHING!
            }
    }
        return *this;
    }
//!!!!!! YOU ARE HERE !!!!!!!!!!!!!!!!!!!!!!!!!
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(){
    

	//Clean end.
	cout << endl;
	return 0;
}
