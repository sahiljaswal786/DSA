#include <bits/stdc++.h>
using namespace std;

// self defined data type for linked list

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
    int ans = lengthOfLL(head);
    cout << ans << endl ;
    node* temp = head;
    while (temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}



int main(){
    vector<int> arr = {12, 23 , 24, 25 ,26};
    node* head = convertToLL(arr);
    print(head);
}