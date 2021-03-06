#include "stdafx.h"
#include "bst.h"
#include "iostream"
using namespace std;

bst::bst()
{
	leftSubtree = NULL;
	rightSubtree = NULL;
	value = 0;
}

bst::bst(int val)
{
	leftSubtree = NULL;
	rightSubtree = NULL;
	value = val;
}

bst::~bst(){}

/*
BRIEF: Функция добавления нового элемента дерева. Использует рекурсию,для того чтобы перемещаться по дереву в поисках правильной позиции.
IN: Адрес корня дерева,который в процессе рекурсии будет изменяться. И значение,которо будет добалено в дерево.
OUT: ---
*/
void bst::addNode(bst *root, int key)
{
	if (key < root->value) {

		if (root->leftSubtree) {
			addNode(root->leftSubtree, key);
		}
		else {
			root->leftSubtree = new bst(key);
		}
	}

	if (key >= root->value) {
		if (root->rightSubtree) {
			addNode(root->rightSubtree, key);
		}
		else {
			root->rightSubtree = new bst(key);
		}
	}
}

/*
BRIEF: Функция вызова функции добавления нового элемента дерева,которая добавит адрес корня дерева,в виде this : переменной ссылающийся самой на себя. Сделанно это для упрощения работы с программой.
IN: Значение,которое станет новым элементом дерева.
OUT: ---
*/

void bst::addNodeWrapper(int key) {
	addNode(this, key);
}

/*
BRIEF: Функция поиска узла или листа в дереве по ключу. Использует рекурсию,для перемещения по дереву в поисках нужной позиции.
IN: Число(Ключ) по которому идёт поиск, указатель на корень дерева,который будет меняться в процессе рекурсии.
OUT: Указатель на узел,найденный по ключу.
*/
bst* bst::find(bst *root, int key)
{

	if (!root) return NULL;
	if (key == root->value)
		//return *root;
		return root;
	if (key < root->value)
	{
		return (find(root->leftSubtree, key));
	}
	else
	{
		return find(root->rightSubtree, key);
	}

}

/*
BRIEF: Функция вызова функции поиска узла или листа в дереве по ключу,которая добавит адрес корня дерева,в виде this : переменной ссылающийся самой на себя. Сделанно это для упрощения работы с программой.
IN: Число(Ключ) по которому идёт поиск. указатель на корень дерева,который будет меняться в процессе рекурсии.
OUT: ---
*/
void bst::findWrapper(int key) {
	find(this, key);
}

/*
BRIEF: Функция поиска самого левого элемента. Вызывается для правого поддерева.
IN: Указатель на корень или узел.
OUT: Указатель на самый левый элемент.
*/
bst bst::minimum(bst *root)
{
	bst *pv = root;
	while (pv->leftSubtree)
		pv = pv->leftSubtree;
	return *pv;
}
/*
BRIEF: Функция поиска самого правого элемента. Вызывается для левого поддерева.
IN: Указатель на корень или узел.
OUT: Указатель на самый правый элемент.
*/
bst bst::maximum(bst *root)
{
	bst *pv = root;
	while (pv->rightSubtree)
		pv = pv->rightSubtree;
	return *pv;
}
/*
BRIEF: Функция вызова функции удаления узла или листа в дереве по ключу,которая добавит адрес корня дерева,в виде this : переменной ссылающийся самой на себя. Сделанно это для упрощения работы с программой.
IN: Число(Ключ) по которому произойдет удаление.
OUT: ---
*/
void bst::delNodeWrapper(int key) {
	delNode(this, key);
}

/*
BRIEF: Функция печати дерева.
IN: Указатель на корень дерева.
OUT: ---
*/
void bst::inorder(bst*root)
{
	cout << endl;
	if (root)
	{
		if (root->value != 0)
			cout << root->value;
		if (root->leftSubtree != 0)
		{
			inorder(root->leftSubtree);
		}
		if (root->rightSubtree != 0)
		{
			inorder(root->rightSubtree);
		}
	}
}
/*
BRIEF: Функция удаления узла или листа по ключу.
IN: Число(Ключ) по которому произойдет удаление. Указатель на корень дерева.
OUT: Возвращает True или False,в зависимости от результата работы.
*/

bool bst::delNode(bst *root, int key)
{
	bst *pv = NULL;
	pv = find(root, key);
	//bst *pv1 = find1(root, key);
	if (pv != NULL)
	{
		if (pv->rightSubtree != NULL)
		{
			bst *min = NULL;
			*min = minimum(pv->rightSubtree);
			pv->value = min->value;
			delNode(min, min->value);


		}

		if (pv->leftSubtree != NULL && pv->rightSubtree == NULL)
		{
			bst *max = NULL;
			*max = maximum(pv->leftSubtree);
			pv->value = max->value;
			delNode(max, max->value);
		}

		if (pv->leftSubtree == NULL && pv->rightSubtree == NULL)
		{
			*pv = NULL;
			//delete pv;
		}
		return true;
	}
	else
		return false;
}
