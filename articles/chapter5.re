= Improving the Shift Cipher

In the previous chapter, we successfully deciphered a shift cipher.

The fundamental problem that reduces the confidentiality of the shift cipher is the limited number of available keys. Because there are so few keys, it can be easily deciphered through brute-force attacks or statistical analysis.

With this fact in mind, this chapter introduces specific improvements to enhance the security of the shift cipher. Through these improvements, we aim to increase the confidentiality of the shift cipher and enable more secure communication.

=={vigenere_cipher} Extending to the Vigenère Cipher

The Vigenère table is a compilation of 26 different substitution tables used in the shift cipher. The leftmost column contains the key letters, and the alphabet is arranged in alphabetical order based on these key letters.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[tikan_table_tougou][The Vigenère table (reproduced)][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/tikan_table_tougou_epub.png" alt="The Vigenère table (reproduced)" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: The Vigenère table (reproduced)</figcaption>
#@# </figure>
#@# //}

In the 16th century, French cryptographer Blaise de Vigenère developed a polyalphabetic cipher using the Vigenère table. Unlike the traditional shift cipher that uses a single key letter, the Vigenère cipher uses a string of letters as the key. We will refer to this as the key string.

By using this key string, the total number of possible keys increases dramatically, making the cipher significantly more resistant to brute-force attacks.

=== Vigenère Cipher Algorithm

The algorithm for the Vigenère cipher is shown in @<img>{vigenere_cipher}.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[vigenere_cipher][Vigenère Cipher Algorithm][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/vigenere_cipher.png" alt="Vigenère Cipher Algorithm" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Vigenère Cipher Algorithm</figcaption>
#@# </figure>
#@# //}

=== Key Generation

The key generation algorithm, @<b>{KeyGen}, generates the key string used in the encryption process. This generated key string is secretly shared between the sender and receiver and is used to maintain the security of encrypted communication.

The length of the key string directly affects its security. If the key string is too short, repeating patterns are more likely to occur, increasing the risk of decryption. On the other hand, if the key string is too long, it becomes difficult to manage, so a practical balance must be achieved. Typically, a key string of moderate length is chosen, balancing usability and security.

If the key string consists of a single character, the cipher becomes equivalent to a shift cipher.

The key string can be based on a specific keyword (called a @<i>{key keyword}), but using a random key increases security.

If a new random key is selected for each encryption, and the key length equals or exceeds the length of the plaintext, then while the ciphertext still reveals that the message uses alphabetic characters, it leaks absolutely no information about the original plaintext. This level of security is equivalent to the @<b>{one-time pad}, which is considered theoretically unbreakable.

Thus, the Vigenère cipher can be seen as a general form of monoalphabetic substitution ciphers. When the key string is only one character long, it becomes a shift cipher; when the key length equals or exceeds the plaintext length, it becomes a one-time pad. Furthermore, when the shift cipher's key is fixed to 3, it becomes the Caesar cipher.

=== Encryption Mechanism

Encryption in the Vigenère cipher involves applying the shift cipher to each character of the plaintext. For example, the first character of the plaintext is encrypted using the first character of the key string as the shift key. The same process is applied to the second character, the third, and so on.

However, if the key string is shorter than the plaintext, the key string is repeated as many times as necessary to match the length of the plaintext. This repeated version of the key is called the @<b>{extended key}.

In summary, the @<i>{n}-th character of the plaintext is encrypted using the @<i>{n}-th character of the extended key as the shift key.

=== Manual Encryption Example

For example, suppose the plaintext is "hello world." and the key string is "STAR". After removing spaces and punctuation from the plaintext, we get "helloworld". To match the length of the plaintext (10 characters), we generate an extended key from the key string (4 characters), resulting in "STARSTARST" (10 characters). This is formed by concatenating @<code>{"STAR" || "STAR" || "ST"}.

We then encrypt the plaintext using the extended key with the shift cipher. During this process, we use the Vigenère table to convert each character. The resulting ciphertext is "ZXLCGPOIDW".

See @<table>{vigenere_example}.

//table[vigenere_example][Vigenère Cipher Encryption Example]{
Plaintext				h		e		l		l		o		w		o		r		l		d
-------------------------------------------------------------
Extended Key		S		T		A		R		S		T		A		R		S		T
Ciphertext			Z		X		L		C		G		P		O		I		D		W
//}

== Experimenting with the Vigenère Cipher Tool

The Vigenère Cipher Tool is a web-based application for encrypting and decrypting text using the Vigenère cipher. It is designed to help users visually understand the encryption process.

 * GitHub Page
 ** @<href>{https://github.com/ipusiron/vigenere-cipher-tool}
 * Demo Page
 ** @<href>{https://ipusiron.github.io/vigenere-cipher-tool/}

Try entering the example we encrypted manually earlier into the tool and verify that it produces the same ciphertext.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[vigenere_cipher_tool][Result of performing the same encryption with the Vigenère Cipher Tool][scale=0.8]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/vigenere_cipher_tool.png" alt="Result of performing the same encryption with the Vigenère Cipher Tool" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Result of performing the same encryption with the Vigenère Cipher Tool</figcaption>
#@# </figure>
#@# //}
