#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

struct product {
    int code;
    char name[50];
    float priceIn;
    float priceOut;
};

struct product *products;

void Input_products();
void Show_products();
void Output_products();
void Update_products();
void Arrange_products();
void Find_products();
void Sell_products();
void Revenue_products();
int main(void) {
    int menu1;
    char *ptr;
    int menu;
    do {
        printf("1.Nhap so luong van thong tin san pham\n");
        printf("2.Hien thi danh sach san pham\n");
        printf("3.Nhap san pham\n");
        printf("4.Cap nhap thong tin san pham\n");
        printf("5.sao xep san pham theo gia(Tang/ giam)\n");
        printf("6.Tim kiem san pham\n");
        printf("7.Ban san pham(co the nhap so luong)\n");
        printf("8.Doanh thu hien tai\n");
        printf("9.Thoat\n");
        printf("Enter your number: ");
        char input[50];
        fgets(input, sizeof(input), stdin);
        menu = strtol(input, &ptr, 10);
        if (*ptr != '\0' && *ptr != '\n') {
            printf("invalid\n");
        }
        switch (menu) {
            case 1:
            case 2:
            case 3:
            case 5:
            case 4:
            case 6:
            case 7:
            case 8:
            default:
            do {
                printf("1.Back to menu:\n");
                printf("2.Exit\n");
                printf("Enter your number: ");
                fgets(input, sizeof(input), stdin);
                menu1 = strtol(input, &ptr, 10);
                if (*ptr != '\0' && *ptr != '\n') {
                    printf("invalid!!!!!\n");
                }
                }while (menu1 != 1 && menu1 != 2);
            if(menu1 == 2) {
                return 1;
            }
            break;
        }
    }while(menu != 9);
    return 0;
}

void Input_products() {

}
void Show_products() {

}
void Output_products() {

}
void Update_products() {

}
void Arrange_products() {

}
void Find_products() {

}
void Sell_products() {

}
void Revenue_products() {

}
