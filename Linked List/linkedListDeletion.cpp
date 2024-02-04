#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data ;
    node* next;

    public:
    node (int data1 , node* next1){
        data = data1;
        next = next1;
    }

    public:
    node (int data1 ){
        data = data1;
        next = nullptr;
    }

};

node* convertToLL(vector<int>& arr){
    node* head = new node (arr[0]);
    node* mover = head;
    for (int i = 1 ; i < arr.size() ; i++){
        node* temp = new node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}


void print(node* head){
    node* temp = head;
    while (temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

node* deleteHead (node* head){
    if (head == NULL ) return NULL;
    node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

node* deleteTail(node* head){
    if (head == NULL || head-> next == NULL) return NULL;
    node* temp = head;
    while(temp-> next -> next != NULL){
        temp = temp->next;
    }
    delete temp-> next;
    temp -> next = nullptr;
    return head;
}

node* deleteK(node* head , int k){
    if(head == NULL) return NULL;
    if(k == 1) {
    node* temp = head;
    head = head->next;
    delete temp;
    return head;
    }
    int cnt = 0;
    node* temp = head;
    node* prev = NULL;
    while (temp != NULL){
        cnt++;
        if(cnt == k){
            prev-> next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp-> next;
    }
    return head;
}

node* deleteVal(node* head, int val){
    if(head == NULL) return NULL;
    if(head->data == val) {
    node* temp = head;
    head = head->next;
    delete temp;
    return head;
    }
    int cnt = 0;
    node* temp = head;
    node* prev = NULL;
    while (temp != NULL){
        cnt++;
        if(temp-> data == val){
            prev-> next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp-> next;
    }
    return head;
}

int main(){
    vector<int> arr = {12, 23 , 24, 25 ,26 , 34 , 48 , 54, 68, 72};
    node* head = convertToLL(arr);
    //print(deleteTail(head));
    //print(deleteK(head , 3));
    print(deleteVal(head , 25));
}