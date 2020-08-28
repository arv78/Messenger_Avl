#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <string>
#define NOMINMAX // i used this because i had a problem in the next header for min and max function
#include <windows.h> // and used this for changing the color
#include <algorithm> // max 
#include <fstream>
#include <math.h>
#include <queue> // friend requests
#define N 1000

struct message {
	int p = 1; // priority
	std::string us1; // username
	std::string text;
};
// starting to build the heap for messages
// instead of a normal array i used a vector to be able to insert and remove easily to finally make the heap out of it
class heap {
private:
	std::vector<message> heapnode;
public:
	heap() : heapnode() {
	}
	// this is priority queue !! 
	std::vector<message> insert_heap(message m) {

		if (heapnode.size() == 0) {
			heapnode.push_back(m);
			return heapnode;
		}
		else {
			heapnode.push_back(m);
			//updating the size each time
			int size = heapnode.size();
			for (int i3 = size - 1; i3 > 0; i3--) {
			if (heapnode[i3].p > heapnode[(i3) / 2].p) {
			message temp = heapnode[i3];
			heapnode[i3] = heapnode[(i3) / 2];
			heapnode[(i3) / 2] = temp;
			}
			}
			return heapnode;
			/*for (int i = 0; i < heapnode.size() - 1; i++)
				for (int j = i + 1; j < heapnode.size(); j++) {
					if (heapnode[i].p < heapnode[j].p)
						std::swap(heapnode[i], heapnode[j]);
				}
			return heapnode;*/
		}
	}
	bool not_empty() {
		if (heapnode.size() > 0)
			return true;
		else
			return false;
	}
	int num() {
		int count = 0;
		for (int i = 0; i < heapnode.size(); i++)
			count++;
		return count;
	}
	void dis_heap() {
		std::string bullshit;
		std::cout << "the messages are: " << std::endl;
		std::cout << heapnode.size() << std::endl;
		for (int g = 0; g < heapnode.size(); g++) {
			std::cout << heapnode[g].us1 << " : " << heapnode[g].text << std::endl;
		}
	}
	void delete_heap() {
		heapnode.erase(heapnode.begin(), heapnode.begin() + heapnode.size());
		std::cout << "****" << std::endl;
		std::cout << heapnode.size() << std::endl;
	}
	int search_heap(std::string a) {
		for (int i = 0; i < heapnode.size(); i++) {
			if (a == heapnode[i].text) {
				return i;
			}
		}
		return -1;
	}
	std::vector<message> get_vec() {
		return heapnode;
	}
	void change(int a, std::string b) {
		heapnode[a].text = b;
	}
};

class friend_req {
private:
	std::queue<std::string> myq; // for the friend requests
public:
	std::queue<std::string> push(std::string a) {
		myq.push(a);
		return myq;
	}
	std::string get_front() {
		return myq.front();
	}
	std::queue<std::string> pop() {
		myq.pop();
		return myq;
	}
	bool empty() {
		if (myq.empty() == true)
			return true;
		else
			return false;
	}
};
// the very first struct for each user
struct user {
	std::string name;
	std::string surname;
	std::string cn; // which stands for cellphone number
	std::string username;
	int pri = 1; // priority
	std::string password;
	heap f; // for the heaps (heap_node)
	friend_req my;
	std::vector<std::string> fl; // friend list with their usernames
	std::vector<std::string> elegants;
	// a constructor
	user() {
		pri = 1;
	}
	void in_file(std::ofstream& a) {
		/*fprintf(out2, "%s %s %s %d %s %s\n", name.c_str(), surname.c_str(), cn.c_str(), pri, username.c_str(), password.c_str());*/
		a << name << " " << surname << " " << cn << " " << pri << " " << username << " " << password << " " << std::endl;
	}
};

// starting the AVL tree (which save the users for us)
struct avlnode {
	user user1;
	// and there should be a queue of friend requests
	avlnode* left;
	avlnode* right;
	int height;
	avlnode* parent;
};
class  AVL {
	avlnode* root;
public:
	AVL() {
		root = NULL;
	}
	// in each level we should gain the height 
	int up_height(avlnode* root) {
		if (root == NULL)
			return -1;
		return root->height;
	}
	// updating the balance with using the height is vital
	int up_balance(avlnode* root) {
		if (root == NULL)
			return 0;
		return up_height(root->left) - up_height(root->right);
	}

