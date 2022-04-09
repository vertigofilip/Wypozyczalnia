#include "stdafx.h"
#include <iostream>
#include <stdio.h>

struct node {
	int val;
	node* next;
};

void Add(node*&H, int x) {
	node* p = new node;
	p->val = x;
	p->next = H;
	H = p;
}
void Delete(node*&H) {
	if (H != NULL) {
		node* p = H;
		H = H->next;
		delete p;
	}
}
void CopyEvery(node*H) {
	node* p = H;
	while (p != NULL) {
		Add(p->next, p->val);
		p = p->next->next;

	}
}
void DeleteEverySecond(node*H) {
	node* p = H;
	while (p != NULL && p->next != NULL) {
		Delete(p->next);
		p = p->next;

	}
}
void DeleteX(node*&H, int x) {
	if (H != NULL) {
		if (H->val == x) Delete(H);
		else {
			node* p = H;
			while (p->next != NULL && p->next->val != x) p = p->next;
			if (p->next != NULL) Delete(p->next);
		}
	}
}
/*void Insert(node*&H,  int x) {
for (int i = 0; i <= position; i++) {
}
}*/

void InsertAsc(node*&H, int x) {
	if (H == NULL) {
		Add(H, x);
	}
	else {
		if (H->val > x) {
			Add(H, x);
		}
		else {
			node*p = H;
			while (p->next != NULL && p->next->val < x) {
				p = p->next;
			}
			Add(p->next, x);
		}
	}
}

void Swap(node*&H) {
	if (H != NULL && H->next != NULL) {
		if (H->next->next == NULL)
		{	//zamiana 1 z 2
			node*e = H;
			H = H->next;
			H->next = e;
			e->next = NULL;
		}
		else {
			node*p = H;
			while (p->next->next != NULL) {
				p = p->next;
			}
			node*e = H;
			H = p->next;
			p->next->next = e->next;
			p->next = e;
			e->next = NULL;
		}
	}
}

int countLength(node*H) {
	int a = 0;
	node*p = H;
	while (p != NULL) {
		p = p->next;
		a++;
	}
	return a;
}

void SplitList(node*&H, node*&H1, node*&H2) {
	if (H != NULL) {
		if (H->next == NULL) {
			H1 = H;
			H = NULL;
		}
		else {
			int c = countLength(H);
			H1 = H;
			node*p = H;
			for (int i = 0; i < c / 2; i++) p = p->next;
			H2 = p->next;
			p->next = NULL;
			H = NULL;
		}
	}
}

void MergeList(node*&H, node*&H1, node*&H2) {
	if (H1 != NULL && H2 == NULL) {
		H = H1; H1 = NULL;
	}
	if (H1 == NULL && H2 != NULL) {
		H = H2; H2 = NULL;
	}
	node*T = H; node*p = NULL;
	while (H1 != NULL && H2 != NULL) {
		if (H1->val < H2->val) {
			p = H1;
			H1 = H1->next;
			if (H == NULL) {
				H = p; 
				T = p; 
				p->next = NULL;
			}
			else {
				T->next = p;
				T = p;
				T->next = NULL;
			}
		}
		else {
			p = H2;
			H2 = H2->next;
			if (H == NULL) {
				H = p;
				T = p;
				p->next = NULL;
			}
			else {
				T->next = p;
				T = p;
				T->next = NULL;
			}
		}
	}
	if (H1 == NULL) {
		T->next = H2;
		H2 == NULL;
	}
	else {
		T->next = H1;
		H1 == NULL;
	}
}




void Show(node* H) {
	std::cout << "H->";
	node* p = H;
	while (p != NULL) {
		std::cout << p->val << "->";
		p = p->next;
	}
	std::cout << "NULL\n";
}


int main()
{
	std::cout << "Test4!" << std::endl;
	char end;

	node* H = NULL;
	H = new node;
	H->val = 10;
	H->next = NULL;
	std::cout << H->val << '\n';
	node*p = new node;
	p->val = 5;
	p->next = H;
	H = p;
	std::cout << H->val << '\n';
	std::cout << H->next->val << '\n';
	std::cout << "Add\n";
	Add(H, 15);
	std::cout << H->val << "\n";
	Show(H);
	Add(H->next, 22);
	Show(H);
	std::cout << "Delete\n";
	Delete(H);
	Show(H);
	std::cout << "CopyEvery\n";
	CopyEvery(H);
	Show(H);
	Add(H->next, 122);
	Add(H->next, 1232);
	std::cout << "DeleteEverySecond\n";
	DeleteEverySecond(H);
	Show(H);
	std::cout << "DeleteX\n";
	DeleteX(H, 122);
	Show(H);

	//-------
	//09.04
	//-------
	std::cout << "Insert\n";
	H = NULL;

	int tab[6] = { 3, 6, 4, 8, 11, 1 };

	for (int i = 0; i < 6; i++){
		InsertAsc(H, tab[i]);
	}

	Show(H);

	H = NULL;
	Add(H, 2);
	Add(H, 3);

	std::cout << "Swap\n";

	Show(H);
	Swap(H); 
	Show(H);
	Add(H, 4);
	Add(H, 7);
	Show(H);
	Swap(H);
	Show(H);

	std::cout << "Split\n";

	Add(H, 54);
	Add(H, 27);
	Add(H, 17);
	Add(H, 64);
	Add(H, 71);
	Show(H);
	node*H1 = NULL;
	node*H2 = NULL;
	SplitList(H, H1, H2);
	Show(H); Show(H1); Show(H2);

	std::cout << "Merge\n";

	MergeList(H, H1, H2);
	Show(H); Show(H1); Show(H2);

	std::cin >> end;
	return 0;
}