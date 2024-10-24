/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    
        Node* reverse (Node* head) {
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void inserAtTail( struct Node* &head, struct Node* &tail, int val) {
        
        Node* temp = new Node(val);
        if(head == NULL) {
            
            head = temp;
            tail = temp;
            return;
        }
        else {
            tail -> next = temp;
            tail = temp;
        }
        
    }
    
    struct Node* add(struct Node* first, struct Node* second) {
        
        int carry = 0;
        
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        while(first != NULL && second != NULL) {
            int sum = carry + first -> data + second -> data;
            
            int digit = sum % 10;
            // create and add in answer
            inserAtTail(ansHead, ansTail, digit);
            
            carry = sum/10;
            first = first -> next;
            second = second -> next;
        }
        
        while(first != NULL) {
            
            int sum = carry + first -> data;
            int digit = sum%10;
            inserAtTail(ansHead, ansTail, digit);
            
            carry = sum/10;
            first = first -> next;
            
        }
        
          while(second != NULL) {
            
            int sum = carry + second -> data;
            int digit = sum%10;
            inserAtTail(ansHead, ansTail, digit);
            
            carry = sum/10;
            second = second -> next;
          }
            
          while(carry != 0) {
            
            int sum = carry;
            int digit = sum%10;
            inserAtTail(ansHead, ansTail, digit);
            
            carry = sum/10;
            
          }
          
          return ansHead;
        
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        
        
        // reverse LL
        
        first = reverse(first);
        second = reverse(second);
        
        // add 
        Node* ans = add(first, second);
        
        // reverse ans list
        
        ans = reverse(ans);
        return ans;
    
    }
};
