#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//��� ���������� �������:
typedef short int balance;

//���������� ������� AVL-������:
template<class T>
struct Tree
{
	T key;//����
	Tree *left;//��������� �� ����� ���������
	Tree *right;//��������� �� ������ ���������

	balance BAL;/*�������� �������:
				"0" - ����� � ������ ��������� ���������(�� ������)
				+1 - ������� � ������ ���������.
				"-1" - � �����.
				*/
};

/*
������� ������ ��� ������� ����������� �������� � ������ ����� ������:
ins - ����������� �������;
root - ������ ������;
high - ���������� ��������� ������ ������ �� ������ ������.
*/
template<class T>
void SearchAndInsert(T ins, Tree<T>** root, bool &high)
{
	Tree<T> *change1, *change2;//��� ������� (������) ������ ��� ������������.

	//���� ������ ������:
	if (*root == NULL)
	{
		*root = new Tree<T>;//�������� ������ ��� ����. �����
		(*root)->key = ins;//�������������� ������ ������
		(*root)->left = NULL;//����� ��������� ���
		(*root)->right = NULL;//������ ��������� ���
		(*root)->BAL = 0;//������ ��������������
		high = true;//��������� ������ ������
	}
	/*����� ���� ��� ������ ����������*/

	//���� ����������� ������� ������ �����:
	else if ((*root)->key > ins)
	{
		//���������� �������� ��� ����� ����� �����:
		SearchAndInsert(ins, &((*root)->left), high);

		//���� ������ ����������: 
		if (high == true)
		{
			/*
			���������� ������ � ������� �����,
			��� ������������� ������ ������������:
			*/
			switch ((*root)->BAL)
			{
			case 1://������������ �� ���������:
			{
				(*root)->BAL = 0;//������ �����������
				high = false;//��������� � ����� �� �������
				break;
			}
			//������ ��������������:
			case 0:
			{
				(*root)->BAL = -1;//��������� ������� ��������� ��� AVL-������
				break;
			}
			case -1://����������� ������������(!)
			{
				//���������� ����� ���� ����� � ���������� ������:
				change1 = (*root)->left;

				//���� ����������� ������� � ����� ���������:
				if (change1->BAL == -1)//����������� ����� ������� (�����):
				{
					(*root)->left = change1->right;//����� ���� ����������� ���� ������
					change1->right = *root;//������ ������ ���� ����������� ������
					(*root)->BAL = 0;//������������ ����������� �������
					*root = change1;//������ ��������� ��� ���������� ������������
				}
				else//����� ����� ���������� ������� �����, � ����� ������ �������:
				{
					change2 = change1->right;//change2 - ������ ����� ������ ���� ����� (change1)

					change1->right = change2->left;//� change2 ���������� ����� ���� ���� �����
					change2->left = change1;//� ������ ����� ���� ���������� ����� ���� ����� 
					(*root)->left = change2->right;//� ����� ���� ����� ���������� ������ ���� �������� change2
					change2->right = *root;//������ ���� �������� change2 �������� �������� �����

					/*
					���� ������������ � ������ ����� ������
					���� ����� ���������� � ����� �������:
					*/
					if (change2->BAL == -1)
						(*root)->BAL = 1;//� ����� ������� ���������� �� ������ �����
					else (*root)->BAL = 0;//����� ������ � ����� �����������

					/*
			        ���� ������������ � ������ ����� ������
					���� ����� ���������� � ������ �������:
					*/
					if (change2->BAL == 1)
						change1->BAL = -1;//����� ���� ����� ��������� � ����� �����
					else change1->BAL = 0;//����� ������ � ������� ���� - �����������

					*root = change2;//�������� ����� ������ ��� ���������� ������������
				}
				(*root)->BAL = 0;//������ ������ �����������
				high = false;//��������� � ����� �� �������
				break;
			}
			}
		}
	}
	//�����, ���� ����������� ������� ������ �����:
	else if ((*root)->key < ins)
	{
		//���������� �������� ��� ������ ����� �����:
		SearchAndInsert(ins, &((*root)->right), high);

		//���� ������ ����������� ���������:
		if (high == true)
		{
			/*
			���������� ������ � ������� �����,
			��� ������������� ������ ������������:
			*/
			switch ((*root)->BAL)
			{
			case -1://������������ �� ���������:
			{
				(*root)->BAL = 0;//��������� � ����� �� �������
				high = false;//=> ������ ���� �� �������
				break;
			}
			case 0://������ ��������������:
			{
				(*root)->BAL = 1;//��������� ������� ��������� ��� AVL-������
				break;
			}
			case 1://��������� ������������:
			{
				//���������� ������ ���� ����� � ���������� ������:
				change1 = (*root)->right;

				if (change1->BAL == 1)//����������� ������ �������:
				{
					(*root)->right = change1->left;//� ������ ����� ������ ���������� ����� ���� ������� ���� change1
					change1->left = *root;//� ������ ����� ���� ���������� ������
					(*root)->BAL = 0;//������������ ����������� �������
					*root = change1;//������ ��������� ��� ���������� ������������
				}
				else//����� ���������� ������ + ������ �������:
				{
					change2 = change1->left;//change2 - ������ ����� ������ ���� ����� (change1)
					change1->left = change2->right;//� change2 ���������� ������ ���� ���� �����
					change2->right = change1;//� ������ ������ ���� ���������� ������ ���� �����

					(*root)->right = change2->left;//� ������ ���� ����� ���������� ����� ���� �������� change2
					change2->left = *root;//����� ���� �������� change2 �������� �������� �����

					//���� ������ ����� ������ ���� ����� - ���������� � �����:
					if (change2->BAL == 1)
						(*root)->BAL = -1;//������ ��������� � ����
					else (*root)->BAL = 0;//����� ������ �����������

										  //���� ������ ����� ������ ���� ����� - ���������� � ����:
					if (change2->BAL == -1)
						change1->BAL = 1;//������ ���� ����� ��������� � �����	
					else change1->BAL = 0;//����� ������ ���� ����� �����������

					*root = change2;//�������� ����� ������ ��� ���������� ������������
				}
				(*root)->BAL = 0;//������ ������ � ����� �����������
				high = false;//��������� � ����� �� �������
				break;
			}
			}
		}
	}
}

