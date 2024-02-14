
#include <iostream>
#include <conio.h>
#include "DoublyLinkedList.h"

using namespace std;

int gcd(int p, int q)
{
	if (q == 0) return p;
	return gcd(q, p % q);
}

// Method Kantora: https://upload.wikimedia.org/wikipedia/commons/thumb/8/85/Diagonal_argument.svg/300px-Diagonal_argument.svg.png

struct Rational {
	int p;
	int q;
	Rational(int p, int q = 1) : p(p), q(q) {}

	friend ostream& operator<< (ostream& os, const Rational& rat)
	{
		os << rat.p << "/" << rat.q;

		return os;
	}

	void operator+= (const Rational& other)
	{
		p = (p * other.q) + (q * other.p);
		q *= other.q;

		int denom = gcd(p, q);
		p /= denom;
		q /= denom;
	}

	bool operator== (const Rational& other)
	{
		return this->p == other.p && this->q == other.q;
	}
};

// returns i-th rational number, using triangle schema
Rational getIthRational(int index) {
	int p = 1, q = 1, s = 2;
	for (int i = 0; i < index + 1; i++) {
		if (p + q != s)
		{
			if (q == 1) p++;
			else q++;
		}
		if (p % 2 && q == 1 || q % 2 == 0 && p == 1)
			s++;
		else if (p + q == s)
		{
			while (true)
			{
				if (s % 2) {
					p--;
					q++;
					if (p == 1) break;
				}
				else {
					p++;
					q--;
					if (q == 1) break;
				}
				if (p % q && q % p) break;
			}
		}
	}
	printf("%d-th rational is %d/%d\n", index, p, q);
	return Rational(p, q);
}

typedef DoublyLinkedList<Rational> RationalsList;

// adds n-th rational number to doubly-linked list
void addNextNumber(RationalsList& l, int& length)
{
	Node<Rational>* last = l.getTailNode();
	int p = 1, q = 1, s = 2;
	bool next = false;
	if (last == nullptr) 
		next = true;
	while(true) {
		if (p + q != s)
		{
			if (q == 1) p++;
			else q++;
		}
		if (next)
		{
			l.append(Rational(p, q));
			break;
		}
		if (p == last->data.p && q == last->data.q)
			next = true;
		if (p % 2 && q == 1 || q % 2 == 0 && p == 1)
			s++;
		else if (p + q == s)
		{
			while (true)
			{
				if (s % 2) {
					p--;
					q++;
					if (p == 1) break;
				}
				else {
					p++;
					q--;
					if (q == 1) break;
				}
				if (p % q && q % p) break;
			}
		}
	}
	length++;


	//system("cls");
	printf(">>> Added %d-th number \"%d/%d\"\n", length, p, q);
}

// initializes doubly-linked list with first n rational numbers, returns list length
int initialize(RationalsList& l)
{
	int n;
	printf(">>> Enter count of first rationals: ");
	cin >> n;

	int p = 1, q = 1, s = 2;
	for (int i = 0; i < n; i++) {
		if (p + q != s)
		{
			if (q == 1) p++;
			else q++;
		}
		l.append(Rational(p, q));
		if (p % 2 && q == 1 || q % 2 == 0 && p == 1)
			s++;
		else if (p + q == s)
		{
			while (true)
			{
				if (s % 2) {
					p--;
					q++;
					if (p == 1) break;
				}
				else {
					p++;
					q--;
					if (q == 1) break;
				}
				if (p % q && q % p) break;
			}
		}
	}
	system("cls");
	printf(">>> Initialized list with first %d rationals\n", n);
	return n;
}

// finds value in list
void find(RationalsList& l)
{
	int p, q;
	printf(">>> Enter p: ");
	cin >> p;
	printf(">>> Enter q: ");
	cin >> q;

	system("cls");
	int res = l.indexOf(Rational(p, q));
	if (res != -1)
		printf(">>> \"%d/%d\" found. Its index: %d\n", p, q, res);
	else
		printf(">>> \"%d/%d\" not found\n", p, q);
}

// prints the sum of all rationals
void sum(RationalsList& l)
{
	Rational sum = 0;
	Node<Rational>* temp = l.getHeadNode();
	while (temp)
	{
		sum += temp->data;
		temp = temp->next;
	}
	system("cls");
	printf(">>> Total sum is \"%d/%d\" = %.2f\n", sum.p, sum.q, (float)sum.p / (float)sum.q);
}

// removes value from list
void remove(RationalsList& l, int& length)
{
	int p, q;
	printf(">>> Enter p: ");
	cin >> p;
	printf(">>> Enter q: ");
	cin >> q;
	
	system("cls");
	bool res = l.remove(Rational(p, q));
	if (res)
	{
		printf(">>> \"%d/%d\" removed\n", p, q);
		length--;
	}
	else
		printf(">>> \"%d/%d\" not found\n", p, q);
}

// optimized solution, inline appending Rationals inside for-loop, not using the function getIthRational, time complexity is O(n)
void menu()
{
	int listLength = 0;
	RationalsList rationalList;

	char inp = ' ';
	while (inp != 'Q')
	{
		printf("A - add next rational\nI - initialize\nF - find value\nL - view list\nR - remove value\nS - sum of all values\nQ - quit\n");
		inp = toupper(_getch());

		system("cls");
		switch (inp)
		{
			case 'A':
				printf(">>> Add next rational\n");
				addNextNumber(rationalList, listLength);
				break;
			case 'F':
				printf(">>> Find value\n");
				find(rationalList);
				break;
			case 'L':
				printf(">>> View list\n");
				rationalList.printAll();
				break;
			case 'R':
				printf(">>> Remove value\n");
				remove(rationalList, listLength);
				break;
			case 'I':
				printf(">>> Initialize\n");
				listLength = initialize(rationalList);
				break;
			case 'S':
				printf(">>> Sum\n");
				sum(rationalList);
				break;
			case 'Q':
				printf(">>> Quit\n");
				break;
		}
	}
}

int main()
{
	menu();
}

