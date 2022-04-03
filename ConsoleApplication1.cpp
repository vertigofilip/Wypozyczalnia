// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

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
	while (p != NULL && p->next!=NULL) {
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
/*void Insert(node*&H, int position, int x) {
	for (int i = 0; i <= position; i++) {

	}
}*/
	


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

	Add(H, 15);
	std::cout << H->val << "\n";
	Show(H);
	Add(H->next, 22);
	Show(H);
	Delete(H);
	Show(H);
	CopyEvery(H);
	Show(H);
	Add(H->next, 122);
	Add(H->next, 1232);
	DeleteEverySecond(H);
	Show(H);
	DeleteX(H, 122);
	Show(H);
	
	std::cin >> end;
	return 0;
}

