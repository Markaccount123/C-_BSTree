//#pragma once
//
////�κ����ݽṹ�ı��ʶ��벻����ɾ���
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
//		//BSTreeΪ�յ�ʱ��
//		if (_root == nullptr)
//		{
//			_root = new Node(key,value);
//			return true;
//		}
//		//��Ϊ�ٲ����ʱ����Ҫ֪��β���Ľڵ㣬��Ȼ�㲻֪����Ӧ����������
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key > key)
//			{
//				//��������ȥ����
//				parent = cur;
//				cur = cur->_left;
//			}
//			else if (cur->_key < key)
//			{
//				//���Ұ����ȥ����
//				parent = cur;
//				cur = cur->_right;
//			}
//			else
//			{
//				//����������Ǵ�ʱ��keyֵ��cur->_key��ȵ����
//				//�ڴ˿������ǲ���������ȵ�����
//				return false;
//			}
//		}
//		//ѭ����������ô��ʱ��parent����������Ҫ����ĸ��ڵ�
//		Node* newnode = new Node(key,value);
//		//��ʱ��Ҫ�жϵ��������ڸ��ڵ����߻����ұ�
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
//		//�������---�����
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
//	////ɾ��������Ҫ��
//	//void Erase()
//private:
//	Node* _root = nullptr;
//
//};


#pragma once

//�κ����ݽṹ�ı��ʶ��벻����ɾ���
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
		//BSTreeΪ�յ�ʱ��
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		//��Ϊ�ٲ����ʱ����Ҫ֪��β���Ľڵ㣬��Ȼ�㲻֪����Ӧ����������
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				//��������ȥ����
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				//���Ұ����ȥ����
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				//����������Ǵ�ʱ��keyֵ��cur->_key��ȵ����
				//�ڴ˿������ǲ���������ȵ�����
				return false;
			}
		}
		//ѭ����������ô��ʱ��parent����������Ҫ����ĸ��ڵ�
		Node* newnode = new Node(key);
		//��ʱ��Ҫ�жϵ����������ڸ��ڵ����߻����ұ�
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
		//�������---�����
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
		//������Ҫ�����Ƿ����������
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
				//�ҵ������ֵ��׼����ʼɾ��
				//���԰�Ҷ�ӽ�㵱����Ϊ�ջ�����Ϊ�յ�һ�������
				//a.��Ϊ��
				//b.��Ϊ��
				//c.���Ҷ���Ϊ��
				if (cur->_left == nullptr)
				{
					//�������
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						//ͼ��ɾ��1�������
						if (cur == parent->_left)
						{
							parent->_left = cur->_right;
						}
						else
						{
							//ͼ��ɾ��8�������
							parent->_right = cur->_right;
						}
					}
					delete cur;
				}
				else if (cur->_right == nullptr)
				{
					//������������������һ��
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						//ͼ��ɾ��1�������
						if (cur == parent->_left)
						{
							parent->_left = cur->_left;
						}
						else
						{
							//ͼ��ɾ��8�������
							parent->_right = cur->_left;
						}
					}
					delete cur;
				}
				else
				{
					//��ʱ�����c��ʱ�������Һ��ӽ��,Ӧ��ʹ���滻��������������ʹ��������������߽�㣨Ҳ��������������С�Ľ���滻��
					//Node* sbParent = nullptr;����һ��ʼ���ǻ�����˼�����Ѹ��ڵ㶨Ϊ��
					Node* sbParent = cur;
					Node* subMin = cur->_right;
					while (subMin->_left)
					{
						sbParent = subMin;
						subMin = subMin->_left;
					}
					cur->_key = subMin->_key;//�滻��
					//���Ǵ�ʱ�п������ҵ������subMin���һ����û����ڵ�ģ����ǿ��ܻ������ҽ�������������㻹��Ҫ֪��subMin�ĸ��ڵ�
					//�滻����Ժ󣬻���Ҫ������滻�Ľ��ֵ����ɾ������ʱ�ֻ��Ϊ�������
					if (subMin == sbParent->_left)
					{
						sbParent->_left = subMin->_right;
					}
					else
					{
						//��ʱ��subMin��㣬������������С���
						//��������Ҳ��������Ϊʲô������һ��ʼ�趨��sbParent = nullptr��
						sbParent->_right = subMin->_right;
					}
					delete subMin;
				}
				return true;
			}
		}
		//�����������ˣ�Ҳû�ҵ����ֵ������false
		return false;
	}
private:
	Node* _root = nullptr;

};
