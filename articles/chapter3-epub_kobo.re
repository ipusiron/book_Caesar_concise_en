= Using Computers to Explore Shift Ciphers

We've explained how shift ciphers work and practiced manual encryption and decryption. Before advancing to breaking Caesar and shift ciphers, let's gain more hands-on experience.

In this chapter, we'll use computers to explore shift ciphers through commands, programs, and tools.

== Using the @<code>{tr} Command for Shift Ciphers

You can implement shift ciphers easily by piping @<code>{echo} and @<code>{tr} commands.

The @<code>{echo} command outputs text to standard output, while @<code>{tr} (translate) command transforms characters from standard input and sends the result to standard output. By combining these commands with a pipe (|), we can create functional shift ciphers in a single line.

=== Testing Caesar Cipher with @<code>{tr} Command

Using lowercase for plaintext and uppercase for ciphertext, we can encrypt "hello world" as follows:

//cmd{
ipusiron@parrot:~$ echo "hello world" | tr a-z D-ZA-C
KHOOR ZRUOG  # Encrypted result
//}

To decrypt the ciphertext:

//cmd{
ipusiron@parrot:~$ echo "KHOOR ZRUOG" | tr D-ZA-C a-z
hello world  # Decrypted result
//}

The output confirms perfect recovery of the original plaintext "hello world".

In classical cryptography, plaintext is conventionally written in lowercase and ciphertext in uppercase. 
The above @<code>{tr} command follows this convention.

To handle both cases, use:

//cmd{
ipusiron@parrot:~$ echo "hello world" | tr 'a-zA-Z' 'd-za-cD-ZA-C'
KHOOR ZRUOG  # Encrypted result
ipusiron@parrot:~$ echo "KHOOR ZRUOG" | tr 'd-za-cD-ZA-C' 'a-zA-Z'
hello world  # Decrypted result
//}

=== Testing ROT13

We can implement ROT13 using the same command structure. Let's verify ROT13's self-inverse property using "i love you." as our plaintext.

//noindent
@<b>{Step 1}: Standard encryption and decryption.

//cmd{
ipusiron@parrot:~$ echo "i love you." | tr a-z N-ZA-M
V YBIR LBH.  # Encrypted text
ipusiron@parrot:~$ echo "V YBIR LBH." | tr N-ZA-M a-z
i love you.  # Decrypted text
//}

//noindent
@<b>{Step 2}: Apply the same ROT13 command twice. To clearly show we're using identical commands, we'll use the case-inclusive @<code>{tr} pattern.

However, to make it clear that the same command is being used, we will use a version of the @<code>{tr} command that supports both lowercase and uppercase letters in its arguments.

//cmd{
ipusiron@parrot:~$ echo "i love you." | tr 'a-zA-Z' 'n-za-mN-ZA-M'
V YBIR LBH.  # First ROT13
ipusiron@parrot:~$ echo "V YBIR LBH." | tr 'a-zA-Z' 'n-za-mN-ZA-M'
i love you.  # Second ROT13 returns to original
//}

Note: In Step 2, we apply the same transformation twice. Since ROT13 shifts by exactly half the alphabet (13 positions), it acts as its own inverse.

== Testing ROT13 with the @<code>{nkf} Command

The @<code>{nkf} command is a filter tool used primarily on UNIX systems to convert text encoding and newline formats.

e.g., It was originally developed for handling Japanese encodings such as Shift_JIS and EUC-JP.

//noindent
@<b>{Step 1}: Prepare a file named @<code>{plain.txt} containing the plaintext. Here, we assume the plaintext consists of lowercase letters.

//cmd{
ipusiron@parrot:~$ cat plain.txt
i love you.
//}

//noindent
@<b>{Step 2}: By adding the @<code>{-r} option to the @<code>{nkf} command, you can perform ROT13 encryption.

//cmd{
ipusiron@parrot:~$ nkf -r plain.txt
v ybir lbh.
//}

The output is the same as the result of ROT13 encryption using the @<code>{tr} command. However, since the text is still in lowercase, let's pass it to the @<code>{tr} command to convert it to uppercase.

//cmd{
ipusiron@parrot:~$ nkf -r plain.txt | tr '[:lower:]' '[:upper:]'
V YBIR LBH.
//}

Now we have obtained the ciphertext.

For the next step where we'll try decryption, let's save the ciphertext message to a file called @<code>{cipher.txt}.

//cmd{
ipusiron@parrot:~$ nkf -r plain.txt | tr '[:lower:]' '[:upper:]' > cipher.txt
//}

//noindent
@<b>{Step 3}: Since ROT13 returns to the original text when applied twice, decryption is simply another encryption. We'll use the @<code>{-r} option of the @<code>{nkf} command once more.

