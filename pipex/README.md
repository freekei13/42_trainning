*This project has been created as part of the 42 curriculum by [csamakka].*

## Description

Pipex is a 42 school project aimed at better understanding shell redirections and pipes by handling them in C.

The program takes an input file, applies a command to it, pipes the result to another command, and writes the final output to a file. This replicates the following shell behavior:

```bash
< input_file command1 | command2 > output_file
```

Pipex also supports multiple chained commands and a `here_doc` mode for heredoc input.

## Instructions

### Compilation

```bash
# Standard
make

# With bonus (here_doc + multiple commands)
make bonus
```

### Regular execution

Pipex supports 2 or more commands:

```bash
./pipex input_file command1 command2 ... commandN output_file
```

The output is written to the specified file. If it already exists, it will be overwritten. This replicates:

```bash
< input_file command1 | command2 | ... | commandN > output_file
```

Each command can include arguments and options using quotation marks:

```bash
./pipex example.txt "cat" "grep x" "sed s/l/.../g" outfile.txt
```

### Heredoc execution

```bash
./pipex here_doc LIMITER command1 command2 ... commandN output_file
```

You will be prompted to input text line by line until `LIMITER` is entered. The output file will be **appended** rather than overwritten. This replicates:

```bash
<< LIMITER command1 | command2 | ... | commandN >> output_file
```

> **Note:** The here_doc bonus prints an extra prompt line after the LIMITER is given as input.

## Resources

- [42 Cursus GitBook](https://42-cursus.gitbook.io/guide/) — General 42 project guide
- Stack Overflow and various programming blogs
- Fellow 42 students
