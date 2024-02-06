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

int lengthOfLL(node * head){
    node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void print(node* head){
    node* temp = head;
    while (temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

node* firstNode (node* temp, int k){
    
    int cnt = 1;
    while(temp != NULL){
        cnt++;
        if(k == cnt){
            return temp;
        }
        temp = temp->next;
    }
    return temp;
}

node* rotate(node* head , int k){
    node* tail = head;
    int len = 1;
    
    while(tail->next != NULL){
        tail = tail->next;
        len ++;
    }

    if (k % len == 0) return head;
    k = k % len;

    tail -> next = head;

    node* newNode = firstNode(head , len - k);

    head =  newNode->next;
    newNode ->next = nullptr;
    return head;
}

int main(){
    vector<int> arr = {12, 23 , 24, 25 ,26 , 65, 34 , 45, 56};
    node* head = convertToLL(arr);
    print(rotate(head, 3));
}