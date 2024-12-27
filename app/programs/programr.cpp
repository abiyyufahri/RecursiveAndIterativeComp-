#include <iostream>
#include <string>
#include <chrono>

struct Node {
    char info;        // Menyimpan karakter '0' atau '1'
    Node* next;      // Pointer ke node berikutnya

    Node(char val) : info(val), next(nullptr) {} // Konstruktor
};

struct SinglyLinkedList {
    Node* head; // Pointer ke node pertama
    Node* tail; // Pointer ke node terakhir
    SinglyLinkedList() : head(nullptr), tail(nullptr) {} // Konstruktor
};

void append(SinglyLinkedList &list, char val) { // insert last
    Node* newNode = new Node(val); 
    if (list.head == nullptr) { // Jika linked list kosong
        list.head = newNode; // Node baru adalah node pertama
        list.tail = newNode; // Node baru adalah node terakhir
    } else {
        list.tail->next = newNode;
        list.tail = newNode;
    }
}

long long total_step = 0;
int n1 = 0;
int n = 0;
// std::string s;
void minStep(Node* s);
// void minStep(int i);

int main(int argc, char* argv[]) {
    if (argc > 1) {
        SinglyLinkedList list = SinglyLinkedList(); // membuat linked list
        std::string binaryString = argv[1]; // Mengambil string dari argumen pertama
        
        for (int i = binaryString.length() - 1; i>=0; --i) { // Membaca string dari belakang
            append(list, binaryString[i]); // Menambahkan karakter ke linked list
        }
        // s = "0" + binaryString;
        
        
        auto start = std::chrono::high_resolution_clock::now();
        minStep( list.head);    // Memanggil fungsi minStep
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "" << duration.count() << "" << std::endl;
        std::cout << total_step << std::endl;
    } else {
        
        std::cout << "No input provided." << std::endl;
    }
    
    return 0;
}



void minStep(Node* s) {
    if( s == nullptr) 
        return;
    else { 

        
        if (s->info == '1') {
            total_step += n - n1;
            n1++;
        }
        n++;
        minStep(s->next);
    }
}

// void minStep(int i) {
//     if( i == -1 ){
//         return;
//     }else {
//         if (s[i] == '1') {
//             total_step += n - n1;
//             n1++;
//         }
//         n++;
//         minStep(i-1);
//     }
// }

// }

// 0  , n = 0
// 1  , n > 0