template<class T>
/*
������� ��� ������������ (��� �������������) ����� ����� ������:
root - ������ ������;
high - ���������� ��������� ������ ������ �� ������ ������.
*/
void BalanceL(Tree<T> **root, bool &high)
{
	if (*root == NULL)
		return;

	Tree<T> *change1, *change2;//��� ������� (������) ������

	balance b1, b2;//��������������� ���������� �������

	/*
	���������� ������ � ������� �����,
	��� ������������� ������ ������������:
	*/
	switch ((*root)->BAL)
	{
	case -1://������������ �� ���������:
	{
		(*root)->BAL = 0;//��������� � ����� �� �������
		break;
	}
	case 0://������ ��������������:
	{
		(*root)->BAL = 1;//��������� ������� ��������� ��� AVL-������
		high = false;//������ ����������� ���������
		break;
	}
	case 1://��������� ������������:
	{
		//���������� ������ ���� ����� � ���������� ������:
		change1 = (*root)->right;
		b1 = change1->BAL;//������ ���� ���������� ���������� � ��������������� b1

		if (b1 >= 0)//����������� ������ �������
		{
			(*root)->right = change1->left;//� ������ ����� ������ ���������� ����� ���� ������� ���� change1
			change1->left = *root;//� ������ ����� ���� ���������� ������

			//������ ���� ����� - �����������:
			if (b1 == 0)
			{
				(*root)->BAL = 1;//������ ��//������ ��������� ��� ���������� ������������������� � ������ �����
				change1->BAL = -1;//������ ���� ����� ��������� � ����� �����
				high = false;//������ �� ����������� ���������
			}
			else
			{
				//������ ������ �����������:
				(*root)->BAL = 0;
				change1->BAL = 0;
			}

			*root = change1;//������ ��������� ��� ���������� ������������
		}
		else//����� ���������� ������ + ������ �������:
		{
			change2 = change1->left;//change2 - ������ ����� ������ ���� ����� (change1)
			b2 = change2->BAL;//������ ���� ���������� ���������� � ��������������� b2
			change1->left = change2->right;//� change2 ���������� ������ ���� ���� �����
			change2->right = change1;//� ������ ������ ���� ���������� ������ ���� �����

			(*root)->right = change2->left;//� ������ ���� ����� ���������� ����� ���� �������� change2
			change2->left = *root;//����� ���� �������� change2 �������� �������� �����

			//���� ������ ����� ������ ���� ����� - ���������� � �����:
			if (b2 == 1)
			{
				(*root)->BAL = -1;//������ ��������� � ����
			}
			else (*root)->BAL = 0;//����� ������ �����������

			//���� ������ ����� ������ ���� ����� - ���������� � ����:
			if (b2 == -1)
			{
				change1->BAL = 1;//������ ���� ����� ��������� � �����
			}
			else change1->BAL = 0;//����� ���� ���� �����������

			*root = change2;//������ ��������� ��� ���������� ������������
			change2->BAL = 0;//������ �����������
		}
		break;
	}
	}
}

