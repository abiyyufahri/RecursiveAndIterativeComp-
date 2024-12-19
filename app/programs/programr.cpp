#include <iostream>
#include <string>

struct Node {
    char data;        // Menyimpan karakter '0' atau '1'
    Node* next;      // Pointer ke node berikutnya

    Node(char val) : data(val), next(nullptr) {} // Konstruktor
};

class SinglyLinkedList {
private:
    Node* head;      // Pointer ke node pertama
    Node* tail;
public:
    SinglyLinkedList() : head(nullptr), tail(nullptr) {} // Konstruktor

    // Fungsi untuk menambahkan karakter ke linked list
    void append(char val) {
        Node* newNode = new Node(val);
        if (!head && !tail) {
            head = newNode; 
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* getHead(){
        return head;
    }

    // Fungsi untuk menampilkan isi linked list
    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data; // Menampilkan karakter
            temp = temp->next;       // Melanjutkan ke node berikutnya
        }
        std::cout << std::endl;
    }

    // Destructor untuk membersihkan memori
    ~SinglyLinkedList() {
        Node* current = head;
        Node* nextNode;
        while (current) {
            nextNode = current->next;
            delete current; // Menghapus node
            current = nextNode;
        }
    }
};

long long total_step = 0;
int n1 = 0;
int n = 0;
void minStep(Node* s);

int main(int argc, char* argv[]) {
    if (argc > 1) {
        SinglyLinkedList list;
        std::string binaryString = argv[1];
        
        minStep( list.getHead());
        std::cout << total_step << std::endl;
        for (int i = binaryString.length() - 1; i>=0; --i) {
            list.append( binaryString[i]);
        }

        cout << total_step << endl;
    } else {
        
        cout << "No input provided." << endl;
    }
    

    // Menambahkan setiap karakter dari string ke linked list
    

    
    return 0;
}



void minStep(Node* s) {
    if( s == nullptr) 
        return;
    else {
        if (s->data == '1') {
            total_step += n - n1;
            n1++;
        }
        n++;
        minStep(s->next);
    }
        
}

// 0  , n = 0
// 1  , n > 0