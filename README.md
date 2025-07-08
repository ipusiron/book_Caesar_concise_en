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
├── manuscript/         # Source text files (Markdown, Re:VIEW, or LaTeX)
├── images/             # Diagrams and illustrations used in the book
├── epub/               # Compiled EPUB files (for Kindle etc.)
├── pdf/                # Preview or printable PDFs
├── assets/             # Cover images, metadata
└── LICENSE             # License to be added upon public release
```

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
