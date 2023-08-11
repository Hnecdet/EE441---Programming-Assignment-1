#include <iostream>
#include <chrono>
using namespace std;
/*
const int MaxStackSize2 = 20;
class Hanoi
{
private:
	int rod1[MaxStackSize2];
	int rod2[MaxStackSize2];
	int rod3[MaxStackSize2];
	int top1;
	int top2;
	int top3;
public:
	Hanoi(int x);
	void Push(const int& item, int x);
	int Pop(const int& item);
	void move(int from, int to);

};
    void solve_hanoi(Hanoi& game){
    }

*/
int nth_prime(int n);
void print_backwards(char const* string);
void benchmark(void (*func)(int))
{
    int const AMOUNT = 20;
    int const REPEAT = 100;
    double results[AMOUNT];
    for (int i = 0 ; i < AMOUNT ; ++i) {
        auto start = std::chrono::steady_clock::now();
        for (int j = 0 ; j < REPEAT ; ++j) {
            func(i+1);
        }
        auto finish = std::chrono::steady_clock::now();
        results[i] = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start).count() / REPEAT;
    }

    std::cout << std::endl << std::endl;
    std::cout << "n\ttime (ns)\n";
    for (int i = 0 ; i < AMOUNT ; ++i) {
        std::cout << i+1 << '\t' << results[i] << '\n';
    }
    std::cout << std::endl;
}
/*
void wrapper_solve_hanoi(int n)
{
    auto game = Hanoi(n);
    solve_hanoi(game);
}
*/
void wrapper_print_backwards(int n)
{
    char * str = new char[n+1];
    for (int i = 0 ; i < n ; ++i) {
        str[i] = 'a' + i;
    }
    str[n] = '\0';

    print_backwards(str);

    delete[] str;
}

void wrapper_nth_prime(int n)
{
    volatile int temp = nth_prime(n);
}

int main()
{
    benchmark(wrapper_nth_prime);
    //benchmark(wrapper_solve_hanoi);
    benchmark(wrapper_print_backwards);
    int a;
    int b;
    b = nth_prime(4);
    cout << b   << endl;
    char str[] = "in the morning ..";
	print_backwards(str);

    //Hanoi Hanoi(5);
	//Hanoi.move(2, 3);

}
