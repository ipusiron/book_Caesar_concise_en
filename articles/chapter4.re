= シーザー暗号とシフト暗号を解読する

本章では、シフト暗号の暗号文をどのように解読するかを詳しく解説します。
ここで、本書のタイトルが示す主題を具体的に取り上げます。

序盤では、解読プロセスを深く理解するため、あえて手動で解読します。
その後、より効率的かつ効果的な解読を目指し、コンピューターを用いた解読法について説明します。

== 総当たり攻撃による暗号解読

シフト暗号は鍵数が少ないため、総当たり攻撃が有効です。

==={brute_force_by_manual} 手動での総当たり攻撃を体験する

シフト暗号の暗号文"KZDVWCZVJCZBURERIIFN"を解読してみます@<fn>{bruteforce_example}。

//footnote[bruteforce_example][この解読例は、拙著『暗号技術のすべて』P.37で紹介したものを若干アレンジしたものです。]

//noindent
1：暗号文の特徴を把握します。
提供された暗号文は、連続した文字列で構成されています。
通常の単語の長さを超えるため、空白などの単語区切りが省略されていると考えられます。

//noindent
2：総当たり攻撃による復号を試みます。
シフト暗号の性質上、シフト数0から25までのすべてを試し、それぞれのシフト数で暗号文を復号します。
シフト数がnの場合、n分だけ左シフト（または26－n分の右シフト）して復号を試みます。
復号結果の一覧は@<table>{bruteforce_of_keys}のとおりです。

//table[bruteforce_of_keys][全シフト数で復号した結果]{
シフト数n	鍵文字	復号結果
-------------------------------------------------------------
0	'A'	kzdvwczvjczbvreriifn
1	'B'	jycuvbyuibyauqdqhhem
2	'C'	ixbtuaxthaxztpcpggdl
3	'D'	hwastzwsgzwysoboffck
4	'E'	gvzrsyvrfyvxrnaneebj
5	'F'	fuyqrxuqexuwqmzmddai
6	'G'	etxpqwtpdwtvplylcczh
7	'H'	dswopvsocvsuokxkbbyg
8	'I'	crvnournburtnjwjaaxf
9	'J'	bqumntqmatqsmivizzwe
10	'K'	aptlmsplzsprlhuhyyvd
11	'L'	zosklrokyroqkgtgxxuc
12	'M'	ynrjkqnjxqnpjfsfwwtb
13	'N'	xmqijpmiwpmoierevvsa
14	'O'	wlphiolhvolnhdqduurz
15	'P'	vkoghnkgunkmgcpcttqy
16	'Q'	ujnfgmjftmjlfbobsspx
17	'R'	timeflieslikeanarrow
18	'S'	shldekhdrkhjdzmzqqnv
19	'T'	rgkcdjgcqjgicylyppmu
20	'U'	qfjbcifbpifhbxkxoolt
21	'V'	peiabheaohegawjwnnks
22	'W'	odhzagdzngdfzvivmmjr
23	'X'	ncgyzfcymfceyuhulliq
24	'Y'	mbfxyebxlebdxtgtkkhp
25	'Z'	laewxdawkdacwsfsjjgo
//}

表の復号結果から、英単語が含まれている文を探します。

手動で正しい平文を特定するには、次の3つのアプローチが有効です。

 * アプローチ①：頻出単語の識別
 ** よく使用される単語（例："the"、"and"、"that"）を探す。
 ** これらの単語が見つかる場合、正しいシフト値である可能性が高い。
 * アプローチ②：不自然な文字列の排除
 ** 子音が連続する、通常の英単語には存在しないような文字列（例："kzdv"）を含む復号結果を除外する。
 ** ただし、単語間の空白や記号が削除されている可能性があるため、この点を考慮する。
 *** 例："good bye"が"goodbye"となり、"dby"が現れるのは自然な現象である。
 * アプローチ③：まれな文字列の分析
 ** 使用頻度の低い文字（例："z"、"q"）が含まれているかを調べ、その前後を見て単語として成立しているかを検討する。

