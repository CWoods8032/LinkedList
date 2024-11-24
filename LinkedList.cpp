#include <iostream>
#include <string>

using namespace std; // Use the std namespace

// Node structure for a doubly linked list
struct Node {
    string website;
    Node* next;
    Node* prev;

    Node(const string& site) : website(site), next(nullptr), prev(nullptr) {}
};

// Doubly linked list class
class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Add a new node at the end of the list
    void insertNode(const string& website) {
        Node* newNode = new Node(website);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Display the entire list
    void displayList() const {
        if (!head) {
            cout << "The list is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->website << " <-> ";
            temp = temp->next;
        }
        cout << "nullptr\n";
    }

    // Traverse forward through the list
    void goForward(Node*& current) const {
        if (!current) {
            cout << "The list is empty.\n";
            return;
        }
        if (current->next) {
            current = current->next;
            cout << "Current Website: " << current->website << endl;
        }
        else {
            cout << "You have reached the end of the list.\n";
        }
    }

    // Traverse backward through the list
    void goBackward(Node*& current) const {
        if (!current) {
            cout << "The list is empty.\n";
            return;
        }
        if (current->prev) {
            current = current->prev;
            cout << "Current Website: " << current->website << endl;
        }
        else {
            cout << "You are at the beginning of the list.\n";
        }
    }

    // Delete a website from the list
    void deleteWebsite(const string& website) {
        Node* temp = head;
        while (temp) {
            if (temp->website == website) {
                if (temp->prev) temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                if (temp == head) head = temp->next;
                if (temp == tail) tail = temp->prev;
                delete temp;
                cout << "Website \"" << website << "\" deleted.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Website \"" << website << "\" not found.\n";
    }

    // Find a website in the list
    void findWebsite(const string& website) const {
        Node* temp = head;
        while (temp) {
            if (temp->website == website) {
                cout << "Website \"" << website << "\" found.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Website \"" << website << "\" not found.\n";
    }

    // Get the head of the list
    Node* getHead() const { return head; }

    // Destructor to clean up memory
    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    Node* current = nullptr;

    // Populate the list using insertNode
    list.insertNode("https://www.google.com");
    list.insertNode("https://www.github.com");
    list.insertNode("https://www.stackoverflow.com");
    list.insertNode("https://www.linkedin.com");
    list.insertNode("https://www.facebook.com");
    list.insertNode("https://www.reddit.com");
    list.insertNode("https://www.youtube.com");
    list.insertNode("https://www.amazon.com");
    list.insertNode("https://www.wikipedia.org");
    list.insertNode("https://www.microsoft.com");
    list.insertNode("https://www.apple.com");
    list.insertNode("https://www.twitter.com");
    list.insertNode("https://www.instagram.com");
    list.insertNode("https://www.netflix.com");
    list.insertNode("https://www.quora.com");
    list.insertNode("https://www.twitch.tv");
    list.insertNode("https://www.pinterest.com");
    list.insertNode("https://www.medium.com");
    list.insertNode("https://www.spotify.com");
    list.insertNode("https://www.adobe.com");

    current = list.getHead();

    // Menu
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display the list\n";
        cout << "2. Go forward and display the webpage\n";
        cout << "3. Go backward and display the webpage\n";
        cout << "4. Add another item to the list\n";
        cout << "5. Delete an item from the list\n";
        cout << "6. Find an item in the list\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            list.displayList();
        }
        else if (choice == 2) {
            list.goForward(current);
        }
        else if (choice == 3) {
            list.goBackward(current);
        }
        else if (choice == 4) {
            string website;
            cout << "Enter the website URL to add: ";
            cin >> website;
            list.insertNode(website);
            cout << "Website added.\n";
        }
        else if (choice == 5) {
            string website;
            cout << "Enter the website URL to delete: ";
            cin >> website;
            list.deleteWebsite(website);
        }
        else if (choice == 6) {
            string website;
            cout << "Enter the website URL to find: ";
            cin >> website;
            list.findWebsite(website);
        }
        else if (choice == 7) {
            cout << "Exiting program.\n";
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}