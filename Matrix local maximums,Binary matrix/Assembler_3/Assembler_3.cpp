#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <iomanip>
#include <cmath>
#include<vector>
#include <set>
#include <algorithm>
using namespace std;
int* InsertionSort(int *def_arr, int N) {
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
	while (cout << "Please,enter the number of program to be launched : "&&cin >> Number_of_Program) 
	{
		switch (Number_of_Program)
		
		{

		case 1:
		{
			system("cls");
		 static	const int N = 5;
		 static	const int num_of_elem = N * N;
			int number_of_max = 0;
			int Matrix[N][N] = { {45,-13,56,2,67},{47,20,42,10,77},{46,20,9,35,7},{86,21,45,79,5},{23,0,51,11,80} };
			separator(100);
			cout << "Number of launched program = " << Number_of_Program <<endl;
			cout << "Our Square Matrix:" << endl;
			int null = 0;
			int addit_arr_size = N + 2;
			for (int i = 0; i < N; i++) {
				cout << endl;
				for (int j = 0; j < N; j++) {
					cout << Matrix[i][j] << ends;
				}
			}
		
			int lines_n_columns[N*N];

			int arr_for_sort[N];
			int buf = 0;
			int coef = 1;
			int m, n;
			// Local Maximums
			_asm 
			{
				lea eax,Matrix
				lea ebx,lines_n_columns
				xor esi,esi
				mov esi,-1
				mov edi,0
				mov edx, addit_arr_size
				mov ecx, addit_arr_size
				imul ecx, 2
				sub edx, ecx
				dec edx
				dec edx

					push_int_min_around_top:
				dec edi
				cmp edi,edx
				je push_int_min_around_bottom
				mov [eax][edi*4],INT_MIN
				jmp push_int_min_around_top

					push_int_min_around_bottom :
				mov edi, N
				imul edi,N
				mov edx,edi
				add edx,addit_arr_size
				inc edx
				dec edi
					bottom_start:
				inc edi
				cmp edi,edx 
				je _begin
				mov[eax][edi * 4], INT_MIN
				jmp bottom_start



					_begin:
				inc esi
				cmp num_of_elem,esi
				je _nothing
					push eax
					mov eax, esi
					cdq
					idiv N
					pop eax
					cmp edx, null
					je _check_left

					push eax
					mov eax, esi
					inc eax
					cdq
					idiv N
					pop eax
					cmp edx, null
					je _check_right

					jmp _check_another

				
					
				
					jmp _begin


				
				
					_check_left:
				
				mov ecx, [eax][esi * 4]

					mov edi, esi
					sub edi, N
					cmp[eax][edi * 4], ecx
					jg _begin

				
					mov edi,esi
					sub edi, N
					add edi,1
				cmp [eax][edi * 4],ecx
				jg _begin

				mov edi, esi
				add edi,1
				cmp [eax][edi * 4], ecx
				jg _begin
					mov edi, esi
					add edi, 1
					add edi, N
					cmp[eax][edi * 4], ecx
					jg _begin

					mov edi, esi
					add edi, N
					cmp[eax][edi * 4], ecx
					jg _begin


				
				jmp _push_elem
				
					_check_right:
				mov ecx, [eax][esi * 4]

					mov edi, esi
					sub edi, N
					cmp[eax][edi * 4], ecx
					jg _begin

					mov edi, esi
					sub edi, N
					sub edi, 1
					cmp[eax][edi * 4], ecx
					jg _begin

					mov edi, esi
					sub edi, 1
					cmp[eax][edi * 4], ecx
					jg _begin

					mov edi, esi
					sub edi, 1
					add edi, N
					cmp[eax][edi * 4], ecx
					jg _begin

					mov edi, esi
					add edi, N
					cmp[eax][edi * 4], ecx
					jg _begin

					jmp _push_elem

						_check_another:
				mov ecx, [eax][esi * 4]

					mov edi, esi
					sub edi, N
					cmp[eax][edi * 4], ecx
					jg _begin

					mov edi, esi
					sub edi, N
					sub edi, 1
					cmp[eax][edi * 4], ecx
					jg _begin

					mov edi, esi
					sub edi, 1
					cmp[eax][edi * 4], ecx
					jg _begin

					mov edi, esi
					sub edi, 1
					add edi, N
					cmp[eax][edi * 4], ecx
					jg _begin

					mov edi, esi
					add edi, N
					cmp[eax][edi * 4], ecx
					jg _begin

					mov edi, esi
					add edi, N
					add edi, 1
					cmp[eax][edi * 4], ecx
					jg _begin

					mov edi, esi
					add edi, 1
					cmp[eax][edi * 4], ecx
					jg _begin

					mov edi, esi
					sub edi, N
					add edi,1
					cmp[eax][edi * 4], ecx
					jg _begin


					jmp _push_elem


		

				_push_elem:
				mov edi, esi
					mov esi, number_of_max
					mov[ebx][esi * 4], edi
					inc esi
					mov number_of_max, esi
					mov esi, edi

				jmp _begin
				_nothing:
			}
			cout << endl << endl;
			cout << "Local maximums:" << endl << endl;
			for (int i = 0; i < number_of_max; i++) {
				m = lines_n_columns[i] / N;
				n = lines_n_columns[i] % N;
				cout<<"Matrix"<<"["<< m <<"]["<< n <<"]=" << Matrix[m][n] << endl;
			}
			cout << endl;
			// Lines Sort
			_asm
			{
				lea eax,Matrix
				lea ebx,arr_for_sort
				xor esi,esi
				mov esi,-1
				mov edi,-1
				_start:
				inc esi
				mov edx,N

				imul edx,coef
				cmp esi,edx
				je _out

				mov ecx,[eax][esi*4]
				inc edi
				mov [ebx][edi*4],ecx

				jmp _start

					_out:

				cmp esi,num_of_elem 
				je _sort
				mov edi,-1
				dec esi
				jmp _sort

					_sort:
				mov buf,esi
				push eax
				push esi
				push edi

				
				push ecx
				push edx


				mov esi,0

					_sort_begin:
				inc esi
				mov edi, esi
				inc edi
				cmp esi,N
				je _fill
					_sort_continue:
				dec edi
				cmp edi,0
				je _sort_begin
				mov ecx,edi
				dec ecx
				mov eax,[ebx][edi*4]
				cmp eax,[ebx][ecx*4]
				jl _swap

				jmp _sort_continue

					_swap:
				mov edx, [ebx][ecx * 4]
				mov [ebx][ecx * 4],eax
				mov	[ebx][edi * 4], edx
				jmp	_sort_continue

					_fill:

					lea eax,Matrix
					
					mov esi,-1
						_fill_start:
					mov edx,coef
					dec edx
					imul edx,N
					mov edi,edx
					dec edi
						_fill_continue:
					inc esi
					inc edi
					cmp esi,N
					je _bring_them_back
					mov ecx,[ebx][esi*4]
					mov [eax][edi*4],ecx
					jmp _fill_continue
					
						_bring_them_back:
					pop esi
					pop edi
					pop ecx
					pop edx
					mov esi,buf
					mov edx, coef
					inc edx
					mov coef, edx
					mov edi, -1
					cmp esi,num_of_elem
					je _finita
					jmp _start

					_finita:

			}
			cout << "Our Matrix with Sorted lines:" << endl;
			for (int i = 0; i < N; i++) {
				cout << endl;
				for (int j = 0; j < N; j++) {
					cout << Matrix[i][j] << ends;
				}
			}
			cout << endl;
			// Lines Reshuffle Sort
			int MatrixCopy[N][N];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					MatrixCopy[i][j] = Matrix[i][j];
				}
			}
			int Indexes[N];
			for (int i = 0; i < N; i++) {
				Indexes[i] = i;
			}
			cout << endl;
			int LineMaxes[N];
			coef = 1;
			buf = -1;
			_asm
			{
				lea eax, LineMaxes
				lea ebx, Matrix
				
				mov esi,-1
				mov edi, -1
					_mov_maxes:
				inc esi
				add edi,N

				cmp esi,N
				je _sort_maxes_n_indexes
				mov ecx,[ebx][edi*4]
				mov [eax][esi*4],ecx
				jmp _mov_maxes
					_sort_maxes_n_indexes:
				mov esi, 0
					sort_begin:
				inc esi
				mov edi, esi
				inc edi
				cmp esi,N
				je _end_of_sort
					sort_continue :
					dec edi
					cmp edi, 0
					je sort_begin
					mov ecx, edi
					dec ecx
					mov edx, [eax][edi * 4]
					cmp edx, [eax][ecx * 4]
					jl _swap_
					jmp sort_continue
					_swap_ :
				push esi
				mov esi,edx
				mov edx, [eax][ecx * 4]
					mov[eax][ecx * 4], esi
					mov[eax][edi * 4], edx

					lea ebx,Indexes
					mov esi, [ebx][edi * 4]
					mov edx,[ebx][ecx*4]
					mov[ebx][ecx*4],esi
					mov[ebx][edi * 4], edx
					pop esi
					jmp	sort_continue

					_end_of_sort:
					lea ebx, Matrix
					lea ecx, MatrixCopy
					lea edx,Indexes

					mov esi,buf
					inc esi
					mov buf,esi
					mov esi,buf
					cmp esi,N
					je done_yeah

					mov edi, [edx][esi * 4]
					imul edi,N
					add edi,N
					mov coef,edi
					sub edi,N
					dec edi
					mov esi,buf
					imul esi,N
						_start_filling:
					inc edi
					mov eax,coef
					cmp edi,eax
					je _end_of_sort
					
					mov eax, [ecx][edi * 4]
					mov [ebx][esi*4],eax
					inc esi
					jmp _start_filling 

						done_yeah:



			}
			cout << "Our Matrix after Reshuffling Sort:" << endl;
			for (int i = 0; i < N; i++) {
				cout << endl;
				for (int j = 0; j < N; j++) {
					cout << Matrix[i][j] << ends;
				}
			}
			cout << endl;
			separator(100);
			break;
		}
		case 2:
		{
			system("cls");
			separator(100);
			cout << "Number of launched program = " << Number_of_Program << endl;
			static const int N = 5;
			static const int M = 7;
			int BinaryMatrix[N][M] = { {1,1,0,1,1,0,1},{1,0,1,1,1,0,0},{1,1,0,1,0,1,1},{0,1,1,0,1,1,1},{0,1,1,1,0,1,1} };
			cout << "Our Binary Matrix:" << endl;
			for (int i = 0; i < N; i++) {
				cout << endl;
				for (int j = 0; j < M; j++) {
					cout << BinaryMatrix[i][j] << ends;
				}
			}
			int max_combo_line=1;
			int max_combo_number_line = 0;
			int indexes_of_max_lines[M];

			int indexes_of_max_columns[N];
			int max_combo_column = 1;
			int max_combo_number_column = 0;


			int elem_num = N*M;
			int buf = 0;
			int coef = 1;

			
			// Lines
			_asm 
			{
				lea edx,BinaryMatrix
				mov esi,-1
				_start_:
					mov ebx, N
					imul ebx, M
					cmp esi, ebx
					je _out_
				inc esi
				mov eax,coef
				imul eax,M
				cmp esi, eax
				je _next_line_
				mov eax,[edx][esi*4]
				cmp eax,1
				je _push_one_

				mov eax,max_combo_line
				cmp buf,eax
				je _equal_to_max_
				jg _greater_than_max_
				jl _less_than_max_
				
					_next_line_:
				
				
				dec esi
					mov eax, max_combo_line
					cmp buf, eax
					
					jg _greater_than_max_
					je _equal_to_max_

				mov ecx,0
				mov buf,ecx
				mov eax,coef
				inc eax
				mov coef,eax
				jmp _start_
					_push_one_:
				
				mov eax, buf
				inc eax
				mov buf, eax

				jmp _start_
				
					_equal_to_max_:
				mov eax, max_combo_number_line
				inc eax
				mov max_combo_number_line,eax
				mov eax, 0
				mov buf, eax
				jmp _start_
					_greater_than_max_:
				mov eax,buf
				mov max_combo_line,eax
				mov eax,0
				mov buf,eax
				mov eax,1
				mov max_combo_number_line,1
				jmp _start_

					_less_than_max_:
				mov eax, 0
				mov buf, eax
				jmp _start_




					_out_:
				mov eax,1
				mov coef,1

				lea eax,indexes_of_max_lines
				lea edx, BinaryMatrix
				mov esi,-1
				mov edi,0
					_beg_:
				mov ebx, N
				imul ebx, M
				cmp esi, ebx
				je _end_
				inc esi
					mov ebx, coef
					imul ebx, M
					cmp esi, ebx
					je _next_
					mov ebx, [edx][esi * 4]
					cmp ebx, 1
					je _push_
					mov ebx,0
					mov buf,ebx
					jmp _beg_

					_push_:
				mov ecx,buf
				inc ecx 
				mov buf,ecx
				mov ecx,buf
				cmp ecx,max_combo_line
				je _mov_index_
				jmp _beg_

					_mov_index_:
				mov ecx, 0
				mov buf, ecx
				mov [eax][edi*4],esi
				inc edi
				jmp _beg_
				
					_next_:
					dec esi
					mov ecx,coef
					inc ecx
					mov coef,ecx

					mov ecx,buf
					cmp ecx,max_combo_line 
					je _mov_index_
					mov ecx,0
					mov buf,ecx

					jmp _beg_
			
					_end_:

			}

			cout << endl << endl;
			cout << "Max Line Sequence = " << max_combo_line << " ( " << max_combo_number_line << " time(s) )" << endl << endl;

			coef = 0;
			buf = 0;
			// Columns
			_asm
			{
				lea edx, BinaryMatrix
				mov esi,M
				sub esi,M
				sub esi,M
				_start_col:

					
					mov ebx,M
					cmp ebx, coef
					je _out_col

					add esi,M
					cdq
					mov eax, esi
					idiv M
					cmp eax,N
					je _next_column_
					lea edx, BinaryMatrix
					mov ebx, [edx][esi * 4]
					cmp ebx, 1
					je _push_one_col

					mov eax, max_combo_column
					cmp buf, eax
					je _equal_to_max_col
					jg _greater_than_max_col
					jl _less_than_max_col

					_next_column_ :

					mov eax, coef
					inc eax
					mov coef, eax
					mov esi, M
					sub esi, M
					sub esi, M
					add esi, coef
					mov eax, max_combo_column
					cmp buf, eax

					jg _greater_than_max_col
					je _equal_to_max_col
						
					mov ecx, 0
					mov buf, ecx
					

					mov esi, M
					sub esi, M
					sub esi, M
					add esi, coef
					jmp _start_col
					_push_one_col :

					mov eax, buf
					inc eax
					mov buf, eax

					jmp _start_col

					_equal_to_max_col :
				mov eax, max_combo_number_column
					inc eax
					mov max_combo_number_column, eax
					mov eax, 0
					mov buf, eax
					jmp _start_col
					_greater_than_max_col :
				mov eax, buf
					mov max_combo_column, eax
					mov eax, 0
					mov buf, eax
					mov eax, 1
					mov max_combo_number_column, 1
					jmp _start_col

					_less_than_max_col :
				mov eax, 0
					mov buf, eax
					jmp _start_col
					/////////////////////////////////////////////////////////////

					
					_out_col :

					mov eax, 0
					mov buf,eax

					mov coef,eax

					
					lea edx, BinaryMatrix

					mov esi, M
					sub esi,M
					sub esi, M
					mov edi, 0

					_beg_col:
					mov ebx, M
					cmp ebx, coef
					je _end_col

					add esi, M
					imul eax, 1
					cdq
					mov eax, esi
					idiv  M
					cmp eax, N

					je _next_col_

					lea edx, BinaryMatrix
					mov ecx, [edx][esi * 4]
					cmp ecx, 1
		
					je _push_c_

					mov ebx, 0
					mov buf, ebx
					jmp _beg_col

					_push_c_ :
					mov ecx, buf
					inc ecx
					mov buf, ecx
					mov ecx, buf
					cmp ecx, max_combo_column
					je _mov_index_col
					jmp _beg_col

						_mov_index_col :
				lea eax, indexes_of_max_columns
				mov[eax][edi * 4], esi
					inc edi
					mov ecx,0
					mov buf,ecx

					jmp _beg_col

					_next_col_ :
				mov eax, coef
					inc eax
					mov coef, eax
					mov esi, M
					sub esi, M
					sub esi, M
					add esi, coef
					mov ecx,buf
				cmp ecx, max_combo_column
					je _mov_index_col

					mov ecx, 0
					mov buf, ecx

					jmp _beg_col

					_end_col:

			}

			cout << "Max Column Sequence = " << max_combo_column << " ( " << max_combo_number_column << " time(s) )" << endl << endl;

			int k = 0;
			

			int line_indexes[N*M];
			int column_indexes[N*M];
			int num_of_intersections = 0;

			cout << "Matrix of Maximums:" << endl;
			int EqualSizedNullMatrix[N][M];
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++) {
					EqualSizedNullMatrix[i][j]=0;
				}
			}

			for (int i = 0; i < max_combo_number_line; i++) {
				for (int j = indexes_of_max_lines[i]; j > indexes_of_max_lines[i] - max_combo_line; j--) {
					EqualSizedNullMatrix[j/M][j%M]=1;
					line_indexes[k]=j;
					k++;
				}
			}
			k = 0;
			for (int i = 0; i < max_combo_number_column; i++) {
				for (int j = indexes_of_max_columns[i]; j > indexes_of_max_columns[i] - max_combo_column*M; j-=M) {
					EqualSizedNullMatrix[j / M][j%M] = 1;
					column_indexes[k]=j;
					k++;
				}
			}

			for (int i = 0; i < N; i++) {
				cout << endl;
				for (int j = 0; j < M; j++) {
					if (EqualSizedNullMatrix[i][j] == 1) {
						cout << EqualSizedNullMatrix[i][j] << ends;
					}
					else cout << "*" << ends;
				}
			}
			cout << endl;
			/*for (int i = 0; i < max_combo_number_line*max_combo_line; i++) {
				cout << line_indexes[i] << ends;
			}
			cout << endl;
			for (int i = 0; i < max_combo_number_column*max_combo_column; i++) {
				cout << column_indexes[i] << ends;
			}
			cout << endl;*/
			int line_ind_n = max_combo_number_line*max_combo_line;
			int col_ind_n = max_combo_number_column*max_combo_column;
			
			// Intersections
			_asm
			{
				lea eax, line_indexes
				lea ebx, column_indexes
				mov esi,-1
					_ready:
				mov edi,-1
				inc esi
				cmp esi, line_ind_n
				je _get_out
					_steady:
				inc edi
				cmp edi, col_ind_n
				je _ready
				mov ecx,[eax][esi*4]
				cmp ecx,[ebx][edi*4]
				je _go

				jmp _steady
					_go:
				mov edx,num_of_intersections
				inc edx
				mov num_of_intersections,edx
				jmp _steady




				_get_out:




			}
			
			
			cout << endl;
			cout <<"Amount of Intersections = "<< num_of_intersections << endl;

			int num_of_locked = 0;

			// Locked Areas
			_asm
			{
			
			
					

				lea eax, BinaryMatrix
				mov esi,0
					frame_up:

				dec esi
					mov edx,0
					sub edx,M
					sub edx,2
					cmp esi,edx
					je frame_down
				mov ebx,1

				mov [eax][esi*4],ebx
					jmp frame_up

					frame_down:
				mov esi,M
				imul esi,N
					frame_down_cont:
					inc esi
					mov edx,M
					imul edx,N
					add edx,M
					add edx,2
					cmp esi,edx
					je start_working
						mov ebx, 1
						mov[eax][esi * 4], ebx
					jmp frame_down_cont

						start_working:

					lea ecx,BinaryMatrix
					mov esi, -1

						lets_start :
						inc esi
						cmp esi, elem_num
						je _do_nothing

						mov eax,esi
						cdq
						idiv M
						cmp edx,0
						je _left_side

						mov eax,esi
						cdq
						add eax,1
						idiv M
						cmp edx, 0
						je _right_side
						




						mov ebx, [ecx][esi * 4]
						cmp ebx, 0
						jne lets_start

						mov edi, esi
						sub edi, M
						mov ebx, [ecx][edi * 4]
						cmp ebx, 1
						jne lets_start

						mov edi, esi
						sub edi, M
						sub edi,1
						mov ebx, [ecx][edi * 4]
						cmp ebx, 1
						jne lets_start
					
						mov edi, esi
						sub edi, 1
						mov ebx, [ecx][edi * 4]
						cmp ebx, 1
						jne lets_start

						mov edi, esi
						add edi, M
						sub edi,1
						mov ebx, [ecx][edi * 4]
						cmp ebx, 1
						jne lets_start

						mov edi, esi
						add edi, M
						mov ebx, [ecx][edi * 4]
						cmp ebx, 1
						jne lets_start

						mov edi, esi
						add edi, M
						add edi,1
						mov ebx, [ecx][edi * 4]
						cmp ebx, 1
						jne lets_start

						mov edi, esi
						add edi, 1
						mov ebx, [ecx][edi * 4]
						cmp ebx, 1
						jne lets_start

						mov edi, esi
						add edi,1
						sub edi, M
						mov ebx, [ecx][edi * 4]
						cmp ebx, 1
						jne lets_start

						jmp add_one

						_left_side:

						mov ebx, [ecx][esi * 4]
						cmp ebx,0
						jne lets_start
						
						mov edi,esi
						sub edi,M
						mov ebx, [ecx][edi * 4]
						cmp ebx,1
						jne lets_start

						mov edi, esi
						sub edi, M
						add edi,1
						mov ebx, [ecx][edi * 4]
						cmp ebx, 1
						jne lets_start

						mov edi, esi
						add edi,1
						mov ebx, [ecx][edi * 4]
						cmp ebx, 1
						jne lets_start

						mov edi, esi
						add edi,M
						add edi,1
						mov ebx, [ecx][edi * 4]
						cmp ebx, 1
						jne lets_start
							
						mov edi, esi
						add edi, M
						mov ebx, [ecx][edi * 4]
						cmp ebx, 1
						jne lets_start

						jmp add_one




								_right_side:

							mov ebx, [ecx][esi * 4]
							cmp ebx, 0
							jne lets_start

							mov edi, esi
							sub edi, M
							mov ebx, [ecx][edi * 4]
							cmp ebx, 1
							jne lets_start

							mov edi, esi
							sub edi, M
							sub edi, 1
							mov ebx, [ecx][edi * 4]
							cmp ebx, 1
							jne lets_start

							mov edi, esi
							sub edi, 1
							mov ebx, [ecx][edi * 4]
							cmp ebx, 1
							jne lets_start

							mov edi, esi
							add edi, M
							sub edi, 1
							mov ebx, [ecx][edi * 4]
							cmp ebx, 1
							jne lets_start

							mov edi, esi
							add edi, M
							mov ebx, [ecx][edi * 4]
							cmp ebx, 1
							jne lets_start

							jmp add_one


							add_one:

						mov eax, num_of_locked
						inc eax
						mov num_of_locked,eax
						jmp lets_start


						_do_nothing : 
				



			}
			cout << "Amount of Locked Areas = " << num_of_locked << endl;

			cout << endl;
			separator(100);
			break;
		}


		}

	}

	system("pause");
	return 0;
}