アプローチを適用した結果、シフト値n=17によって得られる文字列"timeflieslikeanarrow"が最終的な平文として特定しました。
この文字列に適切な空白を挿入し、文の先頭を大文字化し、文末にピリオドを加えます。
完成した"Time flies like an arrow."は「光陰矢のごとし」という意味の英文です。
これが正しい平文であり、使用された鍵のシフト値はn＝17であることを特定できました。

== 頻度分析による暗号解読

頻度分析とは、暗号文に出現する文字頻度（文字の頻度）を分析することで、平文を特定する解読手法です。

頻度分析は古典暗号を解読する際に強力な手段です。
当然ですが、シフト暗号の解読に対しても非常に効果があります。

=== 頻度分析は単一換字式暗号の解読に有効

単一換字式暗号では文字が置き換わるので、「平文に現れる文字の頻度」は「暗号文に現れる別の文字の頻度」に一致します。
つまり、平文と暗号文の全体を見ると、頻度の分布パターンが一致します。
この一致性を利用して、暗号文の文字と平文の文字の対応関係を見つけ出すことができます。

暗号文が長ければ長いほど、頻度分析による解読が成功する確率が高まります。
これは、より多くのテキストデータがあると、標準的な英文の頻度分布に収束しやすくなるためです。

ただし、自然な英文では頻度が収束しやすいですが、意図的に特定の文字を避けて書かれた文章@<fn>{gadsby}では、この収束が見られない可能性があります。
これは頻度分析の際に考慮すべき重要なこのの1つといえます。

//footnote[gadsby][たとえば、アーネスト・ヴィンセント・ライト著の『Gadsby』（ギャズビー）は、5万語を超える短編小説ですが、全編で'e'を含む単語が登場しません。]

文字と単語の頻度パターンについて、どの言語でも絶対的なものは存在しません。
時代によって新しい単語が登場したり、廃れたりするためです。
また、サンプル文によっても結果が変わります。
そのため、統計データを掲載する文献によって、微妙な違いがあります。

=== 英単語の頭文字に注目する

通常、古典暗号の平文は自然言語で書かれています。
自然言語の文章では、出現する文字に偏りが生じます。

ここでは英文について言及します。
手元に英語辞典があれば、閉じた状態で横から見てください。
前小口@<fn>{maekoguti}に検索用のインデックス（黒い帯）が印刷されているはずです。
その帯の幅が大きいほど、その頭文字を持つ英単語が多いことを意味します。
たとえば、's'や'c'から始まる英単語は一般的に多いです。
逆に'x'、'y'、'z'から始まる英単語は少なく、しばしば1つのインデックスとしてまとめられています。

//footnote[maekoguti][書物の背の反対側の部分です。小口ともいいます。]

空白が含まれている暗号文では、単語の頭文字の言語的特徴が解読の手がかりとして役立ちます。
これは、単語の頭文字が特定の頻度パターンを持つためです。

=== メッセージ内の各アルファベットの頻度を利用する

空白がない場合、単語の区切りが不明瞭になるため、文字の頻度分析に頼る別のアプローチが必要です。

英語では、とくに文字'e'がもっとも頻繁に使用される文字であり、'z'や'q'のような文字はほとんど使われません。
つまり、英文全体で見れば、'e'が現れやすく、'z'などは現れにくいということです。

メッセージ内で特定の文字が出現する回数をメッセージ全体の文字数で割った値は、出現確率になります。
この出現確率を文字の頻度、または短縮して文字頻度と呼ぶことにします。

英語における各アルファベットの文字頻度は、統計的に分析されており、これらのデータについては@<chap>{appendixA}で詳述しています。

頻度分析では、文字や文字列の統計的特徴に基づき暗号文の解読を試みる手法です。
この分析は、メッセージ全体を考慮するため、暗号文に空白が含まれているかどうかに係わらず有効です。

