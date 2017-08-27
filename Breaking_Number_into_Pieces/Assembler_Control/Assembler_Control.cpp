#define CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
extern "C" int* _cdecl Sort_n_Amount_of_Num(int*, int);
extern "C" int _cdecl Amount_of_Numbers(int);
int main() {
	int a;
	cin >> a;
	int arr[50];
	int N = Amount_of_Numbers(a);
	for (int i = 0; i < N+1; i++) {
		cout << Sort_n_Amount_of_Num(arr, a)[i];
		cout << ends;

	}

	system("pause");
	return 0;
}