	// for showing the whole AVL for Admin :) that it's me haha!!
	void preorder(avlnode* root) {
		if (root != NULL) {
			std::cout << root->user1.username << std::endl;
			preorder(root->left);
			preorder(root->right);
		}
	}
	void inorder(avlnode* root) {
		if (root != NULL) {
			preorder(root->left);
			std::cout << root->user1.username << std::endl;
			preorder(root->right);
		}
	}
	void postorder(avlnode* root) {
		if (root != NULL) {
			preorder(root->left);
			preorder(root->right);
			std::cout << root->user1.username << std::endl;
		}
	}

	// i need to traverse the AVL to search for users so:
	bool check_trav(avlnode* root, std::string a, std::string b) {
		if (root == NULL)
			return false;
		if (root->user1.username == a && root->user1.password == b)
			return true;
		if (root->user1.username >= a)
			return check_trav(root->left, a, b);
		else
			return check_trav(root->right, a, b);
	}
	//sometimes i need to check only the username so:
	bool check_trav2(avlnode* root, std::string a) {
		if (root == NULL)
			return false;
		if (root->user1.username == a) {
			return true;
		}
		if (root->user1.username >= a) {
			return check_trav2(root->left, a);
		}
		else {
			return check_trav2(root->right, a);
		}
	}
	// i need to return the infomation of the username which i found
	user check_trav3(avlnode* root, std::string a, std::string b) {
		if (root->user1.username == a && root->user1.password == b)
			return root->user1;
		if (root->user1.username >= a)
			return check_trav3(root->left, a, b);
		else
			return check_trav3(root->right, a, b);
	}
	// only username but returns user
	user check_trav33(avlnode* root, std::string a) {
		if (root->user1.username == a)
			return root->user1;
		if (root->user1.username >= a)
			return check_trav33(root->left, a);
		else
			return check_trav33(root->right, a);
	}
	//sometimes i only need to check the cellphone number so:
	bool inorder_trav4(avlnode* root, std::string a) {
		if (root != NULL) {
			inorder_trav4(root->left, a);
			if (root->user1.cn == a)
				return true;
			return false;
			inorder_trav4(root->right, a);
		}
	}
	// just check the username and return the user
	user* check_trav5(avlnode* root, std::string a) {
		if (root == NULL) {
			return NULL;
		}
		if (root->user1.username == a)
			return &root->user1;
		if (root->user1.username >= a)
			return check_trav5(root->left, a);
		else
			return check_trav5(root->right, a);
	}
	// this is for traversing the AVL for admin
	void check_trav6(avlnode* root) {
		if (root != NULL) {
			check_trav6(root->left);
			std::cout << root->user1.username << std::endl;
			check_trav6(root->right);
		}
	}
	// only cellphone -> user 
	user inorder_trav7(avlnode* root, std::string a) {
		if (root != NULL) {
			if (root->user1.username == a)
				return root->user1;
			if (root->user1.username >= a)
				return inorder_trav7(root->left, a);
			else
				return inorder_trav7(root->right, a);
		}
	}
	// this when we need to check in vector
	bool check_vec1(std::vector<std::string> a, std::string b) {
		for (int i = 0; i < a.size(); i++) {
			if (b == a[i])
				return true;
		}
		return false;
	}
	// this when we want to check the elegants
	bool check_elegant1(std::string a, user* b) {
		for (int i = 0; i < b->elegants.size(); i++) {
			if (a == b->elegants[i])
				return true;
		}
		return false;
	}
	// for cellphone
	bool check_cell(avlnode* root, std::string a) {
		if (root != NULL) {
			if (root->user1.cn == a)
				return true;
			if (check_cell(root->left, a)) return true;
			if (check_cell(root->right, a)) return true;
		}
		return false;
	}
	user* check_cell2(avlnode* root, std::string a) {
		if (root != NULL) {
			if (root->user1.cn == a)
				return &root->user1;
			user* temp = check_cell2(root->left, a);
			if (temp != NULL) {
				return temp;
			}
			user* temp2 = check_cell2(root->right, a);
			if (temp2 != NULL) {
				return temp2;
			}
		}
		return NULL;
	}
	// now it's the time for rotations
	avlnode* rightrot(avlnode* root) {
		avlnode* p = root->parent;
		avlnode* root_next = root->left;
		root->left = root_next->right;
		if (root_next->right != NULL)
			root_next->right->parent = root;
		root_next->right = root;
		root->parent = root_next;
		root_next->parent = p;
		// update the parent with the new root
		if (p != NULL) {
			// check if the root is the left/right chid of the parent so the new root should be also 
			if (p->left == root)
				p->left = root_next;
			else
				p->right = root_next;
		}
		// here i'm updating the heights based the new shape
		// if u draw a sample you'll understand
		root->height = std::max(up_height(root->left), up_height(root->right)) + 1;
		root_next->height = std::max(up_height(root->left), root->height);
		return root_next;
	}
	avlnode* leftrot(avlnode* root) {
		avlnode* p = root->parent;
		avlnode* root_next = root->right;
		root->right = root_next->left;
		if (root_next->left != NULL)
			root_next->left->parent = root;
		root_next->left = root;
		root->parent = root_next;
		root_next->parent = p;
		// update the parent with the new root
		if (p != NULL) {
			if (p->left == root)
				p->left = root_next;
			else
				p->right = root_next;
		}
		// like above :)
		root->height = std::max(up_height(root->left), up_height(root->right)) + 1;
		root_next->height = std::max(up_height(root->right), root->height);
		return root_next;
	}
	// when the shape is left -> right 
	avlnode* Lr(avlnode* root) {
		root->left = leftrot(root->left);
		return rightrot(root);
	}
	// vise versa
	avlnode* Rl(avlnode* root) {
		root->right = rightrot(root->right);
		return leftrot(root);
	}
	void pre_file(avlnode* root, std::ofstream& a) {
		if (root != NULL) {
			avlnode* tmp = root;
			tmp->user1.in_file(a);
			pre_file(root->left, a);
			pre_file(root->right, a);
		}
	}

