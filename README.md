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

### 📦 Installation

#### 🂨 Clone the Repository

```bash
git clone https://github.com/saber-88/spot.git ~/spot
cd spot
```

#### ⚙️ Run the Setup Script

```bash
./setup.sh
```

This script will:

* Compile the `spot.c` file using `make`
* Move the resulting binary to `/usr/local/bin`
* Make `spot` globally accessible from your terminal

You may be asked to enter your password because moving files to `/usr/local/bin` requires root privileges.

> ✅ After installation, you can use the tool from anywhere by simply running:

```bash
spot <PATTERN> <FILENAME>
```


---

## 💻 Usage

```bash
spot [OPTIONS] <PATTERN> <FILENAME>
```

### ⚙️ Options

| Flag                  | Description                                                             |
|-----------------------|-------------------------------------------------------------------------|
| `-i`, `--ignore-case` | Highlight all occurrences of pattern in a file ignoring case            |
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

### Count total occurrences

```bash
spot -c hello file.txt
```

### Combined example

```bash
spot -i -c hello file.txt
```

---

## 📦 Sample Output

```bash
spot -i king book.txt
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


