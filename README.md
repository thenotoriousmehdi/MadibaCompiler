# MadibaCompiler
# Mini-Compiler Project

![Compiler](https://img.shields.io/badge/status-active-brightgreen) ![License](https://img.shields.io/badge/license-MIT-blue)

A mini-compiler implementing lexical, syntactic, and semantic analysis phases for a custom-defined programming language. Built using **Flex** (lexical analysis) and **Bison** (syntax/semantic analysis), with intermediate code generation via quadruples.

---

## Project Overview
This project involves designing a compiler for a custom language, covering:
- **Lexical Analysis**: Tokenization using Flex.
- **Syntax/Semantic Analysis**: Parsing with Bison (LALR grammar), AST generation, and conflict resolution.
- **Symbol Table**: Dynamic management of variables, constants, and structured types (e.g., arrays).
- **Intermediate Code**: Quadruple format for code generation.
- **Error Reporting**: Detailed error messages with source file location.

## Language Features
The custom language includes:
- **Program Structure**: Block-based with `begin` and `end` keywords.
- **Comments**: Single-line (`//`) and multi-line (`/* ... */`).
- **Variables**: Simple (e.g., `int x`) and structured (e.g., arrays `int[10] arr`).
- **Types**: `int`, `float`, `bool`, and custom types with specified value ranges.
- **Operators**: 
  - Arithmetic (`+`, `-`, `*`, `/`).
  - Logical (`&&`, `||`, `!`).
  - Comparison (`==`, `!=`, `<`, `>`).
  - Priorities and associativity rules (e.g., `*` over `+`).
- **Control Flow**: `if-else`, `while` loops, and basic I/O instructions.