	// find the min for successor
	avlnode* Min(avlnode* root) {
		if (root == NULL)
			return NULL;
		avlnode* tempi = root;
		while (tempi->left != NULL)
			tempi = tempi->left;
		return tempi;
	}
	// actually we don't need successor as always there is a right sub_tree so min is sufficient
	avlnode* successor(avlnode* x) {
		if (x->right) {
			avlnode* s = Min(x->right);
			return s;
		}
		else {
			avlnode* y = x->parent;
			while (y != NULL && x == y->right) {
				x = y;
				y = y->parent;
			}
			return y;
		}
	}
	// i inserted the users in the AVL based on their username because i couldn't do it with the priority numbers and it's more logical

	avlnode* insert_user(avlnode* root, user a) {
		// if it's the first user
		if (root == NULL) {
			root = new avlnode();
			root->user1 = a;
			root->left = root->right = root->parent = NULL;
			root->height = 0;
		}
		// based on the username
		else if (a.username <= root->user1.username) {
			root->left = insert_user(root->left, a);
			if (up_balance(root) == 2) {
				if (a.username < root->left->user1.username) {
					// so in this case all of them are left and so a right rotation is needed
					root = rightrot(root);
				}
				else {
					// it's left -> right 
					root = Lr(root);
				}
			}
		}
		else if (a.username > root->user1.username) {
			root->right = insert_user(root->right, a);
			if (up_balance(root) == -2) {
				if (a.username > root->right->user1.username) {
					// so in this case all of them are right and so a left rotation is needed
					root = leftrot(root);
				}
				else {
					// it's right -> left 
					root = Rl(root);
				}
			}
		}
		// and at the end like always that every function that we do update the height as well
		root->height = std::max(up_height(root->left), up_height(root->right)) + 1;
		return root;
	}
	avlnode* delete_user(avlnode* root, user* a) {
		if (root == NULL)
			return root;
		if (a->username < root->user1.username)
			root->left = delete_user(root->left, a);
		else if (a->username > root->user1.username)
			root->right = delete_user(root->right, a);
		else {
			// for both 1 and 0 child
			if (root->left == NULL || root->right == NULL) {
				avlnode* tempuser;
				if (root->left != NULL) {
					tempuser = root->left;
				}
				else
					tempuser = root->right;
				// if there is no child 
				if (tempuser == NULL) {
					tempuser = root;
					root = NULL;
				}
				// 1 child
				else {
					std::swap(root, tempuser);
				}

				// in both cases at last you should delete the tempuser
				delete tempuser;
			}
			else {
				// two children -> min -> root -> delete successor
				avlnode* tempuser = Min(root->right);
				// place the successor to the root to delete the successor
				root->user1 = tempuser->user1;
				root->right = delete_user(root->right, &tempuser->user1);
			}
		}
		// 1 node
		if (root == NULL)
			return root;
		// update the height like always
		root->height = std::max(up_height(root->left), up_height(root->right)) + 1;
		// and balance the tree
		if (up_balance(root) > 1) {
			// it's the left left case which needs a right rotation
			if (up_balance(root->left) >= 0)
				return rightrot(root);
			// it's the left right case 
			if (up_balance(root->left) < 0)
				return Lr(root);
		}
		if (up_balance(root) < -1) {
			// it's the right right case -> left rotation
			if (up_balance(root->right) <= 0)
				return leftrot(root);
			if (up_balance(root->right) > 0)
				return Rl(root);
		}
		return root;
	}

