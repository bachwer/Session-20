#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct information {
    int id;
    char name[50];
    char author[30];
    float price;
};
struct information *books;
void intputBook();
void outputBook();
void addBook();
void deleteBook();
void updateBook();
void arrangeBook();
void findBook();
int main() {
    int n;
    int pos;
    char name[50];
    int menu, menu2;
    do {
        printf("1.Nhap so luong va thong tin sach\n");
        printf("2.Hien thi thong tin sahc\n");
        printf("3.Them sach vao vi tri\n");
        printf("4.Xoa sach theo ma\n");
        printf("5.Cap nhap thong tin sach theo ma\n");
        printf("6.Sap xem tang theo gia(Tang / giam\n");
        printf("7.Tim kiem ten theo sach\n");
        printf("8.Thoat\n");
        printf("Enter your number: ");
        scanf("%d", &menu);
        if(menu < 1 || menu > 8) {
            printf("Invalid !!!\n");
            menu2:
            printf("\n");
        do {
            printf("1.Back to menu\n");
            printf("2.Exit\n");
            printf("Enter your number: ");
            scanf("%d", &menu2);
        }while (menu2 != 1 && menu2 != 2);
            if(menu2 == 2) {
                return 0;
            }else {
                menu = 0;
            }
        }
    }while(menu < 1 || menu > 8);
    switch (menu) {
        case 1:
            printf("Moi nhap so luong sach can nhap: ");
            scanf("%d", &n);
            intputBook(&books, &n);
            goto menu2;
        case 2:
            outputBook(&books);
            goto menu2;
        case 3:
            printf("Moi nhap vi tri can them: ");
            scanf("%d", &pos);
            pos--;
            addBook(&books, &n, pos);
            goto menu2;
        case 4:
            printf("Moi nhap vi tri can Xoa: ");
            scanf("%d", &pos);
            pos--;
            deleteBook(&books, &n, pos);
            goto menu2;
        case 5:
            printf("Moi nhap ID can sua: ");
            scanf("%d", &pos);
            pos--;
            updateBook(&books, &n, pos);
            goto menu2;
        case 6:
            do {
                printf("1.Tang\n");
                printf("2.Giam\n");
                printf("Enter your number: ");
                scanf("%d", &menu2);
            }while (menu2 != 1 && menu2 != 2);
        if(menu2 == 1) {
            arrangeBook(&books, &n, 1);
        }else {
            arrangeBook(&books, &n, 2);
        }
            goto menu2;
        case 7:
            printf("Nhap ten sach de tim: ");
            fflush(stdin);
            fgets(name, sizeof(name), stdin);
            name[strlen(name) - 1] = '\0';
            findBook(&books, &n, name);
            goto menu2;
        default:
            printf("Da thoat !");
            return 1;
    }
}

void intputBook(struct information *books[], int const *n) {
        for(int i = 0; i < *n + 1; i++) {
            books[i] = (struct information *) malloc(sizeof(struct information));
            if (books[i] == NULL) {
                printf("erorr %d\n", i + 1);
                return;
            }
        }

        for(int i = 0; i < *n; i++){
        books[i] -> id = i + 1;
        getchar();
        printf("<--- \t\t\t --->\n");
        printf("Moi nhap ten sach: ");
        fgets(books[i] -> name, sizeof(books[i] -> name), stdin);
        books[i] -> name[strlen(books[i] -> name) - 1] = '\0';

        printf("Moi nhap ten tac gia: ");
        fgets(books[i] -> author, sizeof(books[i] -> author), stdin);
        books[i] -> author[strlen(books[i] -> author) - 1] = '\0';

        printf("Moi nhap gia tien: ");
        scanf("%f", &books[i] -> price);
    }
    printf("%s", books[0] -> name);
}

