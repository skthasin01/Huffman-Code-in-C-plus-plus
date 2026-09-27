# Huffman Coding in C++

A simple implementation of the **Huffman Coding algorithm** using C++.

This project demonstrates how Huffman Coding can be used for **lossless data compression** by assigning shorter binary codes to characters with higher frequencies.

## Features

* Take characters and their frequencies as input
* Calculate total frequency
* Calculate original memory using 8 bits per character
* Build a Huffman Tree
* Use a Min Heap / Priority Queue
* Generate Huffman Codes using recursion
* Calculate compressed memory
* Calculate saved memory
* Uses `class` instead of `struct`
* Uses pointers for Huffman Tree nodes

## Technologies Used

* C++
* STL
* `priority_queue`
* `vector`
* `map`
* Recursion
* Binary Tree

## How Huffman Coding Works

Huffman Coding is a lossless compression algorithm.

The basic process is:

1. Take each character and its frequency.
2. Insert all characters into a Min Heap.
3. Select the two nodes with the smallest frequencies.
4. Create a new parent node with their combined frequency.
5. Repeat until only one node remains.
6. The remaining node becomes the root of the Huffman Tree.
7. Traverse the tree recursively:

   * Left = `0`
   * Right = `1`
8. Generate a unique Huffman Code for each character.
9. Calculate the total number of compressed bits.

## Algorithm

```text
Input Characters and Frequencies
             ↓
        Create Nodes
             ↓
       Insert into Min Heap
             ↓
   Take Two Smallest Nodes
             ↓
     Create Parent Node
             ↓
      Insert Parent Node
             ↓
       Repeat Recursively
             ↓
        Huffman Tree
             ↓
     Generate Codes Recursively
             ↓
      Calculate Compressed Bits
             ↓
        Calculate Saved Bits
```

## Example Input

```text
Enter a number for Characters:
4

Enter the Characters & Frequencies:
A 5
B 9
C 12
D 13
```

## Example Output

```text
Total Bits : 312

Huffman Codes:
A=00
B=01
C=10
D=11

Compressed Bits : 78
Save Memory : 234
```

> **Note:** When characters have equal frequencies, the exact Huffman codes can vary while still producing a valid Huffman tree.