==={cryptool_caesar_by_frequency} CrypTool 2で頻度分析してシフト暗号を解読する

CrypTool 2には、コンポーネント一覧の「Cryptanalysis」＞「Specific」カテゴリー内にCaesar Analyzerという頻度分析用のコンポーネントが用意されています。
これは、シフト暗号を解読するために暗号文を頻度分析します。
Caesar Analyzerコンポーネントは、ユニグラム（1文字）だけでなく、バイグラムやトライグラムなどのnグラムグラムも分析可能です。

Caesor Analyzerコンポーネントの内部処理は、次の流れになります。

//noindent
1：与えられた暗号文をすべての可能な鍵で復号します。
つまり、総当たりで復号します。

//noindent
2：得られた平文の文字頻度と、自然言語（たとえば英語）の既知の文字頻度を比較して、もっとも自然な英文になる平文を選び出します。

//noindent
3：その平文を得るために用いた鍵を、解読結果として出力します。

Caesar Analyzerコンポーネントの入出力コネクターは次のとおりです。

 * 入力
 ** Encrypted text…シーザー暗号の暗号文。
 ** Frequency List…Frequency Testコンポーネントの出力。
 * 出力
 ** Key…解析した結果の鍵（1つ）。

CrypTool 2で次のようにプロジェクトを構築します。

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[caesar_fre1][頻度分析で解読するためのプロジェクト][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/caesar_fre1.png" alt="頻度分析で解読するためのプロジェクト" style="max-width: 90%; height: auto;" />
  <figcaption>図：頻度分析で解読するためのプロジェクト</figcaption>
</figure>
//}

各コンポーネントの設定と役目は次のとおりです。

 * Text Inputコンポーネント…プロジェクトの左上に位置する。
 ** "Ciphertext"と名づけてある。
 ** 暗号文をここに入力する。
 * Frequency Testコンポーネント
 ** "FrequencyTest"と名づけてある。
 * Caesar Analyzerコンポーネント
 ** "CaesarAnalysisHelper"と名づけてある。
 * Caesarコンポーネント
 ** "Caesar Decryption"と名づけてある。
 ** ActionでDecryptを選ぶ。
 ** AlphabetにはAからZまでのアルファベット群を書く。
 ** "Output contains Source Case"にチェックを入れる。
 * Text Outputコンポーネント
 ** "Key"と名づけてある。
 ** 解析した鍵を表示する。
 * Text Outputコンポーネント…プロジェクトの一番右に位置する。
 ** "Decrypted Ciphertext"と名づけてある。
 ** 解析した鍵を用いた復号結果を表示する。

暗号化されたテキストはまずFrequencyTestに入力されます。
このコンポーネントはユニグラム（1文字）の頻度を分析し、その結果を棒グラフとして表示します。
分析結果はCaesarAnalysisHelperに送られ、単一文字の頻度を使用して、シーザー暗号の暗号解析を実行します。
解析されたシフト数（鍵）は、最終的にCaesar Decryptionに渡され、暗号文が復号されます。
このシフト数はText OutputコンポーネントのKeyでも確認できます。

先のプロジェクトでは、@<hd>{brute_force_by_manual}で使用した暗号文を解析しています。
短い暗号文であるにもかかわらず、正しい鍵（シフト数17）を特定できました。

== シフト暗号の暗号文であることを識別する

暗号解読の初期段階では、まず与えられた暗号文がどのタイプの暗号化方式によって生成されたかを識別するのが重要です。

暗号法が不明な暗号文が与えられた場合、頻度分析で暗号文の文字頻度の分布を生成し、それが英文の文字頻度の分布をシフトしたものと一致するかどうかを調べます。
一致すればシフト暗号の可能性が高く、一致しなければ別の暗号化方式の可能性が高いと判断できます。

=== 一致指数法で単一換字式暗号を識別する

一致指数は、テキストからランダムに選んだ2つの文字が同じである確率として定義されます。
これは、テキストを解析したり、2つのテキストを比較する際に有用です。
一致指数を分析に利用することを、一致指数法といいます。

たとえば、英語のテキストでの一致指数は約6.7%、ランダムなテキストでは約3.8%であることが知られています。

暗号解読においては、一致指数の定義を完全に理解するよりも、その計算方法と適用の仕方を知ることがより重要です。
これにより、効率的な解読が可能になります。

一致指数法により、テキストが単一換字式暗号であるかどうかを判定できます。
これは「英文である平文の一致指数」と「単一換字式暗号の暗号文の一致指数」がほぼ一致するためです。

次に、一致指数法を計算する方法を紹介します。

//noindent
1：dCode.frは一致指数計算ツール（@<href>{https://www.dcode.fr/index-coincidence}）を提供しています。
Webブラウザーでアクセスしてください。

//noindent
2："MESSAGE TO ANALYSE"のテキストボックスに解読したいメッセージを入力します。
ここではデフォルトで入力されているサンプル暗号文を利用します（以下の引用は、改行を省略してある）。

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

CHARACTERSでは"LETTER A-Z ONLY"を選びます。
[CALCULATE IC]ボタンを押すと、左側のResultに一致指数の計算結果が表示されます。

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[ic1][サンプル暗号文の一致指数を計算する][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/ic1_epub.png" alt="サンプル暗号文の一致指数を計算する" style="max-width: 90%; height: auto;" />
  <figcaption>図：サンプル暗号文の一致指数を計算する</figcaption>
</figure>
//}

//noindent
3：一致指数として0.06402が出力されました。これをパーセントにするには、100倍すればよく、約6.4%になります。
この値は英語の一致指数の6.7%にとても近いため、単一換字式暗号の暗号文の可能性が高いといえます。

== 復号結果が正しい平文メッセージであることを判定する

暗号解読のプロセスを通じて、しばしば複数の平文候補が生成されますが、正しい解となる平文メッセージはただ1つのみ存在します。
このメッセージは一般的に自然言語で表現されます（この文脈では英語）。

正しい平文メッセージは、他の候補と比べてより英文らしく、意味のある内容を持っていることが一般的です。
これは、言語の自然な流れと文脈の整合性から判断されます。

これらの候補を評価するためには、複数のアプローチが存在します。
これには、文法的正確さ、文脈の一貫性、および言語的流暢さが含まれます。
これらの要素を総合的に考慮して、もっとも自然で意味のあるメッセージを正しい平文として特定します。

@<hd>{brute_force_by_manual}では手動で識別するアプローチを紹介しましたが、ここではコンピューターの力を借りられる前提でのアプローチを示します。

 * アプローチ①：単語による判定
 ** 空白を含む平文の場合
 *** "the"などの頻出単語があれば、その平文が正解の可能性が高い。
 ** 空白を含まない平文の場合
 *** "the"が単独の単語として存在するかどうかの判定が難しくなる。たとえば、単語の境界が不明確で"the"が他の文字と連続している可能性がある@<fn>{the_fumei}。
 *** より長い英単語が一致する場合、正解の可能性が増す。
 * アプローチ②：文字頻度に基づく判定
 ** 平文候補の文字頻度が自然な英文の文字頻度に類似している場合、その平文が正解である可能性が高い。
 * アプローチ③：言語的特徴による判定
 ** 英語の特徴的な文字ペア、たとえば"er"、"th"などが頻繁に現れる場合、その平文が正解である可能性が高い。

//footnote[the_fumei][ ヒットした"the"が「単語として単独の"the"」なのか「"～th"と"e～"の連結」なのかを区別できないからです。]

=== 辞書ファイルを活用するアプローチ

コンピューターの力を借りれば、アプローチ①を自動化できます。
このプロセスでは、辞書ファイルが中心的な役割を果たします。

辞書ファイルとは、テキスト形式で単語リストが保存されたファイルです。
各単語は1行に1つずつ、改行で区切られて記録されています。
テキストファイル形式なので、容易に単語を読み書きでき、暗号解読プロセスの効率化を支援します。

英単語の辞書ファイルであれば、復号結果が英文であるかの判定に使えます。

UNIXやUNIXライクなOSであれば、システム内に巨大なファイルが同梱されているケースが多いといえます。
次に示すディレクトリーを探してみてください。

 * "/usr/share/dict"
 * "/usr/dict/words"
 * パスワード解析ツールのインストールディレクトリー内
 ** ParrotOSの場合、オフラインパスワードクラッカーであるJohn the Ripperのパスは"/usr/share/john"であり、ここに"password.lst"ファイルがある。
 * Debian GNU/Linuxの場合
 ** "/usr/share/opendict/dictionaries"
 * macOSの場合
 ** "/Library/Dictionaries"

インターネット上で多様な辞書ファイルが公開されており、これらは自由にダウンロードして使用できます。
さまざまな用途に応じた暗号解読やデータ分析が容易になります。

公開されている辞書ファイルからいくつかをピックアップしてみました。

 * 動物の英単語の辞書ファイル： 動物名や動物に関連する英単語を集めたもの。
 * ヨーロッパ圏の人名の辞書ファイル：ヨーロッパの一般的な人名を含むもの。
 * 高頻度のパスワードの辞書ファイル："12345678"や"password1"のように、よく使われるパスワードのリスト。
 * 流出したパスワードの辞書ファイル：過去に流出したパスワードの集合。パスワード解析にはとても有効。
 * 特定の単語を除外した辞書ファイル：'a'や'I'など一般的すぎる単語を除外したもの。
 * 数字列だけで構成された辞書ファイル：数字のみを含む辞書。PINの解析に有効。
 * 最大8桁の英数字列の全組み合わせの辞書ファイル：辞書攻撃の時間が限られているとき、最大8桁の認証システムのパスワード解析に有効。
 * など

辞書ファイルの詳細については、拙著を参照ください。

 * 『ハッキング・ラボで遊ぶために辞書ファイルを鍛える本』IPUSIRON著
 ** @<href>{https://akademeia.info/?page_id=22508}
 * 『ハッキング・ラボのつくりかた 完全版』IPUSIRON著（翔泳社刊）
 ** @<href>{https://akademeia.info/?page_id=35502}
 ** P.489-494が参考になる。

=== CrypTool 2で総当たり攻撃と辞書判定を実現する

CrypTool 2を用いてアプローチ①を体験してみましょう。

CrypTool 2には「Caesar Brute-Force Analysis」テンプレートが含まれており、これを使用してシフト暗号の解読を体験できます。
このテンプレートは、総当たり攻撃を行い、その結果を辞書判定にかけることで平文を特定します。
もし平文が辞書に含まれる単語を1つでも含んでいれば、その平文を出力します。
含まなければ、その平文は出力しません。
この辞書判定処理をすべての復号結果に対して行います。

自動的に最適な解を絞り込む機能は含まれていないため、複数の有効な平文候補が出力されることがあります。
得られた平文候補から最終的な解を選ぶには、人間の判断が必要です。

それでは、このプロセスをCrypTool 2で実際に試してみましょう。
これにより、シフト暗号解読の実践的な理解が深まります。

//noindent
1：CrypTool 2を起動します。
メイン画面の中央にある「Templates」に注目します。
「Cryptanalysis」＞「Classical」＞「Caesar Brute-Force Analysis」を選んで、ダブルクリックします。

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[bruteforce_analysis][「Caesar Brute-Force Analysis」テンプレートを選ぶ][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/bruteforce_analysis.png" alt="「Caesar Brute-Force Analysis」テンプレートを選ぶ" style="max-width: 90%; height: auto;" />
  <figcaption>図：「Caesar Brute-Force Analysis」テンプレートを選ぶ</figcaption>
</figure>
//}

//noindent
2：ワークスペース上に、シフト暗号を総当たり攻撃するプロジェクトが開きます。

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[cryptool_brute1][シフト暗号を総当たり攻撃するプロジェクト][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/cryptool_brute1.png" alt="シフト暗号を総当たり攻撃するプロジェクト" style="max-width: 90%; height: auto;" />
  <figcaption>図：シフト暗号を総当たり攻撃するプロジェクト</figcaption>
</figure>
//}

各コンポーネントや処理の流れについては後で解説しますので、ここでは試しに実行してみましょう。
左上に位置するCiphertextコンポーネントには、すでにサンプルの暗号文メッセージが入力されています。
この暗号文を使って処理を進めます。

//noindent
3：Caesarコンポーネントの挙動を確認します。
Caesarコンポーネントをダブルクリックし、歯車アイコンを押して設定画面を開きます。
設定画面で、ActionがEncryptに設定されている場合は、Decryptに変更します@<fn>{bruteforce_bug}。
なお、コンポーネントの設定はプロジェクトがStop状態でなければ行えません。

//footnote[bruteforce_bug][Encryptのままでも解読後の平文メッセージを得られますが、鍵が違っています。シフト暗号の復号アルゴリズムは暗号化アルゴリズムで代用できるので、この方法でも解読に成功するのです。しかし、その変換に使った鍵をあくまで暗号化用なので、正しい復号用の鍵に調整するためには26から引く必要があります。]

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[Encrypt2Decrypt][ActionをDecryptにする][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/Encrypt2Decrypt.png" alt="ActionをDecryptにする" style="max-width: 90%; height: auto;" />
  <figcaption>図：ActionをDecryptにする</figcaption>
</figure>
//}

設定を終えたら、ウィンドウの右上にある最小化アイコン（×の左にあるアイコン）を押します。
するとワークスペースに戻ります。

//noindent
4：それではサンプル暗号文を解読してみます。
ワークスペースに戻ったら、[Play]ボタンを押して解読プロセスを開始します。
すると、右上の"All possible plaintexts"コンポーネントに平文候補が次々と表示されます。
解読が一定の段階に達すると、プロセスが一時停止し、右下の"Decrypted Ciphertext"コンポーネントに最終的な解読結果が表示されます。
また、その直上にある"Found shift key"に、解読に使用された鍵（シフト数）が表示されます。

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[cryptool_brute2][サンプル暗号文を総当たり攻撃する][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/cryptool_brute2_epub.png" alt="サンプル暗号文を総当たり攻撃する" style="max-width: 90%; height: auto;" />
  <figcaption>図：サンプル暗号文を総当たり攻撃する</figcaption>
</figure>
//}

今回用いた、解読対象の暗号文メッセージ（653文字）は次のとおりです。

//quote{
Dxbg tgwxkxl Dtibmxe wxk Dkrimhehzbx-Zxlvabvamx oxkebxy lh wktftmblva ngw yhezxgkxbva pbx wtl wxk exzxgwtxkxg wxnmlvaxg Oxklvaenxllxengzlftlvabgx Xgbzft. Wbx 1918 xkyngwxgx Ftlvabgx xkexumx bf Spxbmxg Pxemdkbxz bakx Uenxmxsxbm ngw uxxbgyenllmx wtuxb wbx Pxemzxlvabvamx bg xbgxk Yhkf, wbx Ablmhkbdxk xklm Ctak sxagmx litxmxk bg bakxk Mktzpxbmx kbvambz xbglvatxmsxg dhggmxg. Wxk 2001 xklvabxgxgx Dbghybef Xgbzft fbm Dtmx Pbglexm bg wxk Atnimkheex blm gnk xbgxk ohg obxexg Uxexzxg ynxk wbx ngzxaxnkx Ytlsbgtmbhg, wbx wbxlx Ftlvabgx ubl axnmx tnlnxum. Lh blm wbx Xgbzft gtva pbx ohk wtl uxdtggmxlmx ngw tf uxlmxg xkyhklvamx Oxklvaenxllxengzlzxktxm wxk Pxem.
//}

プロジェクトを実行して、解読結果として得られた平文メッセージは次のとおりです。

//quote{
Kein anderes Kapitel der Kryptologie-Geschichte verlief so dramatisch und folgenreich wie das der legendaeren deutschen Verschluesselungsmaschine Enigma. Die 1918 erfundene Maschine erlebte im Zweiten Weltkrieg ihre Bluetezeit und beeinflusste dabei die Weltgeschichte in einer Form, die Historiker erst Jahr zehnte spaeter in ihrer Tragweite richtig einschaetzen konnten. Der 2001 erschienene Kinofilm Enigma mit Kate Winslet in der Hauptrolle ist nur einer von vielen Belegen fuer die ungeheure Faszination, die diese Maschine bis heute ausuebt. So ist die Enigma nach wie vor das bekannteste und am besten erforschte Verschluesselungsgeraet der Welt.
//}

復号されたテキストが英語でないことは一目瞭然です。
テンプレートを開いた時点で、CrypTool 2のワークスペース中央上にあるDictionaryコンポーネントがドイツ語（German）に設定されていることから、元の平文がドイツ語であることを示唆しています。

解読されたメッセージをDeepL翻訳ツールに入力したところ、ドイツ語として自動検出されました。
その翻訳結果は、エニグマに関するものでした。

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[deepl_german][DeepL翻訳した結果][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/deepl_german.png" alt="DeepL翻訳した結果" style="max-width: 90%; height: auto;" />
  <figcaption>図：DeepL翻訳した結果</figcaption>
</figure>
//}

以上で「Caesar Brute-Force Analysis」テンプレートの使い方の解説は終了です。

このテンプレートの使用を終了するには、[Stop]ボタンを押してシステムをリセットします。
これで現在のセッションの設定やデータがクリアされます。

以降も引き続き解説しますので、プロジェクトは停止だけしておき、閉じないでおきます。

//noindent
4：暗号解読の直接的な手段ではありませんが、一致指数を確認することも有用です。
たとえば、@<href>{https://www.dcode.fr/index-coincidence}で一致指数を計算すると、暗号文の一致指数は8.2%であることを確認できます。

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[ic2][暗号文の一致指数を計算する][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/ic2.png" alt="暗号文の一致指数を計算する" style="max-width: 90%; height: auto;" />
  <figcaption>図：暗号文の一致指数を計算する</figcaption>
</figure>
//}

続けて復号結果の一致指数を計算すると、8.2%になります。
暗号文の一致指数と、復号結果の一致指数が合致しました。
今回はシフト暗号の暗号文だったので、当然の結果といえます。
「シフト暗号は単一換字式暗号の一種であること」と「単一換字式暗号の暗号文の一致指数は、平文の一致指数と同一値であること」の理由によります。

英語の一致指数は5.7%、ドイツ語の一致指数は7.3%です。
今回の計算した一致指数の値は8.2%であり、英語よりドイツ語に近いこともわかります。

//noindent
5：以降、このプロジェクトの各部の処理について解説します。

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[cryptool_brute3][各部の役割][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/cryptool_brute3_epub.png" alt="各部の役割" style="max-width: 90%; height: auto;" />
  <figcaption>図：各部の役割</figcaption>
</figure>
//}

解読プロセスで得られた変換後のメッセージに実在の単語が含まれる場合、それが正しい平文メッセージとして出力されます。
この条件に基づいて、今回は1つのメッセージだけが条件に適合したため、解読結果としてその1つだけが出力されました。

プロジェクトの左部を見てみましょう。
この部分の主な役割は、1から26までの数をインクリメントしながら、その値を出力することです。

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[kakubu1][インクリメントしながら数値を出力する][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/kakubu1.png" alt="インクリメントしながら数値を出力する" style="max-width: 90%; height: auto;" />
  <figcaption>図：インクリメントしながら数値を出力する</figcaption>
</figure>
//}

次に示すコンポーネントを組み合わせて構成されています。
複雑そうに見えますが、プログラミングでよく登場するfor文の処理だと思えばよいでしょう。

 * Number Inputコンポーネント
 ** 初期値の1、最大値の26が用意されている。
 * Inc Decコンポーネント
 ** 今回はModeがIncrement、Inc/Dec valueが1なので、1ずつインクリメントする。
 * Comparatorsコンポーネント
 ** 比較する。
 ** 今回は「<=」という大小比較。
 * Gateコンポーネント
 ** 指定のTriggerを満たすと通す。
 ** 今回はTriggerにtrue valueを設定されている。

今度は中央部に注目してください。
この部分の役割は、復号結果に単語が含まれているかどうかを判定することです。
含まれていれば、PlaintextGateからそのメッセージが出力されます。

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[kakubu2][復号結果に単語が含まれているかどうかを判定する][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/kakubu2.png" alt="復号結果に単語が含まれているかどうかを判定する" style="max-width: 90%; height: auto;" />
  <figcaption>図：復号結果に単語が含まれているかどうかを判定する</figcaption>
</figure>
//}

次に示すコンポーネントを組み合わせて構成されています。

 * Dictionaryコンポーネント
 ** 今回はドイツ語の辞書（30万超の単語を収録）が指定されている。
 * Containsコンポーネント
 ** Search TypeがHashtable、"Count each word only once"にチェックあり。
 * Gateコンポーネント
 ** 指定のTriggerを満たすと通す。
 ** 今回はTriggerにtrue valueを設定されている。

最後に、右部に注目してください。
この部分の役割は、解読結果の鍵（数値）を表示するために文字列に変換することです。
これは"Found shift key"というText Outputコンポーネントに表示させるための処理に過ぎません。

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[kakubu3][数値から文字列に変換する][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/kakubu3.png" alt="数値から文字列に変換する" style="max-width: 90%; height: auto;" />
  <figcaption>図：数値から文字列に変換する</figcaption>
</figure>
//}

次に示すコンポーネントを組み合わせて構成されています。

 * Gateコンポーネント
 ** 指定のTriggerを満たすと通す。
 ** 今回はTriggerにtrue valueを設定されている。
 * Converterコンポーネント
 ** "Converting to"にstringが指定されている。
 ** Digits for UInt[]の"Define Digits as"には"String of Digits"、Digitsには"0123456789ABCDEF"、Endiannessには"Big Endian"が設定されている。
 * Text Outputコンポーネント
 ** "Found shift key"と名づけられている。
 ** 特定した鍵を表示する。

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[converter_component][Converterコンポーネントの設定内容][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/converter_component.png" alt="Converterコンポーネントの設定内容" style="max-width: 90%; height: auto;" />
  <figcaption>図：Converterコンポーネントの設定内容</figcaption>
</figure>
//}

以上で「Caesar Brute-Force Analysis」テンプレートの解説を終わります。

ワークスペースのタブを閉じる際、またはCrypToolを終了する際に、プロジェクトに変更があると"Caesar_ExhaustiveKeySearch.cwm"ファイルを上書きするかどうかを選択するダイアログが表示されます。
もし変更を保存したくない場合は、[いいえ]ボタンを押してください。

もし英語の暗号文を解読したい場合は、Ciphertextコンポーネントに解読対象の暗号文を入力し、Dictionaryコンポーネントの言語設定を「English」に変更してください。
これにより、英語の単語が含まれているかどうかで平文を判断できます。
