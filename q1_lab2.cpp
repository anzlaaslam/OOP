#include<iostream>
using namespace std;
int main(){
	int size=4 , value , count =0;
	cout<<" enter the elements of array and -1 to exit : "<< endl;

	cin>> value;
	int * arr = new int [size ];
	while( value != -1){
		if(count< size ){
			*(arr+count)= value; 
			count ++;
		}
		else 
		{
			int * temp = new int [size *2];
			for( int count=0 ; count< size; count++){
				*(temp+count)= *(arr+count);
			}
			delete [] arr;
			arr= temp;
			delete [] temp;
			temp=0;
			size = size *2;
			*(arr+count) = value;
			count ++;

		}
		cin>> value;
	}
	cout<<"the entered array is " << endl;
	for(int i=count -1 ; i>= 0  ; i--){
		cout<< *(arr+i)<<" " ;
	}
    system ("pause");
	return 0;
} 
