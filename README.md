# Caesar Cipher Breaking – A Concise Edition

This repository hosts the English edition of _Caesar Cipher Breaking – A Concise Edition_, a concise and practical guide to understanding and breaking the Caesar cipher. The book is authored and translated by **IPUSIRON**, a Japanese cryptography writer known for works such as _The Complete Guide to Cryptography_ and _How to Build a Hacking Lab_.

This edition is part of the **Classical Cipher Series**, aiming to make foundational ciphers accessible to international readers.

---

## 📖 About This Book

- **Title:** Caesar Cipher Breaking – A Concise Edition
- **Original Japanese Title:** 『シーザー暗号の解読法 簡易版』  
- **Author:** IPUSIRON  
- **Original Language:** Japanese  
- **Translated by:** The author (self-translated)  
- **License:** To be announced (TBA)

This edition focuses solely on the Caesar cipher and its natural extension, the shift cipher. It is designed for readers new to cryptography, educators, students, and cipher enthusiasts alike.

---

## 📁 Repository Structure

```text
.
├── articles/                 # Main manuscript directory (EPUB/PDF output stored here)
│   ├── book_Caesar_concise_en.epub
│   └── book_Caesar_concise_en.pdf
├── pdf-sample/              # Optional sample PDFs for preview or layout checking
├── .circleci/               # CI/CD configuration
├── .devcontainer/           # Dev container settings for VSCode/Dev Containers
├── .github/                 # GitHub-specific workflows and metadata
├── node_modules/            # Node.js dependencies (auto-generated)
├── .textlintrc              # Textlint configuration for style/grammar checking
├── Gemfile                  # Ruby dependencies (e.g. Re:VIEW)
├── Gruntfile.js             # Build automation script
├── redpen-conf-ja.xml       # RedPen Japanese proofreading config
├── build-in-docker.sh       # Build helper script (inside Docker)
├── setup.sh                 # Environment setup script
├── rebuild-css.sh           # Stylesheet regeneration script
├── package.json             # Node.js project metadata
├── package-lock.json        # Lockfile for npm dependencies
├── .gitignore, .gitlab-ci.yml, .gitpod.yml, .textlintrc, etc.
└── README.md                # This file
```

### 📦 Output Files

The main outputs of this repository are the finalized English edition of the book in both EPUB and PDF formats.  
These files are stored in the `articles/` directory and will be published under open access terms upon release.

- `articles/book_Caesar_concise_en.epub` — EPUB format (for Kindle and other e-readers)
- `articles/book_Caesar_concise_en.pdf` — Printable PDF format

---

## 📚 Build Environment

This repository uses [Re:VIEW](https://github.com/kmuto/review) as the primary typesetting and publishing tool.

All manuscripts are written in Re:VIEW format, and the output (PDF/EPUB) is generated via a reproducible build process.  
This ensures consistency and typographic quality for both print and digital editions.

### 📦 Toolchain

- Re:VIEW 5.x
- review-epubmaker
- review-pdfmaker
- Ruby (via rbenv or rvm recommended)
- Build automation: `rake` or GitHub Actions (TBA)

Build instructions and scripts will be added before the public release.

---

## 👤 About the Author

**IPUSIRON** is a Japanese technical writer and cryptography educator known for making complex security concepts accessible to learners and practitioners.

He has authored **over 30 books in Japanese** on cryptography, classical ciphers, and cybersecurity—including bestsellers such as:

- _The Complete Guide to Cryptography (『暗号技術のすべて』)_
- _How to Build a Hacking Lab Complete Edition (『ハッキング・ラボのつくりかた 完全版』)_
- _The Textbook of White-Hat Hackers (『ホワイトハッカーの教科書』)_
- _The Hacker’s School: A Handbook of Lockpicking (『ハッカーの学校 鍵開けの教科書』)_

He is also an experienced translator and editorial supervisor of cryptographic literature.  
Notably, he served as:

- One of the supervising translators of _Serious Cryptography_ by Jean-Philippe Aumasson (Japanese edition)  
- The translator of _Codebreaking: A Practical Guide_ by Elonka Dunin and Klaus Schmeh (Japanese edition)  
- The translator of _Cracking Codes with Python_ by Al Sweigart (Japanese edition)

In addition, he is the founder of the **Security Akademeia** blog, where he shares hands-on tutorials, cryptographic tools, and insights from the Japanese security community.

This book marks the first English installment of his ongoing **Classical Cipher Series**, aimed at bringing historically significant ciphers to a wider global audience.

- Blog: [https://akademeia.info/](https://akademeia.info/)  
- X: [@ipusiron](https://x.com/ipusiron)  
- GitHub: [https://github.com/ipusiron](https://github.com/ipusiron)

---

## TODO
※このセクションは、リポジトリ公開時にREADME.mdから削除または別ファイル化予定。

- イラストの英語化
- Webツールの英語化等も記載
- リポジトリをパブリックにしたら、Git PagesをONにする。そしてLPとして活用。
    - Jekyllテーマ使用を使えば、プライベートリポジトリのままLPにできそう。
    - 独自ドメインもありかも。SEO対策のため。

## 🗂 開発マイルストーン（自分用メモ）

_このセクションはリポジトリが非公開の間のみ表示されます。公開時には削除予定。_

### ✅ 完了済み
- 2025-07-08：リポジトリ `book_Caesar_concise_en` 作成（プライベート）
- 2025-07-08：英語タイトル決定：「Caesar Cipher Breaking – A Concise Edition」
- 2025-07-08：著者紹介（英語）をREADMEに反映
- 2025-07-09：実際のフォルダー構成に合わせて構成セクション修正
- 2025-07-09：EPUB/PDF成果物の配置先を `articles/` に確定
- 2025-07-09：READMEにRepository Structure更新
- 2025-07-09：READMEにOutput Filesセクション追加
- 2025-07-09：GitHub PagesをLPとして使う方針を確定（Jekyll＋docs/）

### 🛠 作業中
- 原稿の英訳作業中（序文・第1章から順に）
- EPUB/PDF生成用のRe:VIEWビルドスクリプト整備
- GitHub Pages用の `docs/index.md` 準備中
- 英語表紙の草案・カバー画像構成の検討

### 📌 今後の予定（更新版）
- 📖 ～2025年10月：本文（全5章＋付録）の英訳完了を目指す
- 🎨 2025年11月：図表・イラストの英語化、英語版表紙の作成
- 📝 2025年12月：全文の校正（語調・文法・整合性チェック）
- 🔧 2026年1月：最終調整（Re:VIEWレイアウト、meta情報含む）
- 🌐 2026年1月下旬：GitHubにて無料公開（PDF/EPUB）
- 🛒 2026年2月：KDPにてKindle英語版を無料申請（Price Match戦略）
- 📢 2026年2月下旬以降：X（旧Twitter）で英語圏向けに告知・拡散

---

