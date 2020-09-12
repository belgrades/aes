# Inside Rijndael **(AES)**

A basic AES implementation to perform the basic operations in Rijndael's finite field, using the extended Euclidean algorithm.

Fernando Crema

Data Privacy and Security\
Sapienza, Università di Roma

-------
## Goal

**Inside Rijndael.**

The goal of this project is to gain a better understanding of the arithmetic in Rijndael's finite field (underlying the AES blockcipher). In this sense, the basic idea is just to implement the phases **SubBytes** and the associated inverse **invSubBytes**. Therefore, we should:

1. Have the operations related to the Galois Field
    - Multiplication
    - Sum
    - Division
1. Implement the extended Euclidean Algorithm to find the multiplicative inverse of a polynomial $f(x)$ such that $f(x) . f-1(x) mod m(x) = 1$

## Steps 

Write a program (using your favourite programming language) able to:

1. Perform the basic operations in Rijndael's finite field, using the extended Euclidean algorithm for computing the multiplicative inverse of a polynomial.
1. Use your program to re-generate the AES S-Boxes (for both encryption and decryption).

## Bibliography

1. Paar, Christof, 1963-. Understanding Cryptography : a Textbook for Students and Practitioners. Berlin ; London :Springer, 2009.
1. Katz, Jonathan and Lindell, Yehuda . Introduction to Modern Cryptography, CRC Press, Second Edition, 2014.
1. Venturi, Daniele. Crittografia nel Paese delle Meraviglie, Springer, Collana di Informatica, 2012.
1. Joan Daemen, Vincent Rijmen, "The Design of Rijndael: AES – The Advanced Encryption Standard." Springer, 2002. ISBN 3-540-42580-2.