template<class T>
/*
������� ��� ������������ (��� �������������) ������ ����� ������:
root - ������ ������;
high - ���������� ��������� ������ ������ �� ������ ������.
*/
void BalanceR(Tree<T> **root, bool &high)
{
	if (*root == NULL)
		return;

	Tree<T> *change1, *change2;//��� ������� (������) ������

	balance b1, b2;//��������������� ���������� �������

	/*
	���������� ������ � ������� �����,
	��� ������������� ������ ������������:
	*/
	switch ((*root)->BAL)
	{
	case 1://������������ �� ���������:
	{
		(*root)->BAL = 0;//������ �����������
		break;
	}
	case 0://������ ��������������:
	{
		(*root)->BAL = -1;//��������� ������� ��������� ��� AVL-������
		high = false;
		break;
	}
	case -1://����������� ������������(!)
	{
		//���������� ����� ���� ����� � ���������� ������:
		change1 = (*root)->left;
		b1 = change1->BAL;//���������� � ��������������� ���������� ������ ����� ����� �����

		if (b1 <= 0)//����������� ����� �������:
		{
			(*root)->left = change1->right;//����� ���� ����������� ���� ������
			change1->right = *root;//� ������ ���� ������� ���� ����� ������������ �������� �����

		    //���� ������ � ����� ����� ����� - �����������:
			if (b1 == 0)
			{
				(*root)->BAL = -1;//������ ����� ��������� � ����
				change1->BAL = 1;//����� ���� ����� ��������� � �����
				high = false;//������ �� ����������� ���������
			}
			else//�����:
			{
				//������ �����������:
				(*root)->BAL = 0;
				change1->BAL = 0;
			}

			*root = change1;//������ ������ ���������� ��� ���������� ������� ������
		}
		else//������� �����, ����� ������ �������:
		{
			change2 = change1->right;//change2 - ������ ����� ������ ���� ����� (change1)
			b2 = change2->BAL;//� ��������������� ���������� ���������� ������ change2
			change1->right = change2->left;//������ ����� ������ ���� ����� ����������� ����� ���� change2
			change2->left = change1;//����� ���� change2 ����������� ����� ���� �����
			(*root)->left = change2->right;//����� ���� ����� ����������� ������ ���� change2
			change2->right = *root;//������ ���� change2 ����������� ������

			//���� ������ change2 ��������� � ����:
			if (b2 == -1)
			{
				(*root)->BAL = 1;//������ ����� ��������� � �����
			}
			else (*root)->BAL = 0;//����� ������ ����� �����������

			//���� ������ change2 ��������� � �����:
			if (b2 == 1)
			{
				change1->BAL = -1;//����� ���� ����� ��������� � ����
			}
			else change1->BAL = 0;//����� ���� ���� �����������

			*root = change2;//������ ���������� ��� ���������� ������������
			change2->BAL = 0;//������ change2 - �����������
		}
		break;
	}
	}
}

