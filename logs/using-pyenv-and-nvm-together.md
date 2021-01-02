## Context
using pyenv and nvm together

## Problem
pyenv: node: command not found

## Cause
- In .zshrc, adding nvm/bin executable to PATH environment variable came after adding pyenv shims to path
- That is, echo $PATH => "... .pyenv/shims:.nvm/versions/node/v10.16.0/bin:..."
- Problem is, pyenv shims pass your command to pyenv, so when you type "node blahblah" to your command line, it reaches pyenv before reaching nvm.
- It tries to execute "node" through pyenv, but results in "pyenv: node: command not found"

## Solution
- Place nvm before pyenv in PATH (change .zshrc accordingly)
- PATH variable should look like "nvm/.../bin:.pyenv/shims:..."
- Why? Because node command is detected at nvm first and does not reach pyenv
