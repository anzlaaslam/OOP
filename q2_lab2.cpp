#include<iostream>
using namespace std;
int** createPascalTriangle (int n);
void displayPascalTriangle (int** pt, int n);
void deallocatePascalTriangle (int** pt, int n);
int main(){
	int n;
	cout<<"enter rows : " << endl;
    cin>>n;
	int ** ptr = createPascalTriangle (n);
	displayPascalTriangle (ptr, n);
	deallocatePascalTriangle (ptr, n);
	system ("pause");
	return 0;
}
//function to creat pascal triangle
int** createPascalTriangle (int n)
{
	int ** ptr = new int*[n];
	for(int i=0; i< n ; i++){
		ptr[i] = new int [i+1];
	}
	int i=0;
	while(i<n){
		int a=1;
		int j=0;
		while(j<=i){
			*(*(ptr+i)+j) = a;
			a= a*(i-j)/(j+1);
			j++;
		}
		i++;
	}
	return ptr;
}
// for display
void displayPascalTriangle (int** ptr, int n){
	int i=0;
	while(i< n){
		int a=1;
		int j=0;
		while(j<= i){
			cout<<" "<< *(*(ptr+i)+j) <<" ";
			j++;
		}
		cout<< endl;
		i++;
	}
	
}
// dealocation of memory
void deallocatePascalTriangle (int** ptr, int n){
	for(int i=0; i<n ; i++){
		delete [] ptr[i];
	}
	delete [] ptr ;
	ptr=0;
}






















