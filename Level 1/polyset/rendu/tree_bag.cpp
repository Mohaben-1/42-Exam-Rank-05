#include "tree_bag.hpp"
#include <iostream>

tree_bag::tree_bag() : tree(0) {}

tree_bag::tree_bag(const tree_bag &oth) {
	this->tree = copy_node(oth.tree);
}

tree_bag::~tree_bag() {
	this->destroy_tree(this->tree);
}

tree_bag &tree_bag::operator=(const tree_bag &oth) {
	this->clear();
	this->tree = copy_node(oth.tree);
	return *this;
}

tree_bag::node *tree_bag::extract_tree() {
	node *ret = this->tree;
	this->tree = 0;
	return ret;
}

void tree_bag::set_tree(node *t) {
	destroy_tree(this->tree);
	this->tree = t;
}

void tree_bag::insert(int val) {
	node **n = &this->tree;
	while(*n) {
		if (val < (*n)->value)
			n = &(*n)->l;
		else if (val >= (*n)->value)
			n = &(*n)->r;
	}
	*n = new node((node){0, 0, val});
}

void tree_bag::insert(int *array, int size) {
	for (int i = 0; i < size; i++) {
		this->insert(array[i]);
	}
}

void tree_bag::print() const {
	this->print_node(this->tree);
	std::cout << std::endl;
}

void tree_bag::clear() {
	this->destroy_tree(this->tree);
	this->tree = NULL;
}

void tree_bag::destroy_tree(node *n) {
	if (!n)
		return ;
	destroy_tree(n->l);
	destroy_tree(n->r);
	delete (n);
}

void tree_bag::print_node(node *n) {
	if(!n)
		return ;
	print_node(n->l);
	std::cout << n->value << " ";
	print_node(n->r);
}

//there's an issue here, it's defined in the header fil in such a way that the declaration should be 
//void *tree_bag::copy_node(node *n)
//but that causes inconsistencies elsewhere where the function is called to specifically make a tree_bag::node
//Anyone have this .cpp file transcribed that can confirm?
tree_bag::node *tree_bag::copy_node(node *n) {
	if (!n)
		return 0;
	return new node((node){copy_node(n->l), copy_node(n->r), n->value});
}