	// these are for using the private to nad the final form of the function
	void display_pre() {
		preorder(root);
	}
	void display_in() {
		inorder(root);
	}
	void display_post() {
		postorder(root);
	}

	void insert_user2(user a) {
		root = insert_user(root, a);
	}
	bool check(std::string a, std::string b) {
		if (check_trav(root, a, b) == true)
			return true;
		return false;
	}
	bool check2(std::string a) {
		if (check_trav2(root, a) == true)
			return true;
		return false;
	}
	user check3(std::string a, std::string b) {
		/*if (check_trav3(root, a, b) != ) {*/
		user e = check_trav3(root, a, b);
		return e;
		//}
		/*return;*/
	}
	bool check4(std::string a) {
		if (inorder_trav4(root, a) == true)
			return true;
		return false;
	}
	user* check5(std::string a) {
		user* r = check_trav5(root, a);
		return r;
	}
	void check6() {
		check_trav6(root);
	}
	user check7(std::string a) {
		return inorder_trav7(root, a);
	}
	bool check8(std::vector<std::string> a, std::string b) {
		return check_vec1(a, b);
	}
	bool check9(std::string a, user* b) {
		return check_elegant1(a, b);
	}
	bool check10(std::string a, std::vector<std::string> b) {
		for (int i = 0; i < b.size(); i++) {
			if (b[i] == a)
				return true;
		}
		return false;
	}
	// for checking the name and the surname of the sign up!
	bool check11(std::string a) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] >= '1' && a[i] <= '9')
				return false;
		}
		return true;
	}
	// for the check of the username 
	bool check12(std::string a) {
		int len = a.length();
		int i = 0;
		bool flag = false;
		bool flag2 = false;
		while (true) {
			if (a[i] > '0' && a[i] <'9') {
				flag = true;
				i++;
			}
			else if (a[i] > 'A' && a[i] < 'z') {
				flag2 = true;
				i++;
			}
			if (i == len)
				break;
		}
		if (flag == true && flag2 == true)
			return true;
		return false;
	}
	user check33(std::string a) {
		return check_trav33(root, a);
	}
	// i got this from stack overflow to just check for the empty files :)s
	bool is_empty(std::ifstream& pFile) {
		return pFile.peek() == std::ifstream::traits_type::eof();
	}
	void delete_user2(user *a) {
		root = delete_user(root, a);
	}
	bool check66(std::string a) {
		return check_cell(root, a);
	}
	user* check88(std::string a) {
		return check_cell2(root, a);
	}
	void pre_file2(std::ofstream& a) {
		return pre_file(root, a);
	}
};

// i used this to change the coloe in my favor 
char* Color(int color = 7, char* Message = "") {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	return Message;
}
