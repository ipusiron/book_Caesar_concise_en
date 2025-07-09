= The Basics of the Caesar Cipher

In this chapter, we will provide a detailed explanation of the Caesar cipher, which is the central theme of this book.

If we were to explain the Caesar cipher in a straightforward manner, it might simply come across as "a cipher with a simple mechanism."

However, having read this far, you will find this chapter especially valuable.

With an understanding of the essence of classical ciphers, you will be able to recognize the Caesar cipher's deeper significance.

== What Is the Caesar Cipher?

The Caesar cipher is an encryption method that converts plaintext into ciphertext by shifting each letter three positions forward in alphabetical order.

This cipher is named after Gaius Julius Caesar—known simply as "Caesar" in English—the Roman military leader who famously employed it during the Gallic Wars to communicate with his allies while avoiding enemy interception.

The substitution table for the Caesar cipher works as follows:

#@# 1ページ内に収まらないので画像化した.
#@# //table[rot3_tikanhyou][シーザー暗号の置換表]{
#@# a	b	c	d	e	f	g	h	i	j	k	l	m	n	o	p	q	r	s	t	u	v	w	x	y	z
#@# -------------------------------------------------------------
#@# D	E	F	G	H	I	J	K	L	M	N	O	P	Q	R	S	T	U	V	W	X	Y	Z	A	B	C
#@# //}

//embed[latex]{
\floatplacement{figure}{t}
//}
//image[rot3_tikanhyou][Substitution Table for the Caesar Cipher][scale=1.0]{
//}
//embed[latex]{
\floatplacement{figure}{H}
//}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/rot3_tikanhyou.png" alt="Substitution Table for the Caesar Cipher" style="max-width: 90%; height: auto;" />
#@#   <figcaption>図：Substitution Table for the Caesar Cipher</figcaption>
#@# </figure>
#@# //}

Each letter in the plaintext is shifted three positions forward to generate the ciphertext. When this shift extends beyond 'Z', it wraps around to the beginning of the alphabet.

As an example, let's look at the process of encrypting the plaintext "hello" using the Caesar cipher.
We encrypt each letter in order:

//embed[latex]{
\floatplacement{figure}{t}
//}
//image[caesar_enc_hello][Encrypting "hello"][scale=0.8]{
//}
//embed[latex]{
\floatplacement{figure}{H}
//}

#@# //embed[html]{
#@# <figure style="text-align: center;">
#@#   <img src="images/caesar_enc_hello.png" alt="Encrypting &quot;hello&quot;" style="max-width: 90%; height: auto;" />
#@#   <figcaption>図：Encrypting "hello"</figcaption>
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

== シフト暗号とは

シーザー暗号は通常3文字をずらしますが、必ずしも3文字に限定されるわけではありません。
たとえば、1文字や10文字をずらすバージョンも考えられます。

26文字ずらすと、実質的に文字をずらさないのと同じになります。
これは、26で割った余りが0になるためです。

このように任意の数の文字をずらす暗号をシフト暗号と呼び、ずらす量をシフトnとして定義します。
このシフト量nは鍵の役割を果たし、送受信者の間でのみ共有されます。

シフト暗号はその循環性から、しばしばROTと呼ばれます。
これは英語の"rotate"、つまり「回転させる」からきています。
n文字シフトした場合は、ROTnと表記します。

たとえば、1文字をシフトする暗号はROT1と表記され、その置換表は次のとおりです。

#@# 1ページ内に収まらないので画像化した.
#@# //table[rot1_tikanhyou][ROT1の置換表]{
#@# a	b	c	d	e	f	g	h	i	j	k	l	m	n	o	p	q	r	s	t	u	v	w	x	y	z
#@# -------------------------------------------------------------
#@# B	C	D	E	F	G	H	I	J	K	L	M	N	O	P	Q	R	S	T	U	V	W	X	Y	Z	A
#@# //}

#@# #@# //embed[latex]{
#@# #@# \floatplacement{figure}{t}
#@# #@# //}
#@# //image[rot1_tikanhyou][ROT1の置換表][scale=1.0]{
#@# //}
#@# #@# //embed[latex]{
#@# #@# \floatplacement{figure}{H}
#@# #@# //}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/rot1_tikanhyou.png" alt="ROT1の置換表" style="max-width: 90%; height: auto;" />
  <figcaption>図：ROT1の置換表</figcaption>
</figure>
//}

