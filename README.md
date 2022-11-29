# 	:chess_pawn: **[ RPCG ]  Role Playing Chess Game** 	:chess_pawn:

Projeto integrador de um jogo educacional: este jogo conta sobre um peça de peão no seu primeiro dia na confraria. 
Aprenda junto do peão, conceitos básicos de xadrez de maneira mais lúdica que tutoriais engessados na internet. 


## :page_with_curl: One Sheet Paper 

<img src="src/images/one_sheet_paper.png" width="100%"/>


## :floppy_disk: Acesso ao jogo 
> **Observação:** os passos a seguir é para Sistema Operacional Linux  

1. Verificar a instalação do gcc.
    ```bash
    gcc --version
    ```
    Caso não tenha o gcc instalado deve se instalar o pacote build-essencial, utilizando os dois seguintes comandos:
    ```bash
    sudo apt update
    sudo apt install build-essential
    ```

2. Instalar o pacote de jogo [Allegro](https://github.com/liballeg/allegro_wiki/wiki).
    ```bash
    sudo apt-get install liballegro*5.2 liballegro*5-dev
    ```
    Caso não funcione, [clique aqui](https://github.com/liballeg/allegro_wiki/wiki/Quickstart) para comandos alternativos.

3. Compilar os arquivos do projeto com o seguinte comando: 
    ```bash
    gcc main.c -o game $(pkg-config allegro-5 allegro_font-5 allegro_primitives-5 allegro_audio-5 allegro_acodec-5 allegro_image-5 allegro_ttf-5 --libs --cflags)
    ```
    Para inicializar o jogo:
    ```bash
    ./game
    ```

## :open_file_folder: Organização do projeto

.                                           <br />
├── ./.gitignore                            <br />
├── ./README.md                             <br />
├── ./main.c                                <br />
└── ./src                                   <br />
&emsp; &ensp;   ├── ./src/audio             <br />
&emsp; &ensp;   ├── ./src/fonts             <br />
&emsp; &ensp;   ├── ./src/images            <br />
&emsp; &ensp;   ├── ./src/script            <br />
&emsp; &ensp;   ├── ./src/tiles             <br />
&emsp; &ensp;   ├── ./src/audio.h           <br />
&emsp; &ensp;   ├── ./src/map.h             <br />
&emsp; &ensp;   ├── ./src/npc.h             <br />
&emsp; &ensp;   ├── ./src/parallel_game.h   <br />
&emsp; &ensp;   ├── ./src/player.h          <br />
&emsp; &ensp;   ├── ./src/screenplay.h      <br />
&emsp; &ensp;   ├── ./src/stand_screen.h    <br />
&emsp; &ensp;   └── ./src/structure.h       <br />


