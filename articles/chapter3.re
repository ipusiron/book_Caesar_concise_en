= コンピューターの力を借りてシフト暗号を試す

シフト暗号の仕組みについて解説し、手動での暗号化と復号を試しました。
シーザー暗号やシフト暗号の解読に進む前に、もう少しシフト暗号に慣れておきましょう。

本章ではコンピューターの力を借りてシフト暗号を試します。
コマンド、プログラム、ツールを用いてシフト暗号を堪能しましょう。

== trコマンドでシフト暗号を試す

echoコマンドとtrコマンドをパイプでつなぐことにより、シフト暗号を簡単に試せます。

echoコマンドは、標準出力に文字列を書き出すコマンドです。
そして、trコマンドは、標準入力から受け取った文字を置換また削除し、結果を標準出力に渡します。

=== シーザー暗号を試す

平文は小文字、暗号文は大文字で表記することを考慮して、"hello world"という平文を暗号化するには、次のコマンドを実行します。

//cmd{
ipusiron@parrot:~$ echo "hello world" | tr a-z D-ZA-C
KHOOR ZRUOG　←暗号化の結果。
//}

暗号文を復号するには、次のコマンドを実行します。

//cmd{
ipusiron@parrot:~$ echo "KHOOR ZRUOG" | tr D-ZA-C a-z
hello world　←復号の結果。
//}

これにより、元の平文"hello world"と正確に一致することが確認できます。

=== ROT13を試す

同じコマンドを用いて、ROT13も同様に実現できます。
"i love you."という平文を用いて、二重暗号化で元に戻ることを検証してみます。

//noindent
1：まず平文を暗号化し、その結果を復号してみます。

//cmd{
ipusiron@parrot:~$ echo "i love you." | tr a-z N-ZA-M
V YBIR LBH.　←暗号化の結果。
ipusiron@parrot:~$ echo "V YBIR LBH." | tr N-ZA-M a-z
i love you.　←復号の結果。
//}

//noindent
2：次は、同じ平文をROT13で2回暗号化し、結果を確認します。

//cmd{
ipusiron@parrot:~$ echo "i love you." | tr a-z N-ZA-M
V YBIR LBH.　←1回目の暗号化の結果。
ipusiron@parrot:~$ echo "V YBIR LBH." | tr A-Z n-za-m
i love you.　←2回目の暗号化の結果。
//}

結果として、元の平文"i love you."に戻ることが確認できました。

以上により、ROT13を2回適用すると元の平文に戻ることが証明されました。

== nkfコマンドでROT13を試す

nkfコマンドは、ネットワーク用漢字コードの変換を行うフィルターコマンドです。
UNIXシステムで文字コードや改行コードの変換で広く使用されます。

//noindent
1：平文が書かれた"plain.txt"ファイルを用意します。
ここでは、平文は小文字で構成されているものとします。

//cmd{
ipusiron@parrot:~$ cat plain.txt
i love you.
//}

//noindent
2：nkfコマンドに-rオプションをつけると、ROT13で暗号化できます。

//cmd{
ipusiron@parrot:~$ nkf -r plain.txt
v ybir lbh.
//}

出力結果は、trコマンドを用いたROT13での暗号化した結果と同じです。
ただし、小文字のままなので、trコマンドに渡して小文字を大文字に変換してみます。

//cmd{
ipusiron@parrot:~$ nkf -r plain.txt | tr '[:lower:]' '[:upper:]'
V YBIR LBH.
//}

これで暗号文が得られました。

次のステップで復号を試すので、暗号文メッセージを"cipher.txt"ファイルに保存しておきます。

//cmd{
ipusiron@parrot:~$ nkf -r plain.txt | tr '[:lower:]' '[:upper:]' > cipher.txt
//}

//noindent
3：ROT13は二重暗号化で元に戻るので、復号するには再び暗号化するだけです。
再びnkfコマンドの-rオプションを使います。

//cmd{
ipusiron@parrot:~$ nkf -r cipher.txt
I LOVE YOU.
ipusiron@parrot:~$ nkf -r cipher.txt | tr '[:upper:]' '[:lower:]'
i love you.
//}

