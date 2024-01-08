#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

//Reference: https://www.geeksforgeeks.org/quickselect-algorithm/

//Y tuong cua bai nay dua vao thuat toan QuickSelect duoc xay dung dua tren QuickSort, mot thuat toan theo D&C
//Dau tien, ta chon mot phan tu lam pivot va phan vung mang lam hai nua bao gom cac phan tu 
//lon hon pivot va nho hon pivot.
//Tuy nhien, QuickSelect chi dung lai o viec tim kiem mot nua mang chua phan tu thu k lon nhat ma khong can 
//sap xep toan bo mang.

int partition(vector<int> &v, int left, int right) {
    //Phan chia mang lam 2 nua, lay phan tu tai vi tri right cuoi cung lam pivot, va khoi tao i tu left 
    int pivot = v[right], i = left; 
    //Duyet tu left den right-1
    for (int j=left; j<=right-1; j++) { 
        //Neu bat ki phan tu nao lon hon pivot, ta doi cho giua no va phan tu i , sau do tang i len 1
        if (v[j]>=pivot) { 
            swap(v[i], v[j]); 
            i++; 
        } 
    } 
    //Hoan doi giua v[i] va pivot, bao dam tat ca phan tu lon hon hoac bang pivot deu o ben trai cua no
    swap(v[i], v[right]); 
    //Tra ve vi tri pivot moi
    return i; 
} 
  
int kthLargest(vector<int> v, int left, int right, int k) { 
    //Kiem tra k hop le, co nam trong khoang phan tu ma ta xem xet
    if (k>0 && k<=right-left+1) { 
        //Phan chia mang thanh left va right va tinh pivot, luc nay luon bao dam pivot la phan tu ma
        //tat ca phan tu lon hon no deu nam ben trai, cac phan tu nho hon se nam ben phai
        int pivot = partition(v, left, right); 

        //Kiem tra neu pivot nam o vi tri k-1 tu phia ben trai cua mang (Gia tri lon nhat vi tri k0
        //hay noi don gia la co k-1 phan tu lon hon no o vi tri ben trai, tuc chinh no se la vi tri k
        if (pivot-left==k-1)
            //Neu dung ta tra ve gia tri cua no 
            return v[pivot]; 

        //Neu so luong phan tu lon hon pivot lon hon k-1 phan tu, thi ta se tiep tuc tim kiem phan tu lon thu k
        //o phan mang ben trai cua pivot
        if(pivot-left>k-1)return kthLargest(v, left, pivot-1, k); 
        //Nguoc lai, ta se tim ben phai, tuy nhien luc nay ta da bo het cac phan tu ben trai, nen ta can cap nhat
        //lai gia tri tuong ung la k-pivot+left-1
        else return kthLargest(v, pivot+1, right, k-pivot+left-1); 
    } 
} 
  
int main(){ 
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout << kthLargest(v, 0, n - 1, k); 
} 