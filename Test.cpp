#include<iostream>
#include<string>
using namespace std;
#include"BSTree.h"

void TestBSTree()
{

	BSTree<int> t;
	t.Insert(7);
	t.Insert(6);
	t.Insert(5);
	t.Insert(4);
	t.Insert(3);
	t.Insert(2);
	t.Insert(1);
	t.Insert(0);

	t.InOrder();

	t.Erase(5);
	t.Erase(3);
	t.Erase(7);
	t.InOrder();

}
int main()
{
	TestBSTree();
	return 0;
}
	//��ᷢ���������д�����ǵ����������������,��ҪǶ��һ��

	//const BSTreeNode<int>* ret = t.Find(6);
	//cout << "�ҵ���" << endl;

	
	//string strArray[] = { "ƻ��", "ƻ��", "�㽶", "��ݮ", "��ݮ", "��ݮ", "ƻ��", "�㽶", "ƻ��" };
	//BSTree<string, int> countTree;
	//for (auto& str : strArray)
	//{
	//	//ͨ��keyȥ��value
	//	const BSTreeNode<string, int>* ret = countTree.Find(str);
	//	if (ret == nullptr)
	//	{

	//	}
	//	else
	//	{
	//		
	//	}
	//}


	//BSTreeBV<string, string> dict;
	//dict.Insert("string", "�ַ���");
	//dict.Insert("sort", "����");
	//dict.Insert("insert", "����");
	//dict.Insert("left", "���");

	//dict.InOrder();

	//string str;
	//while (cin >> str)
	//{
	//	BSTreeNode<string, string>* ret = dict.Find(str);
	//	if (ret)
	//	{
	//		cout << ret->_value << endl;
	//	}
	//	else
	//	{
	//		cout << "���ʲ�����" << endl;
	//	}
	//}

	//string strArray[] = { "�㽶", "ƻ��", "ƻ��", "����", "�㽶", "ƻ��", "����", "�㽶" };
	//BSTreeBV<string, int> countTree;
	//for (auto& str : strArray)
	//{
	//	BSTreeNode<string, int>* ret = countTree.Find(str);
	//	if (ret == nullptr) //˵���ǵ�һ�γ������ˮ��
	//	{
	//		countTree.Insert(str, 1);
	//	}
	//	else
	//	{
	//		ret->_value++;
	//	}
	//}

	//countTree.InOrder();
//}

//int main()
//{
//	TestBSTree();
//	return 0;
//}