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
	//你会发现如果这样写，你是调不动这个中序函数的,需要嵌套一层

	//const BSTreeNode<int>* ret = t.Find(6);
	//cout << "找到了" << endl;

	
	//string strArray[] = { "苹果", "苹果", "香蕉", "草莓", "草莓", "草莓", "苹果", "香蕉", "苹果" };
	//BSTree<string, int> countTree;
	//for (auto& str : strArray)
	//{
	//	//通过key去找value
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
	//dict.Insert("string", "字符串");
	//dict.Insert("sort", "排序");
	//dict.Insert("insert", "插入");
	//dict.Insert("left", "左边");

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
	//		cout << "单词不存在" << endl;
	//	}
	//}

	//string strArray[] = { "香蕉", "苹果", "苹果", "橘子", "香蕉", "苹果", "橘子", "香蕉" };
	//BSTreeBV<string, int> countTree;
	//for (auto& str : strArray)
	//{
	//	BSTreeNode<string, int>* ret = countTree.Find(str);
	//	if (ret == nullptr) //说明是第一次出现这个水果
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