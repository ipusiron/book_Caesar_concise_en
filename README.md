# Caesar Cipher Breaking – A Concise Edition

This repository hosts the English edition of _Caesar Cipher Breaking – A Concise Edition_, a concise and practical guide to understanding and breaking the Caesar cipher. The book is authored and translated by **IPUSIRON**, a Japanese cryptography writer known for works such as _The Complete Guide to Cryptography_ and _How to Build a Hacking Lab_.

This edition is part of the **Classical Cipher Series**, aiming to make foundational ciphers accessible to international readers.

---

## 🌐 Official Page

The e-book is available for download from the link below.

- 👉 [https://ipusiron.github.io/book_Caesar_concise_en/](https://ipusiron.github.io/book_Caesar_concise_en/)

---

## 📖 About This Book

- **Title:** Caesar Cipher Breaking – A Concise Edition
- **Original Japanese Title:** 『シーザー暗号の解読法 簡易版』  
- **Author:** IPUSIRON  
- **Original Language:** Japanese  
- **Translated by:** The author (self-translated)  
- **License:** CC BY-NC 4.0

This edition focuses solely on the Caesar cipher and its natural extension, the shift cipher. It is designed for readers new to cryptography, educators, students, and cipher enthusiasts alike.

---

## 📄 License

This book is licensed under the **Creative Commons Attribution-NonCommercial 4.0 International (CC BY-NC 4.0)** license.

You are free to:

- Share — copy and redistribute the material in any medium or format
- Adapt — remix, transform, and build upon the material

Under the following terms:

- **Attribution** — You must give appropriate credit.
- **NonCommercial** — You may not use the material for commercial purposes.

For full license terms, see: [https://creativecommons.org/licenses/by-nc/4.0/](https://creativecommons.org/licenses/by-nc/4.0/)

Commercial use is allowed upon request. Please contact the author at ipusiron@gmail.com for licensing inquiries.

Note: This license applies only to the book content and manuscript files in this repository.  
The Re:VIEW tool used for typesetting is licensed separately under the MIT License.  
See: [Re:VIEW](https://github.com/kmuto/review)

---

## 📚 Build Environment

This repository uses [Re:VIEW](https://github.com/kmuto/review) as the primary typesetting and publishing tool.

All manuscripts are written in Re:VIEW format, and the output (PDF/EPUB) is generated via a reproducible build process.
This ensures consistency and typographic quality for both print and digital editions.

### 📁 Repository Structure

```text
.
├── articles/                # Main manuscript directory (EPUB/PDF output stored here)
│   ├── book_Caesar_concise_en.epub
│   └── book_Caesar_concise_en.pdf
├── docs/                    # GitHub Pages site (landing page and assets)
│   ├── index.md             # Top page content (Markdown)
│   ├── cover-ogp.png        # OGP image used for social media previews
│   ├── favicon.ico          # Favicon for the site
│   └── _config.yml          # GitHub Pages config (Jekyll)
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

### 📦 Build Instructions (for PDF)

Make sure Docker is installed, then run:

```sh
docker run --rm -v "$(pwd)":/work vvakame/review:5.8 \
  /bin/sh -c "gem install unicode-display_width && cd /work && review-pdfmaker config.yml"
```

Alternatively, you can use the provided `build.sh` script for convenience:

```sh
sh build.sh
```

### 📦 Output Files

The main outputs of this repository are the finalized English edition of the book in both EPUB and PDF formats.  
These files are stored in the `articles/` directory and will be published under open access terms upon release.

- `articles/book_Caesar_concise_en.epub` — EPUB format (for Kindle and other e-readers)
- `articles/book_Caesar_concise_en.pdf` — Printable PDF format

---

## 👤 About the Author

**IPUSIRON** is a Japanese technical author and educator specializing in security and cryptography.

Born in 1979 in Soma City, Fukushima, Japan, he continues to reside in his hometown.  
With over 20 years of experience in technical writing, he has published **more than 30 books** on cryptography, hacking, and cybersecurity—both commercially and independently.
Notable titles include:

- _The Complete Guide to Cryptography (暗号技術のすべて)_
- _How to Build a Hacking Lab - Complete Edition (ハッキング・ラボのつくりかた 完全版)_
- _The Textbook of White-Hat Hackers (ホワイトハッカーの教科書)_
- _The Hacker’s School: A Handbook of Lockpicking (ハッカーの学校 鍵開けの教科書)_

He is also an experienced translator and editorial supervisor of cryptographic literature.
Notable translation work includes:

- One of the supervising translators of _Serious Cryptography_ by Jean-Philippe Aumasson (Japanese edition)  
- The translator of _Codebreaking: A Practical Guide_ by Elonka Dunin and Klaus Schmeh (Japanese edition)  
- The translator of _Cracking Codes with Python_ by Al Sweigart (Japanese edition)

His professional background includes:

- Developing business applications
- Inspecting and debugging mobile and web apps
- Installing physical security and disaster prevention systems

He currently focuses on writing, lecturing, and tool development, while continuing comprehensive research across information, physical, and human security domains.

His educational philosophy emphasizes active learning—encouraging readers not just to read, but to “learn by doing.”

In recent years, he has expanded into independently published technical books, commonly known as “doujinshi” in Japan. These self-published works allow him to explore niche topics and reach a broader range of readers beyond commercial publishing.

He has also presented at security conferences, high schools, and technical book fairs such as 技術書典 (Gijutsu-Shoten).

He serves as a board member of the **Cyber Risk Defender Association**, a Japanese non-profit organization focused on security awareness and education.

He is also the founder of **Security Akademeia**, a long-running blog where he shares tutorials, cryptographic tools, and insights from the Japanese security community.

This book is the first English installment in his **Classical Cipher Series**, aimed at introducing foundational cryptographic methods to an international audience.

- Blog: [https://akademeia.info/](https://akademeia.info/)  
- X: [@ipusiron](https://x.com/ipusiron)  
- GitHub: [https://github.com/ipusiron](https://github.com/ipusiron)
