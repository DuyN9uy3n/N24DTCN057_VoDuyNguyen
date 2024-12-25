#include <stdio.h>  

#define MAX 100  

int main() {  
    int arr[MAX];  
    int n = 0;  
    int choice;  

    while (1) {  
        printf("\n 3> ---MENU--- > \n");  
        printf("1. Nhap so phan tu va gia tri cho mang.\n");  
        printf("2. In ra gia tri cac phan tu trong mang.\n");  
        printf("3. Dem so luong cac so hoan hao co trong mang.\n");  
        printf("4. Tim gia tri lon thu 2 trong mang.\n");  
        printf("5. Them mot phan tu vao vi tri ngau nhien trong mang.\n");  
        printf("6. Xoa phan tu tai mot vi tri cu the.\n");  
        printf("7. Sap xep mang theo thu tu tang dan (Insertion sort).\n");  
        printf("8. Tim kiem phan tu trong mang (Binary search).\n");  
        printf("9. Sap xep lai mang theo so chan dung truoc, so le dung sau.\n");  
        printf("10. Dao nguoc thu tu cua cac phan tu trong mang.\n");  
        printf("0. Thoat !\n");  
        
        printf("Chon chuc nang: ");  
        scanf("%d", &choice);  

        if (choice == 0) {  
            printf("Thoat khoi chuong trinh.\n");  
            break;  
        }  

        switch(choice) {  
            case 1: {  
                printf("Nhap so phan tu cua mang: ");  
                scanf("%d", &n);  
                for(int i = 0; i < n; i++) {  
                    printf("Nhap gia tri cho phan tu arr[%d]: ", i);  
                    scanf("%d", &arr[i]);  
                }  
                break;  
            }  
            case 2: {  
                for(int i = 0; i < n; i++) {  
                    printf("arr[%d] = %d, ", i, arr[i]);  
                }  
                printf("\n");  
                break;  
            }  
            case 3: {  
                int count = 0;  
                for(int i = 0; i < n; i++) {  
                    int num = arr[i];  
                    if(num < 2) continue;  
                    int sum = 0;  
                    for(int j = 1; j < num; j++) {  
                        if(num % j == 0) sum += j;  
                    }  
                    if (sum == num) count++;  
                }  
                printf("So luong so hoan hao trong mang la: %d\n", count);   
                break;  
            }  
            case 4: {  
                int largest = -1, secondLargest = -1;  
                for(int i = 0; i < n; i++) {  
                    if(arr[i] > largest) {  
                        secondLargest = largest;  
                        largest = arr[i];  
                    } else if(arr[i] > secondLargest && arr[i] < largest) {  
                        secondLargest = arr[i];  
                    }  
                }  
                printf("Gia tri lon thu 2 trong mang la: %d\n", secondLargest);  
                break;  
            }  
            case 5: {  
                int value, index;  
                printf("Nhap phan tu muon them: ");  
                scanf("%d", &value);  
                printf("Nhap vi tri muon them: ");  
                scanf("%d", &index);  
                for(int i = n; i > index; i--) arr[i] = arr[i - 1];  
                arr[index] = value;  
                n++;  
                break;  
            }  
            case 6: {  
                int index;  
                printf("Nhap vi tri muon xoa: ");  
                scanf("%d", &index);  
                if(index >= 0 && index < n) {  
                    for(int i = index; i < n - 1; i++) arr[i] = arr[i + 1];  
                    n--;  
                }  
                break;  
            }  
            case 7: {
            	printf("em quen syntax Insertion Sort @@");
				break;
			}  
            case 8: {  
                int value, left = 0, right = n - 1, found = 0;  
                printf("Nhap phan tu can tim: ");  
                scanf("%d", &value);  
                while(left <= right) {  
                    int mid = (left + right) / 2;  
                    if(arr[mid] == value) {   
                        found = 1;   
                        break;   
                    }  
                    else if(arr[mid] < value) left = mid + 1;  
                    else right = mid - 1;  
                }  
                if(found) printf("Phan tu %d co ton tai trong mang.\n", value);  
                else printf("Phan tu %d khong ton tai trong mang.\n", value);  
                break;  
            }  
            case 9: {  
                int temp[MAX], index = 0;  
                for(int i = 0; i < n; i++) {  
                    if(arr[i] % 2 == 0) temp[index++] = arr[i];  
                }  
                for(int i = 0; i < n; i++) {  
                    if(arr[i] % 2 != 0) temp[index++] = arr[i];  
                }  
                for(int i = 0; i < n; i++) arr[i] = temp[i];  
                printf("Mang da duoc sap xep chan le.\n");  
                
                for(int i = 0; i < n; i++) {  
                    printf("arr[%d] = %d, ", i, arr[i]);  
                }  
                printf("\n"); 
                
                break;  
                
                
            }  
            case 10: {  
               for(int i = 0; i < n / 2; i++) {  
                    int temp = arr[i];  
                    arr[i] = arr[n - i - 1];  
                    arr[n - i - 1] = temp;  
                }  
                printf("Mang da duoc dao nguoc.\n");  
                
                for(int i = 0; i < n; i++) {  
                    printf("arr[%d] = %d, ", i, arr[i]);  
                }  
                printf("\n");  
                break;  
            }  
            default:   
                printf("khong hop le\n");  
        }  
    }  
    return 0;  
}