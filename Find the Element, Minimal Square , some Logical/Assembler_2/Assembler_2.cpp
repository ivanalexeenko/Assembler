#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <iomanip>
#include <cmath>
#include<vector>
#include <set>
#include <algorithm>
using namespace std;
int* InsertionSort(int *def_arr,int N) {
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j>0; j--) {
			if (def_arr[j] < def_arr[j - 1]) {
				swap(def_arr[j], def_arr[j - 1]);
			}
		}
	}
	return def_arr;
}
void separator(int n) {
	for (int i = 0; i < n; i++) {
		cout << "/";
	}
	cout << endl;
}
int main() {
	
	int Number_of_Program;
	while (cout << "Please,enter the number of program to be launched:" << endl&&cin >> Number_of_Program)
	{
		switch (Number_of_Program)
		{
		case 1: 
		{
			const int N = 10;
			separator(100);
			cout << "Number of launched program:" << Number_of_Program << "(1)" << endl;
			cout << "Standart array:" <<setw(50)<<"Sorted Standart Array:"<< endl;
			int def_arr[N] = { 27,30,23,15,8,21,52,10,99,7};
			int sort_arr[N];
			for (int i = 0; i < N; i++) 
			{
				sort_arr[i] = def_arr[i];
			}
			InsertionSort(sort_arr,N);
			for (int i = 0; i < N; i++)
			{
				cout << "Arr[" << i << "]=" << def_arr[i]<<setw(40)<<"Arr["<<i<<"]="<<sort_arr[i]<< endl;
			}
			int left=0, right=9, middle;
			int index;
			int two = 2;
			int one = 1;
			int number;
			int steps = 0;
			int number_is_here = 1;
			cout << "Please,enter the number to search:";
			cin >> number;
			cout << endl;
			_asm
			{

				lea ebx,sort_arr
				xor esi,esi

				_calc:
				mov eax,right
				add eax,left
				imul one
				idiv two
				mov middle,eax
				mov esi,middle
				mov ecx, [ebx][esi* 4] 
				jmp _begin

				_begin:
				cmp number,ecx
				je if_equal
				jg if_greater
				jl if_less


				if_greater:
				mov edx,middle
				mov left,edx
				inc steps

				mov eax,steps
				cmp eax,N
				jg no_elements
				jmp _calc
				
				if_less:
				mov edx, middle
				mov right, edx
				inc steps
				mov eax, steps
				cmp eax, N
				jg no_elements
				jmp _calc


				if_equal:
				mov edx,middle
				mov index,edx
				jmp do_nothing

				no_elements:
				mov eax,0
				mov number_is_here,eax

				do_nothing:
			}
			if (number_is_here == 0 && number == sort_arr[N - 1])
			{
				index = N - 1;
				cout << "Customer's number=" << number << "=" << "sort_arr[" << index << "]" << endl;
			}
			else if(number_is_here == 0 && number != sort_arr[N - 1])
			{
				cout<<"There is no such element here =(" << endl;
			}
			else if (number_is_here == 1)
			{
				cout << "Customer's number="<<number<<"="<<"sort_arr["<< index<<"]"<< endl;

			}
			

				separator(100);
				break;
			}
		case 2:
		{
			int buf = 0;
			const int N = 10;
			const int M = 8;
			int sub_one[N] = {21,23,29,7,5,26,28,24,17,15};
			int sub_two[M] = {23,26,377,7,1,34,24,12};
			const int maximum = max(N, M);
			int temp[maximum];
			int amal_num = 0;
			int amal[M + N];
			int index = 0;
			separator(100);
			InsertionSort(sub_one,N);
			InsertionSort(sub_two,M);
			cout << "Number of launched program:" << Number_of_Program << "(9)" << endl;
			cout << "First Subset = { ";
			for (int i = 0; i < N; i++) {
				cout << sub_one[i] << ends;
			}
			cout <<"}"<< endl;
			cout << "Second Subset = { ";
			for (int i = 0; i < M; i++) {
				cout << sub_two[i] << ends;
			}
			cout << "}" << endl;

			vector<int> intersection;
			set<int>amalgamation;

			_asm
			{
				lea ebx, temp
				lea ecx, sub_one
				lea edx, sub_two
				xor esi, esi
				mov esi, -1

				First_Cycle_Start :
				add esi, 1
					xor edi, edi
					cmp esi, N
					je _nothing

					Second_Cycle_Start :

				cmp edi, M
					je First_Cycle_Start
					mov eax, [ecx][esi * 4]
					cmp eax, [edx][edi * 4]

					je New_Element
					add edi, 1
					jmp Second_Cycle_Start



					New_Element :
				mov eax, [ecx][esi * 4]
					mov buf, esi
					mov esi, index

					mov[ebx][esi * 4], eax
					mov esi, buf
					mov eax, index
					inc eax
					mov index, eax
					jmp First_Cycle_Start


					_nothing :
			}

			cout << "Intersection (sub_1 && sub_2 ) = { ";
			for (int i = 0; i < index; i++) 
			{
				intersection.push_back(temp[i]);
			}

			for (int i = 0; i < intersection.size(); i++)
			{
				cout << intersection[i] << ends;
			}
			cout << "}" << endl;

			_asm
			{
				lea eax,sub_one
				lea ebx,sub_two
				lea ecx,amal
				xor esi,esi
				xor edi,edi
				mov esi,-1
				_ready:
				inc esi
				cmp esi,N
				je _steady
				mov edx,[eax][esi*4]
				mov buf,edi
				mov edi,amal_num
				mov [ecx][edi*4],edx
				inc edi
				mov amal_num,edi
				mov edi,buf
				
				jmp _ready
				_steady:

				cmp edi,M
				je _go
				mov edx, [ebx][edi * 4]
					mov buf, edi
					mov edi, amal_num
					mov[ecx][edi * 4], edx
					inc edi
					mov amal_num, edi
					mov edi, buf
					inc edi
				jmp _steady
				_go:
			}
			for (int i = 0; i < amal_num; i++) 
			{
				amalgamation.insert(amal[i]);
			}
			cout << "Amalgamation (sub_1 || sub_2 ) = { ";
			for (set<int>::iterator i = amalgamation.begin(); i != amalgamation.end(); i++)
			{
				cout << *i << ends;
			}
			cout <<"}"<< endl;
			separator(100);
			break;
		}
		case 3:
		{
			separator(100);
			cout << "Number of launched program:" << Number_of_Program << "(13)" << endl;
			const int N = 10;
			int min_area;
			int OX[N] = { 46,20,9,35,7,86,21,45,79,5 };
			int OY[N] = { 45,-13,56,2,67,47,20,42,10,77 };
			int x_min;
			int x_max;
			int y_min;
			int y_max;
			int a, b;

			// X-Block(min & max)
			_asm
			{
				lea eax, OX
				xor esi, esi
				mov ecx, [eax][esi * 4]
				mov x_min, ecx

				mov esi, -1
				_first:
				inc esi
					cmp esi, N
					je _end
					mov ecx, [eax][esi * 4]
					cmp x_min, ecx
					jg _change_X_MIN
					mov ecx, [eax][esi * 4]
					cmp x_max, ecx
					jl _change_X_MAX

					jmp _first

					_change_X_MIN :
				mov ecx, [eax][esi * 4]
					mov x_min, ecx
					jmp _first


					_change_X_MAX :

				mov ecx, [eax][esi * 4]
					mov x_max, ecx
					jmp _first

					_end :
			}
			// Y-Block(min & max)
			_asm
			{
				lea ebx, OY
				xor edi, edi
				mov ecx, [ebx][edi * 4]
				mov y_min, ecx

				mov edi, -1
				_first_:
				inc edi
					cmp edi, N
					je _end_
					mov ecx, [ebx][edi * 4]
					cmp y_min, ecx
					jg _change_Y_MIN
					mov ecx, [ebx][edi * 4]
					cmp y_max, ecx
					jl _change_Y_MAX

					jmp _first_

					_change_Y_MIN :
				mov ecx, [ebx][edi * 4]
					mov y_min, ecx
					jmp _first_


					_change_Y_MAX :

				mov ecx, [ebx][edi * 4]
					mov y_max, ecx
					jmp _first_

					_end_ :

			}
			// Area-Block(calculating)
			_asm
			{
				mov eax, x_max
				sub eax, x_min
				mov a, eax

				mov ebx, y_max
				sub ebx, y_min
				mov b, ebx
				mov ecx, a
				imul ecx, b
				mov min_area, ecx


			}
			cout << "Our points :" << ends;
			for (int i = 0; i < N; i++) {
				cout<<"{"<<OX[i]<<","<<OY[i]<<"}" << ends;
			}
			cout << endl;
			cout <<"x_min=" <<x_min << endl;
			cout <<"x_max="<< x_max << endl;
			cout <<"y_min="<< y_min << endl;
			cout <<"y_max="<< y_max << endl;
			cout <<"side a="<<a<< endl;
			cout <<"side b="<< b<< endl;
			cout <<"Minimum Area="<<min_area<< endl;

			separator(100);
			break;
		}
		}


	}
	





	system("pause");
	return 0;
}