//cmd{
ipusiron@parrot:~$ nkf -r cipher.txt
I LOVE YOU.
ipusiron@parrot:~$ nkf -r cipher.txt | tr '[:upper:]' '[:lower:]'
i love you.
//}

We have successfully confirmed that the original plaintext message has been restored.

== Testing ROT13 with One-Liner Commands

One-liner commands execute complete operations in a single line. Python's @<code>{codecs} module includes built-in ROT13 support through its encoding functions.

We'll use @<code>{codecs.encode()} for encryption and @<code>{codecs.decode()} for decryption, with "i love you." as our test string.

//noindent
@<b>{Step 1}: Encrypt using ROT13:
//cmd{
ipusiron@parrot:~$ python3 -c "import codecs; print(codecs.encode(\"i love you.\", \"rot-13\"))"
v ybir lbh.  # Encrypted text
//}

//noindent
@<b>{Step 2}: Decrypt using ROT13:
Here we use @<code>{decode()} to show that Python treats ROT13 as a reversible encoding.
//cmd{
ipusiron@parrot:~$ python3 -c "import codecs; print(codecs.decode(\"v ybir lbh.\", \"rot-13\"))"
i love you.  # Decrypted text
//}

#@# == Testing Caesar Cipher in Your Browser

#@# I've created an interactive Caesar Cipher Wheel Tool for experimenting with shift ciphers:

#@#  * GitHub repository
#@#  ** @<href>{https://github.com/ipusiron/caesar-cipher-wheel}
#@#  * Live demo
#@#  ** @<href>{https://ipusiron.github.io/caesar-cipher-wheel/}

#@# Set Shift to 1 for ROT1, or 3 for ROT3 (traditional Caesar cipher).
#@# @<img>{caesar_wheel_tool} demonstrates the tool's interface.

#@# #@# //embed[latex]{
#@# #@# \floatplacement{figure}{t}
#@# #@# //}
#@# //image[caesar_wheel_tool][Caesar cipher with shift of 3][scale=1.0]{
#@# //}
#@# #@# //embed[latex]{
#@# #@# \floatplacement{figure}{H}
#@# #@# //}

#@# #@# //embed[html]{
#@# #@# <figure style="text-align: center;">
#@# #@#   <img src="images/caesar_wheel_tool.png" alt="Caesar cipher with shift of 3" style="max-width: 90%; height: auto;" />
#@# #@#   <figcaption>Figure: Caesar cipher with shift of 3</figcaption>
#@# #@# </figure>
#@# #@# //}

=={caesar_python} Testing Caesar Cipher with Python

Caesar and shift ciphers are fundamental encryption methods with implementations readily available online.

This section uses code adapted from @<i>{Cracking Codes with Python} by Al Sweigart (Japanese translation: 『Pythonでいかにして暗号を破るか』, Socym). The book covers shift ciphers across two chapters:

 * Chapter 5: Encryption and decryption implementation
 * Chapter 6: Brute-force attack techniques

Our implementation is a modified version of the book's code (BSD licensed) that gracefully handles non-alphabetic characters.

 * Usage:
 ** @<code>{message}: string to encrypt/decrypt
 ** @<code>{key}: shift value (0-25)
 ** @<code>{mode}: @<code>{"encrypt"} or @<code>{"decrypt"}

//listnum[caesarCipher][caesarCipher.py][python]{
# https://www.nostarch.com/crackingcodes (BSD Licensed)
# The string to be encrypted/decrypted:
message = 'This is my secret message.'

# The encryption/decryption key:
key = 13

# Whether the program encrypts or decrypts:
mode = 'encrypt' # Set to either 'encrypt' or 'decrypt'.

# Every possible symbol that can be encrypted:
SYMBOLS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' \
        'abcdefghijklmnopqrstuvwxyz' \
        '1234567890 !?.'

def caesar(message, key):
  # Stores the encrypted/decrypted form of the message:
  translated = ""
  for symbol in message:
    # Note: Only symbols in the `SYMBOLS` string can be encrypted/decrypted.
    if symbol in SYMBOLS:
      symbolIndex = SYMBOLS.find(symbol)

      # Perform encryption/decryption:
      if mode == 'encrypt':
        translatedIndex = symbolIndex + key
      elif mode == 'decrypt':
        translatedIndex = symbolIndex - key

      # Handle wrap-around, if needed:
      if translatedIndex >= len(SYMBOLS):
        translatedIndex = translatedIndex - len(SYMBOLS)
      elif translatedIndex < 0:
        translatedIndex = translatedIndex + len(SYMBOLS)

      translated = translated + SYMBOLS[translatedIndex]
    else:
      # Append the symbol without encrypting/decrypting:
      translated = translated + symbol
  return translated

def main():
  # Output the translated string:
  print(caesar(message, key))

