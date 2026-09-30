#  Snake Game

Um clássico jogo da cobrinha (*Snake*) desenvolvido em **C++17** com a biblioteca gráfica **[raylib](https://www.raylib.com/)** e sistema de build **CMake**. Sem dependências extras: apenas C++, raylib e CMake.

##  Funcionalidades

- Movimentação da cobra em grade (grid)
- Comida gerada aleatoriamente (nunca sobre o corpo da cobra)
- Detecção de colisão com paredes e com o próprio corpo
- Tela de *Game Over* com opção de reiniciar

##  Controles

| Tecla                     | Ação                      |
|---------------------------|---------------------------|
| `↑` `↓` `←` `→` ou `WASD` | Mover a cobra             |
| `R`                       | Reiniciar após Game Over  |
| `ESC`                     | Sair do jogo              |

##  Tecnologias

- **Linguagem:** C++17
- **Gráficos / Input / Janela:** raylib 6
- **Build:** CMake 3.15+

##  Pré-requisitos

- Compilador C++17 (GCC, Clang ou MSVC)
- [CMake](https://cmake.org/download/) 3.15 ou superior
- Git (necessário caso o CMake baixe a raylib automaticamente)

##  Como compilar e executar

```bash
# 1. Clone o repositório
git clone https://github.com/seu-usuario/snake_game.git
cd snake_game

# 3. Build
cmake ..

# 4. Compilar
make

# 5. Execute
./build/snake-game
```
```
```

## 🗺️ Ideias para o futuro

- [ ] Aumentar a velocidade conforme a pontuação
- [ ] Salvar o recorde em arquivo
- [ ] Efeitos sonoros e música
- [ ] Menu inicial e níveis de dificuldade
- [ ] Obstáculos no mapa