template<class T>
//������� ����������� ��� �������� ����:
void HelpForDelete(Tree<T> **del, Tree<T> **helper, bool &high)
{
	if (*del == NULL)
		return;

	//���� ������ �� ���������� �������� ������ ���:
	if ((*del)->right != NULL)
	{
		//���������� �������� ��� ����� ��������:
		HelpForDelete(&((*del)->right), helper, high);

		//���� ������ ����������� ���������:
		if (high == true)
		{
			//��������� ������������, �������� ��������� �������:
			BalanceR(del, high);
		}
	}
	else//�����:
	{
		//���������� � ��������������� ������� ���������:
		(*helper)->key = (*del)->key;

		//���������� ��������� �� ��������� �������:
		*helper = *del;

		//���������� ����� � ����� ���� (�� ����������):
		*del = (*del)->left;
		high = true;//������ ����������
	}
}

template<class T>
//������� ��� �������� ����:
void Delete(T del_el, Tree<T> **root, bool &high)
{
	if (*root == NULL)
		return;

	//��������������� ������� ��� ��������:
	Tree<T> *helper = new Tree<T>;

	//���� ��������� ������� ������ ����� ������:
	if ((*root)->key > del_el)
	{
		//����� ���� ����� �� ��������:
		if ((*root)->left != NULL)
		{
			//�������� � ���������� � ������ �������� �� �����:
			Delete(del_el, &((*root)->left), high);

			//���� ������ ����������� ���������:
			if (high == true)
			{
				//��������� ������������:
				BalanceL(root, high);
			}
		}
	}
	//���� ��������� ������� ������ ���������:
	else if ((*root)->key < del_el)
	{
		//������ �� ����� �����:
		if ((*root)->right != NULL)
		{
			//�������� � ���������� � ������� �������� �� �����:
			Delete(del_el, &((*root)->right), high);

			//���� ������ ����������:
			if (high == true)
			{
				//��������� ������������:
				BalanceR(root, high);
			}
		}
	}
	else//� ��������� ������:
	{
		helper = *root;//�������� ������

		//������ �� ����� �����:
		if (helper->right == NULL)
		{
			//����� ������ ��������� � ����� ����:
			*root = helper->left;
			high = true;//������ ����������
		}
		//����� �� ����� �����:
		else if (helper->left == NULL)
		{
			//������ ��������� � ������ ����:
			*root = helper->right;
			high = true;//������ ����������
		}
		else//�����:
		{
			//���� ����� �� ����� ���� �������:
			if (helper->left != NULL)
			{
				//����� ��������������� ������� ��� �������� ��������:
				HelpForDelete(&(helper->left), &helper, high);

				//���� ������ ����������:
				if (high == true)
				{
					//��������� ������������:
					BalanceL(&(*root), high);
				}
			}
		}
	}
}

template<class T>
//����� ������ - �����:
void PrintTree(Tree<T> *root, int level)
{
	if (root != NULL)//���� ���������� ���� �� ������:
	{
		PrintTree(root->left, level + 1);//����� ������� ���������

		//��� ����������� ��������� �������� ���������:
		for (int i = 0; i < level; i++)
		{
			cout << "     ";
		}

		cout << root->key << endl;//����� ����� ���������
		PrintTree(root->right, level + 1);//����� ������ ���������
	}
	else return;//���� ������ �������� - ��������� ������!
}