void outputBook( struct information *books[]) {
    int i = 0;
    while(books[i] -> name[0] != '\0') {
        printf("<--- \t---\t --->\n");
        printf("ID: %d| ", books[i] -> id);
        printf("Name: %s| ", books[i] -> name);
        printf("Author: %s| ", books[i] -> author);
        printf("Price: %.2f| \n", books[i] -> price);
        fflush(stdin);
        i++;
    }

}
void addBook(struct information *books[], int *n, int const pos) {
    for(int i = 0; i < *n + 2; i++) {
        books[i] = (struct information *) realloc(books[i], sizeof(struct information));
        if (books[i] == NULL) {
            printf("erorr %d\n", i + 1);
            return;
        }
    }
    for(int i = *n -1; i >= pos; i--) {
        books[i + 1] -> id = books[i] -> id;
        strcpy(books[i + 1] -> name, books[i] -> name );
        strcpy(books[i + 1] -> author, books[i] -> author );
        books[i + 1] -> price = books[i] -> price;
    }
    fflush(stdin);
    books[pos] -> id = *n + 1;
    printf("Moi nhap ten sach: ");
    fgets(books[pos] -> name, sizeof(books[pos] -> name), stdin);
    books[pos] -> name[strlen(books[pos] -> name) - 1] = '\0';

    printf("Moi nhap ten tac gia: ");
    fgets(books[pos] -> author, sizeof(books[pos] -> author), stdin);
    books[pos] -> author[strlen(books[pos] -> author) - 1] = '\0';

    printf("Moi nhap gia tien: ");
    scanf("%f", &books[pos] -> price);

    (*n)++;

}
void deleteBook(struct information *books[], int *n, int const pos) {
    for(int i = pos; i < *n; i++) {
        books[i] -> id = books[i + 1] -> id;
        strcpy(books[i] -> name, books[i + 1] -> name );
        strcpy(books[i] -> author, books[i + 1] -> author );
        books[i] -> price = books[i + 1] -> price;
    }
    (*n)--;
}
void updateBook(struct information *books[], int const *n, int const pos) {
    int check = -1;
    for(int i = 0; i < *n; i++) {
        if(books[i] -> id == pos) {
            check = 1;
            break;
        }
    }
    if(check == 1) {
        fflush(stdin);
        printf("Moi nhap ten sach: ");
        fgets(books[pos] -> name, sizeof(books[pos] -> name), stdin);
        books[pos] -> name[strlen(books[pos] -> name) - 1] = '\0';

        printf("Moi nhap ten tac gia: ");
        fgets(books[pos] -> author, sizeof(books[pos] -> author), stdin);
        books[pos] -> author[strlen(books[pos] -> author) - 1] = '\0';

        printf("Moi nhap gia tien: ");
        scanf("%f", &books[pos] -> price);
    }else {
        printf("Khong tim thay id!!! \n");
    }
}
void findBook(struct information *books[], int const *n, char name[]) {
    int check = -1;
    for(int i = 0; i < *n ; i++) {
        if(strcmp(books[i] -> name, name) == 0) {
            printf("<--- \tDa tim thay\t --->\n");
            printf("ID: %d| ", books[i] -> id);
            printf("Name: %s| ", books[i] -> name);
            printf("Author: %s| ", books[i] -> author);
            printf("Price: %.2f| \n", books[i] -> price);
            check = 1;
            break;
            }
        }
        if( check == -1) {
            printf("khon tim thay sach: ");
        }
    }
void arrangeBook(struct information *books[],int const *n, int const check) {
            if(check == 1) {
                for(int i = 1; i < *n; i++) {
                    for(int j = 0; j < *n; j++) {
                        if(books[i]->price < books[j] ->price) {
                            float const temp = books[i]->price;
                            books[i]->price = books[j] ->price;
                            books[j] ->price = temp;
                            int const tempid = books[i] ->id;
                            books[i]->id = books[j] ->id;
                            books[j] ->id = tempid;
                            char  tempname[50];
                            strcpy(tempname, books[i] -> name);
                            strcpy(books[i] -> name, books[j] -> name);
                            strcpy(books[j] -> name, tempname);
                            strcpy(tempname, books[i] -> author);
                            strcpy(books[i] -> author, books[j] -> author);
                            strcpy(books[j] -> author, tempname);
                        }
                    }
                }
                } else{
                    for(int i = 1; i < *n; i++) {
                        for(int j = 0; j < *n; j++) {
                            if(books[i]->price > books[j] ->price) {
                                float const temp = books[i]->price;
                                books[i]->price = books[j] ->price;
                                books[j] ->price = temp;
                                int const tempid = books[i] ->id;
                                books[i]->id = books[j] ->id;
                                books[j] ->id = tempid;
                                char  tempname[50];
                                strcpy(tempname, books[i] -> name);
                                strcpy(books[i] -> name, books[j] -> name);
                                strcpy(books[j] -> name, tempname);
                                strcpy(tempname, books[i] -> author);
                                strcpy(books[i] -> author, books[j] -> author);
                                strcpy(books[j] -> author, tempname);
                            }
                        }
                    }
                }
            }
