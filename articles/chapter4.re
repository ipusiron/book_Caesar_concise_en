= Breaking Caesar and Shift Ciphers

This chapter explains in detail how to break shift cipher ciphertexts without knowing the key. Here we address the central challenge indicated by this book's title.

We begin with manual cryptanalysis to develop a thorough understanding of the breaking process. We then implement computer-based methods for efficient and systematic attacks.

== Breaking Shift Ciphers with Brute-Force Attacks

With only 26 possible keys (one for each letter), shift ciphers are vulnerable to brute-force attacks.

==={brute_force_by_manual} Manual Brute-Force Attack

Let's break the shift cipher ciphertext "KZDVWCZVJCZBURERIIFN".

//noindent
@<b>{Step 1}: Analyze the ciphertext characteristics. The ciphertext is a continuous string without spaces or punctuation. This suggests word boundaries have been removed during encryption.

//noindent
@<b>{Step 2}: Execute brute-force decryption. Test all 26 possible shift values (0-25). For shift value n, decrypt by shifting left n positions (or right 26-n positions).

See @<table>{bruteforce_of_keys} for all results.

//table[bruteforce_of_keys][Decryption Results for All Shift Values]{
Shift Value n		Key Character		Decrypted Result
-------------------------------------------------------------
0					'A'					kzdvwczvjczbvreriifn
1					'B'					jycuvbyuibyauqdqhhem
2					'C'					ixbtuaxthaxztpcpggdl
3					'D'					hwastzwsgzwysoboffck
4					'E'					gvzrsyvrfyvxrnaneebj
5					'F'					fuyqrxuqexuwqmzmddai
6					'G'					etxpqwtpdwtvplylcczh
7					'H'					dswopvsocvsuokxkbbyg
8					'I'					crvnournburtnjwjaaxf
9					'J'					bqumntqmatqsmivizzwe
10					'K'					aptlmsplzsprlhuhyyvd
11					'L'					zosklrokyroqkgtgxxuc
12					'M'					ynrjkqnjxqnpjfsfwwtb
13					'N'					xmqijpmiwpmoierevvsa
14					'O'					wlphiolhvolnhdqduurz
15					'P'					vkoghnkgunkmgcpcttqy
16					'Q'					ujnfgmjftmjlfbobsspx
17					'R'					timeflieslikeanarrow
18					'S'					shldekhdrkhjdzmzqqnv
19					'T'					rgkcdjgcqjgicylyppmu
20					'U'					qfjbcifbpifhbxkxoolt
21					'V'					peiabheaohegawjwnnks
22					'W'					odhzagdzngdfzvivmmjr
23					'X'					ncgyzfcymfceyuhulliq
24					'Y'					mbfxyebxlebdxtgtkkhp
25					'Z'					laewxdawkdacwsfsjjgo
//}

To identify the correct plaintext, apply these three approaches:

 * @<b>{Approach 1: Common word detection}
 ** Search for frequent English words ("the", "and", "that")
 ** Their presence indicates a likely correct shift value
 * @<b>{Approach 2: Pattern elimination}
 ** Exclude results with unnatural consonant clusters (e.g., "kzdv")
 ** Remember: word boundaries may be removed ("goodbye" from "good bye")
 * @<b>{Approach 3: Rare letter analysis}
 ** Check context around uncommon letters ('z', 'q')
 ** Verify if they form valid English words

Applying these approaches reveals that shift value 17 produces "timeflieslikeanarrow". Adding spaces and proper capitalization yields: "Time flies like an arrow". This English proverb confirms we've found the correct plaintext with key shift n = 17.

== Breaking Ciphers Through Frequency Analysis

Frequency analysis identifies plaintext by studying character distribution in the ciphertext. This technique devastates classical ciphers, particularly monoalphabetic substitutions like shift ciphers. Since shift ciphers preserve letter frequencies (only shifting positions), frequency analysis remains highly effective.

=== Frequency Analysis Against Monoalphabetic Substitution Ciphers

