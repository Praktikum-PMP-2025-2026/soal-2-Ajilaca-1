/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 4 
 *   Hari dan Tanggal    : 5 Mei 2026
 *   Nama (NIM)          : M Faza Dzil Ikram (13224017)
 *   Nama File           : soal2.c
 *   Deskripsi           : program membaca 2 input linkedlist dan menyatukan keduanya
 */
#include <stdio.h>
#include <stdlib.h>


typedef struct kereta {
    int value;
    struct kereta* next;
} kereta;

// Fungsi untuk membuat node linkedlist, referensi : https://www.geeksforgeeks.org/c/linked-list-in-c/
kereta* buatnode(int value) {
    kereta* newNode = (kereta*)malloc(sizeof(kereta));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambahkan node di akhir list, referensi : https://www.geeksforgeeks.org/dsa/insert-node-at-the-end-of-a-linked-list/
void akhirlist(kereta** head, int value) {
    kereta* newNode = buatnode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    kereta* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
// Fungsi untuk menggabungkan dua linked list, referensi : https://stackoverflow.com/questions/53999906/how-does-this-recursive-function-work-to-merge-sort-two-singly-linked-lists
kereta* mergelist(kereta* l1, kereta* l2) {
    if (l1 == NULL) return l2; // Jika salah satu list habis, kembalikan list lainnya
    if (l2 == NULL) return l1;

    kereta* result = NULL;
    if (l1->value <= l2->value) { // bandingkan node linkedlist saat ini
        result = l1;
        result->next = mergelist(l1->next, l2); // rekursi
    } else {
        result = l2;
        result->next = mergelist(l1, l2->next);
    }
    return result;
}

// Fungsi untuk membebaskan memori list, referesni (option 2) https://stackoverflow.com/questions/59045963/how-to-free-memory-properly-from-linked-list-in-c#:~:text=%23include,seen%20it%20in%20any%20tutorial
void freeList(kereta* head) {
    kereta* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
// Fungsi untuk mencetak list, referensi : https://www.geeksforgeeks.org/dsa/print-linked-list/
void printlist(kereta* head) {
    if (head == NULL) {
        printf("EMPTY");
        return;
    }
    kereta* temp = head;
    while (temp != NULL) {
        printf("%d", temp->value);
        if (temp->next != NULL) printf(" ");
        temp = temp->next;
    }
}


int main() {
    int n1, n2, val;
    kereta* list1 = NULL;
    kereta* list2 = NULL;

    // Input List 1
    if (scanf("%d", &n1) == 1) {
        for (int i = 0; i < n1; i++) {
            scanf("%d", &val);
            akhirlist(&list1, val);
        }
    }

    // Input List 2
    if (scanf("%d", &n2) == 1) {
        for (int i = 0; i < n2; i++) {
            scanf("%d", &val);
            akhirlist(&list2, val);
        }
    }

    kereta* merge = mergelist(list1, list2);

    printf("MERGED ");
    printList(merge);
    printf("\n");

    freeList(merge);

    return 0;
}
