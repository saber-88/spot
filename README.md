# spot

**spot** is a lightweight, terminal-based text search utility written in C. It allows you to search for a pattern in a file, similar to `grep`, with options to ignore case, highlight all matches, count occurrences, and more.

---

## 🔧 Features

- 📌 Search for a pattern in a file
- 🔠 Ignore case while matching
- 🎯 Highlight all occurrences in a line
- 🧮 Count total matches across the file
- 🆘 Display usage/help message
- 🌈 Color-highlighted output for matched patterns

---

## 🚀 Installation

You can build the binary using `gcc`:

```bash
gcc spot.c -o spot
```

Make it globally available by moving it to a location in your `PATH`:

```bash
sudo mv spot /usr/local/bin
```

---

## 💻 Usage

```bash
spot [OPTIONS] <PATTERN> <FILENAME>
```

### ⚙️ Options

| Flag                  | Description                                                             |
|-----------------------|-------------------------------------------------------------------------|
| `-i`, `--ignore-case` | Match pattern ignoring case                                             |
| `-a`, `--all`         | Highlight **all** occurrences of the pattern in each line               |
| `-c`, `--count`       | Display the **total number of matches** instead of matching lines       |
| `-h`, `--help`        | Show help message and exit                                              |

---

## 📂 Examples

### Basic match

```bash
spot hello file.txt
```

### Ignore case

```bash
spot -i Hello file.txt
```

### Highlight all matches in a line

```bash
spot -a hello file.txt
```

### Count total occurrences

```bash
spot -c hello file.txt
```

### Combined example

```bash
spot -i -a -c hello file.txt
```

---

## 📦 Sample Output

```bash
spot -i -a king book.txt
11 : There were a KING with a large jaw and a queen with a plain face...
12 : there were a KING with a large jaw and a queen with a fair face...
```

---

## 🤝 Contributing

Contributions, issues, and suggestions are welcome!

1. Fork the repository
2. Create a new branch (`git checkout -b feature-name`)
3. Make your changes
4. Push to your branch and open a Pull Request

---

## 📜 License

This project is licensed under the **MIT License** – see the [LICENSE](LICENSE) file for details.

---

## 👤 Author

Developed by [Karmveer](https://github.com/saber-88)
