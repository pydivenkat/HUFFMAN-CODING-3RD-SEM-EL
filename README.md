# HUFFMAN-CODING-3RD-SEM-EL
Algorithm 1-Using Min Heaps

In a Min-Heap the key present at the root node must be less than or equal to among the keys present at all of its children. In a Min-Heap the minimum key element present at the root. A Min-Heap is a priority queue that uses the ascending priority i.e. in the construction of a Min-Heap, the smallest element has priority.
Input the string that has to be encoded. The string is condensed into a unique character array and a frequency array
A min heap is created with this data by first storing elements in an array and minheapifying it
The extractMin function is repeatedly used to extract the first two minimum frequencies(along with the associated characters) from the min heap and hence these frequencies are removed from the heap
A new node of the huffman tree is generated whose left and right children are respectively the two minimum frequencies.
The data of the node is fed to the min heap which is minHeapified once more.
The above steps are repeated until there is only one node in the heap which is the root node.
Major Functions and Structures Used:
The minHeapNode structure is the basic element of the implemented minHeap. It also forms a node of the final huffman tree. It consists of a data field to store the character value and a frequency field to store the corresponding frequency. Most importantly, it holds the addresses of its left and right children as it is a node of a binary tree.

The minHeap structure represents a min heap along with details of its properties such as size, capacity and the min heap array which represents the tree.

createMinHeap() : This function dynamically allocates memory for the min heap and initializes its various attributes such as size, capacity(maximum size) and the min heap array which holds the tree.

minHeapify() : This function is helpful in maintaining the property of the min heap by traversing through the heap and comparing all parent nodes with their children. If any violation of the min heap rule(parent is always lesser than child) is found the parent and child are interchanged and the child is checked with its child if it is a parent. Hence the min heap regains its property and the minimum node ends up in the beginning.

Img 3.2.1 minHeapify function

extractMin() : This function simply extracts the value of the root of the min heap as the minimum value is predicted at the root from the structure of the min heap.



buildMinHeap() : This function receives disorganised heap as its input along with the index of addition which brought up this chaos. The function calls the minHeapify function from this index which eliminates unnecessary sorting of the entire heap thereby improving performance and reducing computational cost.

createAndBuildMinHeap() : It takes input as the unique character array and the corresponding frequency array. It calls the createMinHeap function to create min heap structure and allocate space. According to the inputs the nodes are inserted into the array attribute of the created min heap and minHeapified.

buildHuffmanTree() : It is one of the main functions used to build a huffman tree from the existing min heap. A min heap is created by calling the createAndBuildMinHeap function and passing the required dataset. The two minimum frequencies of the min heap are extracted and combined according to the discussed Huffman Algorithm. This combination is added as a separate node to the min heap and the entire heap is min heapified to maintain its properties.

Img 3.2.2 buildHuffmanTree() function
printBin() : This function takes in the huffman tree ,the character to be checked and the character array storing the encoded the string in huffman codes. It does so by reading the character of the string as input and traversing the tree until it reaches the element at a leaf node of the tree. Here it checks whether the value at the leaf is the same as the character. If yes, then code is added to a character array given as input.

printCodes() : It performs an operation similar to the printBin function but instead of taking single character inputs, it takes in the entire string as input. The string is traversed character by character. Each character is traversed through the tree with the general rule that 0 is assigned while traversing to the left node and 1 is assigned while traversing to the right node. The final code is obtained as a combination of all assignments upto a leaf node and is printed along with the corresponding character in the leaf node.



Img 3.2.3 printCodes() function

decodeHuff() : This function works with the decoding algorithm taking the input as the encoded bits and the huffman tree. The encoded string is traversed along with the tree with the rule that a 0 bit indicated right traversal while a 1 bit indicated a left traversal. When a leaf node is reached it prints the character value of the leaf and repeats the tree traversal.


HuffmanCodes() : This function integrates the working of all the other functions to give a sequential procedure of producing the huffman tree, printing the huffman codes and the encoded string and finally decoding it.

Decoding
Using Huffman tree/huffman table generated and the encoded bits of the given string, the original string can be decoded. Hence while decoding we require the encoded message as well as huffman table which has to be stored or sent along with the encoded bits.
The algorithm for decoding is:
Take input as the encoded message and huffman tree
The huffman tree is traversed according to the encoded message.
Starting from the root of the tree, if the encoded bit is 0, the new root is the left child of the current root.
If the encoded bit is 1, new root is the right child of the current root
If we reach a leaf node, we print the value of the node and set the root to the actual root of the tree.






3.2.2 Algorithm-2 Using Queues
When is it applied?
Applied when the given array is sorted
Queues are used for the execution of the programs
Leaf node is created for each character and frequency is increased on encounter with the character
The time complexity of this algorithm is O(n)
If the input is not sorted, it needs to be sorted first before it can be processed by the above algorithm. Sorting can be done using heap-sort or merge-sort both of which run in Theta(nlogn). So, the overall time complexity becomes O(nlogn) for unsorted input. 
This algorithm is applied only when the array is sorted else time complexity increases thus making it an efficient Huffman coding algorithm.
Algorithm
Create two empty queues.
Create a leaf node for each unique character and Enqueue it to the first queue in non-decreasing order of frequency. Initially the second queue is empty.
Dequeue two nodes with the minimum frequency by examining the front of both queues. Repeat following steps two times 
        	1. If the second queue is empty, dequeue from the first queue. 
        	2. If the first queue is empty, dequeue from the second queue. 
        	3. Else, compare the front of two queues and dequeue the minimum. 