if __name__ == '__main__':
  main()
//}

Try running the program in your local Python environment or online:

 * paiza.IO (no registration)
#@#  ** @<href>{https://paiza.io/en/languages/python3}
 * Google Colab (Google account required)
#@#  ** @<href>{https://colab.research.google.com/}
 * CodeChef (no registration)
#@#  ** @<href>{https://www.codechef.com/ide}

When you execute @<list>{caesarCipher} as is, it outputs: @<code>{"guv6Jv6Jz!J6rp5r7Jzr66ntrM"}.

Notice that spaces, punctuation, and case are all preserved during encryption.

To decrypt, set @<code>{message} to the ciphertext and @<code>{mode} to @<code>{"decrypt"}. The output will be the original message: @<code>{"This is my secret message."}.

=== Extending ROT13 to Match the Character Set

In the @<list>{caesarCipher} program, the key was set to 13. Try verifying whether encrypting twice returns the original text, as with ROT13.

//noindent
"This is my secret message."@<br>{}
-> "guv6Jv6Jz!J6rp5r7Jzr66ntrM" (first encryption)@<br>{}
-> "t89EW9EW?KWE53D5FW?5EE175Z" (second encryption)

In this experiment, applying encryption twice did @<b>{not} return the original text.

The reason is that the key doesn't match the character set size. Traditional ROT13 uses a 26-letter alphabet, with a key of 13 (half of 26) ensuring that double encryption restores the original message.

However, @<list>{caesarCipher} recognizes 66 characters:

 * 26 uppercase letters
 * 26 lowercase letters  
 * 10 digits
 * 4 symbols

Therefore, we need a key of 33 (half of 66) for the self-inverse property.

Try this yourself:

//noindent
"This is my secret message."@<br>{}
-> "1ABLdBLdFRdL!0K!MdF!LL8.!g" (first encryption)@<br>{}
-> "This is my secret message." (second encryption)

#@# == Testing the ROT13 Encoder

#@# I've created an interactive ROT13 Encoder web tool:

#@#  * GitHub repository
#@#  ** @<href>{https://github.com/ipusiron/rot13-encoder}
#@#  * Live demo
#@#  ** @<href>{https://ipusiron.github.io/rot13-encoder/}

#@# @<img>{rot13_encorder} shows the algorithm execution sequence.

#@# #@# //embed[latex]{
#@# #@# \floatplacement{figure}{t}
#@# #@# //}
#@# //image[rot13_encorder][Testing the ROT13 Encoder][scale=1.0]{
#@# //}
#@# #@# //embed[latex]{
#@# #@# \floatplacement{figure}{H}
#@# #@# //}

#@# #@# //embed[html]{
#@# #@# <figure style="text-align: center;">
#@# #@#   <img src="images/rot13_encorder.png" alt="Testing the ROT13 Encoder" style="max-width: 90%; height: auto;" />
#@# #@#   <figcaption>Figure: Testing the ROT13 Encoder</figcaption>
#@# #@# </figure>
#@# #@# //}

== Working with Shift Ciphers Using CrypTool 2

CrypTool 2 is a comprehensive GUI-based tool that supports various cryptographic algorithms. Its intuitive interface makes cryptographic operations accessible without programming knowledge. With CrypTool 2, you can focus on encryption, decryption, and cryptanalysis rather than implementation details.

The CrypTool Portal offers four cryptographic learning platforms:

 * CrypTool-Online (CTO)
 ** Browser-based platform
 ** Individual tools for various ciphers
 ** Ideal for quick experiments
 * CrypTool 1 (CT1)
 ** Original version from 1998
 ** Windows only
 ** Started as corporate security training software, now open source
 * CrypTool 2 (CT2)
 ** Modern Windows GUI version
 ** Visual workflow designer for cryptographic operations
 ** Extensive plugin architecture
 * JCrypTool (JCT)
 ** Java-based, cross-platform (Windows, macOS, Linux)
 ** Different UI approach from CrypTool 2
 ** Version 1.0.0 released November 2020
 ** Over 100 plugins available

For this book's demonstrations, we'll use CrypTool 2.1 on Windows.

