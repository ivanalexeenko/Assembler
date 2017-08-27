#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;
void separator(int n) {
	for (int i = 0; i < n; i++) {
		cout << "/";
	}
	cout << endl;
}
int main() {
	int Number_of_Program;
	while (cout << "Please,enter the number of program to be launched:" << endl&& cin >> Number_of_Program) {
		switch (Number_of_Program) {
		case 1:
		{
			int a;
			int res;
			separator(40);
			cout << "Number of launched program = " << Number_of_Program;
			cout << endl;
			cout << "Let's calculate a^12+a^8+a !" << endl;
			cout << "Please,enter integer positive a: ";
			cin >> a;

			_asm {
				mov eax, a
				imul a
				imul a
				imul a
				imul a
				imul a
				imul a
				imul a
				imul a
				imul a
				imul a
				imul a
				mov res, eax
				mov eax, a
				imul a
				imul a
				imul a
				imul a
				imul a
				imul a
				imul a
				add res, eax
				mov ebx, a
				add res, ebx
			}
			cout << a << "^12+" << a << "^8+" << a << "=" << res << endl;
			separator(40);
			break;
		}
		case 2:
		{
			int one = 1;
			int a, b;
			int quotient, modulo;
			separator(40);
			cout << "Number of launched program = " << Number_of_Program;
			cout << endl;
			cout << "Let's find x in ax+b=0 !" << endl;
			cout << "Please,enter integer a & b: ";
			cin >> a >> b;
			if (a == 0 && b != 0) {
				cout << "There is no solution! Zero Divizion!" << endl;
			}
			else if (a == 0 && b == 0) {
				cout << "X can be any number ! " << endl;
			}

			else {
				_asm {
					mov eax, b
					mov ebx, a
					neg eax
					imul one
					idiv ebx
					mov quotient, eax
					mov modulo, edx


				}
				if (b < 0) {
					cout << a << "x" << b << "=0" << endl;
				}
				else cout << a << "x+" << b << "=0" << endl;
				cout << "x = " << quotient << "(modulo=" << modulo << ")" << endl;
			}


			separator(40);
			break;
		}
		case 3:
		{
			int x = 0;
			int y = 0;
			int max_x = 26;
			int max_y = 17;
			int fifty = 50;
			int one = 1;
			int two = 2;
			int three = 3;

			int sol[18];

			separator(40);
			cout << "Number of launched program = " << Number_of_Program;
			cout << endl;
			cout << "Let's calculate the number of integer solutions of 50=2x+3y !" << endl;
			cout << "Integer Solutions:" << endl;

			_asm {
				lea ebx, sol
				xor esi, esi
				CycleOne :
				mov edx, max_x

					cmp edx, x
					je FirstCycleEnd
					mov y, 0
					CycleTwo :

					mov edx, max_y
					cmp edx, y
					je SecondCycleEnd
					mov eax, x
					imul two
					mov ecx, eax
					mov eax, y
					imul three
					add eax, ecx
					cmp eax, fifty
					jne CONTINUE
					mov eax, x
					mov[ebx + esi * 4], eax
					inc esi
					mov eax, y
					mov[ebx][esi * 4], eax
					inc esi





				CONTINUE:
				inc y
					jmp CycleTwo

					SecondCycleEnd :
				inc x
					jmp CycleOne
					FirstCycleEnd :


			}
			for (int i = 0; i < 17; i += 2) {
				cout << "X=" << sol[i] << ends << "Y=" << sol[i + 1] << endl;
			}
			separator(40);
			break;
		}
		case 4:
		{
			int i = 0;
			int result;
			int a;
			int n = 0;
			separator(40);
			cout << "Number of launched program = " << Number_of_Program;
			cout << endl;
			cout << "Let's find maximum appropriate n in a^n" << endl;
			cout << "Please,enter integer a:";
			cin >> a;
			
			if ((a < 2)&&(a>=0))
			{
				cout << "<<n>> can be any integer number =)" << endl;
				separator(40);
			}
			else
			{
				_asm
				{
					mov eax, a
					CycleStart :
					jo CycleFinish
						mov ebx, n
						add ebx, 1
						mov n, ebx
						imul a
						jmp CycleStart
						CycleFinish :
				
				}
				_asm {
					mov eax, a
					mov ebx, n
					dec ebx
					ResultStart :
					cmp ebx, i
						je ResultEnd
						imul a
						inc i
						jmp ResultStart
						ResultEnd :
					mov result, eax
				}

				cout <<"Maximum appropriate n="<< n << endl;
				cout << "Checking..." << endl;
				cout << a << "^" << n << "=" << result << "<=" << INT_MAX << "<=" << a << "^" << n + 1 << endl;
				separator(40);
			}
		

			break;
		}
		case 5:
		{
			int Fib[46];
			_asm {

				lea ecx, Fib
				xor esi, esi
				mov eax, 1
				mov ebx, 0
				mov[ecx + esi * 4], ebx
				inc esi
				mov[ecx + esi * 4], eax
				inc esi
				CycleStarts :

				mov edx, eax
					add eax, ebx
					mov	ebx, edx



					jo CycleFinishes
					mov[ecx + esi * 4], eax
					inc esi
					jmp CycleStarts


					CycleFinishes :
			}
			separator(40);
			cout << "Number of launched program = " << Number_of_Program;
			cout << endl;
			cout << "Fibonacci sequence:" << endl;
			for (int i = 0; i < 47; i++) {
				cout << Fib[i] << endl;
			}
			separator(40);
			break;
		}
		}
	}
}