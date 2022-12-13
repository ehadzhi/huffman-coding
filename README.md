## Huffman Coding lossless data compression
#####  Data Structures project
######  (Computer Science, 2015/16 г.)

##### Task:

Write a program, that ingests a string from standart input fd (or a file), builds a
frequency table, Huffman tree and outputs the binary sequence, which 
codes the original string. After getting the binary sequence, output numbers from 0 to 255, 
which represent the binary sequence in bytes(8 bits). 
Calculate the compression ratio (ratio between number of bits of compressed data 
and the number of bit in the input string - we assume each sybol is coded in one byte). 
Using the Huffman tree reconstruct the original string.
##### Bonus points tasks:

1. The created huffman tree can be exported and imported in a suiting format. 

2. Your program can work with any file in binary format. Also it has a cli with different parameters:
-c[ompress] 
-d[ecompress]
-i fname – input file name
-o fname – output file name
In this case you should compare how your huffman implementation compares to 
ZIP and RAR archiving tools. Pick a file and compress them with the thress.
After that compare the output file sizes.

3. Your program can work with large files or data streams. In this case 
you should implement adaptive Huffman Coding. It should construct a huffman tree 
from incomplete data and modify it in the coding process so that coding efficiency is optimal.
 

Solution documentation: 
[Huffman.pdf](https://github.com/ehadzhi/huffman-coding/blob/master/Huffman.pdf)
