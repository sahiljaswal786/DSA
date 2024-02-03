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

node* reverseLL(node* head){
    if(head == NULL || head->next == NULL) return head;

    node* temp = head;
    node* prev = NULL;

    while(temp){
        node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    } 

    return prev;
}


bool palindrome(node* head){
    if(head == NULL || head->next == NULL) return NULL;

    node* fast = head;
    node* slow = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    node* secondHead = reverseLL(slow->next);

    node* firstHead = head;

    while(secondHead){
        if (firstHead->data != secondHead->data){
            reverseLL(secondHead);
            return false;
        } 
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }
    reverseLL(secondHead);
    return true;
}



int main(){
    vector<int> arr = {1 , 2, 3, 2, 1};
    node* head = convertToLL(arr);
    print(palindrome(head));
}