シーザー暗号はシフト3のシフト暗号と同一であり、これをROT3と表します。

シフト暗号はシーザー暗号と仕組み的に本質な違いがない、文献によっては両者を同義として扱っていることがあります。
文脈によって、その用途を識別すべきでしょう。

== シフト暗号のアルゴリズム

暗号化方式はアルゴリズムの観点で見ると、KenGen、Enc、Decの3つのアルゴリズムから成り立ちます。
ここで、KeyGenは鍵生成アルゴリズム、Encは暗号化アルゴリズム、Decは復号アルゴリズムを指します@<fn>{enc_alg}。

//footnote[enc_alg][KeyGen、Enc、Decの3つのアルゴリズムはシフト暗号に限定されず、現代暗号の暗号化もこの3つによって定義されます。]

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[shift_enc_alg][シフト暗号のアルゴリズム][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/shift_enc_alg.png" alt="シフト暗号のアルゴリズム" style="max-width: 90%; height: auto;" />
  <figcaption>図：シフト暗号のアルゴリズム</figcaption>
</figure>
//}

鍵生成アルゴリズムは鍵を生成し、暗号化アルゴリズムは平文を暗号文に変換します。
そして、復号アルゴリズムは暗号文を復号します。

ここでいう鍵とは、暗号化および復号アルゴリズムにおける変換処理を制御するデータです。
暗号化システムでは、鍵は非常に重要あり、通信の安全を保つために送受信者以外には秘密にされます。
鍵が漏れると、暗号文は誰にでも解読可能となり、平文が露見してしまいます。

=== 正当性を数式で表現する

正当性とは、復号後に暗号文が元の平文に正確に戻ることを指します。
暗号化はこの正当性を保証する必要があります。
もし正しい暗号文と鍵を使用しても元の平文に復元できない場合、その暗号はメッセージを伝達する基本的な目的を果たせていないことになります。

シフト暗号は3つのアルゴリズムによって定義されると述べました。
アルゴリズムを使って正当性を表現すると、任意のmとkeyに対して、次の式が成り立つことを意味します。

//noindent
m=Dec(key, Enc(key, m))

=== 置換表を用いる処理に変更する

先に示したアルゴリズムを置換表を用いる処理に変更すると、次のようになります。

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[shift_enc_alg2][シフト暗号のアルゴリズム＜置換表バージョン＞][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}
//embed[html]{
<figure style="text-align: center;">
  <img src="images/shift_enc_alg2.png" alt="シフト暗号のアルゴリズム＜置換表バージョン＞" style="max-width: 90%; height: auto;" />
  <figcaption>図：シフト暗号のアルゴリズム＜置換表バージョン＞</figcaption>
</figure>
//}

=== 各アルゴリズムの呼び出し方

アリスとボブが3つのアルゴリズムをどう扱うのかを図示すると、次のようになります。
準備段階でKeyGenアルゴリズム、主段階でEncアルゴリズムとDecアルゴリズムを呼び出します。

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[alice_bob_3alg_epub][アリスとボブによるアルゴリズムの呼び出し][scale=0.8]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}
//embed[html]{
<figure style="text-align: center;">
  <img src="images/alice_bob_3alg_epub.png" alt="アリスとボブによるアルゴリズムの呼び出し" style="max-width: 90%; height: auto;" />
  <figcaption>図：アリスとボブによるアルゴリズムの呼び出し</figcaption>
</figure>
//}

=== アルゴリズムの中身にいきなり注目しない

アルゴリズムの内部処理を直ちに理解しようとせず、まずはその入出力に注目することが重要です。
古典暗号や現代暗号を問わず、すべての暗号化で、各アルゴリズムの入出力は基本的に同じです。

 * KeyGenアルゴリズムは、鍵（ここではn）を出力する。
 * Encアルゴリズムは、平文mと鍵nを入力して、暗号文cを出力する。
 * Decアルゴリズムは、暗号文cと鍵n'を入力して、復号結果m'を出力する。
 ** 鍵が正しければ、m'はmそのもの。
 ** 正しく復号される性質を正当性という。

各アルゴリズムの入出力に登場する文字は、一部共通しています。
たとえば、nはKeyGenアルゴリズムの出力、そしてEncアルゴリズムの入力として登場しています。
m, n, c, n', m'により、各アルゴリズムが関連し合っているわけです。
もし入出力の文字が完全に独立していれば、アルゴリズム同士も無関係となります。

