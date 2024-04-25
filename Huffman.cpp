#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class cmp {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

class Solution {
public:
    void traverse(Node* root, vector<string>& ans, const string& temp) {
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(temp);
            return;
        }
        string leftTemp = temp + '0';
        string rightTemp = temp + '1';
        traverse(root->left, ans, leftTemp);
        traverse(root->right, ans, rightTemp);
    }

    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        priority_queue<Node*, vector<Node*>, cmp> pq;

        for (int i = 0; i < N; i++) {
            Node* temp = new Node(f[i]);
            pq.push(temp);
        }

        while (pq.size() > 1) {
            Node* left = pq.top();
            pq.pop();
            Node* right = pq.top();
            pq.pop();

            Node* newnode = new Node(left->data + right->data);
            newnode->left = left;
            newnode->right = right;

            pq.push(newnode);
        }

        Node* root = pq.top();
        vector<string> ans;
        string temp = "";
        traverse(root, ans, temp);
        return ans;
    }
};

int main() {
    string S = "ABCDEF";
    vector<int> f = {5, 9, 12, 13, 16, 45}; // frequencies
    int N = S.size(); // number of characters

    Solution solution;
    vector<string> huffman_codes = solution.huffmanCodes(S, f, N);

    cout << "Huffman Codes:\n";
    for (int i = 0; i < N; ++i) {
        cout << S[i] << ": " << huffman_codes[i] << endl;
    }

    return 0;
}


//
//#include <iostream>
//#include <vector>
//#include <chrono>
//
//using namespace std;
//
//#define MAX_TREE_HT 50
//
//class MinHeapNode {
//public:
//    unsigned frequency;
//    char character;
//    MinHeapNode *left, *right;
//
//    MinHeapNode(char character, unsigned frequency) : character(character), frequency(frequency), left(nullptr), right(nullptr) {}
//};
//
//class MinHeap {
//public:
//    unsigned size;
//    unsigned capacity;
//    MinHeapNode **array;
//
//    MinHeap(unsigned capacity) : size(0), capacity(capacity), array(new MinHeapNode *[capacity]) {}
//};
//
//// Creating Huffman tree node
//MinHeapNode *newNode(char character, unsigned frequency) {
//    return new MinHeapNode(character, frequency);
//}
//
//// Create min heap using given capacity
//MinHeap *createMinHeap(unsigned capacity) {
//    return new MinHeap(capacity);
//}
//
//// Heapify
//void minHeapify(MinHeap *minHeap, int idx) {
//    int smallest = idx;
//    int left = 2 * idx + 1;
//    int right = 2 * idx + 2;
//
//    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
//        smallest = left;
//
//    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
//        smallest = right;
//
//    if (smallest != idx) {
//        MinHeapNode **a = &minHeap->array[smallest];
//        MinHeapNode **b = &minHeap->array[idx];
//
//        MinHeapNode *temp = *a;
//        *a = *b;
//        *b = temp;
//
//        minHeapify(minHeap, smallest);
//    }
//}
//
//// Extract the min
//MinHeapNode *extractMin(MinHeap *minHeap) {
//    MinHeapNode *temp = minHeap->array[0];
//    minHeap->array[0] = minHeap->array[minHeap->size - 1];
//
//    --minHeap->size;
//    minHeapify(minHeap, 0);
//
//    return temp;
//}
//
//// Insertion
//void insertMinHeap(MinHeap *minHeap, MinHeapNode *minHeapNode) {
//    ++minHeap->size;
//    int i = minHeap->size - 1;
//
//    while (i && minHeapNode->frequency < minHeap->array[(i - 1) / 2]->frequency) {
//        minHeap->array[i] = minHeap->array[(i - 1) / 2];
//        i = (i - 1) / 2;
//    }
//
//    minHeap->array[i] = minHeapNode;
//}
//
//// Build min heap
//void buildMinHeap(MinHeap *minHeap) {
//    int n = minHeap->size - 1;
//    int i;
//
//    for (i = (n - 1) / 2; i >= 0; --i)
//        minHeapify(minHeap, i);
//}
//
//MinHeap *createAndBuildMinHeap(char characters[], int frequencies[], int size) {
//    MinHeap *minHeap = createMinHeap(size);
//
//    for (int i = 0; i < size; ++i)
//        minHeap->array[i] = newNode(characters[i], frequencies[i]);
//
//    minHeap->size = size;
//    buildMinHeap(minHeap);
//
//    return minHeap;
//}
//
//MinHeapNode *buildHuffmanTree(char characters[], int frequencies[], int size) {
//    MinHeapNode *left, *right, *top;
//    MinHeap *minHeap = createAndBuildMinHeap(characters, frequencies, size);
//
//    while (minHeap->size != 1) {
//        left = extractMin(minHeap);
//        right = extractMin(minHeap);
//
//        top = newNode('$', left->frequency + right->frequency);
//
//        top->left = left;
//        top->right = right;
//
//        insertMinHeap(minHeap, top);
//    }
//    return extractMin(minHeap);
//}
//
//void printHuffmanCodes(MinHeapNode *root, vector<int> code, int top) {
//    if (root->left) {
//        code[top] = 0;
//        printHuffmanCodes(root->left, code, top + 1);
//    }
//
//    if (root->right) {
//        code[top] = 1;
//        printHuffmanCodes(root->right, code, top + 1);
//    }
//    if (!(root->left) && !(root->right)) {
//        cout << root->character << "  | ";
//        for (int i = 0; i < top; ++i) {
//            cout << code[i];
//        }
//        cout << endl;
//    }
//}
//
//// Wrapper function
//void HuffmanCodes(char characters[], int frequencies[], int size) {
//    MinHeapNode *root = buildHuffmanTree(characters, frequencies, size);
//
//    vector<int> code(MAX_TREE_HT, 0);
//    int top = 0;
//
//    printHuffmanCodes(root, code, top);
//}
//
//int main() {
//    int size;
//    cout << "Enter the size of the character array: ";
//    cin >> size;
//
//    char *characters = new char[size];
//    int *frequencies = new int[size];
//
//    cout << "Enter characters: ";
//    for (int i = 0; i < size; ++i) {
//        cin >> characters[i];
//    }
//
//    cout << "Enter frequencies: ";
//    for (int i = 0; i < size; ++i) {
//        cin >> frequencies[i];
//    }
//
//    cout << "Character | Huffman Code\n";
//    cout << "-------------------------\n";
//
//    chrono::time_point<std::chrono::system_clock> start, end;
//
//    start = std::chrono::system_clock::now();
//
//    HuffmanCodes(characters, frequencies, size);
//
//    end = std::chrono::system_clock::now();
//    chrono::duration<double> elapsed_seconds = end - start;
//
//    std::cout << "Elapsed time: " << elapsed_seconds.count() << "s\n";
//
//    delete[] characters;
//    delete[] frequencies;
//
//    return 0;
//}
//
