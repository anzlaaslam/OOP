#include<iostream>
using namespace std;
int main() {
	cout << "***********WELCOME TO MAZE PATH FINDING GAME ************ " << endl;
	cout << " ___________ENTER SIZE OF MAZE (COL*ROW)__________ : " << endl;
	int rows, cols, flag = 0, count = 0, move = 0;
	cout << "ROWS : ";
	cin >> rows;
	cout << "COLUMNS : ";
	cin >> cols;
	//decalartion of dynamic array 
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}
	// taking input from user 
	cout << " ENTER THE ELEMENTS OF MAZE ONLY 1 AND 0 : " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 1 && arr[i][j] != 0) {
				cout << " YOU ENTERED INVALID INPUT.... ENTER 0 OR 1 TYO GET EXACT PATH " << endl;
				cin >> arr[i][j];
			}
		}
	}
	// display maze entered by user 
	cout << " MAAZE YOU ENTERED : \n\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;

	}
	// taking ending and starting point of path from from where robort will move
	cout << "****** ENTER STARTING AND ENDING POINT OF PATH ******* \n \n" << endl;
	int ep_r, ep_c, sp_r, sp_c;
	cout << "STARTING POINT :  " << endl;
	cout << "ROWS : ";
	cin >> sp_r;
if (sp_r > rows)
{
	cout << " YOU ENTERED INVALID POINT THAT IS GETTING OUT OF BOUND  " << endl;
	cin >> sp_r;
}
cout << "COLUMNS : ";
cin >> sp_c;
if (sp_c > cols) {
	cout << " YOU ENTERED INVALID POINT THAT IS GETTING OUT OF BOUND  " << endl;
	cin >> sp_c;
}

cout << "\n \nENDING POINT :  " << endl;
cout << "ROWS : ";
cin >> ep_r;
if (ep_r > rows)
{
	cout << " YOU ENTERED INVALID POINT THAT IS GETTING OUT OF BOUND  " << endl;
	cin >> ep_r;
}
cout << "COLUMNS : ";
cin >> ep_c;
if (ep_c > cols) {
	cout << " YOU ENTERED INVALID POINT THAT IS GETTING OUT OF BOUND  " << endl;
	cin >> sp_c;
}


cout << "\n\n ENTER PATH (e.g r1<-d2<-l4<-u1)  : " << endl;
cout << "YOU MUST HAVE TO ENTER STAR (i.e '*') TO TERMINATE INPUT_____ :  " << endl;
char* str = new char[200];
cin.getline(str, 200, '*');
for (int i = 0; i < strlen(str); i++) {
	//for rightward movement
	if (str[i] == 'r') {
		count = str[i + 1] - 48;
		move = move + count;
		for (int i = sp_r; i < ep_r; i++) {
			for (int j = sp_c; j < ep_c; j++) {
				if (i > ep_r && j > ep_c)
					cout << " YOU ENTERED PATH OUT OF LIMIT " << endl;
				if (i >= sp_r || j >= sp_c)
					if (arr[i][j + move] == 0)
						flag = 1;
			}
		}
	}

	//for downward movement
	if (str[i] == 'd') {
		count = str[i + 1] - 48;
		for (int i = sp_r; i < ep_r; i++) {
			for (int j = sp_c; j < ep_c; j++) {
				if (i > ep_r || j > ep_c)
					cout << " YOU ENTERED PATH OUT OF LIMIT " << endl;
				if (i >= sp_r || j >= sp_c)
					if (arr[i + move][j] == 0)
						flag = 1;
			}
		}
	}

	//for leftward movement
	if (str[i] == 'l') {
		count = str[i + 1] - 48;
		move = move + count;
		for (int i = sp_r; i < ep_r; i++) {
			for (int j = sp_c; j < ep_c; j++) {
				if (i > ep_r || j > ep_c)
					cout << " YOU ENTERED PATH OUT OF LIMIT " << endl;
				if (i >= sp_r || j >= sp_c)
					if (arr[i][j - count] == 0)
						flag = 1;

			}
		}
	}
	//for upward movement
	if (str[i] == 'u') {
		count = str[i + 1] - 48;
		move = move + count;
		for (int i = sp_r; i < ep_r; i++) {
			for (int j = sp_c; j < ep_c; j++) {
				if (i > ep_r || j > ep_c)
					cout << " YOU ENTERED PATH OUT OF LIMIT " << endl;
				if (i >= sp_r || j >= sp_c)
					if (arr[i - count][j] == 0)
						flag = 1;
			}
		}
	}

}
if (flag == 1) {
	cout << "TRUE" << endl;
}
else if (flag == 0) {
	cout << "FALSE" << endl;
}
// deallocation of maze array
for (int i = 0; i < rows; i++) {
	delete[] arr[i];
}
delete[]arr;
arr = nullptr;
// deallocation of input path
delete[] str;
str = nullptr;
	return 0;
}