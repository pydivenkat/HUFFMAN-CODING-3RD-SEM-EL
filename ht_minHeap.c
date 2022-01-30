#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// A Huffman tree node
struct MinHeapNode {

    // One of the input characters
    char data;

    // Frequency of the character
    unsigned freq;

    // Left and right child of this node
    struct MinHeapNode *left, *right;
};
struct MinHeap {

    // Current size of min heap
    unsigned size;

    // capacity of min heap
    unsigned capacity;

    // Array of minheap node pointers
    struct MinHeapNode** array;
};

/*A function allocate a new min heap node with given character 
and frequency of the character*/
struct MinHeapNode* newNode(char data, unsigned freq)
{
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(
        sizeof(struct MinHeapNode));

    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;

    return temp;
}

// A function to create a min heap of given capacity
struct MinHeap* createMinHeap(unsigned capacity)

{

    struct MinHeap* minHeap
        = (struct MinHeap*)malloc(sizeof(struct MinHeap));

    // current size is 0
    minHeap->size = 0;

    minHeap->capacity = capacity;

    minHeap->array = (struct MinHeapNode**)malloc(
        minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// A function to swap two min heap nodes
void swapMinHeapNode(struct MinHeapNode** a,
                     struct MinHeapNode** b)

{

    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// The standard minHeapify function.
void minHeapify(struct MinHeap* minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size
        && minHeap->array[left]->freq
               < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size
        && minHeap->array[right]->freq
               < minHeap->array[smallest]->freq)
        smallest = right;
    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest],
                        &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// A function to check if size of heap is 1 or not
int isSizeOne(struct MinHeap* minHeap)
{

    return (minHeap->size == 1);
}

// A standard function to extract minimum value node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap)

{

    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

// A utility function to insert a new node to Min Heap
void insertMinHeap(struct MinHeap* minHeap,
                   struct MinHeapNode* minHeapNode)

{

    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i
           && minHeapNode->freq
                  < minHeap->array[(i - 1) / 2]->freq) {

        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

// A function to build min heap
void buildMinHeap(struct MinHeap* minHeap)

{

    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// A function to print an array of size n
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);

    printf("\n");
}

// Function to check if this node is leaf
int isLeaf(struct MinHeapNode* root)

{

    return !(root->left) && !(root->right);
}

/* Creates a min heap of capacity equal to size and inserts all            
character of data[] in min heap.*/
struct MinHeap* createAndBuildMinHeap(char data[],
                                      int freq[], int size)

{

    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

// The main function that builds Huffman tree
struct MinHeapNode* buildHuffmanTree(char data[],
                                     int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap
        = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}


void printCodes(struct MinHeapNode* root, int arr[],
                int top)
{
    // Assign 0 to left edge and recur
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    // Assign 1 to right edge and recur
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        printf("%c : ", root->data);
        printArr(arr, top);
    }
}




int bc = 0;
void printBin(struct MinHeapNode* root, int arr[],
                int top, char c, char bin[])

{
    
    // Assign 0 to left edge and recur
    if (root->left) {

        arr[top] = 0;
        printBin(root->left, arr, top + 1,c,bin);
    }

   // Assign 1 to right edge and recur
    if (root->right) {

        arr[top] = 1;
        printBin(root->right, arr, top + 1,c,bin);
    }
    if(c==root->data){
        for (int i = 0; i < top; ++i){
            // printf("%d", arr[i]);
            bin[bc++] = arr[i] + '0';
        }
    }
}
void decode_huff(struct MinHeapNode* root , char s[]){
    struct MinHeapNode *my_root = root;
    for(int i = 0 ; s[i]!='\0' ; i++){
        if(s[i] == '1')
            my_root=my_root->right;        
        else
            my_root = my_root->left;
        if(isLeaf(my_root)){
            printf("%c",my_root->data);
            my_root=root;
        }
    }  
}




void HuffmanCodes(char data[], int freq[], int size, char str[])

{
    struct MinHeapNode* root
        = buildHuffmanTree(data, freq, size);

    int arr[MAX_TREE_HT], top = 0;

    printCodes(root, arr, top);
    printf("\n");
    int i=0;
    top=0;
    char bin[100];
    for(int i=0;i<100;i++)
        bin[i] = '\0';
    
    printf("The endoded code is: \n");
    
    while(str[i]!='\0'){
        printBin(root, arr, top,str[i],bin);
        i++;
    }
    printf("\n%s\n",bin);
    printf("The original size is %d bits\n",strlen(str)*8);
    printf("The encoded size is %d bits\n",strlen(bin));
    printf("\nThe decoded code is: \n");
    decode_huff(root,bin);
}
int searchArr(char arr[],char c){
    for(int i=0;i<100;i++){
        if(arr[i]==c)
            return 1;
    }
    return 0;
}






int main()
{
    char arr[100];
    for(int i=0;i<100;i++)
        arr[i] = '\0';
    int freq[100];
    for(int i=0;i<100;i++)
        freq[i] = 0;
    char str[100];
    printf("Enter the string: \n");
    scanf("%[^\n]s",str);
    int c=0;
    for(int i=0;str[i]!='\0';i++){
        int count = 1;
        if(!searchArr(arr,str[i])){
            for(int j=i+1;str[j]!='\0';j++)
                if(str[i]==str[j])
                    count++;
            arr[c] = str[i];
            freq[c++] = count;
        }
    }
    HuffmanCodes(arr, freq, c, str);
    return 0;
}