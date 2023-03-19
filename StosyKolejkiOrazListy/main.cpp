#include<iostream>
#include<string>
#include <sstream>

using namespace std;

struct Node{
    string data;
    Node* next;
    Node* prev;
};

Node* sentinel;
bool init_check = false;

void init_list(){
    sentinel = new Node;
    sentinel->next = sentinel;
    sentinel->prev = sentinel;
    init_check = true;
}

void add(string s){
    Node* newNode = new Node;
    newNode->data = s;

    newNode->prev = sentinel->prev;
    newNode->next = sentinel;
    sentinel->prev->next = newNode;
    sentinel->prev = newNode;
}

string print(){
    string result = "";

    if (sentinel->next == NULL) {
        result += "Error print";
        return result;
    }


    Node* curr = sentinel->next;
    if (curr == sentinel){
        result += "[]";
        return result;
    }
    result += "[";
    while (curr != sentinel){
        result += curr->data;
        curr = curr->next;
        if (curr != sentinel) result += " <-> ";
    }
    result += "]";
    return result;
}

string search_s(string s){
    Node* curr = sentinel->next;
    while (curr != sentinel){
        if (curr->data == s) return "True";
        curr = curr->next;
    }
    return "False";
}

void remove_s(string s){
    Node* curr = sentinel->next;
    while (curr != sentinel){
        if (curr->data == s){
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        return;
    }
    curr = curr->next;
    }
}

void clean(){
    Node* curr = sentinel->next;
    while (curr != sentinel) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    sentinel->next = NULL;
    delete sentinel;
    init_check = false;
}

void non_repeated(){
    Node* curr = sentinel->next;
    while (curr != sentinel){
        bool found = false;
        Node* next = curr->next;
        Node* temp = sentinel->next;
        while (temp != sentinel && !found){
        if (temp != curr && temp->data == curr->data){
            found = true;
            remove_s(curr->data);
        }
        temp = temp->next;
        }
        curr = next;
    }
}

void mergeToList(){
    add("one");
    add("two");
    add("three");
}

int main(){
    string input;
    string result = "";


    while (getline(cin, input)){
        if (input == "")break;
        stringstream ss(input);
        string halfinput;
        int i = 0;
        string tab[2];

        while(getline(ss,halfinput, ' ')){
            tab[i] = halfinput;
            i++;
        }

        if(tab[0] == "init_list")if(!init_check)init_list();else result += "Error init_list\n";
        else if(tab[0] == "print")if(init_check){result += print() + "\n";}else result += "Error print";
        else if(tab[0] == "add")if(init_check)add(tab[1]);else result += "Error add";
        else if(tab[0] == "search")if(init_check)result += search_s(tab[1]) + "\n";else result += "Error search";
        else if(tab[0] == "remove")if(init_check && search_s(tab[1]) == "True")remove_s(tab[1]);else result += "Error remove";
        else if(tab[0] == "clean")if(init_check)clean();else result += "Error clean";
        else if(tab[0] == "non_repeated")if(init_check)non_repeated();else result += "Error non_repeated";
        else if(tab[0] == "merge")if(init_check)mergeToList();else result += "Error merge";
        else cout<<"Niepoprawna operacja"<<endl;
    }
    cout<<result<<endl;

    return 0;
}