入出力とその関係を理解した上で、アルゴリズムの内部処理に注目するのがコツです。

新しい暗号化方式の解説を読む際は、以上のことを留意した上で読んでみてください。

== ROT13は2回暗号化すると元に戻る

ROT13は鍵n=13を使用するシフト暗号です。
暗号化では文字を右に13文字シフトし、復号では左に13文字シフトします。

ROT13の置換表は次のようになります。

#@# 1ページ内に収まらないので画像化した.
#@# //table[rot13_tikanhyou][ROT13の置換表]{
#@# a	b	c	d	e	f	g	h	i	j	k	l	m	n	o	p	q	r	s	t	u	v	w	x	y	z
#@# -------------------------------------------------------------
#@# N	O	P	Q	R	S	T	U	V	W	X	Y	Z	A	B	C	D	E	F	G	H	I	J	K	L	M
#@# //}

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[rot13_tikanhyou][ROT13の置換表][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}
//embed[html]{
<figure style="text-align: center;">
  <img src="images/rot13_tikanhyou.png" alt="ROT13の置換表" style="max-width: 90%; height: auto;" />
  <figcaption>図：ROT13の置換表</figcaption>
</figure>
//}

置換表の2行目は、1行目の前半「'a'から'm'まで」と後半「'n'から'z'まで」を入れ替えた状態になっています。
これはアルファベットが26文字であることに基づいています。

=== ROT13の置換表

