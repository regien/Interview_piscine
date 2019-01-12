#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>
#include "header.h"

void		get_basicinfo(struct s_node *root, struct s_info *info, int height)
{
	if (!(root))
		return ;
	if (root->value < info->min)
		info->min = root->value;
	if (root->value > info->max)
		info->max = root->value;
	info->elements += 1;
	if ((height + 1) > info->height)
		info->height = (height + 1);

	get_basicinfo(root->left, info, (height + 1));
	get_basicinfo(root->right, info, (height + 1));
}

// dont use directions just use int max and int min, which is the head when moving
// 4 lines --- max
void		validate_bst(struct s_node *root, struct s_info *info, int previous_head, int direction)
{
	if (previous_head == -1)
		previous_head = root->value;
	if (direction == -1) { // center - normal validatation
		if (root->left) {
			if(root->left->value > root->value)
				info->isBST = 0;
		} else if (root->right)
			if(root->right->value < root->value)
				info->isBST = 0;
	}
	else if (direction == 0) { // left
		if (root->left) {
			if(root->left->value > root->value)
				info->isBST = 0;
		} else if (root->right)
			if(root->right->value < root->value || root->right->value > previous_head)
				info->isBST = 0;
	}
	else if (direction == 1) { // right
		if (root->left) {
			if(root->left->value > root->value || root->left->value < previous_head)
				info->isBST = 0;
		} else if (root->right)
			if(root->right->value < root->value)
				info->isBST = 0;
	}
	if (root->left)
		validate_bst(root->left, info, root->value, 0);
	if (root->right)
		validate_bst(root->right, info, root->value, 1);
}

// assuming it's height balanced
void		validate_balancing(struct s_node *root, struct s_info *info)
{
	struct s_info		left;
	struct s_info		right;

	left.height = 0;
	right.height = 0;
	if (root->left)
		get_basicinfo(root->left, &left, 0);
	if (root->right)
		get_basicinfo(root->right, &right, 0);
	if (left.height - right.height < 0)
		info->isBalanced = ((left.height - right.height) * -1 <= 1 ? 1 : 0);
	else
		info->isBalanced = ((left.height - right.height) <= 1 ? 1 : 0);
	return ;
}

struct s_info		getInfo(struct s_node *root)
{
	struct s_info	holder;

	holder.elements = 0;
	holder.height = 0;
	holder.isBalanced = 0;
	holder.isBST = 1;
	if (!(root))
		return (holder);
	holder.min = root->value;
	holder.max = root->value;
	validate_bst(root, &holder, -1, -1);
	get_basicinfo(root, &holder, holder.height);
	validate_balancing(root, &holder);
	return (holder);
}