Create a new internal node with frequency equal to the sum of the two nodes frequencies. Make the first Dequeued node as its left child and the second Dequeued node as right child. Enqueue this node to the second queue.
Repeat steps#3 and #4 while there is more than one node in the queues. The remaining node is the root node and the tree is complete.   












The major functions used are:
The QueueNode structure represents the individual entity of the queue. It also functions as a node of the huffman tree with left and right attributes. The node contains fields for the unique character value it stores and the corresponding frequency.
The Queue structure represents a queue entity. It contains details of the front and rear ends of the queue and its capacity(maximum size). It also contains the array which implements the queue
createQueue() : An explicitly declared function which sets up a queue entity. It allocates memory for the Queue structure and assigns values to its parameters. The front and rear members are assigned -1, while the capacity is set to the maximum size value passed on to the function. A double pointer array is initialized to hold the queue nodes.
enQueue() : This function enables the addition of a queue node item to the rear end of the queue after checking for the overflow condition.
deQueue() : Similar to enqueue, it targets to remove an element from the front end of the queue and increment the front pointer after checking for the queue empty condition.
findMin() : It is an essential function to find the minimum node values in the two queue scheme which is required for the huffman coding concept. Since the inputs are sorted the front of the queue has the minimum values. The function internally calls the dequeue function for those of the two queues which have the minimum value. 
buildHuffmanTree() : This function uses queues to build the huffman tree. The first queue stores the character nodes in their sorted input order of their frequencies. The second queue is initially empty. The two minimum values in the two queues are obtained by comparing their front values twice. These values are added and enqueued to the second queue. This process continues until only one node remains in the second queue.








3.2.3 Comparing algorithm-1 and algorithm-2
The time complexities of the two algorithms are calculated and using the clock function the real  time taken is measured. 
The time of execution of the two algorithms is measured using the below mentioned clock function to compare their time complexities.

The clock() function is defined in the ctime header file. The clock() function returns the approximate processor time that is consumed by the program. The clock() time depends upon how the operating system allocates resources to the process, that's why clock() time may be slower or faster than the actual clock










3.3 Image compression using Huffman coding
Huffman coding proves to be an efficient technique to perform lossless compression of data, especially images. This is particularly useful in transmission and storage of data where bits represent data. The idea to generate variable length bit coded data helps to reduce redundancy and increase space required and the subsequent time. 
The above comparisons of time complexities are enough proof for us to go with the queue implementation of the arrays. Alternatively, according to the form of data in this application(array of image pixels), we make use of the array implementation of the huffman tree. The need for the min Heapify function is eliminated by explicitly sorting the input pixel intensity values according to their frequencies which provides for a better time complexity effectively. The utilization of algorithm-1 or algorithm-2 is purely situation dependent. For example, in case of large data, the sorting algorithm may itself take a lot of time thereby reducing the performance of the encoding.
Algorithm for compression(encoding) of images using huffman code
Step 1 :
Read the Image into a 2D array(image) using bmp format of image
Create a Histogram of the pixel intensity values present in the Image
Find the number of pixel intensity values having non-zero frequency of occurrence
Step 2 :
Define a struct which will contain the pixel intensity values(pix), their corresponding frequencies, the pointer to the left(*left) and right(*right) child nodes and also the string array for the Huffman code word(code).
Step 3 :
Define another Struct which will contain the pixel intensity values(pix), their corresponding frequencies and an additional field, which will be used for storing the position of new generated nodes
Step 4 :
Declaring an array of structs. Each element of the array corresponds to a node in the Huffman Tree.
Initialize the two arrays pix_freq and huffcodes with information of the leaf nodes.
Sorting the huffcodes array according to the frequency of occurrence of the pixel intensity values
Step 5 :
Start by combining the two nodes with lowest frequencies of occurrence and then replacing the two nodes by the new node. This process continues until we have a root node. The first parent node formed will be stored at index node in the array pix_freq and the subsequent parent nodes obtained will be stored at higher values of index.
Step 6 :
Backtrack from the root to the leaf nodes to assign code words
Encode the Image into a text file.

                       



Decoding the Image
Using the decompression algorithm discussed earlier, using the generated Huffman tree and the encoded bits, we can obtain the decoded image array. This array is checked with the original array for validation of the decoding.

Main sections defined are : 

strconcat() : It takes in two strings and one character as the input. The second string argument is concatenated with the character and stored in the first string.

Reading the image pixels into an image array using the fseek and fread functions. This image array is traversed and printed.

A histogram array which stores the unique pixel values and their corresponding frequencies. It stores the zero as well as non zero occurring pixels.

A pixfreq structure is defined which stores the pixel intensity value, the frequency for that pixel intensity, the left and right children of the node and the code for that pixel value.

A huffcode node is defined with the attributes of pixel intensity, the corresponding frequency and the location of that pixel value in the pixfreq array.

Two arrays, one having its individual element as huffcode node and the other having its individual element as pixfreq structure are initialized with each unique pixel value along with the corresponding frequency.

The next section involves sorting the huffcode array in the descending order.

The build huffman tree section involves making the huffman tree by traversing through the huffman codes sorted array and combining the minimum frequency nodes in the array. This combined frequency is inserted into the huffman code array such that its order is maintained. The combined frequency node is also appended to the pix freq array in this section setting the node’s right and left attributes as the two minimum frequencies which gave the appended node.

Using backtracking the huffman tree generated is iterated to obtain the huffman codes which are further displayed.
