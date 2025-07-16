= The Basics of the Caesar Cipher

In this chapter, we will provide a detailed explanation of the Caesar cipher, which is the central theme of this book.

If we were to explain the Caesar cipher in a straightforward manner, it might simply come across as "a cipher with a simple mechanism."

However, having read this far, you will find this chapter especially valuable.

With an understanding of the essence of classical ciphers, you will be able to recognize the Caesar cipher's deeper significance.

== What Is the Caesar Cipher?

@<kw>{The Caesar cipher} is an encryption method that converts plaintext into ciphertext by shifting each letter three positions forward in alphabetical order.

This cipher is named after Gaius Julius Caesar—known simply as "Caesar" in English—the Roman military leader who famously employed it during the Gallic Wars to communicate with his allies while avoiding enemy interception.

@<img>{rot3_tikanhyou} shows the @<kw>{substitution table} for the Caesar cipher.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[rot3_tikanhyou][Substitution Table for the Caesar Cipher][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/rot3_tikanhyou.png" alt="Substitution Table for the Caesar Cipher" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Substitution Table for the Caesar Cipher</figcaption>
#@# </figure>
#@# //}

Each letter in the plaintext is shifted three positions forward to generate the ciphertext. When this shift extends beyond 'Z', it wraps around to the beginning of the alphabet.

As an example, let us examine how the plaintext "hello" is encrypted using the Caesar cipher. Each letter is encrypted sequentially. See @<img>{caesar_enc_hello}.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[caesar_enc_hello][Encrypting "hello"][scale=0.8]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/caesar_enc_hello.png" alt="Encrypting &quot;hello&quot;" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Encrypting "hello"</figcaption>
#@# </figure>
#@# //}

 * Plaintext letter 'h' ⇒ Ciphertext letter 'K'
 * Plaintext letter 'e' ⇒ Ciphertext letter 'H'
 * Plaintext letter 'l' ⇒ Ciphertext letter 'O'
 * Plaintext letter 'l' ⇒ Ciphertext letter 'O'
 * Plaintext letter 'o' ⇒ Ciphertext letter 'R'

As a result, the ciphertext becomes @<b>{"KHOOR"}.

Note that plaintext is written in lowercase and ciphertext in uppercase, following a traditional convention in classical cryptography. This distinction makes it easy to identify which is which at a glance. However, not all texts follow this convention, so context remains important.

Although the Caesar cipher is simple, it demonstrates three fundamental elements of modern cryptography:

 * Algorithm
 * Key (3 in the Caesar cipher)
 * Substitution

== What Is a Shift Cipher?

The Caesar cipher typically shifts letters by 3 positions, but it isn't limited to 3. For instance, you can shift by 1, 10, or any other number of positions. Shifting by 26 positions is effectively the same as no shift at all, since the remainder when divided by 26 is zero.

A cipher that shifts letters by any arbitrary number is called a @<kw>{shift cipher}, with the shift amount defined as @<b>{n}. This value @<b>{n} serves as the key, shared only between sender and receiver.

Due to their cyclic nature, shift ciphers are often called @<kw>{ROT ciphers}, from the English word @<i>{rotate}. A shift of @<b>{n} positions is denoted as @<kw>{ROTn}.

For example, a 1-position shift is written as @<kw>{ROT1}. See @<img>{rot1_tikanhyou} for its substitution table.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[rot1_tikanhyou][Substitution Table for ROT1][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/rot1_tikanhyou.png" alt="Substitution Table for ROT1" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Substitution Table for ROT1</figcaption>
#@# </figure>
#@# //}

The Caesar cipher is a shift cipher with a shift of 3, denoted as ROT3.

Since shift ciphers and the Caesar cipher share the same mechanism, some sources use these terms interchangeably. Context determines which term is more appropriate.

== Shift Cipher Algorithm

From an algorithmic perspective, an encryption scheme comprises three fundamental algorithms: @<b>{KeyGen}, @<b>{Enc}, and @<b>{Dec}. Here, @<b>{KeyGen} denotes the key generation algorithm, @<b>{Enc} denotes the encryption algorithm, and @<b>{Dec} denotes the decryption algorithm@<fn>{enc_alg}.

//footnote[enc_alg][These three algorithms—@<b>{KeyGen}, @<b>{Enc}, and @<b>{Dec}—are not exclusive to shift ciphers but form the foundational framework of modern cryptographic schemes.]

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[shift_enc_alg][Shift Cipher Algorithm][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/shift_enc_alg.png" alt="Shift Cipher Algorithm" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Shift Cipher Algorithm</figcaption>
#@# </figure>
#@# //}

The key generation algorithm generates a key, while the encryption algorithm converts plaintext into ciphertext. The decryption algorithm decrypts the ciphertext.

The term key here refers to the data that controls the transformation process in both encryption and decryption algorithms. In cryptographic systems, keys are critically important and must be kept secret from anyone other than the sender and receiver to maintain secure communication. If a key is compromised, the ciphertext can be decrypted by anyone, exposing the plaintext.

=== Mathematical Expression of Correctness

@<kw>{Correctness} refers to the property that decryption accurately recovers the original plaintext from the ciphertext. An encryption scheme must guarantee this correctness. If the original plaintext cannot be recovered even when using the correct ciphertext and key, the encryption fails to fulfill its fundamental purpose of secure communication.

As mentioned earlier, the shift cipher is defined by three algorithms. Using these algorithms to express correctness means that for any message @<i>{m} and @<i>{key}, the following equation must hold:

//texequation{
m=Dec(key, Enc(key, m))
//}
#@# //noindent
#@# @<m>{m=Dec(key, Enc(key, m))}

=== Modify the Process to Use a Substitution Table

The modified algorithm using a substitution table is shown in @<img>{shift_enc_alg2}.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[shift_enc_alg2][Shift Cipher Algorithm <Substitution Table Version>][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/shift_enc_alg2.png" alt="Shift Cipher Algorithm &lt;Substitution Table Version&gt;" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Shift Cipher Algorithm &lt;Substitution Table Version&gt;</figcaption>
#@# </figure>
#@# //}

=== How to Call Each Algorithm

@<img>{alice_bob_3alg_epub} shows the algorithm execution sequence. Alice and Bob call @<b>{KeyGen} in the preparation stage, then @<b>{Enc} and @<b>{Dec} in the main stage.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[alice_bob_3alg_epub][Calling the algorithm by Alice and Bob][scale=0.8]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/alice_bob_3alg_epub.png" alt="Calling the algorithm by Alice and Bob" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: alling the algorithm by Alice and Bob</figcaption>
#@# </figure>
#@# //}

=== Focus on Input/Output Before Implementation Details

Rather than diving into implementation details, first understand each algorithm's inputs and outputs. All encryption algorithms—classical or modern—follow the same basic input/output pattern:

 * @<b>{KeyGen} outputs a key (denoted @<i>{n})
 * @<b>{Enc} inputs plaintext @<i>{m} and key @<i>{n}, outputs ciphertext @<i>{c}
 * @<b>{Dec} inputs ciphertext @<i>{c} and key @<i>{n'}, outputs decrypted result @<i>{m'}
 ** When the key is correct: @<i>{m'} = @<i>{m}
 ** This property is called @<kw>{correctness}

Notice how these symbols connect the algorithms:

@<i>{n} links @<b>{KeyGen} to @<b>{Enc}, 
while @<i>{c} links @<b>{Enc} to @<b>{Dec}. Without these shared symbols, the algorithms would be independent.

Understanding these input/output relationships first makes the implementation details much clearer. Apply this approach when learning any new cryptographic scheme.

== Applying ROT13 Twice Restores the Original Text

@<kw>{ROT13} is a shift cipher that uses a key of @<m>{n = 13}. Since the alphabet has 26 letters and @<m>{13 = 26/2}, ROT13 has a unique property: encryption and decryption are identical operations.

The substitution table for ROT13 is shown in @<img>{rot13_tikanhyou}.

#@# 1ページ内に収まらないので画像化した.
#@# //table[rot13_tikanhyou][ROT13の置換表]{
#@# a	b	c	d	e	f	g	h	i	j	k	l	m	n	o	p	q	r	s	t	u	v	w	x	y	z
#@# -------------------------------------------------------------
#@# N	O	P	Q	R	S	T	U	V	W	X	Y	Z	A	B	C	D	E	F	G	H	I	J	K	L	M
#@# //}

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[rot13_tikanhyou][Substitution Table for ROT13][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/rot13_tikanhyou.png" alt="Substitution Table for ROT13" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Substitution Table for ROT13</figcaption>
#@# </figure>
#@# //}

Notice that each letter maps to another letter exactly 13 positions away. 
The second row is formed by swapping the first half (a–m) with the second half (n–z). This symmetry means that applying ROT13 twice returns the original text:

//texequation{
\mathrm{ROT13}( \mathrm{ROT13}(m) ) = m
//}

=== ROT13 Substitution Table

@<img>{rot13_mapping} shows the bijective mapping where each letter pairs with another exactly 13 positions away.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[rot13_mapping][ROT13 Character Mapping][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/rot13_mapping_epub.png" alt="ROT13 Character Mapping" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: ROT13 Character Mapping</figcaption>
#@# </figure>
#@# //}

Notice that shifting 13 positions left equals shifting 13 positions right. Since 13 is half of 26, this creates ROT13's defining characteristic: @<kw>{self-inverse property}.

Mathematically, since @<m>$13 = -13 \pmod {26}$:

 * Encryption: @<m>$(x + 13) \pmod {26}$
 * Decryption: @<m>$(x - 13) \pmod {26} = (x + 13) \pmod {26}$

Therefore, applying ROT13 twice returns each letter to its original position—ROT13 is its own inverse.

@<img>{rot13_and_rot13} demonstrates this self-inverse property in action.

#@# 1ページ内に収まらないので画像化した.
#@# //table[rot13_and_rot13][ROT13を2回実行]{
#@# 平文	a	b	c	d	e	f	g	h	i	j	k	l	m	n	o	p	q	r	s	t	u	v	w	x	y	z
#@# -------------------------------------------------------------
#@# 1回目の暗号化	N	O	P	Q	R	S	T	U	V	W	X	Y	Z	A	B	C	D	E	F	G	H	I	J	K	L	M
#@# 2回目の暗号化	A	B	C	D	E	F	G	H	I	J	K	L	M	N	O	P	Q	R	S	T	U	V	W	X	Y	Z
#@# //}

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[rot13_and_rot13][ROT13 Applied Twice: Full Cycle][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/rot13_and_rot13.png" alt="ROT13 Applied Twice: Full Cycle" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: ROT13 Applied Twice: Full Cycle</figcaption>
#@# </figure>
#@# //}

=== Applications of ROT13

ROT13 does not provide genuine confidentiality but is used to temporarily obscure text:

 * To hide puzzle answers from immediate view
 * To obscure potentially offensive content
 * To conceal geocaching location hints
 ** Geocaching is a GPS-based treasure-hunting game
 ** @<href>{https://www.geocaching.com/play}

== Shift Ciphers Are a Type of Substitution Cipher

The key in a shift cipher specifies the shift distance. This creates a one-to-one character mapping—effectively a substitution table. Since shift ciphers work by substituting each letter with another, they are a special case of substitution ciphers.

=== Shift Cipher Keys and Their Representations

Earlier, we established that shift cipher key = shift amount = substitution table@<fn>{tougou}.

//footnote[tougou][The equals sign '=' indicates conceptual equivalence, not numerical equality.]

Shift values range from 0 to 25. Why exactly 26 values? Because the alphabet has 26 letters:

 * Shifting by 26 returns to the original position
 * Shifting by 27 equals shifting by 1

We can represent each shift value with a letter, creating a @<kw>{key character} system (@<table>{shift_keychar})@<fn>{shift_keychar_mapping}.

//footnote[shift_keychar_mapping][Alternative mappings exist (e.g., 'A'=1, 'B'=2, ..., 'Z'=26), but 'A'=0 ensures no change when shift is zero.]

//table[shift_keychar][Shift Values and Key Characters]{
Shift Value		Key Character
-------------------------------------------------------------
0							'A'
1							'B'
2							'C'
3							'D'
…							…
25							'Z'
//}

For example, ROT3 uses key character 'D'. 
In its substitution table, the ciphertext row begins with 'D'—the key character determines the table structure.

This principle applies to all shift ciphers: knowing the key character instantly reveals the substitution pattern.

Therefore:

//centering{
Caesar cipher key = shift value = key character = substitution table
//}

== Encrypting English Sentences with a Shift Cipher

Encrypting individual English words using a shift cipher works without problems.

However, encrypting complete English sentences introduces complications. This is because English sentences contain non-alphabetic characters (characters other than letters of the alphabet).

These non-alphabetic characters include spaces, commas, periods, exclamation marks, question marks, and other punctuation. Since the Caesar cipher handles only alphabetic characters, it excludes all non-alphabetic characters from the plaintext during encryption. As a result, the output ciphertext consists solely of letters, without the excluded characters.

To properly restore the original sentence after decryption, you must carefully reinsert the missing spaces and punctuation.

== Hands-on Practice with Caesar Cipher

Let's experience the encryption process using the Caesar cipher.
We'll use key letter 'D', which corresponds to a shift of 3.

==={enc_by_caesar} Encryption Example

As an example, we'll use the following line from the beginning of Edgar Allan Poe's poem @<i>{"The Sleeper"}@<fn>{sleeper}@<fn>{poestories}.

//footnote[sleeper][As poetry allows various interpretations, one translation might be: "On a certain midnight in June, under a mysterious moon, I stood."]
//footnote[poestories][Poe's works are available at PoeStories.com (@<href>{https://poestories.com/read/ovalportrait}). "The Sleeper" can be found at @<href>{https://poestories.com/read/sleeper}.]

//quote{
At midnight, in the month of June, I stand beneath the mystic moon.
//}

To simplify our discussion, we'll follow these conditions:

 * Keep all spaces and punctuation; do @<b>{not} remove non-alphabetic characters
 * Write all ciphertext in @<b>{uppercase}

Now, let's walk through the encryption steps:

//noindent
@<b>{Step 1}: Convert all plaintext to lowercase.

This gives us (before capitalization):

//noindent
"at midnight, in the month of june, i stand beneath the mystic moon."

//noindent
@<b>{Step 2}: Apply the substitution table for key letter 'D'. We substitute each letter according to the plaintext row of the table.

The resulting ciphertext is:

//noindent
"DW PLGQLJKW, LQ WKH PRQWK RI MXQH, L VWDQG EHQHDWK WKH PBVWLF PRRQ."

=== Decryption Example

Now let's go through the decryption process:

//noindent
@<b>{Step 1}: Decrypt using the substitution table for key letter 'D'. For decryption, we use the ciphertext row (second row) of the table. This gives us:

//noindent
"at midnight, in the month of june, i stand beneath the mystic moon."

//noindent
@<b>{Step 2}: Verify the message makes sense and apply proper capitalization. In the final step, we apply proper capitalization as follows:

 * The first letter of the sentence
 * The pronoun "I"
 * Proper nouns (months, countries, names)

The final result is:

//noindent
"At midnight, in the month of June, I stand beneath the mystic moon."

This result perfectly matches the original plaintext.

==[column] Shift Ciphers and Mathematics

This section explains how to express shift cipher operations mathematically. To begin with, we assign each letter a numerical value from 0 to 25:

//texequation{
A=0, B=1, ..., Z=25
//}

Let @<m>{T} be the plaintext character, @<m>{K} the key character, and @<m>{C} the ciphertext character.
The shift cipher operation is then:

//texequation{
T + K \equiv C \pmod{26}
//}

For encryption, @<m>{C} is unknown while @<m>{T} and @<m>{K} are known. Since only one variable is unknown, we can solve for @<m>{C}.

For decryption, @<m>{T} is unknown while @<m>{C} and @<m>{K} are known. We solve for @<m>{T} similarly.

Since substitution ciphers (including shift ciphers) replace letters systematically, we can view the substitution table as a bijective mapping from the alphabet set to itself.

This mathematical perspective clarifies the fundamental mechanisms of classical ciphers 
and often directly informs their implementation in code.
#@# ==[/column]
#@# Columns are used when complex layouts are needed during EPUB or PDF builds, but they are not necessary for regular paragraphs or block quotes.
