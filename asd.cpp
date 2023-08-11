
#include "benchmark.h"
#include <iostream>
#include <cstring>
using namespace std;
//returns true if the given number is prime
bool Prime(int n) {
    bool answer = true;
    if (n < 2)
        return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            answer = false;
        }
    }
    return answer;
}
int nth_prime(int n) {
    int count = 0;
    for (int i = 0, count = 0;count <= n;i++) {
        if (Prime(i)) {
            count++;
            if (count == n) {
                return i;
            }
        }
    }

}

const int MaxStackSize = 9999;
template <class T>
class Stack
{
private:
	T stacklist[MaxStackSize];
	int top;
public:
	Stack(void); // constructor to initialize top
	//modification operations
	void Push(const T& item);
	T Pop(void);
	//check stack state returns top element value without removal
	int StackEmpty(void) const;
	//returns true if the stack is empty
	int StackFull(void) const;
	//returns true if the stack is full
};
template <class T>
Stack<T>::Stack(void) :top(-1)
{}
template <class T>
//Push
void Stack<T>::Push(const T& item)//
{
	//can not push if stack has exceeded its limits
	if (top == MaxStackSize - 1)
	{
		cerr << "Stack overflow" << endl;
		exit(1);
	}
	// increment top and copy item into list
	top++;
	stacklist[top] = item;
}
template <class T>
//pop
T Stack<T>::Pop(void)
{
	T temp;
	// is stack empty nothing to pop
	if (top == -1)
	{
		cerr << "Stack empty" << endl;
		exit(1);
	}
	//record the top element
	temp = stacklist[top];
	//decrement top and return the earlier top element
	top--;
	return temp;
}
template <class T>
//StackEmpty: returns true if the stack is empty
int Stack<T>::StackEmpty(void) const
{
	return top == -1;
}
template <class T>
//StackFull: returns true if the stack is full
int Stack<T>::StackFull(void) const
{
	return top == (MaxStackSize - 1);
}

void print_backwards(char const* string) {
	Stack<char> S;
	int a = 0;

	for (char const* end = string;*end != '\0'; *end++)
	{
		S.Push(*end);
	}

	int i = 0;
	while (!S.StackEmpty())
	{
		cout << S.Pop();
	}
}
/*
class Disc {
private:

public:
	int diameterofdiscs[];
	Disc(int x);
};
Disc::Disc(int x) {
	if (x > 20 || x < 0) {
		cerr << "ERROR";
	}
	else {
		for (int i = 1; i < x; i++)
			diameterofdiscs[i] = i;
	}
}


Hanoi::Hanoi(int x) :top2(-1), top3(-1),top1(x-1)
{
	for (int i = 1, j = x; i <= top1, j<=1; i++, j--)
		rod1[i] = j;
	for (int i = 1; i < MaxStackSize2; i++ )
		rod2[i], rod3[i] = 0;
}
void Hanoi::Push(const int& item, int x)//
{
	//can not push if stack has exceeded its limits
	if (top1 == MaxStackSize2 - 1 || top3 == MaxStackSize2 - 1 || top2 == MaxStackSize2 - 1)
	{
		cerr << "Stack overflow" << endl;

	}
	// increment top and copy item into list
	if (item == 1) {
		top1++;
		rod1[top1] = x;
	}
	else if (item == 2) {
		top2++;
		rod2[top2] = x;
	}
	else if (item ==3) {
		top3++;
		rod3[top3] = x;
	}
	else
		cerr << "ERROR" << endl;

}
int Hanoi::Pop(const int& item)
{
	int temp;
	// is stack empty nothing to pop
	if (top1 == -1 || top2 == -1 || top3 == -1 )
	{
		cerr << "Stack empty" << endl;
	}
	if (item == 1) {
		//record the top element
		temp = rod1[top1];
		//decrement top and return the earlier top element
		top1--;
		return temp;
	}
	else if (item == 2) {
		//record the top element
		temp = rod1[top1];
		//decrement top and return the earlier top element
		top1--;
		return temp;
	}
	else if (item == 3) {
		//record the top element
		temp = rod1[top1];
		//decrement top and return the earlier top element
		top1--;
		return temp;
	}
	else
		cerr << "ERROR" << endl;


}
void Hanoi::move(int from, int to) {
	int a;
	cout << "Disc "<< endl;
			switch (from) {
			case 1:
				if (to == 2) {
					a = Pop(1);
					Push(2, a);
					cout << "Disc " << a << " is moved from Rod " << from << " to Rod " << to << endl;
					break;
				}
				else if (to == 3) {
					a = Pop(1);
					Push(3, a);
					cout << "Disc " << a << " is moved from Rod " << from << " to Rod " << to << endl;
					break;
				}
			case 2:
				if (to == 3) {
					a = Pop(2);
					Push(3, a);
					cout << "Disc " << a << " is moved from Rod " << from << " to Rod " << to << endl;
					break;
				}
				else if (to == 1) {
					a = Pop(2);
					Push(3, a);
					cout << "Disc " << a << " is moved from Rod " << from << " to Rod " << to << endl;
					break;
				}
			case 3:
				if (to == 1) {
					a = Pop(1);
					Push(1, a);
					cout << "Disc " << a << " is moved from Rod " << from << " to Rod " << to << endl;
					break;
				}
				else if (to == 2) {
					a = Pop(3);
					Push(2, a);
					cout << "Disc " << a << " is moved from Rod " << from << " to Rod " << to << endl;
					break;
				}
			}
		}

*/
