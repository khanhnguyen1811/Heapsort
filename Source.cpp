#include <iostream> 
using namespace std; 
void Swapp(int *pa, int *pb){
	int tam = *pa; 
	*pa = *pb; 
	*pb = tam; 
}
void heapify(int arr[], int sopt, int i){
	int lagrest = i;
	int l, r; 
	l = 2 * i + 1; 
	r = 2 * i + 2;
	// xet trai lon hon root, largre = vi tri do. 
	if (l < sopt && arr[l] > arr[lagrest])
	{
		lagrest = l; 
	}
	// xet phai lon hon root., large = vi tri do. 
	if (r < sopt && arr[r] > arr[lagrest])
	{
		lagrest = r; 
	}
	//hoan doi. 
	if (lagrest != i)
	{
		Swapp(&arr[i], &arr[lagrest]);
		//chay lai ham voi i = largest; 
		heapify(arr, sopt, lagrest);
	}
}
//viet ham sort. 
void Heapsort(int arr[], int sopt){
	for (int i = sopt / 2 -1; i >= 0; i--)
	{
		//build heap. 
		heapify(arr, sopt, i);
	}
	for (int i = sopt-1; i >= 0; i--)
	{
		Swapp(&arr[0], &arr[i]);
		//build max heap. 
		heapify(arr, i, 0);
	}
}
int main(){
	int arr[100], sopt, i; 
	cout << "nhap so phan tu: "; cin >> sopt; 
	for (i = 0; i < sopt; i++)
	{
		cin >> arr[i];
	}
	//call ham. 
	Heapsort(arr, sopt); 
	cout << "mang sap xep la: " << "\n"; 
	for (i = 0; i < sopt; i++)
	{
		cout << arr[i] << " ";
	}
	return 0; 
}
