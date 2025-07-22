= Letter Frequency in Alphabets

The characteristics of letter frequency (how often letters appear) are often effective in deciphering classical ciphers. Moreover, letter frequency can help identify or narrow down the language (or writing system) used in the encrypted message.

For example, in Spanish, the relative pronoun "que" is frequently used, so the letter 'q' appears more often compared to other languages. In German texts, letters like 'e' and 'n' are highly frequent. Each language has its own skewed distribution where certain letters appear more frequently than others. In other words, every language has a unique semiotic fingerprint.

By effectively leveraging these biases in letter frequency, cryptanalysis can become significantly more powerful.

== Letter Frequency Distribution

In English, each letter appears with the probabilities shown in @<table>{char_frequency}. These values represent the typical letter frequency in general English texts.

//table[char_frequency][Letter Frequency Distribution]{
Letter	Frequency		Letter	Frequency
-------------------------------------------------------------
A				0.082				N				0.067
B				0.015				O				0.075
C				0.028				P				0.019
D				0.043				Q				0.001
E				0.127				R				0.060
F				0.022				S				0.063
G				0.020				T				0.091
H				0.061				U				0.028
I				0.070				V				0.010
J				0.002				W				0.023
K				0.008				X				0.001
L				0.040				Y				0.020
M				0.024				Z				0.001
//}

== Letter Frequency Graph

CrypTool 2 provides a built-in template for classical cipher analysis called the @<b>{Friedman Test for Classical Ciphers}. Using the sample provided with this template, we obtain the following results. The sample consists of 8,334 characters of English text.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[friedman_test][Letter Frequency Graph][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/friedman_test.png" alt="Letter Frequency Graph" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Letter Frequency Graph</figcaption>
#@# </figure>
#@# //}

The letter 'E' appears with striking prominence. Its frequency is 13.17%, which is quite close to the 12.7% shown in @<table>{char_frequency}.

Next comes 'T', followed by 'O', 'N', 'A', 'S', 'I', and 'R'. While the exact order doesn't perfectly match the frequencies in @<table>{char_frequency}, it is largely consistent.

== Grouping by Letter Frequency

Letters can be classified into six groups based on their frequency of appearance, as shown in @<table>{char_frequency_group}.

//table[char_frequency_group][Hierarchical Classification of Letter Frequencies]{
Group							Letters										Frequency Range		Remarks
-------------------------------------------------------------------------------------------------------------
Most Frequent			E													0.12							Key for analysis
High Frequency		T, A, O, I, N, S, H, R		0.06-0.09					Common letters
Medium Frequency	D, L, U, C, M							0.03-0.04					-
Low Frequency			F, Y, W, G, P, B, V				0.015-0.028				-
Rare							J, K, Q, X, Z							Below 0.01				Very rare
//}

== Letter Frequencies Across Languages

Wikipedia's "Letter frequencies" page provides information on letter frequencies for various languages.

When letters are ordered by frequency, we get the sequences shown in @<table>{ETAOIN}.

//table[ETAOIN][Most Frequent Letters and Mnemonics by Language]{
Language	Letter Sequence
-------------------------------------------------------------
English		ETAOIN SHRDLU
Spanish		EAOSR NIDLT
French		ESAIT NRUOL
German		ENISR ATDHU
Italian		EAION LRTSC
//}

You don't need to memorize every sequence, but it's useful to remember @<b>{ETAOIN} for English. This is a well-known mnemonic that aids memory and is commonly used in cryptanalysis.

While not every English text will follow this exact order of frequency, most will roughly align with it.

Incidentally, the phrase @<b>{ETAOIN SHRDLU} also became famous in the era of hot metal typesetting. It originated from typesetters' habits and often appeared in printed English materials as a placeholder. It is documented in resources such as the @<i>{Oxford English Dictionary} and @<i>{Random House Webster's Unabridged Dictionary}.

This string also corresponds to the first two vertical columns of keys on the left side of a Linotype machine keyboard, traceable by hand.
