//#pragma once
//
////任何数据结构的本质都离不开增删查改
//template <class K,class V>
//struct BSTreeNode
//{
//	const K _key;
//	V _value;
//	struct BSTreeNode<K,V>* _left;
//	struct BSTreeNode<K,V>* _right;
//
//	BSTreeNode(const K& key,const V& value)
//		:_key(key)
//		, _value(value)
//		, _left(nullptr)
//		, _right(nullptr)
//	{}
//};
//
//template<class K,class V>
//class BSTreeBV
//{
//	typedef  BSTreeNode<K,V> Node;
//public:
//	bool Insert(const K& key,const V& value)
//	{
//		//BSTree为空的时候
//		if (_root == nullptr)
//		{
//			_root = new Node(key,value);
//			return true;
//		}
//		//因为再插入的时候，需要知道尾部的节点，不然你不知道他应该怎样链接
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key > key)
//			{
//				//往左半边树去链接
//				parent = cur;
//				cur = cur->_left;
//			}
//			else if (cur->_key < key)
//			{
//				//往右半边树去链接
//				parent = cur;
//				cur = cur->_right;
//			}
//			else
//			{
//				//这种情况就是此时的key值和cur->_key相等的情况
//				//在此棵树中是不允许有相等的树的
//				return false;
//			}
//		}
//		//循环结束，那么此时的parent就是我们需要插入的父节点
//		Node* newnode = new Node(key,value);
//		//此时还要判断倒是链接在父节点的左边还是右边
//		if (parent->_key > key)
//		{
//			parent->_left = newnode;
//		}
//		else
//		{
//			parent->_right = newnode;
//		}
//		return true;
//	}
//
//
//	void _InOrder(Node* root)
//	{
//		if (root == nullptr)
//			return;
//		//中序遍历---左根右
//		_InOrder(root->_left);
//		cout << root->_key << ":"<<root->_value<<endl;
//		_InOrder(root->_right);
//	}
//
//	void InOrder()
//	{
//		_InOrder(_root);
//		cout << endl;
//	}
//
//	 Node* Find(const K& key)
//	{
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				cur = cur->_right;
//			}
//			else if (cur->_key > key)
//			{
//				cur = cur->_left;
//			}
//			else
//			{
//				return cur;
//			}
//		}
//
//		return nullptr;
//	}
//
//	////删除（很重要）
//	//void Erase()
//private:
//	Node* _root = nullptr;
//
//};


#pragma once

//任何数据结构的本质都离不开增删查改
template <class K>
struct BSTreeNode
{
	K _key;
	struct BSTreeNode<K>* _left;
	struct BSTreeNode<K>* _right;

	BSTreeNode(const K& key)
		:_key(key)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template<class K>
class BSTree
{
	typedef  BSTreeNode<K> Node;
public:
	bool Insert(const K& key)
	{
		//BSTree为空的时候
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		//因为再插入的时候，需要知道尾部的节点，不然你不知道他应该怎样链接
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				//往左半边树去链接
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				//往右半边树去链接
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				//这种情况就是此时的key值和cur->_key相等的情况
				//在此棵树中是不允许有相等的树的
				return false;
			}
		}
		//循环结束，那么此时的parent就是我们需要插入的父节点
		Node* newnode = new Node(key);
		//此时还要判断到底是链接在父节点的左边还是右边
		if (parent->_key > key)
		{
			parent->_left = newnode;
		}
		else
		{
			parent->_right = newnode;
		}
		return true;
	}


	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		//中序遍历---左根右
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	const Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}

		return nullptr;
	}


	bool Erase(const K& key)
	{
		//首先需要查找是否存在这个结点
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				//找到了这个值，准备开始删除
				//可以把叶子结点当成左为空或者右为空的一种情况，
				//a.左为空
				//b.右为空
				//c.左右都不为空
				if (cur->_left == nullptr)
				{
					//极端情况
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						//图中删除1结点的情况
						if (cur == parent->_left)
						{
							parent->_left = cur->_right;
						}
						else
						{
							//图中删除8结点的情况
							parent->_right = cur->_right;
						}
					}
					delete cur;
				}
				else if (cur->_right == nullptr)
				{
					//极端情况，和上面基本一致
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						//图中删除1结点的情况
						if (cur == parent->_left)
						{
							parent->_left = cur->_left;
						}
						else
						{
							//图中删除8结点的情况
							parent->_right = cur->_left;
						}
					}
					delete cur;
				}
				else
				{
					//此时是情况c的时候，有左右孩子结点,应该使用替换法，在这里我们使用右子树的最左边结点（也就是右子树中最小的结点替换）
					//Node* sbParent = nullptr;可能一开始就是会这样思考，把父节点定为空
					Node* sbParent = cur;
					Node* subMin = cur->_right;
					while (subMin->_left)
					{
						sbParent = subMin;
						subMin = subMin->_left;
					}
					cur->_key = subMin->_key;//替换掉
					//但是此时有可能你找到的这个subMin结点一定是没有左节点的，但是可能还会有右结点的情况，所以你还需要知道subMin的父节点
					//替换完成以后，还需要把这个替换的结点值进行删除，此时又会分为两种情况
					if (subMin == sbParent->_left)
					{
						sbParent->_left = subMin->_right;
					}
					else
					{
						//此时的subMin结点，就是右子树最小结点
						//所以这里也就引出了为什么不能让一开始设定的sbParent = nullptr，
						sbParent->_right = subMin->_right;
					}
					delete subMin;
				}
				return true;
			}
		}
		//整个都找完了，也没找到这个值，返回false
		return false;
	}
private:
	Node* _root = nullptr;

};