確かに、元の平文メッセージに戻ったことを確認できました。

== ワンライナーコマンドでROT13を試す

ワンライナーコマンドは、1行で実行できるコマンドのことを指します。

Pythonのcodecsは、さまざまなエンコードやデコードを行う関数を定義した標準ライブラリーモジュールです。
codecs.encode()関数を使用すると、指定の方式でエンコードできます。
対して、codecs.decode()関数を使用すると、指定の方式でデコードできます。

ここでは、これらの関数を用いてROT13を扱う方法を紹介します。
平文は"i love you."とします。

//noindent
1：ROT13で暗号化するには、次のワンライナーコマンドを入力します。

//cmd{
ipusiron@parrot:~$ python3 -c "import codecs; print(codecs.encode(\"i love you.\", \"rot-13\"))"
v ybir lbh.　←暗号化の結果。
//}

//noindent
2：ROT13で復号するには、次のワンライナーコマンドを入力します。
あえて二重暗号化ではなく、デコードする方法を試しています。

//cmd{
ipusiron@parrot:~$ python3 -c "import codecs; print(codecs.decode(\"v ybir lbh.\", \"rot-13\"))"
i love you.　←復号の結果。
//}

== ブラウザーでシーザー暗号を試す

シーザー暗号円盤ツール（Caesar Cipher Wheel Tool）という、インタラクティブなシーザー暗号（厳密にはシフト暗号）の暗号化・復号ツールを用意しました。

 * GitHubページ
 ** @<href>{https://github.com/ipusiron/caesar-cipher-wheel}
 * デモページ
 ** @<href>{https://ipusiron.github.io/caesar-cipher-wheel/}

Shiftを1に設定するとROT1、3に設定するとROT3（シーザー暗号）になります。

//embed[html]{
<figure style="text-align: center;">
  <img src="images/caesar_wheel_tool.png" alt="Shiftを3にして暗号化した" style="max-width: 90%; height: auto;" />
  <figcaption>図：Shiftを3にして暗号化した</figcaption>
</figure>
//}

=={caesar_python} Pythonでシーザー暗号を試す

シーザー暗号やシフト暗号は基本的な暗号化方式であるため、関連プログラムはインターネット上で容易に見つかります。

『Pythonでいかにして暗号を破るか』（ソシム刊）では、さまざまな古典暗号と、簡単な現代暗号をPythonで実装する方法を解説しています。
扱っている古典暗号の中には、シフト暗号が含まれています。
具体的には、第5章で暗号化・復号のプログラム、第6章で総当たり攻撃用のプログラムを紹介しています。
興味のある方は、読んでみてください。

 * 『Pythonでいかにして暗号を破るか』日本語解説ページ
 ** @<href>{https://akademeia.info/?page_id=94}
 ** @<href>{https://www.socym.co.jp/book/1216}

ここでは、『Pythonでいかにして暗号を破るか』に掲載されたプログラムを若干修正した@<list>{caesarCipher}を用います。
このプログラムは非アルファベット文字にも対応しています。
使用する際、messageには変換対象の文字列、keyにはシフト数を指定します。
そして、暗号化する際にはmodeを"encrypt"、復号する際には"decrypt"を設定します。

//listnum[caesarCipher][caesarCipher.py][python]{
# https://www.nostarch.com/crackingcodes (BSD Licensed)
# 暗号化・復号する文字列.
message = 'This is my secret message.'

# 暗号化・復号の鍵.
key = 13

# プログラムが暗号化するか復号するか.
mode = 'encrypt' # 'encrypt'あるいは'decrypt'のどちらかを指定する.

# 暗号化できるシンボルの全候補.
SYMBOLS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' \
			'abcdefghijklmnopqrstuvwxyz' \ '
			'1234567890 !?.'

def caesar(message, key):
	translated = ""
	for symbol in message:
		# 注意：文字列SYMBOLSに含まれるシンボルのみを暗号化・復号する.
		if symbol in SYMBOLS:
			symbolIndex = SYMBOLS.find(symbol)

			# 暗号化・復号を実行する.
			if mode == 'encrypt':
				translatedIndex = symbolIndex + key
			elif mode == 'decrypt':
				translatedIndex = symbolIndex - key

			# 必要に応じてラップアラウンドを処理する.
			if translatedIndex >= len(SYMBOLS):
				translatedIndex = translatedIndex - len(SYMBOLS)
			elif translatedIndex < 0:
				translatedIndex = translatedIndex + len(SYMBOLS)

			translated = translated + SYMBOLS[translatedIndex]
		else:
			# 暗号化・復号せずにシンボルを追加する.
			translated = translated + symbol
	return translated

def main():
	print(caesar(message, key))

if __name__ == '__main__':
	main()
//}

実際にプログラムを実行してみてください。
ローカルのPython環境下で実行してもよいですし、オンライン実行環境でもよいでしょう。

 * Python Online
 ** paiza.IOのPython用オンライン実行環境。
 ** ユーザー登録不要。
 ** @<href>{https://paiza.io/ja/languages/python3}
 * Google Colaboratory
 ** Googleアカウント必須。
 ** @<href>{https://colab.research.google.com/notebooks/welcome.ipynb?hl=ja}
 * CodeChef
 ** ユーザー登録不要。
 ** @<href>{https://www.codechef.com/ide}
 * Ideone.com
 ** ユーザー登録不要。
 ** @<href>{https://ideone.com/}

@<list>{caesarCipher}をそのまま実行すると、暗号文"guv6Jv6Jz!J6rp5r7Jzr66ntrM"が出力されます。
この暗号文は、空白やピリオドも含めて暗号化されており、大文字と小文字が区別されていることがわかります。

次に、messageに先ほど得られた暗号文"guv6Jv6Jz!J6rp5r7Jzr66ntrM"を指定し、modeを"decrypt"に設定します。
その後、実行すると、復号されて"This is my secret message."が出力されます。
これは元の平文そのものです。

=== 文字体系に合わせてROT13を拡張する

@<list>{caesarCipher}のプログラムでは、鍵が13でした。
ROT13を用いて、2回暗号化すると元に戻るかを試してみてください。

//noindent
"This is my secret message."@<br>{}
⇒"guv6Jv6Jz!J6rp5r7Jzr66ntrM"（1回目の暗号化の結果）@<br>{}
⇒"t89EW9EW?KWE53D5FW?5EE175Z"（2回目の暗号化の結果）

この試みでは、2回暗号化しても元のテキストに戻りませんでした。
その理由は、プログラムが認識する文字体系の文字数を考えた鍵を使わなかったためです
通常のROT13が扱う文字体系は26文字のアルファベットだったので、半分の13を鍵とすることで、2回の暗号化後に元のテキストに戻りました。
しかし、今回の文字体系は合計66文字（＝大文字26＋小文字26＋数字10＋記号4）の文字を含んでいます。
そのため、鍵を33（文字数の半分）と設定しなければ、2回の暗号化で元に戻りません。
このことを実際に検証してみてください。

//noindent
"This is my secret message."@<br>{}
⇒"1ABLdBLdFRdL!0K!MdF!LL8.!g"（1回目の暗号化の結果）@<br>{}
⇒"This is my secret message."（2回目の暗号化の結果）

== ROT13エンコーダーでROT13を試す

ROT13エンコーダー（ROT13 Encoder）という、インタラクティブなROT13のWebツールを用意しました。

 * GitHubページ
 ** @<href>{https://github.com/ipusiron/rot13-encoder}
 * デモページ
 ** @<href>{https://ipusiron.github.io/rot13-encoder/}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/rot13_encorder.png" alt="ROT13エンコーダーでの実験" style="max-width: 90%; height: auto;" />
  <figcaption>図：ROT13エンコーダーでの実験</figcaption>
</figure>
//}

== CrypTool 2を用いてシフト暗号を扱う

CrypTool 2はGUIで操作できる総合ツールであり、あらゆる暗号に対応しています。
直感的に操作できます。
CrypTool 2を用いることで、暗号化方式の実装ではなく、暗号化・復号・解読そのものに力を注げます。

CrypTool Portal（@<href>{https://www.cryptool.org/en/}）では、次の4種類の暗号学習プラットフォームツールが提供しています。

 * CrypTool-Online（CTO）
 ** Webブラウザーで動作する。
 ** 暗号支援ツールが個別に用意されている。
 ** 簡易的に各種暗号を扱いたいときに便利。
 * CrypTool 1（CT1）
 ** CrypToolのファーストバージョン。1998年から開発が始まった。
 ** Windows専用。
 ** 元々は企業向けの情報セキュリティ教育アプリケションとして設計され、その後オープンソース・プロジェクトに発展した。
 * CrypTool 2（CT2）
 ** Windows専用のGUIバージョン。
 * JCrypTool（JCT）
 ** Javaで動作し、Windows、macOS、Linuxに対応する。
 ** ユーザーインタフェースはCrypTool 2とまったく異なる。
 ** 2020年11月に安定版1.0.0をリリースした。
 ** 100以上の異なるプラグインが用意されている。

本書ではWindows版のCrypTool 2.1を用いて解説します。

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[CrypTool][CrypTool 2.1の起動直後の画面][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/CrypTool.png" alt="CrypTool 2.1の起動直後の画面" style="max-width: 90%; height: auto;" />
  <figcaption>図：CrypTool 2.1の起動直後の画面</figcaption>
</figure>
//}

=== ウィザード機能でシフト暗号を試す

CrypTool 2では、シフト暗号を手軽に試せるウィザードが備わっています。
ここでは、そのウィザードを開始し、使用する方法を詳しく解説します。

CrypTool 2で「シーザー暗号」と言及する際には、「シフト暗号」を指していることを覚えておいてください。

//noindent
1：CrypTool 2のホーム画面で、[New]アイコンを押します。
または、「New」アイコンの右側にある下向き矢印を押して、「Wizard」を選択しても構いません。

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[crypt_enc0][Wizardの起動の仕方][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/crypt_enc0.png" alt="Wizardの起動の仕方" style="max-width: 90%; height: auto;" />
  <figcaption>図：Wizardの起動の仕方</figcaption>
</figure>
//}

//noindent
2：Wizardタグが開きます。
「TASK SELECTION」画面で「Enryption/Decryption」を選び、[Next]ボタンを押します。

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[crypt_enc1][「TASK SELECTION」画面][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/crypt_enc1.png" alt="「TASK SELECTION」画面" style="max-width: 90%; height: auto;" />
  <figcaption>図：「TASK SELECTION」画面</figcaption>
</figure>
//}

//noindent
3：「AGE SELECTION」画面で「Classic Encryption/Decryption」を選び、[Next]ボタンを押します。

//noindent
4：「ALGORITHM SELECTION」画面で「Caesar」を選び、[Next]ボタンを押します。

//noindent
5：「MESSAGE INPUT」画面が表示されます。
暗号化したい場合は「Encrypt」、復号したい場合は「Decrypt」を選びます。
今回は暗号化するので「Encrypt」を選びます。

テキストボックスには暗号化・復号の対象であるメッセージを書き込みます。
ここでは前章で扱った"at midnight, in the month of june, i stand beneath the mystic moon."を入力しました。

右のKeyにシフト数を入力します。
ここではデフォルトの「3」のままとします。

すべての設定を終えたら、[Next]ボタンを押します。

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[crypt_enc2][「MESSAGE INPUT」画面][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/crypt_enc2.png" alt="「MESSAGE INPUT」画面" style="max-width: 90%; height: auto;" />
  <figcaption>図：「MESSAGE INPUT」画面</figcaption>
</figure>
//}

//noindent
6：「CAESAR OUTPUT」画面にて、変換前と後のメッセージが表示されます。
"dw plgqljkw, lq wkh prqwk ri mxqh, l vwdqg ehqhdwk wkh pbvwlf prrq."という暗号文が得られました。

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[crypt_enc3][「CAESAR OUTPUT」画面][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/crypt_enc3.png" alt="「CAESAR OUTPUT」画面" style="max-width: 90%; height: auto;" />
  <figcaption>図：「CAESAR OUTPUT」画面</figcaption>
</figure>
//}

続けて別のメッセージを暗号化したければ、[Back]ボタンで「MESSAGE INPUT」画面に戻れます。
終了したい場合は[Abort]ボタンを押します。

最終的にウィザード画面が不要であれば、タブを閉じます。

=== シフト暗号を実現するためのプロジェクト

次に、ワークスペース上でシフト暗号で暗号化するためのプロジェクトを作成してみます。
復号用のプロジェクトは、基本的に暗号化のものと同じであるため、ここでは省略します。
詳細は@<hd>{chapter4|cryptool_caesar_by_frequency}に記述しています。

作成するシフト暗号用のプロジェクトは、次のようになります。

#@# //embed[latex]{
#@# \floatplacement{figure}{t}
#@# //}
#@# //image[cryptool_caesar1][シフト暗号の暗号化プロジェクト][scale=1.0]{
#@# //}
#@# //embed[latex]{
#@# \floatplacement{figure}{H}
#@# //}

//embed[html]{
<figure style="text-align: center;">
  <img src="images/cryptool_caesar1.png" alt="シフト暗号の暗号化プロジェクト" style="max-width: 90%; height: auto;" />
  <figcaption>図：シフト暗号の暗号化プロジェクト</figcaption>
</figure>
//}

プロジェクトで中心的な役割を果たすのは、中央に配置されるCaesarコンポーネントです。
このコンポーネントには"Caesar"という名づけられていますが、シフト暗号の処理を担います。

自分でプロジェクトを構築する際には、最初にワークスペース上にCaesarコンポーネントを配置します。
左のコンポーネント一覧の"Classic Ciphers"にCaesarコンポーネントがありますので、これをワークスペースにドラッグします。
あとは入出力に各種コンポーネントを接続して、プロジェクトを完成させます。

Caesarコンポーネントに接続できるコネクターは次のとおりです。

 * 入力
 ** Text input：平文。
 ** External alphabet input：使用するアルファベットを含む文字列。ここが接続されていない場合は、内部アルファベットが使われる。
 ** Shift value：鍵となるシフト数。整数値。
 * 出力
 ** Text output：暗号文。

接続すべきものはText Input、Text Output、Number Inputコンポーネントであり、これらはすべてコンポーネント一覧の「Tools」＞「Data input/output」にあります。

また、Caesarコンポーネントの内部設定の項目は、次のとおりです。

 * Action：暗号化なら「Encrypt」、復号なら「Decrypt」を指定する。
 * Alphabet：External alphabet inputコネクターが未接続の場合、使用するアルファベットを指定する。
 * Alphabet parameters：アルファベット以外の文字の扱いを設定する。
 ** Unknown symbol handling：そのまま出力するなら「Ignore」、削除するなら「Remove」、不明文字として'?'に置き換えるなら「Replace with '?'」を指定する。
 ** Case sensitive：大文字と小文字を区別する場合はチェックを入れる。
 ** Output contains Source Case：変換後も大文字・小文字を保持する場合にチェックを入れる。

各コンポーネントを配置して、必須の配線を完了すれば、プロジェクトが完成したことになります。
ツールバーの「Execute」セクションにある「Play」アイコンを押して、暗号化を開始します。
結果は、右側のText Outputコンポーネントに表示されます。

処理を止めるには「Stop」ボタンを押します。

平文"at midnight, in the month of june, i stand beneath the mystic moon."を鍵3で暗号化すると、暗号文"dw plgqljkw, lq wkh prqwk ri mxqh, l vwdqg ehqhdwk wkh pbvwlf prrq."が得られました。
この暗号文は、ウィザードを使用した場合と同じ結果であり、正確に暗号化されたことを証明しています。
