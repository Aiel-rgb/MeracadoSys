# 🛒 MercadoSys

Sistema de mercado desenvolvido em **linguagem C** como projeto de estudo para a faculdade, com foco em ponteiros, alocação dinâmica de memória e modularização de código.

---

## 🎯 Objetivo

O principal intuito deste projeto foi aprender e praticar os recursos fundamentais da linguagem C:

- **Ponteiros** — uso de `*` e `**`, passagem por referência, acesso com `->`
- **Alocação dinâmica** — `malloc`, `realloc` e `free`
- **Structs** — modelagem de dados com `typedef struct`
- **Modularização** — separação em arquivos `.h` e `.c`
- **Bibliotecas padrão** — `stdio.h`, `stdlib.h`, `string.h`

---

## 📁 Estrutura do Projeto

```
MercadoSys/
├── main.c               # Menu principal e interface do usuário
├── headers/
│   ├── tipos.h          # Structs: Produto e Venda
│   ├── produtos.h       # Declarações do módulo de produtos
│   ├── estoque.h        # Declarações do módulo de estoque
│   └── vendas.h         # Declarações do módulo de vendas
└── modules/
    ├── produtos.c        # Cadastro, busca e listagem de produtos
    ├── Estoque.c         # Controle de entrada e saída de estoque
    └── vendas.c          # Registro de vendas e relatórios
```

---

## ⚙️ Funcionalidades

- **Cadastrar produtos** — nome, preço e quantidade, com alocação dinâmica via `realloc`
- **Listar produtos** — tabela formatada com valor total do estoque
- **Realizar venda** — débito automático do estoque e cálculo de comissão (5%)
- **Verificar estoque** — alerta de estoque baixo ou esgotado
- **Adicionar estoque** — reposição de unidades de um produto
- **Relatório de vendas** — total vendido e total de comissões

---

## 🧠 Conceitos Aplicados

### Ponteiro para ponteiro (`**`)
Usado em `cadastrarProdutos` para que o `realloc` possa alterar o endereço original do array:
```c
void cadastrarProdutos(Produto **produtos, int *total, int quantosAdicionar);
```

### Alocação dinâmica com realloc
O array de produtos cresce conforme o usuário cadastra, sem tamanho fixo:
```c
Produto *temp = realloc(*produtos, (*total + quantosAdicionar) * sizeof(Produto));
```

### Acesso via ponteiro com `->`
Funções de estoque recebem ponteiro para o produto e modificam diretamente:
```c
void adicionarEstoque(Produto *p, int quantidade) {
    p->quantidade += quantidade;
}
```

### Separação em headers
Cada módulo tem seu `.h` com as declarações e seu `.c` com a implementação, evitando dependências circulares.

---

## 🚀 Como Compilar e Rodar

**Requisitos:** gcc instalado

```bash
# Clonar ou entrar na pasta do projeto
cd MercadoSys

# Compilar todos os módulos juntos
gcc -Wall main.c modules/produtos.c modules/Estoque.c modules/vendas.c -o mercado

# Rodar
./mercado
```

---

## 📚 Bibliotecas Utilizadas

| Biblioteca | Uso no projeto |
|---|---|
| `stdio.h` | `printf`, `scanf` |
| `stdlib.h` | `malloc`, `realloc`, `free`, `system` |
| `string.h` | `strcpy`, `strcmp` |

---

## 👨‍💻 Aut: Nevesz

Desenvolvido como projeto de estudo de **Estruturas de Dados em C** na faculdade.
