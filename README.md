# Simple Shell

This is a simple shell program written in C that provides basic command-line functionality. It supports a subset of common shell commands and features.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Allowed Functions and System Calls](#allowed-functions-and-system-calls)
- [Contributing](#contributing)
- [License](#license)

## Features

- Basic command execution
- Path resolution for command execution
- Environment variable handling
- Built-in commands: cd, env, setenv, unsetenv, alias
- Error handling for common system calls

## Getting Started

### Prerequisites

- GCC (GNU Compiler Collection)
- Linux/Unix environment

### Building the Shell

```bash
gcc *.c -o simple_shell
```

### Running the Shell

```bash
./simple_shell
```

## Usage

Once the shell is running, you can enter commands as you would in a regular shell. Here are some examples:

```bash
$ ls
$ cd /path/to/directory
$ setenv MY_VARIABLE my_value
$ alias myalias='echo Hello, World!'
$ myalias
```

## Allowed Functions and System Calls

The following functions and system calls are allowed in this shell:

- `access`, `chdir`, `close`, `closedir`, `execve`, `exit`, `_exit`
- `fflush`, `fork`, `free`, `getcwd`, `getline`, `getpid`, `isatty`
- `kill`, `malloc`, `open`, `opendir`, `perror`, `read`, `readdir`
- `signal`, `stat`, `lstat`, `fstat`, `strtok`, `wait`, `waitpid`, `wait3`, `wait4`
- `write`

## Contributing

Contributions are welcome! If you have any improvements or bug fixes, feel free to submit a pull request.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/my-feature`)
3. Commit your changes (`git commit -m 'Add some feature'`)
4. Push to the branch (`git push origin feature/my-feature`)
5. Open a pull request

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
