# Notes

## Union

A ideia do Union neste caso é unificar o mesmo espaco de memoria de onde essas variaveis vao ficar,

Exemplo:

int ocupa 32 bits (4 bytes), float tambem ocupa 32 bits (4 bytes)
se eu tivesse uma propriedade para cada tipo dessa variavel, elas ocupariam 8 bytes:

```c
struct example {
    int i; // 4 bytes
    float i; // 4 bytes
}
```

Mas caso elas estiverem dentro do union, como elas irao ocupar o mesmo espaco, acabariam 
usando apenas 4 bytes:

```c
struct example {
    union {
        int i;
        float i;
    } // 4 bytes
}
```

## Alinhamento natural

Todo hardware é feito inicialmente em mente de conseguir carregar apenas dados alinhados, a instrução que carrega 32 bits espera estar alinhado em 32 bits, ela vê a memória como um grande array de objetos de 32 bits

Qual a diferença entre:

```c 
struct { int x; char c; };
struct { char c; int x; };
```

Quando colocamos o int primeiro, ira seguir normalmente o char precisa estar alinhado com multiplos de 1 byte, ou seja, tanto faz o lugar em que ele vai estar.
Mas quando colocamos o char primeiro, o int vai se alinhar com o proximo multiplo dele (4 bytes), fazendo com que o char ocupe 4 bytes em vez de apenas 1.
Entao a primeira struct ucupa 5 bytes e a segunda acaba ocupando 8 bytes.

