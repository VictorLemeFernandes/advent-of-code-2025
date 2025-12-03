#include <iostream>

using namespace std;

template <typename T> class Node {
    public:
        T data;
        Node<T>* next;
        Node<T>* previous;

        Node(T data) {
            this->data = data;
            this->next = nullptr;
            this->previous = nullptr;
        }
};

template <typename T> class CircularLinkedList {
    private:
        Node<T>* head;
    public:
        CircularLinkedList() { head = nullptr; }
        
        void insertAtEnd(T value) {
            Node<T>* newNode = new Node<T>(value);
            if (head == nullptr) {
                head = newNode;
                head->next = head;
                head->previous = head;
            } else {
                Node<T>* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                newNode->next = head;
                temp->next = newNode;
                newNode->previous = temp;
                head->previous = newNode;
            }
        }

        void display() {
            if (head == nullptr)
                return;
            
            Node<T>* temp = head;
            do {
                cout << temp->data << " -> ";
                temp = temp->next;
            } while (temp != head);
            cout << "HEAD" << endl;
        }
};

int main () {
    CircularLinkedList<int> cll;

    for(int i = 0; i < 10; i++) {
        cll.insertAtEnd(i + 1);
    }

    cll.display();

    return 0;
}