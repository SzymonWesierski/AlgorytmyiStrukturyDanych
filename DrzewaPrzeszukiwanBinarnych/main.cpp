#include<iostream>
#include<string>
#include <sstream>

using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;
    bool switch_value;

    Node(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
        this->switch_value = true;
    }
};

Node *root;
bool init_check = false;

void initTree() {
    root = nullptr;
    init_check = true;

}

void insertTree(int value) {
    if (root == nullptr) {
        root = new Node(value);
        return;
    }
    Node *current = root;
    while (true) {
        if (current->switch_value == false){
            current->switch_value = true;
        }

        else if (current->switch_value == true){
            current->switch_value = false;
        }
        if (value == current->value) {
            if (current->switch_value == false) {
                if (current->left == nullptr) {
                    current->left = new Node(value);
                    return;
                }
                current = current->left;
            } else {
                if (current->right == nullptr) {
                    current->right = new Node(value);

                    return;
                }
                current = current->right;
            }
        }
        else if (value < current->value) {


            if (current->left == nullptr) {
                current->left = new Node(value);
                return;
            }
            current = current->left;

        } else {


            if (current->right == nullptr) {
                current->right = new Node(value);
                return;
            }
            current = current->right;
        }
    }
}

string searchTree(int value) {
    if (root == nullptr) {
        return "False";
    }

    Node *current = root;
    while (current != nullptr) {
        if (value == current->value) {
            return "True";
        }
        if (value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return "False";
}

Node* getMin(Node *node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

Node* deleteValueMethod(Node *node, int value) {
    if (node == nullptr) {
        return nullptr;
    }

    if (value == node->value) {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        if (node->left == nullptr) {
            Node *temp = node->right;
            delete node;
            return temp;
        }
        if (node->right == nullptr) {
            Node *temp = node->left;
            delete node;
            return temp;
        }
        Node *temp = getMin(node->right);
        node->value = temp->value;
        node->right = deleteValueMethod(node->right, temp->value);
        return node;
    } else if (value < node->value) {
        node->left = deleteValueMethod(node->left, value);
        return node;
    } else {
        node->right = deleteValueMethod(node->right, value);
        return node;
    }
}

void deleteValue(int value) {
    root = deleteValueMethod(root, value);
}

string inOrderMethod(Node *node) {
    stringstream result;
    if (node == nullptr) {
        return "";
    }
    result << inOrderMethod(node->left);
    result << node->value << " ";
    result << inOrderMethod(node->right);
    return result.str();
}

string inOrder() {
    int len;
    string inOrderResult;
    inOrderResult = inOrderMethod(root);
    len = inOrderResult.length();
    inOrderResult = inOrderResult.erase(len - 1,1);
    return inOrderResult;
}

string preOrderMethod(Node *node) {
    stringstream result;
    if (node == nullptr) {
        return "";
    }
    result << node->value << " ";
    result << preOrderMethod(node->left);
    result << preOrderMethod(node->right);
    return result.str();
}

string preOrder() {
    int len;
    string preOrderResult;
    preOrderResult = preOrderMethod(root);
    len = preOrderResult.length();
    preOrderResult = preOrderResult.erase(len - 1,1);
    return preOrderResult;
}

string postOrderMethod(Node *node) {
    stringstream result;
    if (node == nullptr) {
        return "";
    }
    result << postOrderMethod(node->left);
    result << postOrderMethod(node->right);
    result << node->value << " ";
    return result.str();
}

string postOrder() {
    int len;
    string postOrderResult;
    postOrderResult = postOrderMethod(root);
    len = postOrderResult.length();
    postOrderResult = postOrderResult.erase(len - 1,1);
    return postOrderResult;
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

        if(tab[0] == "init_tree")if(!init_check)initTree();else result += "Error init_tree\n";
        else if(tab[0] == "insert")if(init_check)insertTree(stoi(tab[1]));else result += "Error insert\n";
        else if(tab[0] == "search")if(init_check)result += searchTree(stoi(tab[1])) + "\n";else result += "Error search\n";
        else if(tab[0] == "delete")if(init_check && searchTree(stoi(tab[1])) == "True")deleteValue(stoi(tab[1]));else result += "Error delete\n";
        else if(tab[0] == "in_order")if(init_check)result += inOrder() + "\n";else result += "Error in_order\n";
        else if(tab[0] == "pre_order")if(init_check)result += preOrder() + "\n";else result += "Error pre_order\n";
        else if(tab[0] == "post_order")if(init_check)result += postOrder() + "\n";else result += "Error post_order\n";
        else cout<<"Niepoprawna operacja"<<endl;
    }
    cout<<result<<endl;

    return 0;
}