上記の置換表から後半部分を取り除くと、次のような簡略化した表が得られます。
この表は文字の対応関係を示し、実際の置換に利用できます。

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[rot13_mapping][ROT13の文字対応][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/rot13_mapping_epub.png" alt="ROT13の文字対応" style="max-width: 90%; height: auto;" />
  <figcaption>図：ROT13の文字対応</figcaption>
</figure>
//}

置換表を見て気づくかもしれませんが、「左に13文字シフトすること」と「右に13文字シフトすること」は同じ結果をもたらします。
これにより、左に13文字シフトを2回繰り返すと、元の位置に戻ります。
これがROT13の最大の特徴です。

ROT13を2回適用すると各文字は元に戻ります。

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
#@# //image[rot13_and_rot13][ROT13を2回実行][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/rot13_and_rot13.png" alt="ROT13を2回実行" style="max-width: 90%; height: auto;" />
  <figcaption>図：ROT13を2回実行</figcaption>
</figure>
//}

=== ROT13の用途

ROT13は本格的な秘匿性を提供するものではなく、主に文字列を一時的に隠したり、読みにくくするために使用されます。

 * パズルの答えを一見してわからなくする。
 * 投稿時に他人を不快にさせる可能性がある内容を隠すため。
 * ジオキャッシング（geocaching）の場所に関するヒントを隠す。
 ** ジオキャッシングとは、GPSまたはGNSSを利用した地球規模の宝探しゲームのこと。
 ** @<href>{https://www.geocaching.com/play}

== シフト暗号は換字式暗号の一種

シフト暗号の鍵は、シフトする文字数を示します。
この数に基づき、平文と暗号文の対応表が定義されます。
この表は、全アルファベットがどのように変換されるかを示し、実質的に置換表そのものです。

したがって、シフト暗号は換字式暗号の一種になります。

=== シフト暗号の鍵あれこれ

以前「シフト暗号の鍵＝シフト数＝置換表」という関係性を説明しました@<fn>{tougou}。

//footnote[tougou][ここでの等号「＝」は数値的な一致ではなく、本質的に同じであることを示しています。]

実際、シフトする数は0から25までの26種類です。
これは、26文字をシフトすると元の位置に戻り、27文字をシフトすると1文字シフトしたのと同じ効果があるためです。

これにより、26文字のアルファベットを26種類のシフト数に対応させられます（@<table>{shift_keychar}）@<fn>{shift_keychar_mapping}。
鍵を1文字で表現するため、これを鍵文字と呼びます。

//footnote[shift_keychar_mapping][たとえば、シフト数1を'A'、2を'B'、…、26を'Z'とする方法も考えられます。ただし、シフト0の場合に平文と暗号文を同じにするためには、シフト0を'A'に割り当てるほうが自然といえます。]

//table[shift_keychar][シフト数と鍵文字の対応]{
シフト数	鍵文字
-------------------------------------------------------------
0	'A'
1	'B'
2	'C'
3	'D'
…	…
25	'Z'
//}

たとえば、ROT3は鍵文字'D'を用いるシフト暗号でした。
ROT3の置換表を見ると、暗号文の行が左端から'D'で始まっており、これは鍵文字'D'と一致します。

他のROTnについても同様の議論が可能です。
鍵文字がわかれば、暗号文の先頭文字を容易に決定でき、置換表をすぐに作成できます。

これらの点をまとめると、次の関係が明らかになります。

//centering{
シーザー暗号の鍵＝ずらす文字数＝シフト数＝置換表＝鍵文字
//}

== 英文をシフト暗号で暗号化する

英単語をシフト暗号で暗号化する場合、とくに問題は生じません。

しかし、英文を暗号化すると問題が生じます。
英文には、非アルファベット文字（アルファベット以外の文字）が含まれているからです。
ここでいう非アルファベット文字とは、空白、カンマ、ピリオド、感嘆符、疑問符などのことです。

シーザー暗号はアルファベットのみを扱うため、暗号化の際に平文から非アルファベット文字を除外します。
その結果、出力される暗号文には除外した文字が含まれません。
復号後は元の文へ正確に作業が必要になります。

== 手を動かしてシーザー暗号を体験する

それでは、実際にシーザー暗号を使って暗号化のプロセスを体験してみましょう。
今回は、鍵文字'D'を用いたシフト暗号と同等です。

==={enc_by_caesar} 暗号化してみよう

例として、エドガー・アラン・ポーの詩「眠れるひと」（"The Sleeper"）の冒頭から次に示す文@<fn>{sleeper}を引用します@<fn>{poestories}。

//footnote[sleeper][詩なのでさまざまな訳が考えられます。その一例として「6月のとある真夜中に、怪しげな月の下、私は立っていた」と訳せます。]
//footnote[poestories][ポーの作品については、PoeStories.com（@<href>{https://poestories.com/read/ovalportrait}）で公開されています。"The Sleeper"は@<href>{https://poestories.com/read/sleeper}で参照できます。]

//quote{
At midnight, in the month of June, I stand beneath the mystic moon.
//}

ここでは議論を簡単にするため、次の条件を設定します。

 * 空白や句読点を除外せず、アルファベット以外の文字もそのままにする。
 * 暗号文はすべて大文字で表記する。

それでは、暗号化の手順を説明します。

//noindent
1：まず、平文をすべて小文字に変換します。
変換の結果、"at midnight, in the month of june, i stand beneath the mystic moon."となります。

//noindent
2：次に、鍵文字'D'の置換表を用いて暗号化します。
この際、置換表の1行目にある平文文字を基に変換を進めます。
最終的に、"DW PLGQLJKW, LQ WKH PRQWK RI MXQH, L VWDQG EHQHDWK WKH PBVWLF PRRQ."という暗号文メッセージが得られます。

=== 復号してみよう

次に、復号の手順を説明します。

//noindent
1：鍵文字'D'に基づく置換表を用いて、復号します。
復号なので、表の2行目にある暗号文文字を基に変換を進めます。
結果として、"at midnight, in the month of june, i stand beneath the mystic moon."という平文メッセージが得られます。

//noindent
2：このメッセージが意味を成していることを確認した上で、適宜、正しい英文に修正します。
具体的には、メッセージがすべて小文字であるため、文頭や'I'、および国・月などの固有名詞の頭文字を大文字に修正します。
最終的には"At midnight, in the month of June, I stand beneath the mystic moon."となりました。
これは元の平文と同じです。

==[column] シフト暗号と数学

シフト暗号の動作を数学的に表現する方法を説明します。
まず、次のように各アルファベット文字に0から25までの数字を割り当てます。

//noindent
A=0, B=1, ..., Z=25

平文文字をT、鍵文字をK、暗号文文字をCとします。
すると、次の関係式でシフト暗号の処理を表現できます。

//noindent
T + K ≡ C (mod 26)

暗号化の場合は、Cが未知、TとKは既知です。
3つの変数のうち1つだけが未知なので、合同方程式を解くことでCを求められます。

また、復号の場合は、Tが未知、CとKが既知です。
同様にして、Tが求められます。

ところで、換字式暗号（シフト暗号を含む）はアルファベットを置き換える操作なので、置換表をアルファベットの集合からアルファベットの集合への写像でとらえられます。

以上のように古典暗号の仕組みを数学的にとらえると見通しがよくなり、本質が浮かび上がってきます。
場合によっては、プログラムの実装に応用できます。

==[/column]
