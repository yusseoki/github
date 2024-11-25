#include <iostream>
#include <string>
using namespace std;

#define MAX 10001

struct Node{
	string email;
	string passward;
	Node* link;

	Node(const string& email, const string& passward) : email(email), passward(passward), link(nullptr){}
};

Node* table[MAX] = { nullptr };

int Hash(const string& email) {
	int hash = 5321;
	for (int i = 0; i < email.length(); i++) {
		hash = (((hash << 5) + hash) + email[i]) % MAX;
	}
	return hash;
}

void insert(const string& email, const string& passward) {
	int index = Hash(email);
	Node* newnode = new Node(email, passward);

	if (table[index] == nullptr)
		table[index] = newnode;
	else {
		Node* current = table[index];
		while (current->link != nullptr)
			current = current->link;
		current->link = newnode;
	}
}

string search(const string& email) {
	int index = Hash(email);
	Node* current = table[index];
	while (current != nullptr) {
		if (current->email == email) {
			return current->passward;
		}
		current = current->link;
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string email, passward;
		cin >> email>>passward;
		insert(email, passward);
	}
	for (int i = 0; i < m; i++) {
		string find;
		cin >> find;
		cout<<search(find)<<"\n";
	}
	return 0;
}