#include <iostream> 
#include <queue> 
using namespace std; 
#define sz(v) (int)(v.size())
#define MAX_SIZE 100005

struct HuffmanNode { 
    int freq;
    char val;
    HuffmanNode* left; 
    HuffmanNode* right; 
    HuffmanNode(char ch, int frq) { 
        val = ch; 
        freq = frq; 
        left = right = NULL; 
    } 
};

struct cmp {  
    bool operator()(HuffmanNode* a, HuffmanNode* b) { 
        return a->freq > b->freq; 
    } 
}; 

HuffmanNode* generateTree(priority_queue<HuffmanNode*, vector<HuffmanNode*>, cmp> pq) { 
    while (sz(pq) != 1) { 
        HuffmanNode* left = pq.top(); 
        pq.pop();
        HuffmanNode* right = pq.top(); 
        pq.pop();
        HuffmanNode* cur = new HuffmanNode('$', left->freq + right->freq); 
        cur->left = left; 
        cur->right = right; 
        pq.push(cur); 
    }
    return pq.top();
}

void printCode(HuffmanNode* root, int arr[], int cur) { 
    if (root->left) { 
        arr[cur] = 0; 
        printCode(root->left, arr, cur + 1); 
    }
    if (root->right) { 
        arr[cur] = 1; 
        printCode(root->right, arr, cur + 1); 
    }
    if (root->left == NULL && root->right == NULL) { 
        cout << root->val << " :: "; 
        for (int i = 0; i < cur; i++) { 
            cout << arr[i]; 
        } 
        cout << endl; 
    }
}

int main() { 
    string msg;
    cin >> msg;
    int n = msg.size();
    int freq[n];
    for (int i = 0; i < n; i++) {
        cin >> freq[i];
    }
    
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, cmp> pq; 
    for (int i = 0; i < n; i++) { 
        HuffmanNode* tmp = new HuffmanNode(msg[i], freq[i]); 
        pq.push(tmp); 
    } 

    HuffmanNode* root = generateTree(pq); // stores the root of Huffman Tree
    int a[MAX_SIZE], cur = 0; 
    printCode(root, a, cur);  
    return 0; 
} 