In monoalphabetic substitution ciphers, each plaintext character maps to a fixed ciphertext character. This preserves character frequencies—the frequency distribution remains identical, just with different letters. This preservation allows cryptanalysts to match ciphertext characters to plaintext characters.

Longer ciphertexts yield better results, as larger samples converge toward standard English letter frequencies.

However, texts deliberately avoiding certain letters@<fn>{gadsby} defy standard frequency patterns. Cryptanalysts must consider such edge cases.

//footnote[gadsby][Ernest Vincent Wright's "Gadsby" (50,000+ words) contains no words with the letter 'e'.]

Letter and word frequencies vary by language, era, and text type. New words emerge while others become obsolete. Sample selection significantly affects results. Consequently, frequency tables differ across reference sources.

=== Initial Letter Patterns in English Words

Classical cipher plaintexts typically use natural language. Natural languages exhibit predictable character distributions—here we examine English.

If you have an English dictionary, close it and view the fore edge@<fn>{maekoguti}. You'll see index tabs (black bands) marking each letter section.
Band width directly reflects word frequency: wider bands contain more words starting with that letter.

//footnote[maekoguti][The edge opposite the spine, also called the fore edge.]

Letters like 's' and 'c' have wide bands, while 'x', 'y', and 'z' are so rare they often share a single tab.

When ciphertexts preserve word boundaries, initial letter frequencies become powerful cryptanalytic tools. These patterns hold true across virtually all English texts.

=== Analyzing Character Frequencies Without Word Boundaries

Without spaces to mark word boundaries, we must rely on character frequency patterns.

English exhibits predictable character distributions:

 * Most common: e, t, a, o, i, n
 * Least common: z, q, x, j

//texequation{
\text{Character Frequency} = \frac{\text{Occurrences}}{\text{Total Characters}}
//}

This ratio reveals how often each character appears in typical English text. See @<chap>{appendixA} for detailed frequency tables.

Since frequency patterns persist regardless of spacing, this technique breaks both spaced and unspaced ciphertexts equally well.

==={cryptool_caesar_by_frequency} Breaking Shift Ciphers with Frequency Analysis in CrypTool 2

CrypTool 2 provides the Caesar Analyzer component (found under Cryptanalysis > Specific) for frequency-based cryptanalysis. This component breaks shift ciphers by analyzing character frequencies, supporting unigrams, bigrams, trigrams, and higher n-grams.

The Caesar Analyzer operates as follows:

//noindent
@<b>{Step 1}: Decrypt the ciphertext with all possible keys (brute force).

//noindent
@<b>{Step 2}: Compare each result's character frequencies against known language patterns.

//noindent
@<b>{Step 3}: Select the most linguistically probable plaintext and output its key.

Component connections:

 * Inputs
 ** @<b>{Encrypted text}: The shift cipher ciphertext
 ** @<b>{Frequency List}: Language statistics from Frequency Test component
 * Output
 ** @<b>{Key}: The most probable decryption key