@<img>{CrypTool} shows the CrypTool 2.1 interface upon startup.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[CrypTool][CrypTool 2.1 startup screen][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/CrypTool.png" alt="CCrypTool 2.1 startup screen" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: CrypTool 2.1 startup screen</figcaption>
#@# </figure>
#@# //}

=== Using the Shift Cipher Wizard

CrypTool 2 includes a wizard for experimenting with shift ciphers. This section explains how to launch and use it.

Note: CrypTool 2 uses "Caesar Cipher" and "Shift Cipher" interchangeably.

//noindent
@<b>{Step 1}: Click the [New] icon on the CrypTool 2 home screen, or click the dropdown arrow next to it and select "Wizard".

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[crypt_enc0][Launching the wizard from the home screen][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/crypt_enc0.png" alt="Launching the wizard from the home screen" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Launching the wizard from the home screen</figcaption>
#@# </figure>
#@# //}

//noindent
@<b>{Step 2}: The Wizard tab opens. In the "TASK SELECTION" screen, select "Encryption/Decryption" and click [Next]. Refer to @<img>{crypt_enc1}.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[crypt_enc1]["TASK SELECTION" screen][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/crypt_enc1.png" alt="&quot;TASK SELECTION&quot; screen" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: &quot;TASK SELECTION&quot; screen</figcaption>
#@# </figure>
#@# //}

//noindent
@<b>{Step 3}: In the "AGE SELECTION" screen, select "Classic Encryption/Decryption" and click [Next].

//noindent
@<b>{Step 4}: In the "ALGORITHM SELECTION" screen, select "Caesar" and click [Next].

//noindent
@<b>{Step 5}: The "MESSAGE INPUT" screen appears. Select "Encrypt" to encrypt or "Decrypt" to decrypt. Since we're encrypting, select "Encrypt".

Enter your message in the text box. Here, we use the text from the previous chapter:

//noindent
"At midnight, in the month of June, I stand beneath the mystic moon."

Enter the shift value in the Key field on the right. We'll keep the default value of 3.

Once all settings are complete, click [Next]. Refer to @<img>{crypt_enc2}.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[crypt_enc2]["MESSAGE INPUT" screen][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/crypt_enc2.png" alt="&quot;MESSAGE INPUT&quot; screen" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: &quot;MESSAGE INPUT&quot; screen</figcaption>
#@# </figure>
#@# //}

//noindent
@<b>{Step 6}: The CAESAR OUTPUT screen displays the original message and its encrypted form. The resulting ciphertext is:

//noindent
@<code>{"dw plgqljkw, lq wkh prqwk ri mxqh, l vwdqg ehqhdwk wkh pbvwlf prrq."}

@<img>{crypt_enc2} shows the "CAESAR OUTPUT" screen.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[crypt_enc3]["CAESAR OUTPUT" screen][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/crypt_enc3.png" alt="&quot;CAESAR OUTPUT&quot; screen" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: &quot;CAESAR OUTPUT&quot; screen</figcaption>
#@# </figure>
#@# //}

To encrypt another message, click [Back] to return to MESSAGE INPUT. To exit, click [Abort]. 

When finished, close the wizard tab.

=== Creating a Shift Cipher Project

Let's create a workspace project for shift cipher encryption. Since the decryption project uses essentially the same structure, we'll focus on encryption here. For decryption details, see @<hd>{chapter4-epub_kobo|cryptool_caesar_by_frequency}.

@<img>{cryptool_caesar1} shows the completed shift cipher project looks.

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
//image[cryptool_caesar1][Shift cipher encryption project][scale=1.0]{
//}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/cryptool_caesar1.png" alt="Shift cipher encryption project" style="max-width: 90%; height: auto;" />
#@#   <figcaption>Figure: Shift cipher encryption project</figcaption>
#@# </figure>
#@# //}

The Caesar component, located in the center, plays the central role in the project. Although named "Caesar," it handles shift cipher processing.

When building your own project, first place the Caesar component on the workspace. Find the Caesar component under "Classic Ciphers" in the left component list and drag it to the workspace. Then connect various components to the inputs and outputs to complete the project.

The Caesar component accepts these connectors:

 * Input
 ** @<b>{Text input}: Plaintext
 ** @<b>{External alphabet input}: String containing the alphabet to use. If unconnected, uses internal alphabet
 ** @<b>{Shift value}: Shift number (key) as integer
 * Output
 ** @<b>{Text output}: Ciphertext

Connect the Text Input, Text Output, and Number Input components, found under Tools > Data input/output.

Caesar component settings:

 * Action: Select "Encrypt" or "Decrypt"
 * Alphabet: Specifies alphabet when External alphabet input is unconnected
 * Alphabet parameters: Configure non-alphabetic character handling
 ** Unknown symbol handling: "Ignore" (output as-is), "Remove" (delete), or "Replace with '?'"
 ** Case sensitive: Check to distinguish uppercase/lowercase
 ** Output contains source case: Check to preserve original casing

After placing components and making connections, click the Play icon in the Execute toolbar section to start. Results appear in the Text Output component.

Click Stop to halt the process.

Encrypting "at midnight, in the month of june, i stand beneath the mystic moon." with key 3 produces:

//noindent
"dw plgqljkw, lq wkh prqwk ri mxqh, l vwdqg ehqhdwk wkh pbvwlf prrq."

This matches the wizard output, confirming proper implementation.
