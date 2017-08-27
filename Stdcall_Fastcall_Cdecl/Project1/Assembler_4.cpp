#define CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
extern "C" int _stdcall Sol(int, int, int);
extern "C" int _fastcall Remainder(int, int);
extern "C" int _cdecl DivideByTwo(int);
extern "C" int _stdcall StrIndex(char*, int, char);
int main() {
	int Program;
	while (cout << "Please,enter the number of program : "&&cin >> Program) {
		switch (Program) {
		case 1: 
		{


			int a, x, b;
			cout << "Number of launched program = " << Program << endl;
			cout << "Lets calculate ax+b" << endl;
			cout << "Please,enter a,then x,then b" << endl;
			cin >> a >> x >> b;
			cout << a << "*" << x << "+" << b << "=" << Sol(a, x, b) << endl;
			break;
		}
		case 2:
		{
			int a, b;
			cout << "Number of launched program = " << Program << endl;
			cout <<"Please,enter integer a and b : " << endl;
			cin >> a >> b;
			cout << "Remainder from divizion a and b (a % b) = " << Remainder(a,b) << endl;
			break;
		}
		case 3:
		{
			int a;
			cout << "Number of launched program = " << Program << endl;
			cout << "Please,enter integer a : " << endl;
			cin >> a;
			cout <<a<<" / 2 = "<< DivideByTwo(a) << endl;
			break;
		}
		case 4:
		{
			char symb;
			cout << "Number of launched program = " << Program << endl;
			cout << "Our string: " << endl;
			char str[50] = "My name is Blurryface and I care what you think";
			for (int i = 0; i < strlen(str) + 1; i++) {
				cout << str[i];
			}
			cout << endl;
			cout << "Please,enter the sumbol to find : ";
			cin >> symb;
			if (StrIndex(str, strlen(str), symb) == -1) {
				cout << "There is no such symbol here =( " << endl;
			}
			else cout <<"Index of '"<<symb<<"' is "<< StrIndex(str, strlen(str), symb) << endl;

			break;
		}
		}
	}
	
	



	 
	

	system("pause");
	return 0;


}