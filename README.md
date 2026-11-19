# Bank Management System in C

A simple console-based Bank Management System written in C.
You can create accounts, deposit money, withdraw money, and view account details.

Account data is stored in memory while the program is running (up to 100 customers). It is not saved to a file, so records are cleared when you exit.

## Features

- Create new bank accounts
- Prevent duplicate account numbers
- Deposit money with validation
- Withdraw money with a balance check
- Display an individual account
- Display all accounts
- Supports up to 100 customers

## How to run

```bash
gcc bank_management.c -o bank
./bank
```

## Tech stack

C language · structures and arrays
