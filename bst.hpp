#ifndef functional
#include <functional>
#endif

#ifndef iostream
#include <iostream>
#endif

template<class key_t, class cmp = std::less<key_t> >
struct bst
{
    cmp Cmp;
	struct node
	{
	    node(key_t&);
		key_t key;
		node *left, *right, *parent;
	};
	struct iterator
	{
		node* ptr;
		bool operator !=(const iterator&);
		bool operator ==(const iterator&);
		iterator& operator ++();
		const key_t& operator *();
	};
	node *head;
	int size;
    bst(cmp Cmp_=cmp())
   {
       Cmp=Cmp_;
	   head = nullptr;
	   size = 0;
    }
	void left_rotation(node*);
	void right_rotation(node*);
	iterator search(const key_t&);
	void insert(key_t);
	iterator begin();
	iterator end();
};



template<class key_t, class cmp>
bst<key_t, cmp>::node::node(key_t& x)
{
	key = x;
	left = right = parent = nullptr;
}

template<class key_t, class cmp>
typename bst<key_t, cmp>::iterator bst<key_t, cmp>::search(const key_t& x)
{
	node* tmp = head;
	iterator res;
	while (tmp != nullptr)
	{
		if (*tmp == x)
		{
			res.ptr = tmp;
			return res;
		}
		if (Cmp(x, *tmp))
		{
			tmp = tmp->left;
		}
		else
		{
			tmp = tmp->right;
		}
	}
	res.ptr = tmp;
	return res;
}

template<class key_t, class cmp>
void bst<key_t, cmp>::left_rotation(node* x)
{
	node* y = x->left;
	if (x->left == nullptr)
	{
		std::cout << "can't rotate left" << std::endl;
		return;
	}
	x->left = y->right;
	y->right = x;
	y->parent = x->parent;
	x->parent = y;
}

template<class key_t, class cmp>
void bst<key_t, cmp>:: right_rotation(node* x)
{
	node* y = x->right;
	if (x->right == nullptr)
	{
		std::cout << "can't rotate " << std::endl;
		return;
	}
	x->left = y->right;
	y->right = x;
	y->parent = x->parent;
	x->parent = y;
}

template<class key_t, class cmp>
bool bst<key_t, cmp>::iterator:: operator !=(const bst<key_t, cmp>::iterator& other)
{
	return ptr != other.ptr;
}

template<class key_t, class cmp>
bool bst<key_t, cmp>::iterator:: operator ==(const bst<key_t, cmp>::iterator& other)
{
	return ptr == other.ptr;
}

template<class key_t, class cmp>
typename bst<key_t, cmp>::iterator& bst<key_t, cmp>::iterator:: operator ++()
{
	if (ptr == nullptr)
	{
		std::cout << "overflow in increment" << std::endl;
	}
	if (ptr->right != nullptr)
	{
		ptr = ptr->right;
		while (ptr->left != nullptr)
		{
			ptr = ptr->left;
		}
		return *this;
	}
	node* next = ptr->parent;
	while (next != nullptr && next->right==ptr)
	{
		next = next->parent;
		ptr = ptr->parent;
	}
	if (next == nullptr)
	{
		ptr = nullptr;
		return *this;
	}
	ptr = next;
	return *this;
}

template<class key_t, class cmp>
const key_t& bst<key_t, cmp>::iterator:: operator *()
{
	return ptr->key;
}

template<class key_t, class cmp>
void bst<key_t, cmp>::insert(key_t x)
{
	node* tmp = head;
	if (tmp == nullptr)
	{
		head = new node(x);
		++size;
		return;
	}
	bool flag_less;
	while (tmp != nullptr)
	{
		if (tmp->key == x)
		{
			return;
		}
		if (Cmp(x, tmp->key))
		{
			if (tmp->left == nullptr)
			{
				flag_less = true;
				break;
			}
			tmp = tmp->left;
		}
		else
		{
			if (tmp->right == nullptr)
			{
				flag_less = false;
				break;
			}
			tmp = tmp->right;
		}
	}
	node* new_node = new node(x);
	if (flag_less)
	{
		tmp->left = new_node;
		new_node->parent = tmp;
		++size;
		return;
	}
	tmp->right = new_node;
	new_node->parent = tmp;
	++size;
	return;
}

template<class key_t, class cmp>
typename bst<key_t, cmp>::iterator bst<key_t, cmp>::begin()
{
	iterator res;
	node* p = head;
	while (p->left != nullptr)
	{
		p = p->left;
	}
	res.ptr = p;
	return res;
}

template<class key_t, class cmp>
typename bst<key_t, cmp>::iterator bst<key_t, cmp>::end()
{
	iterator res;
	res.ptr = nullptr;
	return res;
}

