# Calculadora

## Ordem de precedencia:
```
  () | -
  ^
  * | /
  + | -
```
## Forma aumentada BNF
```
  <expressao> ::= <adic>
  <adic> ::= <mult> {('-' | '+') <mult>}
  <mult> ::= <pot> {('/' | '*') <pot>}
  <pot> ::= <prio> {'^' <prio>}
  <prio> ::= '(' <expressao> ')' | [<negativo>] {<digit>}+
  <negativo> ::= '-'
  <digit> ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
```