Build your project as shown in @<img>{caesar_fre1}:

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[caesar_fre1][Frequency analysis project setup][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/caesar_fre1.png" alt="Frequency analysis project setup" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Frequency analysis project setup</figcaption>
#@# </figure>
#@# //}

Component configuration and roles:

 * @<b>{Text Input} ("Ciphertext") – Top left
 ** Input: Encrypted text to analyze
 * @<b>{Frequency Test} ("FrequencyTest")
 ** Function: Analyzes character frequencies
 ** Output: Bar chart visualization
 * @<b>{Caesar Analyzer} ("CaesarAnalysisHelper")
 ** Function: Determines most probable shift value
 * @<b>{Caesar} ("Caesar Decryption")
 ** Action: Decrypt
 ** Alphabet: A-Z
 ** Settings: Enable "Output contains Source Case"
 * @<b>{Text Output} ("Key")
 ** Displays: Identified shift value
 * @<b>{Text Output} ("Decrypted Ciphertext") – Far right
 ** Displays: Final decrypted text

Workflow:

//noindent
1. FrequencyTest analyzes unigram frequencies and generates a bar chart
//noindent
2. CaesarAnalysisHelper uses these frequencies to determine the most probable key
//noindent
3. Caesar component decrypts the ciphertext using the identified key
//noindent
4. Both the key and decrypted text are displayed in their respective outputs

Testing with the ciphertext from @<hd>{brute_force_by_manual} correctly identified shift value 17, despite its brevity.

== Identifying Shift Cipher Ciphertext

In cryptanalysis, identifying the encryption method is the crucial first step.

When analyzing unknown ciphertext, use frequency analysis to generate its character distribution. Compare this against shifted versions of standard English frequencies. A match indicates a likely shift cipher; no match suggests a different encryption method.

=== Using Index of Coincidence to Identify Monoalphabetic Ciphers

The Index of Coincidence (IC) measures the probability that two randomly selected characters match.
This statistical tool helps analyze texts and identify encryption types.

Typical IC values:

 * English text: ~6.7%
 * Random text: ~3.8%

In practical cryptanalysis, calculating and applying IC matters more than understanding its theoretical foundations.

The IC method reliably identifies monoalphabetic substitution ciphers because character substitution preserves the original IC value—the frequency pattern remains intact, just with different letters.

Next, we'll calculate the Index of Coincidence.

//noindent
@<b>{Step 1}: Access the Index of Coincidence calculator at dCode.fr: @<href>{https://www.dcode.fr/index-coincidence}

//noindent
@<b>{Step 2}: Enter the message to analyze in "MESSAGE TO ANALYSE". We'll use the provided sample ciphertext (shown here without line breaks):

//quote{
ABC DCEFG
FHI JBK LHM KGFKN
OMPPHOK LHM JBK
OGQLCDE GH DCEFG
C FJRK SKKD GBLCDE
GH ANHMBCOF J
NCGGNK. FJRK
SKKD HMG SBKJTCDE
BHJQO GFCO
JAGKBDHHD AHB GFK
IJEHDO. EHHQ DCEFG
//}

Select "LETTER A-Z ONLY" under CHARACTERS. Click [CALCULATE IC] to display the results. @<img>{ic1} shows the process of calculating the Index of Coincidence.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[ic1][Calculating the Index of Coincidence][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/ic1_epub.png" alt="Calculating the Index of Coincidence" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Calculating the Index of Coincidence</figcaption>
#@# </figure>
#@# //}

//noindent
@<b>{Step 3}: The IC value is 0.06402 (6.4%). This closely matches English's typical IC of 6.7%, strongly indicating a monoalphabetic substitution cipher.

== Verifying Correct Plaintext Recovery

Cryptanalysis typically generates multiple plaintext candidates, but only one represents the true message. This message will be in natural language—English in our context.

The correct plaintext exhibits natural English characteristics and meaningful content, distinguishable through linguistic flow and contextual coherence.

While @<hd>{brute_force_by_manual} demonstrated manual techniques, here we leverage computational methods to evaluate candidates:

 * @<b>{Approach 1: Word-Based Analysis}
 ** With spaces preserved:
 *** High-frequency words ("the", "and", "is") indicate probable correctness
 ** Without spaces:
 *** Word boundary detection becomes challenging@<fn>{the_fumei}
 *** Longer word matches increase confidence
 * @<b>{Approach 2: Frequency Analysis}
 ** Compare character distributions against standard English frequencies
 * @<b>{Approach 3: Bigram/Trigram Analysis}
 ** Common pairs ("th", "er", "in") suggest natural English

//footnote[the_fumei][Distinguishing standalone "the" from fragments like "...th" + "e..." requires context.]

=== Leveraging Dictionary Files

Computers can automate Approach 1 through dictionary files.

A dictionary file is a plain text file containing one word per line. This simple format enables efficient word lookup during cryptanalysis.

English dictionary files help verify whether decrypted text forms valid English.

Common dictionary locations on UNIX-like systems:

 * @<code>{/usr/share/dict}
 * @<code>{/usr/dict/words}
 * Password tool directories:
 ** ParrotOS: @<code>{/usr/share/john/password.lst}
 ** Debian: @<code>{/usr/share/opendict/dictionaries}
 ** macOS: @<code>{/Library/Dictionaries}

Beyond system dictionaries, specialized wordlists serve different cryptanalytic purposes:

 * @<b>{General dictionaries}: Animal names, European names, technical terms
 * @<b>{Password lists}: Common choices ("12345678", "password1"), leaked databases
 * @<b>{Filtered sets}: Excluding single letters ('a', 'I'), focusing on meaningful words
 * @<b>{Pattern-based}: Numeric sequences (PIN analysis), alphanumeric combinations (≤8 characters)
 * etc.

=== Performing Brute-Force Attack and Dictionary Matching with CrypTool 2

Let's experience Approach 1 using CrypTool 2.

CrypTool 2 includes a template called "Caesar Brute-Force Analysis," which allows you to experience decrypting Caesar ciphers. This template performs a brute-force attack and then applies dictionary matching to identify the correct plaintext.

If the decrypted result contains even one word found in the dictionary, that plaintext is output. If it does not contain any dictionary words, it is discarded. This dictionary check is performed on all decryption results.

Since the tool does not include a function to automatically narrow down the optimal solution, multiple valid plaintext candidates may be output. Human judgment is required to select the final correct plaintext from the candidates.

Now, let's actually try this process in CrypTool 2. This will deepen your practical understanding of Caesar cipher decryption.

//noindent
@<b>{Step 1}: Launch CrypTool 2. Look for the "Templates" section in the center of the main screen. Navigate to "Cryptanalysis" > "Classical" > "Caesar Brute-Force Analysis" and double-click it. Refer to @<img>{bruteforce_analysis}.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[bruteforce_analysis][Select the "Caesar Brute-Force Analysis" template][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/bruteforce_analysis.png" alt="Select the &quot;Caesar Brute-Force Analysis&quot; template" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Select the "Caesar Brute-Force Analysis" template</figcaption>
#@# </figure>
#@# //}

//noindent
@<b>{Step 2}: A project for performing a brute-force attack on a Caesar cipher will open in the workspace. See @<img>{cryptool_brute1}.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[cryptool_brute1][Project for performing a brute-force attack on a Caesar cipher][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/cryptool_brute1.png" alt="Project for performing a brute-force attack on a Caesar cipher" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Project for performing a brute-force attack on a Caesar cipher</figcaption>
#@# </figure>
#@# //}

We will explain each component and the process flow later. For now, let's simply try running the project.

In the upper-left corner, you'll find the Ciphertext component, which already contains a sample encrypted message. We'll proceed using this ciphertext.

//noindent
@<b>{Step 3}: Check the behavior of the Caesar component. Double-click the Caesar component and click the gear icon to open its settings. If the Action is set to Encrypt, change it to Decrypt@<fn>{bruteforce_bug}.

Note that component settings can only be modified when the project is in the Stop state.

//footnote[bruteforce_bug][Although you can still obtain the plaintext message even if it remains set to Encrypt, the key will be incorrect. The decryption algorithm for Caesar cipher can technically be replaced with the encryption algorithm, so decryption will still succeed. However, since the key used is for encryption, you must subtract it from 26 to get the correct decryption key.]

Refer to @<img>{Encrypt2Decrypt}.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[Encrypt2Decrypt][Change Action to Decrypt][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/Encrypt2Decrypt.png" alt="Change Action to Decrypt" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Change Action to Decrypt</figcaption>
#@# </figure>
#@# //}

After finishing the settings, click the minimize icon in the upper-right corner of the window (the icon to the left of the ×). This will return you to the workspace.

//noindent
@<b>{Step 4}: Now let's decrypt the sample ciphertext.

After returning to the workspace, press the [Play] button to start the decryption process. Plaintext candidates will begin to appear in the "All possible plaintexts" component in the upper right. Once the decryption reaches a certain point, the process will pause, and the final decrypted result will be displayed in the "Decrypted Ciphertext" component in the lower right.

Just above that, the "Found shift key" component displays the key (shift value) used for decryption. See @<img>{cryptool_brute2}.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[cryptool_brute2][Brute-force attacking the sample ciphertext][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/cryptool_brute2b.png" alt="Brute-force attacking the sample ciphertext" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Brute-force attacking the sample ciphertext</figcaption>
#@# </figure>
#@# //}

The ciphertext message (653 characters) used for decryption is as follows:

//quote{
Dxbg tgwxkxl Dtibmxe wxk Dkrimhehzbx-Zxlvabvamx oxkebxy lh wktftmblva ngw yhezxgkxbva pbx wtl wxk exzxgwtxkxg wxnmlvaxg Oxklvaenxllxengzlftlvabgx Xgbzft. Wbx 1918 xkyngwxgx Ftlvabgx xkexumx bf Spxbmxg Pxemdkbxz bakx Uenxmxsxbm ngw uxxbgyenllmx wtuxb wbx Pxemzxlvabvamx bg xbgxk Yhkf, wbx Ablmhkbdxk xklm Ctak sxagmx litxmxk bg bakxk Mktzpxbmx kbvambz xbglvatxmsxg dhggmxg. Wxk 2001 xklvabxgxgx Dbghybef Xgbzft fbm Dtmx Pbglexm bg wxk Atnimkheex blm gnk xbgxk ohg obxexg Uxexzxg ynxk wbx ngzxaxnkx Ytlsbgtmbhg, wbx wbxlx Ftlvabgx ubl axnmx tnlnxum. Lh blm wbx Xgbzft gtva pbx ohk wtl uxdtggmxlmx ngw tf uxlmxg xkyhklvamx Oxklvaenxllxengzlzxktxm wxk Pxem.
//}

The plaintext message obtained after running the project is as follows:

//quote{
Kein anderes Kapitel der Kryptologie-Geschichte verlief so dramatisch und folgenreich wie das der legendaeren deutschen Verschluesselungsmaschine Enigma. Die 1918 erfundene Maschine erlebte im Zweiten Weltkrieg ihre Bluetezeit und beeinflusste dabei die Weltgeschichte in einer Form, die Historiker erst Jahr zehnte spaeter in ihrer Tragweite richtig einschaetzen konnten. Der 2001 erschienene Kinofilm Enigma mit Kate Winslet in der Hauptrolle ist nur einer von vielen Belegen fuer die ungeheure Faszination, die diese Maschine bis heute ausuebt. So ist die Enigma nach wie vor das bekannteste und am besten erforschte Verschluesselungsgeraet der Welt.
//}

It is immediately obvious that the decrypted text is not in English.

The Dictionary component in the upper center of the CrypTool 2 workspace was set to "German" when the template was opened, suggesting that the original plaintext is in German.

When we entered the decrypted message into the DeepL translation tool, it was automatically detected as German. The translation result was about the Enigma machine. See @<img>{deepl_german}.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[deepl_german][Result after translating with DeepL][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/deepl_german.png" alt="Result after translating with DeepL" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Result after translating with DeepL</figcaption>
#@# </figure>
#@# //}

This concludes the explanation of how to use the "Caesar Brute-Force Analysis" template.

To end use of this template, press the [Stop] button to reset the system. This will clear the current session's settings and data.

Since we will continue with further explanations, please stop the project but do not close it.

//noindent
@<b>{Step 5}: While not a direct method of decryption, checking the index of coincidence can also be useful.

For example, if you calculate the index of coincidence using @<href>{https://www.dcode.fr/index-coincidence}, you can confirm that the index of coincidence of the ciphertext is 8.2%. See @<img>{ic2}.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[ic2][Calculate the index of coincidence of the ciphertext][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/ic2.png" alt="暗Calculate the index of coincidence of the ciphertext" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Calculate the index of coincidence of the ciphertext</figcaption>
#@# </figure>
#@# //}

When you then calculate the index of coincidence of the decrypted result, it also comes out to 8.2%.

The index of coincidence of the ciphertext matches that of the decrypted result.

Since this was a Caesar cipher ciphertext, this is a natural outcome. This is because "the Caesar cipher is a type of monoalphabetic substitution cipher" and "the index of coincidence of a monoalphabetic substitution cipher's ciphertext equals that of the plaintext."

The index of coincidence for English is 5.7%, and for German it is 7.3%.

The calculated value of 8.2% is therefore closer to German than to English.

//noindent
@<b>{Step 6}: From here on, we will explain the processing of each part of this project. See @<img>{cryptool_brute3}.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[cryptool_brute3][Roles of each part][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/cryptool_brute3.png" alt="Roles of each part" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Roles of each part</figcaption>
#@# </figure>
#@# //}

If the transformed message obtained during the decryption process contains real words, it will be output as the correct plaintext message.

Based on this condition, only one message met the criteria this time, so only that one was output as the decryption result.

Let's look at the left section of the project.

The main role of this part is to increment numbers from 1 to 26 and output their values. See @<img>{kakubu1}.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[kakubu1][Outputting numbers while incrementing][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/kakubu1.png" alt="Outputting numbers while incrementing" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Outputting numbers while incrementing</figcaption>
#@# </figure>
#@# //}

It is composed of the following components. Although it may look complicated, you can think of it as a for loop commonly used in programming.

 * Number Input component
 ** Initial value of 1 and maximum value of 26 are provided.
 * Inc Dec component
 ** Since Mode is set to Increment and Inc/Dec value is 1, it increments by 1.
 * Comparators component
 ** Performs comparisons.
 ** In this case, it uses the "<=" comparison operator.
 * Gate component
 ** Passes data when the specified Trigger is met.
 ** The Trigger is set to true value.

Now focus on the center section.

The role of this section is to determine whether the decryption result contains any words. If it does, the message is output from the PlaintextGate. See @<img>{kakubu2}.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[kakubu2][Determining whether the decrypted result contains words][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/kakubu2.png" alt="Determining whether the decrypted result contains words" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Determining whether the decrypted result contains words</figcaption>
#@# </figure>
#@# //}

It is composed of the following components:

 * Dictionary component
 ** A German dictionary (containing over 300,000 words) is specified.
 * Contains component
 ** Search Type is set to Hashtable, with "Count each word only once" checked.
 * Gate component
 ** Passes data when the specified Trigger is met.
 ** The Trigger is set to true value.

Finally, look at the right section.

The role of this part is to convert the decryption result key (numeric value) to a string for display. This is simply a process to display it in the "Found shift key" Text Output component. See @<img>{kakubu3}.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[kakubu3][Converting numbers to strings][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/kakubu3.png" alt="Converting numbers to strings" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Converting numbers to strings</figcaption>
#@# </figure>
#@# //}

It is composed of the following components:

 * Gate component
 ** Passes data when the specified Trigger is met.
 ** The Trigger is set to true value.
 * Converter component
 ** "Converting to" is set to string.
 ** For Digits for UInt[], "Define Digits as" is set to "String of Digits", Digits is set to "0123456789ABCDEF", and Endianness is set to "Big Endian".
 * Text Output component
 ** Named "Found shift key".
 ** Displays the identified key.

Refer to @<img>{converter_component} for the Converter component settings.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[converter_component][Converter component settings][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/converter_component.png" alt="Converter component settings" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Converter component settings</figcaption>
#@# </figure>
#@# //}

This concludes the explanation of the "Caesar Brute-Force Analysis" template.

When closing the workspace tab or exiting CrypTool, if there are changes to the project, a dialog will appear asking whether to overwrite the "Caesar_ExhaustiveKeySearch.cwm" file. If you do not want to save the changes, click the [No] button.

If you want to decrypt an English ciphertext, enter the ciphertext into the Ciphertext component and change the language setting of the Dictionary component to "English". This allows you to determine the plaintext based on whether it contains English words.
